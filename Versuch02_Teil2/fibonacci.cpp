//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 2.2
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <chrono>//使用标准时间工具

//from Versuch2.1 递归形式
int fibonacciRekursiv(int n)
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
    return fibonacciRekursiv(n - 1) + fibonacciRekursiv(n - 2);
}


//定义 fibonacci迭代Iterativ函数，参数为整数 n，返回第 n 项
int fibonacci(int n)
{
    //int previousFib = 1; 初始化前两个变量,为0,1
    int previousFib = 0;
    int currentFib = 1;

    //首先处理边界

    //f(0) 返回 0
    if(n == 0)
    {
        return 0;
    }

    //f(1) 返回 1
    if(n == 1)
    {
        return 1;
    }

    //从第 2 项开始,计算到第 n 项

    //for (int i = 0; i <= n; i++) 从第二项开始循环
    for (int i = 2; i <= n; i++)
    {
        int newFib = previousFib + currentFib;
        //previousFib = newFib;
        //currentFib = previousFib;
        previousFib = currentFib;
        currentFib = newFib;
    }

    //返回第 n 项fibonacci Zahl
    return currentFib;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    //for (int i = 1; i <= 12 ; i ++) fibonacci序列从第0个开始
    for (int i = 0; i <= 12 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }


    //3.比较n=42,两个方式的运算速度,并给出原因
    int n = 42;

    //a.直接观察比较运行速度
    std::cout << std::endl;
    std::cout << "method a " << std::endl;
    std::cout << "Iterativ: f(" << n << ") = " << fibonacci(n) << std::endl ;
    std::cout << "Rekursiv: f(" << n << ") = " << fibonacciRekursiv(n) << std::endl ;

    //b.量化运行时间
    //Rekursiv
    auto startRekursiv = std::chrono::high_resolution_clock::now(); //保存开始时间节点, auto让程序自己判断数据类型
    int ergebnisRekursiv = fibonacciRekursiv(n); //调用递归函数, 计算f(n),并把结果保存到ergebnisRekursiv
    auto endRekursiv = std::chrono::high_resolution_clock::now(); //记录结束时间

    //Iterativ
    auto startIterativ = std::chrono::high_resolution_clock::now();
    int ergebnisIterativ = fibonacci(n);
    auto endIterativ = std::chrono::high_resolution_clock::now();

    //计算运行时间,转换成纳秒10^-9s
    auto dauerRekursiv =
        std::chrono::duration_cast<std::chrono::nanoseconds>(endRekursiv - startRekursiv);

    auto dauerIterativ =
        std::chrono::duration_cast<std::chrono::nanoseconds>(endIterativ - startIterativ);
    
    std::cout << std::endl;
    std::cout << "method b " << std::endl;
    std::cout << "Rekursiv: f(" << n << ") = " << ergebnisRekursiv << std::endl;
    std::cout << "Zeit rekursiv: " << dauerRekursiv.count() << " Nanosekunden" << std::endl;

    std::cout << "Iterativ: f(" << n << ") = " << ergebnisIterativ << std::endl;
    std::cout << "Zeit iterativ: " << dauerIterativ.count() << " Nanosekunden" << std::endl;

    //4. n = 47 Overflow
    //Iterativ: f(47) = -1323752223
    //Rekursiv: f(47) = -1323752223
  
    n = 47;
    std::cout << "Iterativ: f(" << n << ") = " << fibonacci(n) << std::endl ;
    std::cout << "Rekursiv: f(" << n << ") = " << fibonacciRekursiv(n) << std::endl ;

    return 0;
}

