#ifndef STREET_H
#define STREET_H

#include "city.h"

#include <QGraphicsScene>

/**
 * @brief Represents a street connecting two cities.
 */
class Street
{
public:
    /**
     * @brief Creates a street between two cities.
     * @param city1 First endpoint of the street.
     * @param city2 Second endpoint of the street.
     */
    Street(City* city1, City* city2);

    /**
     * @brief Draws the street with the default style.
     * @param scene Scene that receives the line item.
     */
    void draw(QGraphicsScene& scene) const;

    /**
     * @brief Draws the street highlighted in red.
     * @param scene Scene that receives the highlighted line item.
     */
    void drawRed(QGraphicsScene& scene) const;

    /**
     * @brief Returns the first city of the street.
     * @return Pointer to the first endpoint.
     */
    City* getCity1() const;

    /**
     * @brief Returns the second city of the street.
     * @return Pointer to the second endpoint.
     */
    City* getCity2() const;

private:
    ///< First endpoint of the street.
    City* city1;
    ///< Second endpoint of the street.
    City* city2;
};

#endif // STREET_H
