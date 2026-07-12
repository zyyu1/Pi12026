///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "mapiofileinput.h"

#include <fstream>
#include <sstream>

#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

//#define CITY_EXTENSION
//#define STREET_EXTENSION

#ifdef CITY_EXTENSION
    #include "bigtown.h"
    #include "smalltown.h"
#endif
#ifdef STREET_EXTENSION
    #include "motorway.h"
    #include "stateroad.h"
#endif

/**
 * @brief Stores the file paths used for later map import.
 */
MapIoFileinput::MapIoFileinput(QString pathToCityFile, QString pathToStreetFile):
    pathToCityFile(pathToCityFile),
    pathToStreetFile(pathToStreetFile)
{
}

/**
 * @brief Destroys the file-based map reader.
 */
MapIoFileinput::~MapIoFileinput()
{
}

/**
 * @brief Reads city and street data from the configured files and adds them to the map.
 */
void MapIoFileinput::fillMap(AbstractMap &map)
{
    // Temporary variables used while parsing the input files line by line.
    QString line;
    QString name;
    QString xPositionString;
    QString yPositionString;
    QString firstCityName;
    QString secondCityName;
#ifdef CITY_EXTENSION
    QString cityTyp;
#endif

#ifdef STREET_EXTENSION
    QString streetTyp;
#endif

    int xPosition;
    int yPosition;
    QFile cityFile(pathToCityFile);
    QFile streetFile(pathToStreetFile);

    // Both files must be available before the map can be built.
    if (!cityFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open city file: " << pathToCityFile;
        return;
    }

    if (!streetFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open street file: " << pathToStreetFile;
        return;
    }

    QTextStream input(&cityFile);

    // Read all city definitions and create matching city objects.
    while (!input.atEnd())
    {
        input >> name;
        input >> xPositionString;
        input >> yPositionString;

#ifdef CITY_EXTENSION
        input >> cityTyp;
#endif

        xPosition = xPositionString.toInt();
        yPosition = yPositionString.toInt();

        City *city;

#ifdef CITY_EXTENSION
        if (cityTyp.compare("BigTown") == 0)
        {
            city = new BigTown(name, xPosition, yPosition);
        }
        else
        {
            city = new SmallTown(name, xPosition, yPosition);
        }
#else
        city = new City(name, xPosition, yPosition);
#endif

        // Insert the city into the target map before processing the next line.
        map.addCity(city);
        input.readLine();
    }

    QTextStream inputStreet(&streetFile);

    // Read all street definitions and connect the corresponding cities.
    while (!inputStreet.atEnd())
    {
        inputStreet >> firstCityName;
        inputStreet >> secondCityName;
#ifdef STREET_EXTENSION
        inputStreet >> streetTyp;
#endif

        City* city1 = map.findCity(firstCityName);
        City* city2 = map.findCity(secondCityName);

        // Keep debug output if one of the endpoint cities cannot be resolved.
        if (!city1)
        {
            qDebug() << "Failed to create Street. First city not found Data: " << line;
        }
        if (!city2)
        {
            qDebug() << "Failed to create Street. Second city not found Data: " << line;
        }

        Street *street;

#ifdef STREET_EXTENSION
        if (streetTyp.compare("Motorway") == 0)
        {
            street = new Motorway(city1, city2);
        }
        else
        {
            street = new Stateroad(city1, city2);
        }
#else
        street = new Street(city1, city2);
#endif

        // Let the map decide whether the street is valid and can be inserted.
        bool success = map.addStreet(street);
        if (success == false)
        {
            qDebug() << "Failed to create Street. Data: " << line;
        }
        inputStreet.readLine();
    }

    streetFile.close();
    cityFile.close();
}
