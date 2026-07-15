/*!
 * Praktikum Informatik 1
 *
 * @file Person.h
 */

#ifndef Person_H_
#define Person_H_

#include "Datum.h"
#include <string>

/*!
 * @brief Class representing a person
 *
 * The Person class stores the information about a person that is relevant for
 * the library system:
 *  - name
 *  - date of birth
 */
class Person
{
public:
    /*!
     * @brief Constructor
     *
     * \param initName Name of the person, defaults to an empty string
     * \param initGeburtsdatum Date of birth, defaults to the current date
     */
    Person(std::string initName = "", Datum initGeburtsdatum = Datum());

    /*!
     * @brief Destructor
     */
    ~Person();

    /*!
     * @brief Returns the person's name
     *
     * \return Name of the person
     */
    std::string getName() const;

    /*!
     * @brief Returns the person's date of birth
     *
     * \return Date of birth
     */
    Datum getGeburtsdatum() const;

private:
    std::string name;
    Datum geburtsdatum;
};

#endif
