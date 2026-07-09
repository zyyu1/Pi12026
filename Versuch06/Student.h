//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @file Student.h
 * @brief Declaration of the Student class.
 */

/**
 * @brief Stores the master data of a student.
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
     * @brief Prints all stored student data to the console.
     */
    void ausgabe() const;

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

#endif
