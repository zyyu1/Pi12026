//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

int main()
{
    
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    vector1.ausgabe();
    vector2.ausgabe();

    Vektor erdRadius(0, 0, 0);      // bitte sinnvoll initialisieren
    Vektor aussichtsPunkt(0, 0, 0); // bitte sinnvoll initialisieren
    Vektor sicht(0, 0, 0);

    return 0;

}
