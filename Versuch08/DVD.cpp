/*!
 * Praktikum Informatik 1
 *
 * @file DVD.cpp
 */

#include "DVD.h"

#include <iostream>

/*!
 * @brief Constructor of the DVD class
 *
 * \param initTitel Title of the DVD
 * \param initAltersfreigabe Age rating of the DVD
 * \param initGenre Genre of the DVD
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
: Medium(initTitel)
, altersfreigabe(initAltersfreigabe)
, genre(initGenre)
{
}

/*!
 * @brief Outputs all information about the DVD
 *
 * \param out Output stream
 */
void DVD::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
    out << "Genre: " << genre << std::endl;
}

/*!
 * @brief Lends the DVD if the age restriction is met
 *
 * \param person Person who wants to borrow the DVD
 * \param ausleihdatum Date of borrowing
 *
 * \return true if the DVD was borrowed successfully
 * \return false if the person is not old enough
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
