//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 2.1
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

//Fibonacci-Zahlen: 0, 1, 1, 2, 3, 5, 8, 13, . . .
//写出Fibonacci-Zahlen的递归形公式f(n) = f(n−1) + f(n−2)
//// 递归：一个函数在自己的定义中调用自己。

// 递归计算第 n 个 Fibonacci 数
int fibonacci(int n)
{
    // 递归结束条件 1：f(0) = 0
    if (n == 0)
    {
        return 0;
    }

    // 递归结束条件 2：f(1) = 1
    if (n == 1)
    {
        return 1;
    }

    // 其他情况可满足递归公式：f(n) = f(n-1) + f(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    //用for循环依次输出 n = 0 到 25 的 Fibonacci 值
    for (int i = 0; i <= 25; i++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl;
    }

    return 0;
}
