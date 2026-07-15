/*!
 * Praktikum Informatik 1
 *
 * @file Person.cpp
 */
 
#include "Person.h"

// Constructor
Person::Person(std::string initName, Datum initGeburtsdatum)
: name(initName)
, geburtsdatum(initGeburtsdatum)
{
}

// Destructor
Person::~Person()
{
}

// Returns the date of birth
Datum Person::getGeburtsdatum() const
{
    return geburtsdatum;
}

// Returns the name
std::string Person::getName() const
{
    return name;
}
