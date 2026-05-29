//============================================================================
// Name        : Rekursion.cpp
// Author      : 
// Version     : 1.0
// Copyright   : 
// Description : Dies ist eine rekursive Implementierung, die ein Wort rueckwaerts ausgeben kann
//============================================================================


#include <iostream>
#include <string>


std::string wortRueckwaerts(std::string wort)
{
    // Abbruchbedingung fuer die Rekursion (das Wort besteht nur noch aus einem Buchstaben)
    if(wort.length() == 1)
    {
        return wort;
    }
    else
    {
        char ersterBuchstabe = wort.at(0);
        std::string restWort = wort.erase(0,1);
        // Rekursionsaufruf, das restWort soll nun rueckwaerts bestimmt werden
        return wortRueckwaerts(restWort) + ersterBuchstabe;
    }
}

int main()
{
    std::string wort = "BAUMSCHULE";
    std::string wortRueck = wortRueckwaerts(wort);

    std::cout << "Wort: " << wort << std::endl;
    std::cout << "Wort rueckwaerts: " << wortRueck << std::endl;

    return 0;
}
