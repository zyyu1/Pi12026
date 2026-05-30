//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////


/**
 * \file main.cpp
 * \brief Hauptprogramm zur Berechnung der Horizontentfernung.
 */
//一个 1.70 m 高的人站在 555.7 m 高的平台上，在半径 6371 km 的理想圆地球上能看多远
//用前面实现的 Vektor 类和旋转函数，通过迭代算法完成
//一开始视线是水平的
//然后让视线一点点向下转
//每转一点，就检查这条视线是不是已经碰到地球表面
//当它刚好碰到地球表面时，这个点就是地平线附近, 切点, skalarProd = 0
#include "Vektor.h"
#include <iostream>
#include <iomanip>

/**
 * \brief Berechnet iterativ die Horizontentfernung für einen Aussichtspunkt.
 *
 * \return 0 bei erfolgreicher Programmausführung.
 */
int main()
{
    
    //Vektor vector1(1, 0, 0);
    //Vektor vector2(0, 1, 0);

    //人高度
    const double height = 1.7;
    //平台高度
    const double platformHeight = 555.7;
    //地球半径
    const double radius = 6371000.0;
    //总高度
    const double gesamtHoehe = platformHeight + height;

    //vector1.ausgabe();
    //vector2.ausgabe();

    Vektor erdRadius(0, radius, 0);      // 地球中心在 (0,0,0), 当前脚下地表点在 y 轴正方向, 半径为 6371 km
    Vektor aussichtsPunkt(0, gesamtHoehe + radius, 0); // 眼睛所在的位置,555.7+1.7=557.4,距离地心的距离为 6371+0.5574 km,初始值为0,后续迭代更新
    Vektor sicht = aussichtsPunkt.sub(erdRadius); // Sichtvektor aktualisieren初始视线向量, 从从地表点指向眼睛,视线向量 - 地球半径向量

    //确定一个非常小的旋转角度, 用于逼近地平线
    const double alpha = -0.00000001; // 顺时针旋转角度
    int schritte = 0; // 初始化旋转步数计数器

    // 当视线与地球半径的点积大于 0 时, 说明视线还没有碰到地球表面
    while (erdRadius.skalarProd(sicht) > 0)
    {
        erdRadius.rotiereUmZ(alpha); // 沿 Z 轴旋转地球半径向量
        sicht = aussichtsPunkt.sub(erdRadius); // 更新视线向量为从眼睛位置指向新的地表点的向量
        schritte++; // 增加旋转步数计数器
    }   

    // 设置输出格式为固定小数点，并保留4位小数
    std::cout << std::fixed << std::setprecision(4);

    // 输出结果
    std::cout << "Sie können " << sicht.laenge() / 1000.0 << " Km weit sehen." << std::endl; // 输出可见距离，单位为 km
    std::cout << "Sie sind " << gesamtHoehe << " Meter hoch." << std::endl; // 输出人站立的高度
    std::cout << "Der Winkel beträgt " << erdRadius.winkel(aussichtsPunkt) << " Grad." << std::endl; // 输出地球半径向量与眼睛位置向量之间的夹角
    std::cout << "Anzahl Schritte: " << schritte << std::endl; // 输出旋转的步数   

    return 0;

}
