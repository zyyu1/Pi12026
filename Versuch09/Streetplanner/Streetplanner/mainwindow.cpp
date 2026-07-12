#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addcitydialog.h"
#include "addstreetdialog.h"
#include "city.h"
#include "dijkstra.h"
#include "map.h"
#include "mapiofileinput.h"
#include "street.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QRandomGenerator>

#include <cmath>

///////////////////////////////////////////////////////////////////////////////
// Test Functions
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Tests whether the current input field contains a number or plain text.
 */
void MainWindow::testInput()
{
    // Read the current user input from the test line edit.
    QString input = ui->lineEdit_testInput->text();

    bool trans = false;
    int number = input.toInt(&trans);

    // If conversion succeeds, treat the input as a number.
    if (trans)
    {
        QMessageBox::information(
            this,
            "Input test",
            "The input is a number.\nNumber + 4 = " + QString::number(number + 4));
    }
    else
    {
        // Otherwise show the text unchanged.
        QMessageBox::information(this, "Input test", "The input is text:\n" + input);
    }
}

/**
 * @brief Draws two example cities into the graphics scene.
 */
void MainWindow::testDrawCity()
{
    // Remove previous scene content before drawing the example.
    scene->clear();

    City city1("Aachen", 100, 100);
    City city2("Bonn", 220, 180);

    city1.draw(*scene);
    city2.draw(*scene);

    qDebug() << "Cities drawn";
}

/**
 * @brief Builds and draws a small manually created example map.
 */
void MainWindow::testMap()
{
    // Start with an empty scene so the test result is clearly visible.
    scene->clear();

    // Create a small example graph in memory.
    City* city1 = new City("Aachen", 100, 100);
    City* city2 = new City("Cologne", 250, 150);
    City* city3 = new City("Bonn", 200, 250);

    Street* street1 = new Street(city1, city2);
    Street* street2 = new Street(city1, city3);
    Street* street3 = new Street(city2, city3);

    // Replace the current map with a fresh test map.
    delete map;
    map = new Map();

    map->addCity(city1);
    map->addCity(city2);
    map->addCity(city3);

    map->addStreet(street1);
    map->addStreet(street2);
    map->addStreet(street3);
    map->draw(*scene);

    qDebug() << "Map drawn";
}

/**
 * @brief Tests city lookup by name.
 */
void MainWindow::testFindCity()
{
    // Build a minimal map used only for this lookup test.
    delete map;
    map = new Map();

    City* city1 = new City("Aachen", 100, 100);
    City* city2 = new City("Cologne", 250, 150);

    map->addCity(city1);
    map->addCity(city2);

    // Search for an existing city by name.
    City* foundCity = map->findCity("Aachen");

    if (foundCity != nullptr && foundCity->getName() == "Aachen")
    {
        qDebug() << "testFindCity successful. Found Aachen.";
    }
    else
    {
        qDebug() << "testFindCity failed.";
    }
}

/**
 * @brief Tests retrieving all streets connected to a city.
 */
void MainWindow::testStreetList()
{
    // Build a map where one city has exactly two connected streets.
    delete map;
    map = new Map();

    City* city1 = new City("Aachen", 100, 100);
    City* city2 = new City("Cologne", 250, 150);
    City* city3 = new City("Bonn", 200, 250);

    Street* street1 = new Street(city1, city2);
    Street* street2 = new Street(city1, city3);

    map->addCity(city1);
    map->addCity(city2);
    map->addCity(city3);
    map->addStreet(street1);
    map->addStreet(street2);

    // Query all streets connected to Aachen.
    QVector<Street*> streets = map->getStreetList(city1);

    if (streets.size() == 2)
    {
        qDebug() << "testStreetList successful. Aachen has 2 connected streets.";
    }
    else
    {
        qDebug() << "testStreetList failed. Expected 2, actual:" << streets.size();
    }
}

/**
 * @brief Tests retrieving the opposite city of a street.
 */
void MainWindow::testOppositeCity()
{
    // Build a simple street between two cities.
    delete map;
    map = new Map();

    City* city1 = new City("Aachen", 100, 100);
    City* city2 = new City("Cologne", 250, 150);

    Street* street1 = new Street(city1, city2);

    map->addCity(city1);
    map->addCity(city2);
    map->addStreet(street1);

    // Ask the map for the other endpoint of the street.
    City* oppositeCity = map->getOppositeCity(street1, city1);

    if (oppositeCity != nullptr && oppositeCity->getName() == "Cologne")
    {
        qDebug() << "testOppositeCity successful. Opposite city is Cologne.";
    }
    else
    {
        qDebug() << "testOppositeCity failed.";
    }
}

/**
 * @brief Tests street length calculation.
 */
void MainWindow::testLength()
{
    // Build a simple street with known coordinates and distance.
    delete map;
    map = new Map();

    City* city1 = new City("Aachen", 100, 100);
    City* city2 = new City("Cologne", 250, 150);
    Street* street1 = new Street(city1, city2);

    map->addCity(city1);
    map->addCity(city2);
    map->addStreet(street1);

    // Compare the computed length against the expected Euclidean distance.
    double length = map->getLength(street1);
    double expected = std::sqrt(150 * 150 + 50 * 50);

    if (std::abs(length - expected) < 0.001)
    {
        qDebug() << "testLength successful.";
    }
    else
    {
        qDebug() << "testLength failed.";
    }
}

/**
 * @brief Runs the standard AbstractMap conformance test from the exercise template.
 */
void MainWindow::testAbstractMap()
{
    // This test follows the structure provided in TestFunktionen.txt.
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);

    qDebug() << "MapTest: Start Test of the Map";
    {
        // A street must not be added before both endpoint cities exist in the map.
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1)
        {
            qDebug() << "-Error: Street should not be added if cities have not been added.";
        }
    }

    {
        // After adding the cities, the same street should be accepted.
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1)
        {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        // Existing cities must be found, missing cities must return nullptr.
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
        {
            qDebug() << "-Error: City a could not be found.";
        }

        city = testMap.findCity("b");
        if (city != b)
        {
            qDebug() << "-Error: City b could not be found.";
        }

        city = testMap.findCity("c");
        if (city != nullptr)
        {
            qDebug() << "-Error: If city could not be found nullptr should be returned.";
        }
    }

    // Extend the test graph for the remaining checks.
    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        // The map must return the opposite endpoint of a valid street.
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
        {
            qDebug() << "-Error: Opposite city should be b.";
        }

        city = testMap.getOppositeCity(s, c);
        if (city != nullptr)
        {
            qDebug() << "-Error: Opposite city for a city not linked by the street should be nullptr.";
        }
    }

    {
        // The street length should match the expected geometry.
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        if (l < expectedLength * 0.95 || l > expectedLength * 1.05)
        {
            qDebug() << "-Error: Street length is not equal to the expected value.";
        }
    }

    {
        // Street lists should contain the expected number of connected streets.
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1)
        {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s)
        {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
        {
            qDebug() << "-Error: Two streets should be found for city b.";
        }
    }

    qDebug() << "MapTest: End Test of the Map.";
}

/**
 * @brief Fills and draws the predefined NRW map.
 */
void MainWindow::testFillMap()
{
    // Clear the scene and replace the current map with a fresh example map.
    scene->clear();

    delete map;
    map = new Map();

    mapIo->fillMap(*map);
    map->draw(*scene);

    qDebug() << "NRW map drawn";
}

/**
 * @brief Executes a fixed Dijkstra example and highlights the result.
 */
void MainWindow::testDijkstra()
{
    // Draw a fresh predefined map before highlighting the path.
    scene->clear();

    delete map;
    map = new Map();

    mapIo->fillMap(*map);
    map->draw(*scene);

    // Run a fixed example search used for visual testing.
    QVector<Street*> path = Dijkstra::search(*map, "Aachen", "Düsseldorf");

    // Highlight each street of the shortest path.
    for (Street* street : path)
    {
        street->drawRed(*scene);
    }

    qDebug() << "Shortest path drawn";
}

/**
 * @brief Draws a rectangle at a random position in the scene.
 */
void MainWindow::testRandomRect()
{
    // Clear the scene so the random rectangle is easy to spot.
    scene->clear();

    int x = QRandomGenerator::global()->bounded(300);
    int y = QRandomGenerator::global()->bounded(300);

    scene->addRect(x, y, 40, 30);

    qDebug() << "Random rectangle drawn";
}

///////////////////////////////////////////////////////////////////////////////
// Test Button Slots
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Runs the simple input test.
 */
void MainWindow::on_pushButton_clicked()
{
    qDebug() << "=== Test ===";
    testInput();
    qDebug() << "=== End of Test ===";
}

/**
 * @brief Runs the AbstractMap conformance test.
 */
void MainWindow::on_pushButton_testAbstractMap_clicked()
{
    testAbstractMap();
}

/**
 * @brief Runs the Dijkstra visualization test.
 */
void MainWindow::on_pushButton_testDijkstra_clicked()
{
    testDijkstra();
}

///////////////////////////////////////////////////////////////////////////////
// Main Window Setup
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates the main window and initializes the graphics scene.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox_showTests->setChecked(false);

    // Hide the optional test controls until the checkbox is enabled.
    ui->label_test->setVisible(false);
    ui->label_testInput->setVisible(false);
    ui->lineEdit_testInput->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_testAbstractMap->setVisible(false);
    ui->pushButton_testDijkstra->setVisible(false);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    map = new Map();
    mapIo = new MapIoNrw();
}

/**
 * @brief Releases the user interface and helper objects owned by the window.
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete map;
    delete mapIo;
}

/**
 * @brief Updates the city combo boxes while preserving the current selection if possible.
 */
void MainWindow::updateCityComboBoxes()
{
    // Remember the current selection so it can be restored after refilling the lists.
    QString currentStart = ui->comboBox_startCity->currentText();
    QString currentTarget = ui->comboBox_targetCity->currentText();

    // Remove old entries before inserting the current map content.
    ui->comboBox_startCity->clear();
    ui->comboBox_targetCity->clear();

    QStringList cityNames = map->getCityNameList();

    ui->comboBox_startCity->addItems(cityNames);
    ui->comboBox_targetCity->addItems(cityNames);

    // Restore the previous selection if the city still exists.
    int startIndex = ui->comboBox_startCity->findText(currentStart);
    if (startIndex >= 0)
    {
        ui->comboBox_startCity->setCurrentIndex(startIndex);
    }

    int targetIndex = ui->comboBox_targetCity->findText(currentTarget);
    if (targetIndex >= 0)
    {
        ui->comboBox_targetCity->setCurrentIndex(targetIndex);
    }
}

///////////////////////////////////////////////////////////////////////////////
// Main UI Slots
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Reloads the predefined NRW map and draws it.
 */
void MainWindow::on_pushButton_fillMap_clicked()
{
    scene->clear();

    // Rebuild the map to avoid mixing old and new content.
    delete map;
    map = new Map();

    mapIo->fillMap(*map);
    map->draw(*scene);

    updateCityComboBoxes();

    qDebug() << "Map filled and drawn";
}

/**
 * @brief Searches and highlights a path between the selected start and target city.
 */
void MainWindow::on_pushButton_searchPath_clicked()
{
    // Always redraw the base map before drawing the highlighted result.
    scene->clear();
    map->draw(*scene);

    QString startCity;
    QString targetCity;

    // Prefer manual text input; fall back to the combo boxes if the line edits are empty.
    if (!ui->lineEdit_startCity->text().isEmpty())
    {
        startCity = ui->lineEdit_startCity->text();
    }
    else
    {
        startCity = ui->comboBox_startCity->currentText();
    }

    if (!ui->lineEdit_targetCity->text().isEmpty())
    {
        targetCity = ui->lineEdit_targetCity->text();
    }
    else
    {
        targetCity = ui->comboBox_targetCity->currentText();
    }

    // Run the shortest-path search on the current map.
    QVector<Street*> path = Dijkstra::search(*map, startCity, targetCity);

    if (path.isEmpty())
    {
        QMessageBox::warning(this, "Path search", "No path found. Please check the city names.");
        return;
    }

    // Highlight the returned path on top of the normal map drawing.
    for (Street* street : path)
    {
        street->drawRed(*scene);
    }

    qDebug() << "Path drawn from" << startCity << "to" << targetCity;
}

/**
 * @brief Clears the current scene content.
 */
void MainWindow::on_pushButton_clearScene_clicked()
{
    scene->clear();
    qDebug() << "Scene cleared";
}

/**
 * @brief Opens the add-city dialog and inserts the created city into the map.
 */
void MainWindow::on_pushButton_addCity_clicked()
{
    // Open the dialog and wait for the user to accept or cancel it.
    AddCityDialog dialog(this);
    int result = dialog.exec();

    if (result == QDialog::Accepted)
    {
        // Create the city object from the dialog content.
        City* newCity = dialog.createCity();

        if (newCity == nullptr)
        {
            QMessageBox::warning(this, "Add city", "Invalid input. Please enter a name and valid integer coordinates.");
            return;
        }

        // Add the city, refresh the UI lists, and redraw the map.
        map->addCity(newCity);
        updateCityComboBoxes();

        scene->clear();
        map->draw(*scene);

        qDebug() << "City added via dialog:" << newCity->getName();
    }
}

/**
 * @brief Opens the add-street dialog and inserts the created street into the map.
 */
void MainWindow::on_pushButton_addStreet_clicked()
{
    // Provide the current city names so the user can select valid endpoints.
    AddStreetDialog dialog(map->getCityNameList(), this);

    int result = dialog.exec();

    if (result == QDialog::Accepted)
    {
        // Read the endpoint names from the dialog.
        QString firstCityName = dialog.getFirstCityName();
        QString secondCityName = dialog.getSecondCityName();

        // Resolve the names to actual city objects stored in the map.
        City* city1 = map->findCity(firstCityName);
        City* city2 = map->findCity(secondCityName);

        if (city1 == nullptr || city2 == nullptr)
        {
            QMessageBox::warning(this, "Add street", "At least one city was not found.");
            return;
        }

        // Create and add the street only if both cities are valid.
        Street* newStreet = new Street(city1, city2);
        bool success = map->addStreet(newStreet);

        if (!success)
        {
            QMessageBox::warning(this, "Add street", "The street could not be added.");
            delete newStreet;
            return;
        }

        // Redraw the map so the new street becomes visible.
        scene->clear();
        map->draw(*scene);

        qDebug() << "Street added via dialog:" << firstCityName << "-" << secondCityName;
    }
}

/**
 * @brief Shows or hides the test controls.
 */
void MainWindow::on_checkBox_showTests_clicked(bool checked)
{
    // Toggle all test-related widgets together.
    ui->label_test->setVisible(checked);
    ui->label_testInput->setVisible(checked);
    ui->lineEdit_testInput->setVisible(checked);
    ui->pushButton->setVisible(checked);
    ui->pushButton_testAbstractMap->setVisible(checked);
    ui->pushButton_testDijkstra->setVisible(checked);
}

/**
 * @brief Closes the main window.
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/**
 * @brief Clears the scene via the menu action.
 */
void MainWindow::on_actionClear_scene_triggered()
{
    scene->clear();
    qDebug() << "Scene cleared";
}

/**
 * @brief Shows a short about dialog for the application.
 */
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "Streetplanner\nPraktikum Informatik 1");
}

/**
 * @brief Opens two text files, loads a map from them, and redraws the scene.
 */
void MainWindow::on_actionOpen_triggered()
{
    // Ask the user for the city file first.
    QString cityFilePath = QFileDialog::getOpenFileName(this, "Open city file", "", "Text files (*.txt);;All files (*)");

    if (cityFilePath.isEmpty())
    {
        return;
    }

    // Ask for the street file in a second step.
    QString streetFilePath = QFileDialog::getOpenFileName(this, "Open street file", "", "Text files (*.txt);;All files (*)");

    if (streetFilePath.isEmpty())
    {
        return;
    }

    // Replace the current map before importing the new one from file.
    scene->clear();

    delete map;
    map = new Map();

    MapIoFileinput fileInput(cityFilePath, streetFilePath);
    fileInput.fillMap(*map);

    // Draw the imported map and refresh the city selection widgets.
    map->draw(*scene);
    updateCityComboBoxes();

    qDebug() << "Map loaded from files";
}

/**
 * @brief Placeholder slot for the save action.
 */
void MainWindow::on_actionSave_triggered()
{
    QMessageBox::information(this, "Save", "Save was clicked.");
}
