/*!
 * Praktikum Informatik 1
 *
 * @file Magazin.h
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Datum.h"
#include "Medium.h"

#include <string>

/*!
 * @brief Klasse Magazin
 *
 * Die Klasse Magazin ist eine abgeleitete Klasse von Medium.
 * Sie speichert zusaetzlich das Erscheinungsdatum und die Sparte.
 */
class Magazin : public Medium
{
public:
    /*!
     * @brief Konstruktor der Klasse Magazin
     *
     * \param initTitel Titel des Magazins
     * \param initAusgabe Erscheinungsdatum der Ausgabe
     * \param initSparte Sparte des Magazins
     */
    Magazin(std::string initTitel, Datum initAusgabe, std::string initSparte);

    /*!
     * @brief Virtuelle Ausgabefunktion
     *
     * \param out Ausgabestream
     */
    void ausgabe(std::ostream& out) const override;

    /*!
     * @brief Leiht das Magazin aus, falls es nicht die neueste Ausgabe ist
     *
     * \param person Person, die das Magazin ausleihen moechte
     * \param ausleihdatum Datum, an dem das Magazin ausgeliehen werden soll
     *
     * \return true, wenn das Magazin ausgeliehen werden konnte
     * \return false, wenn die aktuelle Ausgabe nicht verliehen werden darf
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    /*!
     * @brief Erscheinungsdatum der Ausgabe
     */
    Datum datumAusgabe;

    /*!
     * @brief Sparte des Magazins
     */
    std::string sparte;
};

#endif
