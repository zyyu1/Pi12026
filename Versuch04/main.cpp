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
        // Beispielvektoren fuer einen schnellen Funktionstest.
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

    // Hoehenangaben in Metern: Augenhoehe, Plattformhoehe und Erdradius.
    //初始化高度参数：眼睛高度、平台高度和地球半径
    const double height = 1.7;
    const double platformHeight = 555.7;
    const double radius = 6371000.0;
    const double gesamtHoehe = platformHeight + height;

    // Erdmittelpunkt im Ursprung, Beobachter senkrecht ueber dem Nordpol.
    //初始定义, 地球中心在原点，观察者垂直于北极上方
    Vektor erdRadius(0, radius, 0);
    Vektor aussichtsPunkt(0, gesamtHoehe + radius, 0);

    // Sichtlinie vom Beobachter zum Horizont, initial gleich der Differenz aus Aussichtspunkt und Erdradius
     //从观察者到地平线的视线，初始值为aussichtsPunkt和erdRadius的差
    Vektor sicht = aussichtsPunkt.sub(erdRadius);

    // Der Radiusvektor wird schrittweise gedreht, bis die Sichtlinie tangential wird.
    //逐步旋转半径向量，直到视线变为切线
    const double alpha = -0.00000001;   //顺时针 Uhrzeigersinn
    int schritte = 0;

    //只要erdRadius和sicht的点积大于0，继续旋转erdRadius并更新sicht，直到它们变为切线（点积为0）orthogonal
    while (erdRadius.skalarProd(sicht) > 0)
    {
        erdRadius.rotiereUmZ(alpha);
        sicht = aussichtsPunkt.sub(erdRadius);
        schritte++;
    }

    // Ausgabe der berechneten Sichtweite und des zugehoerigen Winkels.
    //输出计算得到的视距和相关角度
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Sie koennen " << sicht.laenge() / 1000.0 << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << gesamtHoehe << " Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << erdRadius.winkel(aussichtsPunkt) << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << schritte << std::endl;

    return 0;
}
