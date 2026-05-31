//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/*
 * Die oeffentliche Schnittstelle ist in Student.h dokumentiert.
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

unsigned int Student::getMatNr() const
{
    return matNr;
}

std::string Student::getName() const
{
    return name;
}

std::string Student::getGeburtstag() const
{
    return geburtstag;
}

std::string Student::getAdresse() const
{
    return adresse;
}

void Student::ausgabe() const
{
    std::cout << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl;
}
