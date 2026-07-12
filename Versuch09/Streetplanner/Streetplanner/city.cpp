#include "city.h"

#include <QBrush>
#include <QGraphicsTextItem>

/**
 * @brief Constructs a city with name and coordinates.
 */
City::City(QString name, int x, int y)
    : name(name), x(x), y(y)
{
}

/**
 * @brief Draws the city marker and its label into the scene.
 */
void City::draw(QGraphicsScene &scene) const
{
    scene.addEllipse(x - 5, y - 5, 10, 10, QPen(), QBrush(Qt::black));
    scene.addText(name)->setPos(x + 6, y - 10);
}

/**
 * @brief Returns the display name of the city.
 */
QString City::getName() const
{
    return name;
}

/**
 * @brief Returns the x coordinate of the city.
 */
int City::getX() const
{
    return x;
}

/**
 * @brief Returns the y coordinate of the city.
 */
int City::getY() const
{
    return y;
}
