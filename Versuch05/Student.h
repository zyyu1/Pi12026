//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @brief Speichert die Stammdaten eines Studenten.
 */
class Student
{
public:
    /**
     * @brief Erstellt einen leeren Studenten.
     */
    Student();

    /**
     * @brief Erstellt einen Studenten mit vollstaendigen Stammdaten.
     *
     * @param matNr Matrikelnummer des Studenten
     * @param name Vollstaendiger Name des Studenten
     * @param geburtstag Geburtsdatum des Studenten
     * @param address Adresse des Studenten
     */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);

    /**
     * @brief Liefert die Matrikelnummer des Studenten.
     *
     * @return Matrikelnummer des Studenten
     */
    unsigned int getMatNr() const;

    /**
     * @brief Liefert den Namen des Studenten.
     *
     * @return Name des Studenten
     */
    std::string getName() const;

    /**
     * @brief Liefert das Geburtsdatum des Studenten.
     *
     * @return Geburtsdatum des Studenten
     */
    std::string getGeburtstag() const;

    /**
     * @brief Liefert die Adresse des Studenten.
     *
     * @return Adresse des Studenten
     */
    std::string getAdresse() const;

    /**
     * @brief Gibt alle gespeicherten Studentendaten auf der Konsole aus.
     */
    void ausgabe() const;

private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

#endif
