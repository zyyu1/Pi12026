/*!
 * Praktikum Informatik 1 MMXXVI
 *
 * @file Datum.cpp
 */

#include "Datum.h"

#include <time.h>
#include <sstream>

// Initialization of the month-day array
const int Datum::tageMonat[12] = { 31,30,31,28,31,30,31,31,30,31,30,31 };

// Default constructor
Datum::Datum()
{
    // Read the current time
    time_t aktuelleZeit;
    time(&aktuelleZeit);

    // Create a pointer to the current date structure
    struct tm* aktuellesDatum = localtime(&aktuelleZeit);

    // Assign the values
    tag   = aktuellesDatum->tm_mday;
    monat = aktuellesDatum->tm_mon + 1;
    jahr  = aktuellesDatum->tm_year + 1900;
}

// Constructor
Datum::Datum(int initTag, int initMonat, int initJahr)
: tag(initTag)
, monat(initMonat)
, jahr(initJahr)
{
}

// Destructor
Datum::~Datum(void)
{
}

// Writes the date to an output stream
void Datum::ausgabe(std::ostream& out) const
{
    out << tag << ".";

    // Format output as 01 instead of 1
    if (monat < 10)
    {
        out << '0';
    }

    out << monat << "." << jahr;
}

// Reads a date from an input stream
void Datum::eingabe(std::istream& in)
{
    std::string DatumString;

    while (true)
    {
        in >> DatumString;
        try
        {
            // Reject input with invalid length
            if (DatumString.length() != 10)
            {
                throw (std::string("Falsches Format!"));
            }

            // Use a string stream to convert into integers
            std::istringstream stringstream;
            stringstream.str(DatumString);

            // Read the day
            stringstream >> tag;

            // A dot must follow the day
            if ((char)stringstream.get() != '.')
            {
                throw (std::string("Falsches Format!"));
            }

            // Read the month
            stringstream >> monat;

            // Validate the month
            if ((monat < 1) || (monat > 12))
            {
                throw (std::string("Ung黮tiger Monat!"));
            }

            // Validate the day within the selected month
            if ((tag > tageMonat[monat - 1]) || (tag < 1))
            {
                throw (std::string("Ung黮tiger tag!"));
            }

            // A dot must follow the month
            if ((char)stringstream.get() != '.')
            {
                throw (std::string("Falsches Format!"));
            }

            // Read the year
            stringstream >> jahr;

            if(jahr < 1000 || jahr > 2026 )
            {
                throw(std::string("Ung黮tiges Jahr!"));
            }

            // The date was read successfully
            return;
        }
        catch (std::string& fehler)
        {
            std::cout << fehler << std::endl;
            std::cout << "Bitte nochmal eingeben: ";
        }
    }
}

// Overloaded subtraction operator
int Datum::operator-(const Datum datum) const
{
    int tagDiff = tag - datum.tag;
    int monatDiff = monat - datum.monat;
    int jahrDiff = jahr - datum.jahr;

    // Round down the month difference
    if (tagDiff < 0)
    {
        monatDiff--;
    }

    // Calculate the difference in months
    return monatDiff + 12 * jahrDiff;
}

Datum Datum::operator+(const int anzahl_Tage) const
{
    int tagNeu = tag + anzahl_Tage;
    int monatNeu = monat;
    int jahrNeu = jahr;

    // Move forward across multiple months if necessary
    while (tagNeu > tageMonat[monatNeu-1])
    {
        // Increase the month and subtract its day count
        tagNeu -= tageMonat[monatNeu-1];
        monatNeu++;

        // The month must not become larger than 12
        if (monatNeu > 12)
        {
            monatNeu -= 12;
            jahrNeu++;
        }
    }
    return Datum(tagNeu, monatNeu, jahrNeu);
}

// Assignment operator
Datum& Datum::operator=(Datum& Datum)
{
    jahr = Datum.jahr;
    monat = Datum.monat;
    tag = Datum.tag;

    return *this;
}

// Stream operator for ostream
std::ostream& operator<<(std::ostream& out, const Datum& datum)
{
    datum.ausgabe(out);
    return out;
}

// Stream operator for istream
std::istream& operator >> (std::istream& in, Datum& datum)
{
    datum.eingabe(in);
    return in;
}
