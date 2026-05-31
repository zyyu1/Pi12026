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
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

Vektor::~Vektor()
{
}

void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

double Vektor::laenge() const
{
    const double laenge = std::sqrt((x * x) + (y * y) + (z * z));
    return laenge;
}

Vektor Vektor::sub(const Vektor& input) const
{
    const Vektor differenz(x - input.x, y - input.y, z - input.z);
    return differenz;
}

double Vektor::skalarProd(const Vektor& input) const
{
    const double a = x * input.x;
    const double b = y * input.y;
    const double c = z * input.z;
    const double skalarprodukt = a + b + c;

    return skalarprodukt;
}

double Vektor::winkel(const Vektor& input) const
{
    const double skalarprodukt = skalarProd(input);
    const double betrag1 = laenge();
    const double betrag2 = input.laenge();

    if (betrag1 == 0.0 || betrag2 == 0.0)
    {
        return 0.0;
    }

    double cosAlpha = skalarprodukt / (betrag1 * betrag2);

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

void Vektor::rotiereUmZ(const double rad)
{
    const double newX = x * std::cos(rad) - y * std::sin(rad);
    const double newY = x * std::sin(rad) + y * std::cos(rad);

    x = newX;
    y = newY;
}
