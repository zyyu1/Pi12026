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
 * @brief Magazine class
 *
 * The Magazin class is derived from Medium.
 * It stores the issue date and the category in addition to the title.
 */
class Magazin : public Medium
{
public:
    /*!
     * @brief Constructor of the Magazin class
     *
     * \param initTitel Title of the magazine
     * \param initAusgabe Issue date
     * \param initSparte Category of the magazine
     */
    Magazin(std::string initTitel, Datum initAusgabe, std::string initSparte);

    /*!
     * @brief Virtual output function
     *
     * \param out Output stream
     */
    void ausgabe(std::ostream& out) const override;

    /*!
     * @brief Lends the magazine if it is not the newest issue
     *
     * \param person Person who wants to borrow the magazine
     * \param ausleihdatum Date of borrowing
     *
     * \return true if the magazine was borrowed successfully
     * \return false if the current issue may not be borrowed
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    /*!
     * @brief Issue date
     */
    Datum datumAusgabe;

    /*!
     * @brief Category of the magazine
     */
    std::string sparte;
};

#endif
