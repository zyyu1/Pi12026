//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @file Student.cpp
 * @brief Implementierung der Klasse Student.
 */

/*
 * Die oeffentliche Schnittstelle ist in Student.h dokumentiert.
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Erstellt einen Studenten mit leeren Standardwerten.
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Liefert die Matrikelnummer.
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Liefert den Namen.
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Liefert das Geburtsdatum.
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Liefert die Adresse.
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle gespeicherten Stammdaten in einer Zeile aus.
 */
void Student::ausgabe() const
{
    std::cout << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl;
}
