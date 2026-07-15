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
 * @brief DVD class
 *
 * The DVD class is derived from Medium.
 * It stores the age rating and the genre in addition to the title.
 */
class DVD : public Medium
{
public:
    /*!
     * @brief Constructor of the DVD class
     *
     * \param initTitel Title of the DVD
     * \param initAltersfreigabe Age rating of the DVD
     * \param initGenre Genre of the DVD
     */
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

    /*!
     * @brief Virtual output function
     *
     * \param out Output stream
     */
    void ausgabe(std::ostream& out) const override;

    /*!
     * @brief Lends the DVD if the age restriction is met
     *
     * \param person Person who wants to borrow the DVD
     * \param ausleihdatum Date of borrowing
     *
     * \return true if the DVD was borrowed successfully
     * \return false if the person is not old enough
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    /*!
     * @brief Age rating of the DVD
     */
    int altersfreigabe;

    /*!
     * @brief Genre of the DVD
     */
    std::string genre;
};

#endif
