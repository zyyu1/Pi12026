///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "abstractmap.h"

/**
 * @brief Utility class that provides shortest-path search using Dijkstra's algorithm.
 */
class Dijkstra
{
public:
    /**
     * @brief Finds the shortest path between two cities.
     * @param map Map on which the search is performed.
     * @param start Name of the start city.
     * @param target Name of the target city.
     * @return List of streets forming the shortest path. Empty if no connection was found.
     */
    static QVector<Street*> search(const AbstractMap &map, QString start, QString target);

private:
    /**
     * @brief Hidden constructor for utility class semantics.
     */
    Dijkstra();
};

#endif // DIJKSTRA_H
