#include "map.h"

#include <cmath>

#include <QDebug>

/**
 * @brief Creates an empty map.
 */
Map::Map()
{
}

/**
 * @brief Adds a city pointer to the internal city list.
 */
void Map::addCity(City* city)
{
    // Reject invalid input early.
    if (city == nullptr)
    {
        qDebug() << "City is null";
        return;
    }

    // 防止同一城市重复添加
    if (findCity(city->getName()) != nullptr)
    {
        qDebug() << "City already exists:" << city->getName();
        delete city;
        return;
    }

    // Store the city pointer so it becomes part of the graph structure.
    cities.push_back(city);

    qDebug() << "City added to map:" << city->getName();
}

/**
 * @brief Adds a street if both endpoint cities are already stored in the map.
 */
bool Map::addStreet(Street* street)
{
    // Reject invalid input early.
    if (street == nullptr)
    {
        qDebug() << "Street is null";
        return false;
    }

    // Read the two endpoint cities of the street.
    City* city1 = street->getCity1();
    City* city2 = street->getCity2();

    //检查两个城市都在地图上
    if (!cities.contains(city1) || !cities.contains(city2))
    {
        qDebug() << "Street cannot be added because at least one city is not in the map";
        return false;
    }

    //如果已经存在同一对城市之间的街道，就拒绝重复添加
    for (Street* existingStreet : streets)
    {
        bool sameDirection =
            existingStreet->getCity1() == city1 && existingStreet->getCity2() == city2;
        bool oppositeDirection =
            existingStreet->getCity1() == city2 && existingStreet->getCity2() == city1;

        if (sameDirection || oppositeDirection)
        {
            qDebug() << "Street already exists between"
                     << city1->getName()
                     << "and"
                     << city2->getName();
            delete street;
            return false;
        }
    }

    streets.push_back(street);

    qDebug() << "Street added to map";
    return true;
}

/**
 * @brief Draws all streets first and then all cities.
 */
void Map::draw(QGraphicsScene& scene) const
{
    // Draw streets first so city markers and labels stay visible on top.
    for (Street* street : streets)
    {
        street->draw(scene);
    }

    for (City* city : cities)
    {
        city->draw(scene);
    }
}

/**
 * @brief Searches a city by its name.
 */
City* Map::findCity(const QString cityName) const
{
    // Perform a linear search over all stored cities.
    for (City* city : cities)
    {
        if (city->getName() == cityName)
        {
            qDebug() << "City found:" << cityName;
            return city;
        }
    }

    qDebug() << "City not found:" << cityName;
    return nullptr;
}

/**
 * @brief Collects all streets connected to a given city.
 */
QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> connectedStreets;

    // Collect every street whose first or second endpoint matches the given city.
    for (Street* street : streets)
    {
        if (street->getCity1() == city || street->getCity2() == city)
        {
            connectedStreets.push_back(street);
        }
    }

    qDebug() << "Number of connected streets:" << connectedStreets.size();

    return connectedStreets;
}

/**
 * @brief Returns the opposite endpoint of a street.
 */
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    // Invalid input cannot produce a meaningful opposite city.
    if (street == nullptr || city == nullptr)
    {
        qDebug() << "Street or city is null";
        return nullptr;
    }

    if (street->getCity1() == city)
    {
        return street->getCity2();
    }

    if (street->getCity2() == city)
    {
        return street->getCity1();
    }

    qDebug() << "The city is not connected to this street";
    return nullptr;
}

/**
 * @brief Computes the Euclidean length of a street.
 */
double Map::getLength(const Street* street) const
{
    // Invalid streets are treated as length zero.
    if (street == nullptr)
    {
        qDebug() << "Street is null";
        return 0.0;
    }

    City* city1 = street->getCity1();
    City* city2 = street->getCity2();

    // Compute the Euclidean distance between the two endpoint coordinates.
    int dx = city1->getX() - city2->getX();
    int dy = city1->getY() - city2->getY();

    double length = std::sqrt(dx * dx + dy * dy);

    qDebug() << "Street length:" << length;

    return length;
}

/**
 * @brief Builds a list containing the names of all stored cities.
 */
QStringList Map::getCityNameList() const
{
    QStringList cityNames;

    // Extract only the names so they can be shown in combo boxes and dialogs.
    for (City* city : cities)
    {
        cityNames.append(city->getName());
    }

    return cityNames;
}

/**
 * @brief Returns the internal city container for read-only export operations.
 */
const QVector<City*>& Map::getCities() const
{
    return cities;
}

/**
 * @brief Returns the internal street container for read-only export operations.
 */
const QVector<Street*>& Map::getStreets() const
{
    return streets;
}
