/*!
 * Praktikum Informatik 1
 *
 * @file Buch.h
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

#include <string>

/*!
 * @brief Book class
 *
 * The Buch class is derived from Medium.
 * In addition to the title, it stores the author of the book.
 */
class Buch : public Medium
{
public:
    /*!
     * @brief Constructor of the Buch class
     *
     * \param initTitel Title of the book
     * \param initAutor Author of the book
     */
    Buch(std::string initTitel, std::string initAutor);

    /*!
     * @brief Virtual output function
     *
     * \param out Output stream
     */
    void ausgabe(std::ostream& out) const override;

private:
    /*!
     * @brief Author of the book
     */
    std::string autor;
};

#endif
