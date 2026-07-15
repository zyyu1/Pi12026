/*!
 * Praktikum Informatik 1 MMXXVI
 *
 * @file Datum.h
 */

#ifndef Datum_H_
#define Datum_H_

#include <string>
#include <iostream>

/*! \brief Class representing a date
 *
 * Stores a date consisting of day, month, and year.
 * The Datum class provides several functions and operators that can be used
 * to output, modify, and compare dates.
 */
class Datum
{
public:
    /*!
     * @brief Default constructor
     *
     * Initializes the object with the current date.
     */
    Datum();

    /*!
     * @brief Constructor for a specific date
     *
     * \param initTag Day value
     * \param initMonat Month value
     * \param initJahr Year value
     */
    Datum(int initTag, int initMonat, int initJahr);

    /*!
     * @brief Destructor
     */
    ~Datum(void);

    /*!
     * @brief Reads a date from an input stream
     *
     * \param in Input stream
     */
    void eingabe(std::istream& in);

    /*!
     * @brief Writes the date to an output stream
     *
     * \param out Output stream
     */
    void ausgabe(std::ostream& out) const;

    /*!
     * @brief Assignment operator
     *
     * \param d Right-hand side operand
     */
    Datum& operator=(Datum& d);

    /*!
     * @brief Subtraction operator
     *
     * \param d Right-hand side operand
     *
     * \return Difference between the two dates in full months
     */
    int operator-(const Datum d) const;

    /*!
     * @brief Addition operator
     *
     * \param anzahlTage Number of days to add
     *
     * \return Modified date
     */
    Datum operator+(const int anzahlTage) const;

private:
    int tag;
    int monat;
    int jahr;

    /*!
     * @brief Number of days in each month
     */
    static const int tageMonat[12];
};

/*!
 * @brief Overloaded output stream operator for Datum
 *
 * \param out Left-hand side output stream
 * \param d Right-hand side date object
 *
 * \return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& out, const Datum& d);

/*!
 * @brief Overloaded input stream operator for Datum
 *
 * \param in Left-hand side input stream
 * \param d Right-hand side date object
 *
 * \return Reference to the input stream
 */
std::istream& operator >> (std::istream& in, Datum& d);

#endif
