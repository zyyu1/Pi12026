//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
//一个 1.70 m 高的人站在 555.7 m 高的平台上，在半径 6371 km 的理想圆地球上能看多远
//用前面实现的 Vektor 类和旋转函数，通过迭代算法完成
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
