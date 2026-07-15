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
 * @brief Constructor of the Medium class
 *
 * \param initTitel Title of the medium
 */
Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

/*!
 * @brief Virtual destructor of the Medium class
 */
Medium::~Medium(void)
{
}

/*!
 * @brief Outputs the general information of the medium
 *
 * \param out Output stream
 */
//保留实现,因此子类可以复用亲类的实现,并在子类中添加额外的输出信息
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
 * @brief Lends the medium if it is still available
 *
 * \param person Person who wants to borrow the medium
 * \param ausleihdatum Date of borrowing
 *
 * \return true if the medium was borrowed successfully
 * \return false if the medium is already lent out
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
 * @brief Returns a borrowed medium
 */
void Medium::zurueckgeben()
{
    //检查是否还在借出状态,如果是,则将状态改为未借出,并输出归还信息;如果不是,则输出提示信息
    if (status == true)
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
 * @brief Returns the unique ID of the medium
 *
 * \return ID of the medium
 */
unsigned int Medium::getID()
{
    return ID;
}

/*!
 * @brief Overloaded output operator for Medium
 *
 * \param os Output stream
 * \param medium Medium to be written
 *
 * \return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Medium& medium)
{
    medium.ausgabe(os);
    return os;
}

/*!
 * @brief Returns the lending status of the medium
 *
 * \return true if the medium is lent out
 * \return false if the medium is available
 */
bool Medium::getStatus() const
{
    return status;
}
