///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIONRW_H
#define MAPIONRW_H

#include "mapio.h"

/**
 * @brief Provides a predefined hardcoded NRW example map.
 */
class MapIoNrw : public MapIo
{
public:
    /**
     * @brief Creates the NRW map provider.
     */
    MapIoNrw();

    /**
     * @brief Destroys the NRW map provider.
     */
    virtual ~MapIoNrw();

    /**
     * @brief Fills a map with the predefined NRW example data.
     * @param map Map object that receives the example data.
     */
    void fillMap(AbstractMap &map) override;
};

#endif // MAPIONRW_H
