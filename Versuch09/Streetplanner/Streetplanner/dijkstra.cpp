///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "dijkstra.h"

#include <QDebug>

/**
 * @brief Helper structure used by the Dijkstra algorithm.
 *
 * It stores the current city, the distance from the start city,
 * and the street used to reach this city on the current best path.
 */
class Tuppel
{
public:
    ///< City represented by this entry.
    City* city;
    ///< Current known shortest distance from the start city.
    double distance;
    ///< Street used to reach the city on the shortest known path.
    Street* shortestWay;
};

/**
 * @brief Searches the shortest path between two cities using Dijkstra's algorithm.
 */
QVector<Street*> Dijkstra::search(const AbstractMap &map, QString start, QString target)
{
    // Resolve the start and target names to actual city objects.
    City* startPointer = map.findCity(start);
    City* targetPointer = map.findCity(target);
    if (startPointer == nullptr || targetPointer == nullptr)
    {
        qDebug() << "Dijkstra: Cities not found";
        QVector<Street*> l;
        return l;
    }

    QVector<Tuppel> green;
    QVector<Tuppel> yellow;

    // Start the algorithm with the start city at distance zero.
    Tuppel temp = {startPointer, 0, nullptr};
    yellow.push_back(temp);

    while (yellow.empty() == false)
    {
        // Select the yellow entry with the currently smallest distance.
        Tuppel edgeToProcessData;
        QVector<Tuppel>::iterator edgeToProcess = yellow.begin();
        for (QVector<Tuppel>::iterator it = yellow.begin(); it != yellow.end(); it++)
        {
            if ((*it).distance < (*edgeToProcess).distance)
            {
                edgeToProcess = it;
            }
        }
        edgeToProcessData = *edgeToProcess;
        green.push_back(*edgeToProcess);
        yellow.erase(edgeToProcess);

        // Build a list of direct successors reachable from the current city.
        QVector<Street*> streets = map.getStreetList(edgeToProcessData.city);
        QVector<Tuppel> successorList;
        for (QVector<Street*>::const_iterator it = streets.begin(); it != streets.end(); it++)
        {
            temp.city = map.getOppositeCity(*it, edgeToProcessData.city);
            temp.distance = map.getLength(*it);
            temp.shortestWay = *it;
            successorList.push_back(temp);
        }

        for (QVector<Tuppel>::const_iterator successor = successorList.begin(); successor != successorList.end(); successor++)
        {
            // Check whether this city was already seen before.
            bool found = false;
            for (QVector<Tuppel>::iterator it = green.begin(); it != green.end(); it++)
            {
                if ((*successor).city == (*it).city)
                {
                    found = true;
                    if (edgeToProcessData.distance + (*successor).distance < (*it).distance)
                    {
                        (*it).distance = edgeToProcessData.distance + (*successor).distance;
                        (*it).shortestWay = (*successor).shortestWay;
                    }
                }
            }
            for (QVector<Tuppel>::iterator it = yellow.begin(); it != yellow.end(); it++)
            {
                if ((*successor).city == (*it).city)
                {
                    found = true;
                    if (edgeToProcessData.distance + (*successor).distance < (*it).distance)
                    {
                        (*it).distance = edgeToProcessData.distance + (*successor).distance;
                        (*it).shortestWay = (*successor).shortestWay;
                    }
                }
            }

            if (found == false)
            {
                // A newly discovered city is added to the yellow frontier.
                temp.city = (*successor).city;
                temp.distance = edgeToProcessData.distance + (*successor).distance;
                temp.shortestWay = (*successor).shortestWay;
                yellow.push_back(temp);
            }
        }
    }

    QVector<Street*> shortestPath;
    City* currentEdge = nullptr;

    // Start backtracking from the target city to reconstruct the path.
    for (QVector<Tuppel>::const_iterator it = green.begin(); it != green.end(); it++)
    {
        if ((*it).city == targetPointer)
        {
            shortestPath.insert(shortestPath.begin(), (*it).shortestWay);
            currentEdge = map.getOppositeCity((*it).shortestWay, (*it).city);
        }
    }

    if (currentEdge == nullptr)
    {
        qDebug() << "Dijkstra: No Connection between the targets";
        QVector<Street*> l;
        return l;
    }

    while (currentEdge != startPointer)
    {
        // Walk backwards through the stored predecessor streets until the start is reached.
        for (QVector<Tuppel>::const_iterator it = green.begin(); it != green.end(); it++)
        {
            if ((*it).city == currentEdge)
            {
                shortestPath.insert(shortestPath.begin(), (*it).shortestWay);
                currentEdge = map.getOppositeCity((*it).shortestWay, (*it).city);
            }
        }
    }
    return shortestPath;
}
