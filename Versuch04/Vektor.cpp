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

//类 Vektor 规定每个对象都有x,y,z,那么对象就是这一组具体值,like v1 = (1, 2, 3); v2 = (4, 5, 6)

/*
 * Die Klassenschnittstelle ist in Vektor.h dokumentiert.
 */
//建立Konstruktor构造函数，初始化成员变量.前面的vektor表示类, 后面的vektor是函数名
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ){       //初始化列表，inx直接赋值给成员变量x,使其初始化
}

// Destruktor,当一个对象被销毁时，析构函数会被自动调用,清理对象,接触内存
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
Vektor Vektor::sub(const Vektor& input) const                         //&表示传递一个Referanz引用，避免复制整个对象，提高效率
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
    // 在零向量的情况下，夹角没有定义，直接返回0度
    if (betrag1 == 0.0 || betrag2 == 0.0)
    {
        return 0.0;
    }

    // Berechnung des Kosinus des Winkels mit der Formel: cos(alpha) = (a * b) / (|a| * |b|)
     //使用公式计算夹角的余弦值：cos(alpha) = (a * b) / (|a| * |b|)
    double cosAlpha = skalarprodukt / (betrag1 * betrag2);

    // Rundungsfehler duerfen den Wertebereich von acos nicht verletzen.
    //由于浮点数计算的精度问题，cosAlpha可能会略微超出[-1, 1]的范围，这会导致acos函数出错，因此需要进行边界检查
    if (cosAlpha > 1.0)
    {
        cosAlpha = 1.0;
    }
    else if (cosAlpha < -1.0)
    {
        cosAlpha = -1.0;
    }

    // Umrechnung von Radiant in Grad.
     //将弧度转换为角度，使用公式：角度 = 弧度 * (180 / π)
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
    z = z; // z-Komponente bleibt unverändert
}
