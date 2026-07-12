#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "mapionrw.h"

#include <QGraphicsScene>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Main application window of the Streetplanner project.
 *
 * The main window manages the graphics scene, user interaction, dialogs,
 * example tests, and path-search actions.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Creates the main window.
     * @param parent Parent widget.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the main window and owned helper objects.
     */
    ~MainWindow() override;

private slots:
    /**
     * @brief Runs the simple input test.
     */
    void on_pushButton_clicked();

    /**
     * @brief Fills the map with the predefined NRW data.
     */
    void on_pushButton_fillMap_clicked();

    /**
     * @brief Searches and highlights a path between start and target city.
     */
    void on_pushButton_searchPath_clicked();

    /**
     * @brief Clears the graphics scene.
     */
    void on_pushButton_clearScene_clicked();

    /**
     * @brief Opens the add-city dialog and adds the created city.
     */
    void on_pushButton_addCity_clicked();

    /**
     * @brief Opens the add-street dialog and adds the created street.
     */
    void on_pushButton_addStreet_clicked();

    /**
     * @brief Shows or hides the test controls area.
     * @param checked Whether the controls should be visible.
     */
    void on_checkBox_showTests_clicked(bool checked);

    /**
     * @brief Closes the application window.
     */
    void on_actionExit_triggered();

    /**
     * @brief Clears the graphics scene via the menu action.
     */
    void on_actionClear_scene_triggered();

    /**
     * @brief Shows the about dialog.
     */
    void on_actionAbout_triggered();

    /**
     * @brief Loads a map from user-selected input files.
     */
    void on_actionOpen_triggered();

    /**
     * @brief Placeholder for saving the current map.
     */
    void on_actionSave_triggered();

    /**
     * @brief Runs the AbstractMap conformance test.
     */
    void on_pushButton_testAbstractMap_clicked();

    /**
     * @brief Runs the Dijkstra visualization test.
     */
    void on_pushButton_testDijkstra_clicked();

private:
    /**
     * @brief Tests whether the manual input is text or a number.
     */
    void testInput();

    /**
     * @brief Draws example cities directly into the scene.
     */
    void testDrawCity();

    /**
     * @brief Builds and draws a small hand-made map.
     */
    void testMap();

    /**
     * @brief Runs the standard AbstractMap test from the exercise template.
     */
    void testAbstractMap();

    /**
     * @brief Fills and draws the predefined NRW map.
     */
    void testFillMap();

    /**
     * @brief Runs a fixed Dijkstra example and highlights the result.
     */
    void testDijkstra();

    /**
     * @brief Tests city lookup by name.
     */
    void testFindCity();

    /**
     * @brief Tests retrieving all streets of a city.
     */
    void testStreetList();

    /**
     * @brief Tests retrieving the opposite city of a street.
     */
    void testOppositeCity();

    /**
     * @brief Tests street length calculation.
     */
    void testLength();

    /**
     * @brief Draws a randomly placed rectangle for scene testing.
     */
    void testRandomRect();

    /**
     * @brief Refreshes the start and target city combo boxes.
     */
    void updateCityComboBoxes();

    ///< Designer-generated user interface.
    Ui::MainWindow *ui;
    ///< Scene displayed by the graphics view.
    QGraphicsScene *scene;
    ///< Current working map.
    Map* map;
    ///< Provider for the predefined NRW map.
    MapIo* mapIo;
};

#endif // MAINWINDOW_H
