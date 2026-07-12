#include "street.h"

#include <QPen>

/**
 * @brief Constructs a street between two cities.
 */
Street::Street(City* city1, City* city2)
    : city1(city1)
    , city2(city2)
{
}

/**
 * @brief Draws the street using the default line style.
 */
void Street::draw(QGraphicsScene& scene) const
{
    scene.addLine(city1->getX(),
                  city1->getY(),
                  city2->getX(),
                  city2->getY());
}

/**
 * @brief Draws the street highlighted in red.
 */
void Street::drawRed(QGraphicsScene& scene) const
{
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::red);

    scene.addLine(city1->getX(),
                  city1->getY(),
                  city2->getX(),
                  city2->getY(),
                  pen);
}

/**
 * @brief Returns the first endpoint of the street.
 */
City* Street::getCity1() const
{
    return city1;
}

/**
 * @brief Returns the second endpoint of the street.
 */
City* Street::getCity2() const
{
    return city2;
}
