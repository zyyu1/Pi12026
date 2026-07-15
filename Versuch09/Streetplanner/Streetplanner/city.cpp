#include "city.h"

#include <QBrush>
#include <QGraphicsTextItem>

/**
 * @brief Constructs a city with name and coordinates.
 */
//这里我们定义了一个新class
City::City(QString name, int x, int y)
    : name(name), x(x), y(y)
{
}

/**
 * @brief Draws the city marker and its label into the scene.
 */
void City::draw(QGraphicsScene &scene) const
{
    //在 scene 上画一个黑色小圆 (左上角坐标,宽,高,默认边框笔,用黑色填充)
    scene.addEllipse(x - 5, y - 5, 10, 10, QPen(), QBrush(Qt::black));
    //在图上写城市名字(把城市名作为文本加到场景里,文字显示的位置)
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
