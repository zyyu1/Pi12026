///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIOFILEINPUT_H
#define MAPIOFILEINPUT_H

#include "mapio.h"

/**
 * @brief Reads map data from two text files.
 *
 * One file contains city data, the other contains street connections.
 */
class MapIoFileinput : public MapIo
{
public:
    /**
     * @brief Creates a file-based map reader.
     * @param pathToCityFile Path to the city input file.
     * @param pathToStreetFile Path to the street input file.
     */
    MapIoFileinput(QString pathToCityFile, QString pathToStreetFile);

    /**
     * @brief Destroys the file input object.
     */
    ~MapIoFileinput();

    /**
     * @brief Fills a map from the configured input files.
     * @param map Map object that receives the parsed data.
     */
    void fillMap(AbstractMap &map) override;

protected:
    ///< File path of the city data file.
    QString pathToCityFile;
    ///< File path of the street data file.
    QString pathToStreetFile;
};

#endif // MAPIOFILEINPUT_H
