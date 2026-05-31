#ifndef Vektor_H
#define Vektor_H

/**
 * \file Vektor.h
 * \brief Deklaration der Klasse Vektor.
 */

#include <cmath>
#include <iomanip>
#include <iostream>

/**
 * \brief Repräsentiert einen dreidimensionalen Vektor.
 */
class Vektor
{
public:
    /**
     * \brief Erstellt einen Vektor mit den angegebenen Komponenten.
     *
     * \param x X-Komponente des Vektors
     * \param y Y-Komponente des Vektors
     * \param z Z-Komponente des Vektors
     */
    Vektor(double x, double y, double z);

    /**
     * \brief Zerstoert den Vektor.
     */
    ~Vektor();

    /**
     * \brief Gibt die Komponenten des Vektors auf der Konsole aus.
     */
    void ausgabe() const;

    /**
     * \brief Berechnet die Differenz zwischen diesem Vektor und einem anderen Vektor.
     *
     * \param input Der zu subtrahierende Vektor
     * \return Der berechnete Differenzvektor
     */
    Vektor sub(const Vektor& input) const;

    /**
     * \brief Berechnet die Länge des Vektors.
     *
     * \return Länge des Vektors
     */
    double laenge() const;

    /**
     * \brief Berechnet das Skalarprodukt mit einem anderen Vektor.
     *
     * \param input Der zweite Vektor
     * \return Das Skalarprodukt beider Vektoren
     */
    double skalarProd(const Vektor& input) const;

    /**
     * \brief Berechnet den Winkel zwischen zwei Vektoren in Grad.
     *
     * \param input Der zweite Vektor
     * \return Winkel zwischen den Vektoren in Grad
     */
    double winkel(const Vektor& input) const;

    /**
     * \brief Rotiert den Vektor um die z-Achse.
     *
     * \param rad Rotationswinkel im Bogenmaß
     */
    void rotiereUmZ(double rad);

private:
    /** X-Komponente des Vektors. */
    double x;
    /** Y-Komponente des Vektors. */
    double y;
    /** Z-Komponente des Vektors. */
    double z;
};

#endif
