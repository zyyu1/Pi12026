//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 04: Einfuehrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

/**
 * \file Vektor.cpp
 * \brief Implementierung der Klasse Vektor.
 */

#include "Vektor.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * \brief Konstruktor der Klasse Vektor.
 *
 * \param inX x-Komponente des Vektors.
 * \param inY y-Komponente des Vektors.
 * \param inZ z-Komponente des Vektors.
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

/**
 * \brief Destruktor der Klasse Vektor.
 */
Vektor::~Vektor()
{
}

/**
 * @brief Function printing the components of the vector
 */
// 将向量的三个分量输出到控制台。
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * \brief Berechnet die Laenge des Vektors.
 *
 * \return Laenge des Vektors.
 */
// 计算向量长度。
double Vektor::laenge() const
{
    const double laenge = std::sqrt((x * x) + (y * y) + (z * z));
    return laenge;
}

/**
 * \brief Berechnet die Differenz zwischen diesem Vektor und einem anderen Vektor.
 *
 * \param input Der andere Vektor, von dem subtrahiert wird.
 * \return Ein neuer Vektor, der die Differenz darstellt.
 */
// 向量相减，返回差向量。
Vektor Vektor::sub(const Vektor& input) const
{
    const Vektor differenz(x - input.x, y - input.y, z - input.z);
    return differenz;
}

/**
 * \brief Berechnet das Skalarprodukt mit einem anderen Vektor.
 *
 * \param input Der andere Vektor.
 * \return Skalarprodukt der beiden Vektoren.
 */
// 计算两个向量的点积。
double Vektor::skalarProd(const Vektor& input) const
{
    const double a = x * input.x;
    const double b = y * input.y;
    const double c = z * input.z;
    const double skalarprodukt = a + b + c;

    return skalarprodukt;
}

/**
 * \brief Berechnet den Winkel zwischen zwei Vektoren in Grad.
 *
 * \param input Der zweite Vektor.
 * \return Winkel zwischen den Vektoren in Grad.
 */
// 根据点积公式计算夹角，并将弧度转换为角度。
double Vektor::winkel(const Vektor& input) const
{
    const double skalarprodukt = skalarProd(input);
    const double betrag1 = laenge();
    const double betrag2 = input.laenge();

    // 任一向量长度为 0 时，夹角没有实际意义，这里返回 0 防止除以 0。
    if (betrag1 == 0.0 || betrag2 == 0.0)
    {
        return 0.0;
    }

    double cosAlpha = skalarprodukt / (betrag1 * betrag2);

    // 浮点误差可能让 cosAlpha 略微超出 [-1, 1]，先限制到 acos 的合法范围。
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
 * \brief Rotiert den Vektor um die z-Achse.
 *
 * \param rad Rotationswinkel im Bogenmass.
 */
// 绕 z 轴旋转向量。
void Vektor::rotiereUmZ(const double rad)
{
    const double newX = x * std::cos(rad) - y * std::sin(rad);
    const double newY = x * std::sin(rad) + y * std::cos(rad);

    x = newX;
    y = newY;
    z = z; // z 坐标保持不变。
}
