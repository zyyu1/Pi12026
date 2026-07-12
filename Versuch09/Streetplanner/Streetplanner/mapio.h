///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIO_H
#define MAPIO_H

#include "abstractmap.h"

/**
 * @brief Abstract base class for map data providers.
 *
 * Implementations fill an AbstractMap with cities and streets from a certain
 * source, for example hardcoded data or text files.
 */
class MapIo
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~MapIo();

    /**
     * @brief Adds cities and streets to the provided map.
     * @param map Map object that will be filled with data.
     */
    virtual void fillMap(AbstractMap &map) = 0;
};

#endif // MAPIO_H
