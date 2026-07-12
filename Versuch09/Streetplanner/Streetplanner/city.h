#ifndef CITY_H
#define CITY_H

#include <QGraphicsScene>
#include <QString>

/**
 * @brief Represents a city on the map.
 *
 * A city has a name and a two-dimensional position used for drawing and
 * distance calculations.
 */
class City
{
public:
    /**
     * @brief Creates a new city.
     * @param name Display name of the city.
     * @param x X coordinate in the graphics scene.
     * @param y Y coordinate in the graphics scene.
     */
    City(QString name, int x, int y);

    /**
     * @brief Draws the city into a graphics scene.
     * @param scene Scene that receives the city marker and label.
     */
    void draw(QGraphicsScene &scene) const;

    /**
     * @brief Returns the city name.
     * @return Name of the city.
     */
    QString getName() const;

    /**
     * @brief Returns the x coordinate.
     * @return X position of the city.
     */
    int getX() const;

    /**
     * @brief Returns the y coordinate.
     * @return Y position of the city.
     */
    int getY() const;

private:
    ///< Display name of the city.
    QString name;
    ///< X position in the scene.
    int x;
    ///< Y position in the scene.
    int y;
};

#endif // CITY_H
