/*!
 * Praktikum Informatik 1
 *
 * @file Magazin.cpp
 */

#include "Magazin.h"

#include <iostream>

/*!
 * @brief Constructor of the Magazin class
 *
 * \param initTitel Title of the magazine
 * \param initAusgabe Issue date
 * \param initSparte Category of the magazine
 */
Magazin::Magazin(std::string initTitel, Datum initAusgabe, std::string initSparte)
: Medium(initTitel)
, datumAusgabe(initAusgabe)
, sparte(initSparte)
{
}

/*!
 * @brief Outputs all information about the magazine
 *
 * \param out Output stream
 */
void Magazin::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Ausgabe: " << datumAusgabe << std::endl;
    out << "Sparte: " << sparte << std::endl;
}

/*!
 * @brief Lends the magazine if it is not the latest issue
 *
 * \param person Person who wants to borrow the magazine
 * \param ausleihdatum Date of borrowing
 *
 * \return true if the magazine was borrowed successfully
 * \return false if the current issue may not be borrowed
 */
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    if ((ausleihdatum - datumAusgabe) < 1)
    {
        std::cout << "Die neueste Ausgabe eines Magazins darf nicht ausgeliehen werden." << std::endl;
        return false;
    }

    return Medium::ausleihen(person, ausleihdatum);
}
