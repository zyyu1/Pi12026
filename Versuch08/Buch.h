/*!
 * Praktikum Informatik 1
 *
 * @file Buch.h
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

#include <string>

/*!
 * @brief Klasse Buch
 *
 * Die Klasse Buch ist eine abgeleitete Klasse von Medium.
 * Sie speichert zusaetzlich zum Titel den Autor des Buches.
 */
class Buch : public Medium
{
public:
    /*!
     * @brief Konstruktor der Klasse Buch
     *
     * \param initTitel Titel des Buches
     * \param initAutor Autor des Buches
     */
    Buch(std::string initTitel, std::string initAutor);

    /*!
     * @brief Virtuelle Ausgabefunktion
     *
     * \param out Ausgabestream
     */
    void ausgabe(std::ostream& out) const override;

private:
    /*!
     * @brief Autor des Buches
     */
    std::string autor;
};

#endif
