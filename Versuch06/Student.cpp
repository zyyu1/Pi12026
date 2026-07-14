//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @file Student.cpp
 * @brief Implementation of the Student class.
 */

/*
 * The public interface is documented in Student.h.
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Creates a student with empty default values.
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Returns the matriculation number.
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Returns the name.
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Returns the date of birth.
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Returns the address.
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Prints all stored master data in one line.
 */
void Student::ausgabe() const
{
    std::cout << name << ", MatNr. " << matNr << ", geb. am " << geburtstag << ", wohnhaft in " << adresse << std::endl;
}
