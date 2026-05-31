//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 2.1
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

// Dieses Programm berechnet Fibonacci-Zahlen rekursiv
// und gibt die Werte von f(0) bis f(25) aus.

/**
 * @file Fibonacci.cpp
 * @brief Berechnet Fibonacci-Zahlen rekursiv und gibt eine Wertetabelle aus.
 */

#include <iostream> // Fuer die Ausgabe mit std::cout

// Beispiel fuer die Fibonacci-Folge: 0, 1, 1, 2, 3, 5, 8, 13, ...
// Rekursive Berechnung der n-ten Fibonacci-Zahl
//写出Fibonacci-Zahlen的递归形公式 f(n) = f(n−1) + f(n−2)
//// 递归：一个函数在自己的定义中调用自己。

// Funktion zur rekursiven Berechnung einer Fibonacci-Zahl
// 递归计算第 n 个 Fibonacci 数
/**
 * @brief Berechnet die n-te Fibonacci-Zahl rekursiv.
 *
 * @param n Index der gesuchten Fibonacci-Zahl
 * @return Wert der n-ten Fibonacci-Zahl
 */
int fibonacci(int n)
{
    // Abbruchbedingung: Die 0. Fibonacci-Zahl ist 0
    // 递归结束条件 1：f(0) = 0
    if (n == 0)
    {
        return 0;
    }

    // Abbruchbedingung: Die 1. Fibonacci-Zahl ist 1
    // 递归结束条件 2：f(1) = 1
    if (n == 1)
    {
        return 1;
    }

    // Rekursiver Fall: Die Zahl ergibt sich aus der Summe
    // der beiden vorherigen Fibonacci-Zahlen
    // 其他情况可满足递归公式：f(n) = f(n-1) + f(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hauptfunktion des Programms
/**
 * @brief Gibt die Fibonacci-Zahlen von f(0) bis f(25) aus.
 *
 * @return 0 bei erfolgreicher Programmausfuehrung
 */
int main()
{
    // Ausgabe der Fibonacci-Zahlen von f(0) bis f(25)
    //用for循环依次输出 n = 0 到 25 的 Fibonacci 值
    for (int i = 0; i <= 25; i++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl;
    }

    return 0;
}
