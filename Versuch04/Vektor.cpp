//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
//将向量打印到console
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}


/**
 * \brief Berechnet die Länge des Vektors.
 *
 * \return Länge des Vektors.
 */
//计算向量长度 
double Vektor::laenge() const
{
    const double laenge = std::sqrt((x * x)+(y * y)+(z * z));
    return laenge;
}


/**
 * \brief Berechnet die Differenz zwischen diesem Vektor und einem anderen Vektor.
 *
 * \param input Der andere Vektor, von dem subtrahiert wird.
 * \return Ein neuer Vektor, der die Differenz darstellt.
 */
//向量相减,返回差向量
Vektor Vektor::sub(const Vektor& input) const
{
    //定义差向量，x1-x2, y1-y2, z1-z2
    const Vektor differenz (x - input.x, y - input.y, z - input.z);
    return differenz;
}


/**
 * \brief Berechnet das Skalarprodukt mit einem anderen Vektor.
 *
 * \param input Der andere Vektor.
 * \return Skalarprodukt der beiden Vektoren.
 */
//计算两个向量的点积x1x2+y1y2+z1z2
double Vektor::skalarProd(const Vektor& input) const
{
    //计算点积
    double a = x * input.x;
    double b = y * input.y; 
    double c = z * input.z;
    const double skalarprodukt = a + b + c;

    return skalarprodukt;
}


/**
 * \brief Berechnet den Winkel zwischen zwei Vektoren in Grad.
 *
 * \param input Der zweite Vektor.
 * \return Winkel zwischen den Vektoren in Grad.
 */
//计算两个向量的夹角,返回 Grad= Radiant*360/2pi
//winkel = :skalarProd / (|laenge1| * |laenge2|)
double Vektor::winkel(const Vektor& input) const
{
    //计算点积
    const double skalarprodukt = skalarProd(input);

    //计算两个vektor的绝对值(长度)
    const double betrag1 = laenge();
    const double betrag2 = input.laenge();

    //得到cos值
    const double cosAlpha = skalarprodukt / (betrag1 * betrag2);

    //反变换
    const double winkelRadiant = std::acos(cosAlpha);

    //Radiant -> Grad
    const double winkelGrad = winkelRadiant * 180.0 / M_PI;

    return winkelGrad;

}


/**
 * \brief Rotiert den Vektor um die z-Achse.
 *
 * \param rad Rotationswinkel im Bogenmaß.
 */
//绕z-Achse旋转的角度,rad 旋转角, 单位Radiant弧度
void Vektor::rotiereUmZ(const double rad)
{
    //旋转公式：x' = x*cos(rad) - y*sin(rad), y' = x*sin(rad) + y*cos(rad)
    const double newX = x * std::cos(rad) - y * std::sin(rad);
    const double newY = x * std::sin(rad) + y * std::cos(rad);

    //更新x和y的值
    x = newX;
    y = newY;
    z = z; // z坐标保持不变
}