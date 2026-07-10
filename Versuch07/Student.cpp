//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "Student.h"

/**
 * @file Student.cpp
 * @brief Implementation of the Student class.
 */

Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
    matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{
}

/**
 * @brief Creates a student with empty default values.
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{
}

/**
 * @brief Returns the matriculation number.
 *
 * @return Student matriculation number
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Returns the name.
 *
 * @return Student name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Returns the date of birth.
 *
 * @return Student date of birth
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Returns the address.
 *
 * @return Student address
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Writes all stored student data to the specified output stream.
 *
 * @param out Output stream to print to
 */
void Student::ausgabe(std::ostream& out) const
{
    out << name << ", MatNr. " << matNr << ", geb. am "
        << geburtstag << ", wohnhaft in " << adresse;
}

/**
 * @brief Compares two students by their matriculation numbers.
 *
 * @param other Student to compare with
 * @return true if this student has a smaller matriculation number
 */
bool Student::operator<(const Student& other) const
{
    return matNr < other.matNr;
}

/**
 * @brief Compares two students by their matriculation numbers.
 *
 * @param other Student to compare with
 * @return true if this student has a larger matriculation number
 */
bool Student::operator>(const Student& other) const
{
    return matNr > other.matNr;
}

/**
 * @brief Compares two students by their matriculation numbers.
 *
 * @param other Student to compare with
 * @return true if both students have the same matriculation number
 */
bool Student::operator==(const Student& other) const
{
    return matNr == other.matNr;
}

/**
 * @brief Writes a Student object to an output stream.
 *
 * @param out Output stream to write to
 * @param student Student object to output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& out, const Student& student)
{
    student.ausgabe(out);
    return out;
}
