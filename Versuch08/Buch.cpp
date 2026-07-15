/*!
 * Praktikum Informatik 1
 *
 * @file Buch.cpp
 */

#include "Buch.h"

#include <iostream>

/*!
 * @brief Constructor of the Buch class
 *
 * \param initTitel Title of the book
 * \param initAutor Author of the book
 */
Buch::Buch(std::string initTitel, std::string initAutor): Medium(initTitel), autor(initAutor)
{
}

/*!
 * @brief Outputs all information about the book
 *
 * \param out Output stream
 */
void Buch::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Autor: " << autor << std::endl;
}
