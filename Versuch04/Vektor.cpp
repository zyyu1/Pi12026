//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 04: Einfuehrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

/**
 * @file Vektor.cpp
 * @brief Implementierung der Klasse Vektor.
 */

#include "Vektor.h"

#ifndef M_PI
/** @brief Kreiszahl pi fuer Grad-Radiant-Umrechnungen. */
#define M_PI 3.14159265358979323846
#endif

/*
 * Die Klassenschnittstelle ist in Vektor.h dokumentiert.
 */
//建立构造函数，初始化成员变量
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

Vektor::~Vektor()
{
}

/**
 * @brief Gibt alle drei Komponenten formatiert auf der Konsole aus.
 */
//输出向量的三个分量，格式化显示
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Berechnet den Betrag des aktuellen Vektors.
 */
//计算向量的长度，使用欧几里得范数
double Vektor::laenge() const
{
    const double laenge = std::sqrt((x * x) + (y * y) + (z * z));
    return laenge;
}

/**
 * @brief Bildet die komponentenweise Differenz zweier Vektoren.
 */
//计算两个向量的差，返回一个新的向量
Vektor Vektor::sub(const Vektor& input) const
{
    const Vektor differenz(x - input.x, y - input.y, z - input.z);
    return differenz;
}

/**
 * @brief Berechnet das Skalarprodukt des aktuellen Vektors mit input.
 */
//计算两个向量的点积，返回一个标量值
double Vektor::skalarProd(const Vektor& input) const
{
    const double a = x * input.x;
    const double b = y * input.y;
    const double c = z * input.z;
    const double skalarprodukt = a + b + c;

    return skalarprodukt;
}

/**
 * @brief Bestimmt den Winkel zwischen zwei Vektoren in Grad.
 */
//计算两个向量之间的夹角，返回一个角度值
double Vektor::winkel(const Vektor& input) const
{
    const double skalarprodukt = skalarProd(input);
    const double betrag1 = laenge();
    const double betrag2 = input.laenge();

    // Fuer Nullvektoren ist der Winkel nicht sinnvoll definiert.
    if (betrag1 == 0.0 || betrag2 == 0.0)
    {
        return 0.0;
    }

    double cosAlpha = skalarprodukt / (betrag1 * betrag2);

    // Rundungsfehler duerfen den Wertebereich von acos nicht verletzen.
    if (cosAlpha > 1.0)
    {
        cosAlpha = 1.0;
    }
    else if (cosAlpha < -1.0)
    {
        cosAlpha = -1.0;
    }

    const double winkelRadiant = std::acos(cosAlpha);
    const double winkelGrad = winkelRadiant * 180.0 / M_PI;

    return winkelGrad;
}

/**
 * @brief Rotiert den Vektor in der x-y-Ebene um die z-Achse.
 */
//使用旋转矩阵绕z轴旋转向量，更新x和y分量
void Vektor::rotiereUmZ(const double rad)
{
    const double newX = x * std::cos(rad) - y * std::sin(rad);
    const double newY = x * std::sin(rad) + y * std::cos(rad);

    x = newX;
    y = newY;
}
