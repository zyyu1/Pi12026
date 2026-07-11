/*!
 * Praktikum Informatik 1
 *
 * @file DVD.cpp
 */

#include "DVD.h"

#include <iostream>

/*!
 * @brief Konstruktor der Klasse DVD
 *
 * \param initTitel Titel der DVD
 * \param initAltersfreigabe Altersfreigabe der DVD
 * \param initGenre Genre der DVD
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
: Medium(initTitel)
, altersfreigabe(initAltersfreigabe)
, genre(initGenre)
{
}

/*!
 * @brief Gibt alle Informationen der DVD aus
 *
 * \param out Ausgabestream
 */
void DVD::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
    out << "Genre: " << genre << std::endl;
}

/*!
 * @brief Leiht die DVD aus, wenn die Altersfreigabe erfuellt ist
 *
 * \param person Person, die die DVD ausleihen moechte
 * \param ausleihdatum Datum, an dem die DVD ausgeliehen werden soll
 *
 * \return true, wenn die DVD ausgeliehen werden konnte
 * \return false, wenn die Person nicht alt genug ist
 */
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    int alter = ausleihdatum - person.getGeburtsdatum();
    alter = alter / 12;

    if (alter < altersfreigabe)
    {
        std::cout << "Die Person ist nicht alt genug fuer diese DVD." << std::endl;
        return false;
    }

    return Medium::ausleihen(person, ausleihdatum);
}
