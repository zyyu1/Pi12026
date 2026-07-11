/*!
 * Praktikum Informatik 1
 *
 * @file Buch.cpp
 */

#include "Buch.h"

#include <iostream>

/*!
 * @brief Konstruktor der Klasse Buch
 *
 * \param initTitel Titel des Buches
 * \param initAutor Autor des Buches
 */
Buch::Buch(std::string initTitel, std::string initAutor)
: Medium(initTitel)
, autor(initAutor)
{
}

/*!
 * @brief Gibt alle Informationen des Buches aus
 *
 * \param out Ausgabestream
 */
void Buch::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Autor: " << autor << std::endl;
}
