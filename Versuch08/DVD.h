/*!
 * Praktikum Informatik 1
 *
 * @file DVD.h
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

#include <string>

/*!
 * @brief Klasse DVD
 *
 * Die Klasse DVD ist eine abgeleitete Klasse von Medium.
 * Sie speichert zusaetzlich Altersfreigabe und Genre.
 */
class DVD : public Medium
{
public:
    /*!
     * @brief Konstruktor der Klasse DVD
     *
     * \param initTitel Titel der DVD
     * \param initAltersfreigabe Altersfreigabe der DVD
     * \param initGenre Genre der DVD
     */
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

    /*!
     * @brief Virtuelle Ausgabefunktion
     *
     * \param out Ausgabestream
     */
    void ausgabe(std::ostream& out) const override;

    /*!
     * @brief Leiht die DVD aus, wenn die Altersfreigabe erfuellt ist
     *
     * \param person Person, die die DVD ausleihen moechte
     * \param ausleihdatum Datum, an dem die DVD ausgeliehen werden soll
     *
     * \return true, wenn die DVD ausgeliehen werden konnte
     * \return false, wenn die Person nicht alt genug ist
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    /*!
     * @brief Altersfreigabe der DVD
     */
    int altersfreigabe;

    /*!
     * @brief Genre der DVD
     */
    std::string genre;
};

#endif
