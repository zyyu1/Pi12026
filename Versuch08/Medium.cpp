/*!
 * Praktikum Informatik 1
 *
 * @file Medium.cpp
 */

#include "Medium.h"

#include <iostream>
#include <string>

unsigned int Medium::currentID = 1;

/*!
 * @brief Konstruktor der Klasse Medium
 *
 * \param initTitel Titel des Mediums
 */
Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

/*!
 * @brief Virtueller Destruktor der Klasse Medium
 */
Medium::~Medium(void)
{
}

/*!
 * @brief Gibt alle Informationen des Mediums aus
 *
 * \param out Ausgabestream
 */
void Medium::ausgabe(std::ostream& out) const
{
    out << "ID: " << ID << std::endl;
    out << "Titel: " << titel << std::endl;

    if (status)
    {
        out << "Status : Das Medium ist seit dem " << datumAusgeliehen
                  << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
        out << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

/*!
 * @brief Leiht ein Medium aus, wenn es noch verfuegbar ist
 *
 * \param person Person, die das Medium ausleihen moechte
 * \param ausleihdatum Datum, an dem das Medium ausgeliehen wird
 *
 * \return true, wenn das Medium erfolgreich ausgeliehen wurde
 * \return false, wenn das Medium bereits verliehen ist
 */
bool Medium::ausleihen(Person person, Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }

    status = true;
    personAusgeliehen = person;
    datumAusgeliehen = ausleihdatum;
    std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
    return true;
}

/*!
 * @brief Gibt ein ausgeliehenes Medium zurueck
 */
void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zurueckgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

/*!
 * @brief Liefert die eindeutige ID des Mediums
 *
 * \return ID des Mediums
 */
unsigned int Medium::getID()
{
    return ID;
}

/*!
 * @brief Ueberladener Ausgabeoperator fuer Medium
 *
 * \param os Ausgabestream
 * \param medium Medium, das ausgegeben werden soll
 *
 * \return Referenz auf den Ausgabestream
 */
std::ostream& operator<<(std::ostream& os, const Medium& medium)
{
    medium.ausgabe(os);
    return os;
}

/*!
 * @brief Liefert den Ausleihstatus des Mediums
 *
 * \return true, wenn das Medium ausgeliehen ist
 * \return false, wenn das Medium verfuegbar ist
 */
bool Medium::getStatus() const
{
    return status;
}
