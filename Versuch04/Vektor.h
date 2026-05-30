#ifndef Vektor_H
#define Vektor_H

#include <cmath>
#include <iomanip>
#include <iostream>

class Vektor
{
public:
    Vektor(double x, double y, double z);
    ~Vektor();

    void ausgabe() const;
    Vektor sub(const Vektor& input) const;
    double laenge() const;
    double skalarProd(const Vektor& input) const;
    double winkel(const Vektor& input) const;
    void rotiereUmZ(double rad);

private:
    double x;
    double y;
    double z;
};

#endif
