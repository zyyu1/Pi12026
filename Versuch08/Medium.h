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

/*!
 * @brief Base class for all media
 *
 * The Medium class is the base class for objects that represent media items.
 * All other media types such as books, magazines, or DVDs are derived from it.
 */
class Medium
{
public:
    /*!
     * @brief Constructor
     *
     * \param initTitel Title of the medium
     */
    Medium(std::string initTitel);

    /*!
     * @brief Virtual destructor
     */
    virtual ~Medium(void);

    /*!
     * @brief Virtual output function
     *
     * \param out Output stream
     */
    virtual void ausgabe(std::ostream& out) const = 0;   //pure virtual function -> medium is an abstract class
                                                         //提供规则,不能实现,只说“每个媒体都必须能输出, 但具体怎么输出，由子类实现
    /*!
     * @brief Virtual lend function
     *
     * \param person Person who wants to borrow the medium
     * \param ausleihdatum Date of borrowing
     *
     * \return true if the medium was borrowed successfully
     * \return false if the medium is already lent out
     */
    virtual bool ausleihen(Person person, Datum ausleihdatum); //同样是虚函数,并保留实现,让子类可以服用或重写

    /*!
     * @brief Returns the medium to the library
     */
    virtual void zurueckgeben();

    /*!
     * @brief Returns the ID
     *
     * \return Unique medium ID
     */
    unsigned int getID();

    /*!
     * @brief Returns the lending status
     *
     * \return true if the medium is currently lent out
     * \return false if the medium is available
     */
    bool getStatus() const;

protected:
    /*!
     * @brief Static variable for generating consecutive IDs
     */
    static unsigned int currentID;

    /*!
     * @brief Unique ID of the medium
     */
    unsigned int ID;

    /*!
     * @brief Title of the medium
     */
    std::string titel;

    /*!
     * @brief Lending status of the medium
     */
    bool status;

    /*!
     * @brief Date when the medium was lent out
     */
    Datum datumAusgeliehen;

    /*!
     * @brief Person who borrowed the medium
     */
    Person personAusgeliehen;
};

/*!
 * @brief Output operator for media
 *
 * \param os Output stream
 * \param medium Medium to be written
 *
 * \return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Medium& medium);

#endif
