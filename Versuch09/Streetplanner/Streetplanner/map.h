#ifndef MAP_H
#define MAP_H

#include "abstractmap.h"
#include "city.h"
#include "street.h"

#include <QGraphicsScene>
#include <QStringList>
#include <QVector>

/**
 * @brief Concrete implementation of the AbstractMap interface.
 *
 * The map stores cities and streets, offers graph-related lookup functions,
 * and can draw its current contents.
 */
class Map : public AbstractMap  //map inherits from Abstracrmap
{
public:
    /**
     * @brief Creates an empty map.
     */
    Map();

    /**
     * @brief Adds a city to the map.
     * @param city City to add.
     */
    void addCity(City* city) override;

    /**
     * @brief Adds a street if both endpoint cities are already part of the map.
     * @param street Street to add.
     * @return true if the street was added, false otherwise.
     */
    bool addStreet(Street* street) override;

    /**
     * @brief Finds a city by name.
     * @param cityName Name to search for.
     * @return Matching city pointer or nullptr if not found.
     */
    City* findCity(const QString cityName) const override;

    /**
     * @brief Returns all streets connected to a city.
     * @param city City whose adjacent streets are requested.
     * @return Vector of connected streets.
     */
    QVector<Street*> getStreetList(const City* city) const override;

    /**
     * @brief Returns the opposite endpoint of a street.
     * @param street Street to inspect.
     * @param city One endpoint of the street.
     * @return The other endpoint, or nullptr if the city does not belong to the street.
     */
    City* getOppositeCity(const Street* street, const City* city) const override;

    /**
     * @brief Calculates the Euclidean length of a street.
     * @param street Street whose length is requested.
     * @return Length of the street.
     */
    double getLength(const Street* street) const override;

    /**
     * @brief Returns the names of all cities stored in the map.
     * @return List of city names.
     */
    QStringList getCityNameList() const;

    /**
     * @brief Draws all streets and cities into the given scene.
     * @param scene Target graphics scene.
     */
    void draw(QGraphicsScene& scene) const;

    /**
     * @brief Provides read-only access to all stored cities.
     * @return Constant reference to the internal city container.
     */
    const QVector<City*>& getCities() const;

    /**
     * @brief Provides read-only access to all stored streets.
     * @return Constant reference to the internal street container.
     */
    const QVector<Street*>& getStreets() const;

private:
    ///< All cities currently stored in the map.
    QVector<City*> cities;
    ///< All streets currently stored in the map.
    QVector<Street*> streets;
};

#endif // MAP_H
