//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 04: Einfuehrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/** @mainpage
 *
 * Praktikum Informatik 1 MMXXVI <BR>
 * Versuch 4: Einfuehrung in Klassen
 * <BR>
 * Klasse Vektor und Horizontberechnung
 *
 */

/**
 * @file main.cpp
 * @brief Hauptprogramm zur Berechnung der Horizontentfernung.
 */

#include "Vektor.h"
#include <iomanip>
#include <iostream>

/**
 * @brief Berechnet iterativ die Horizontentfernung fuer einen Aussichtspunkt.
 *
 * @return 0 bei erfolgreicher Programmausfuehrung
 */
int main()
{
    // Bei Bedarf kann dieser Block auf true gesetzt werden, um die
    // einzelnen Memberfunktionen der Klasse Vektor separat zu testen.
    
    //单独测试各个Verctor成员函数的代码块，设置为true时执行测试, 默认为false
    const bool TEST_VEKTOR = false;

    if (TEST_VEKTOR)
    {
        Vektor a(1.0, 2.0, 3.0);
        Vektor b(4.0, 5.0, 6.0);

        std::cout << "Testvektor a:" << std::endl;
        a.ausgabe();

        std::cout << "Testvektor b:" << std::endl;
        b.ausgabe();

        std::cout << "Laenge von a: " << a.laenge() << std::endl;
        std::cout << "Skalarprodukt a * b: " << a.skalarProd(b) << std::endl;
        std::cout << "Winkel zwischen a und b: " << a.winkel(b) << " Grad" << std::endl;

        Vektor differenz = a.sub(b);
        std::cout << "Differenz a - b:" << std::endl;
        differenz.ausgabe();

        a.rotiereUmZ(3.14159265358979323846 / 2.0);
        std::cout << "a nach Rotation um die z-Achse:" << std::endl;
        a.ausgabe();
    }

    const double height = 1.7;
    const double platformHeight = 555.7;
    const double radius = 6371000.0;
    const double gesamtHoehe = platformHeight + height;

    Vektor erdRadius(0, radius, 0);
    Vektor aussichtsPunkt(0, gesamtHoehe + radius, 0);
    Vektor sicht = aussichtsPunkt.sub(erdRadius);

    const double alpha = -0.00000001;
    int schritte = 0;

    while (erdRadius.skalarProd(sicht) > 0)
    {
        erdRadius.rotiereUmZ(alpha);
        sicht = aussichtsPunkt.sub(erdRadius);
        schritte++;
    }

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Sie koennen " << sicht.laenge() / 1000.0 << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << gesamtHoehe << " Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << erdRadius.winkel(aussichtsPunkt) << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << schritte << std::endl;

    return 0;
}
