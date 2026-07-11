/*!
 * Praktikum Informatik 1
 *
 * @file Magazin.cpp
 */

#include "Magazin.h"

#include <iostream>

/*!
 * @brief Konstruktor der Klasse Magazin
 *
 * \param initTitel Titel des Magazins
 * \param initAusgabe Erscheinungsdatum der Ausgabe
 * \param initSparte Sparte des Magazins
 */
Magazin::Magazin(std::string initTitel, Datum initAusgabe, std::string initSparte)
: Medium(initTitel)
, datumAusgabe(initAusgabe)
, sparte(initSparte)
{
}

/*!
 * @brief Gibt alle Informationen des Magazins aus
 *
 * \param out Ausgabestream
 */
void Magazin::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Ausgabe: " << datumAusgabe << std::endl;
    out << "Sparte: " << sparte << std::endl;
}

/*!
 * @brief Leiht das Magazin aus, wenn es sich nicht um die neueste Ausgabe handelt
 *
 * \param person Person, die das Magazin ausleihen moechte
 * \param ausleihdatum Datum, an dem das Magazin ausgeliehen werden soll
 *
 * \return true, wenn das Magazin ausgeliehen werden konnte
 * \return false, wenn die aktuelle Ausgabe nicht verliehen werden darf
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
