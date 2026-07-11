/*!
 * Praktikum Informatik 1
 *
 * @file Medium.h
 */

#ifndef MEDIUM_H_
#define MEDIUM_H_

#include "Datum.h"
#include "Person.h"

#include <iostream>

/*! \brief Basisklasse fuer saemtliche Medien
 *
 * Diese Klasse stellt eine Basisklasse fuer Objekte dar, die Medien beschreiben.
 * Von dieser Klasse werden alle anderen Medien, wie z.B. Buch oder DVD, abgeleitet.
 */
class Medium
{
public:
    /*!
     * @brief Konstruktor
     *
     * \param initTitel Titel des Mediums
     */
    Medium(std::string initTitel);

    /*!
     * @brief Virtueller Destruktor
     */
    virtual ~Medium(void);

    /*!
     * @brief Virtuelle Ausgabefunktion
     *
     * \param out Ausgabestream
     */
    virtual void ausgabe(std::ostream& out) const = 0; //所有媒体的输出写到输出流out中

    /*!
     * @brief Virtuelle Ausleihen-Funktion
     *
     * \param person Person, die das Medium ausleihen moechte
     * \param ausleihdatum Datum, an dem das Medium ausgeliehen wird
     *
     * \return true, wenn das Medium ausgeliehen werden konnte
     * \return false, wenn das Medium bereits verliehen ist
     */
    virtual bool ausleihen(Person person, Datum ausleihdatum);

    /*!
     * @brief Gibt ein Medium in die Buecherei zurueck
     */
    virtual void zurueckgeben();

    /*!
     * @brief Zugriff auf die ID
     *
     * \return Eindeutige ID des Mediums
     */
    unsigned int getID();

    /*!
     * @brief Zugriff auf den Ausleihstatus
     *
     * \return true, wenn das Medium ausgeliehen ist
     * \return false, wenn das Medium verfuegbar ist
     */
    bool getStatus() const;

protected:
    /*!
     * @brief Statische Variable fuer fortlaufende IDs
     */
    static unsigned int currentID;

    /*!
     * @brief Eindeutige ID des Mediums
     */
    unsigned int ID;

    /*!
     * @brief Titel des Mediums
     */
    std::string titel;

    /*!
     * @brief Ausleihstatus des Mediums
     */
    bool status;

    /*!
     * @brief Datum der Ausleihe
     */
    Datum datumAusgeliehen;

    /*!
     * @brief Person, die das Medium ausgeliehen hat
     */
    Person personAusgeliehen;
};

/*!
 * @brief Ausgabeoperator fuer Medien
 *
 * \param os Ausgabestream
 * \param medium Medium, das ausgegeben werden soll
 *
 * \return Referenz auf den beschriebenen Stream
 */
std::ostream& operator<<(std::ostream& os, const Medium& medium);

#endif
