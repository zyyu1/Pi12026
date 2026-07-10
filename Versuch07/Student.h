//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <ostream>
#include <string>

/**
 * @file Student.h
 * @brief Declaration of the Student class used in Versuch07.
 */

/**
 * @brief Stores the master data of a student.
 *
 * The class provides comparison operators based on the matriculation number
 * so that Student objects can be used with STL algorithms such as
 * std::sort() and std::find().
 */
class Student
{
public:
    /**
     * @brief Creates an empty student.
     */
    Student();

    /**
     * @brief Creates a student with complete master data.
     *
     * @param matNr Student matriculation number
     * @param name Full name of the student
     * @param geburtstag Student's date of birth
     * @param address Student's address
     */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);

    /**
     * @brief Returns the student's matriculation number.
     *
     * @return Student matriculation number
     */
    unsigned int getMatNr() const;

    /**
     * @brief Returns the student's name.
     *
     * @return Student name
     */
    std::string getName() const;

    /**
     * @brief Returns the student's date of birth.
     *
     * @return Student date of birth
     */
    std::string getGeburtstag() const;

    /**
     * @brief Returns the student's address.
     *
     * @return Student address
     */
    std::string getAdresse() const;

    /**
     * @brief Writes all stored student data to the specified output stream.
     *
     * @param out Output stream to print to
     */
    void ausgabe(std::ostream& out) const;

    /**
     * @brief Compares two students by their matriculation numbers.
     *
     * @param other Student to compare with
     * @return true if this student has a smaller matriculation number
     */
    bool operator<(const Student& other) const;

    /**
     * @brief Compares two students by their matriculation numbers.
     *
     * @param other Student to compare with
     * @return true if this student has a larger matriculation number
     */
    bool operator>(const Student& other) const;

    /**
     * @brief Compares two students by their matriculation numbers.
     *
     * @param other Student to compare with
     * @return true if both students have the same matriculation number
     */
    bool operator==(const Student& other) const;

private:
    /** Student matriculation number. */
    unsigned int matNr;

    /** Full name of the student. */
    std::string name;

    /** Date of birth of the student. */
    std::string geburtstag;

    /** Postal address of the student. */
    std::string adresse;
};

/**
 * @brief Writes a student's data to an output stream.
 *
 * This overload enables statements such as
 * `std::cout << student << std::endl;`.
 *
 * @param out Output stream to print to
 * @param student Student whose data is to be printed
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& out, const Student& student);

#endif
