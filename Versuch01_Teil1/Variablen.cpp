//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
// Dieses Programm demonstriert grundlegende Datentypen,
// Ein- und Ausgabe, Typumwandlung, Strings und Arrays.

#include <iostream> // Fuer Ein- und Ausgabe mit std::cin und std::cout
#include <string>   // Fuer die Verwendung von std::string

// Hauptfunktion des Programms
int main()
{   
    // Einlesen von zwei ganzen Zahlen
    // Variablen fuer die Eingabewerte
    //1.计算整数和与整数除法结果并输出

    //定义操作整数
    int iErste = 0;
    int iZweite = 0;

    // Variablen fuer die Berechnungsergebnisse
    //定义输出整数
    int iSumme = 0;
    int iQuotient = 0;

    //std::cin 标准输入，读入数据
    //std::cout 标准输出，把内容显示到控制台

    //Benutzer nach zwei ganzen Zahlen fragen und diese einlesen
    //提示用户输入整数
    //读取已输入的整数并赋值
    std::cout << "Geben Sie bitte eine ganze Zahl ein: ";//把字符串送到 std::cout，然后std::cout 再把它显示到屏幕上
    std::cin >> iErste; //把用户输入的内容，从 std::cin 读出来，放进变量
    std::cout << "Geben Sie bitte eine zweite ganze Zahl(except 0) ein: "; 
    std::cin >> iZweite;
    std::cout << std::endl;
    
    // Berechnung von Summe und ganzzahligem Quotienten
    //定义运算
    iSumme = iErste + iZweite;
    iQuotient = iErste / iZweite;

    // Ausgabe der berechneten Ergebnisse
    //输出运算结果
    std::cout << "Die Summe ist: " << iSumme << std::endl; //换行，并且立刻刷新输出缓冲区, c "\n"
    std::cout << "Der Quotient ist: " << iQuotient << std::endl;//本质上，前一个 << 操作结束后，返回的还是 std::cout，所以后面还能继续接 <<
    std::cout << std::endl;


    // Die gleichen Berechnungen in Variablen vom Typ double speichern
    // Achtung: Die Division erfolgt hier trotzdem noch als Integer-Division
    //2.再计算一次和与商，但是把结果存到 double 类型变量里

    double dSumme = 0.0;
    double dQuotient = 0.0;

    dSumme = iErste + iZweite;
    dQuotient = iErste / iZweite;
    
    std::cout << "Die Summe als double ist: " << dSumme << std::endl;
    std::cout << "Der Quotient als double ist: " << dQuotient << std::endl;
    std::cout << std::endl;
    //因为 iErste 和 iZweite 都是 int，所以会先做整数除法，再把结果放进 double


    // Vor der Division werden die Operanden in double umgewandelt
    // Dadurch entsteht eine Gleitkommadivision
    //3.在除法之前，把操作数转成 double

    double dSummeCast = 0.0;
    double dQuotientCast = 0.0;

    // Explizite Umwandlung von int zu double
    //强制类型转换
    double dErste = static_cast<double>(iErste);
    double dZweite = static_cast<double>(iZweite);

    dSummeCast = dErste + dZweite;
    dQuotientCast = dErste / dZweite;

    std::cout << "Die Summe mit Typecasting ist: " << dSummeCast << std::endl;
    std::cout << "Der Quotient mit Typecasting ist: " << dQuotientCast << std::endl;
    std::cout << std::endl;


    // Einlesen von Vorname und Nachname
    // Zusammensetzen des Namens in zwei verschiedenen Schreibweisen
    //4.输入姓名，以不同方式拼接
    //定义字符串

    // Variablen fuer Vorname, Nachname und zusammengesetzte Namen
    std::string sVorname = "";
    std::string sNachname = "";
    std::string sVornameName = "";
    std::string sNameVorname = "";

    //读取用户输入

    std::cout << "Geben Sie bitte Ihren Vornamen ein: ";
    std::cin >> sVorname;
    
    std::cout << "Geben Sie bitte Ihren Nachnamen ein: ";
    std::cin >> sNachname;
    std::cout << std::endl;

    // Verknuepfung der Strings
    //拼接
    sVornameName = sVorname + " " + sNachname;
    sNameVorname = sNachname + ", " + sVorname;

    //输出结果
    std::cout << "Name in der Form Vorname Nachname: " << sVornameName << std::endl;
    std::cout << "Name in der Form Nachname, Vorname(mindestens zwei Buchstaben): " << sNameVorname << std::endl;
    std::cout << std::endl;


    // Beispiel fuer ein eindimensionales Array
    //5.
    //a.定义一个一维数组,然后输出

    {
        int iFeld[2] = {1, 2};

        std::cout << "iFeld[0]: " << iFeld[0] << std::endl;
        std::cout << "iFeld[1]: " << iFeld[1] << std::endl;
        std::cout << std::endl;

    // Beispiel fuer ein zweidimensionales Array
    //b.定义二维数组

        int spielfeld[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        };

        std::cout << "spielfeld:" << std::endl;
        std::cout << spielfeld[0][0] << " " << spielfeld[0][1] << " " << spielfeld[0][2] << std::endl;
        std::cout << spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << std::endl;
        std::cout << std::endl;

    // Beispiel fuer einen neuen Gueltigkeitsbereich (Block)
    // Die lokale Konstante iZweite verdeckt innerhalb des Blocks die aeussere Variable
    //c.block 内部定义一个新的常量
    //在 block 里面，iZweite 会优先表示内部的 const int iZweite

        const int iZweite = 1;

        std::cout << "iZweite im Block ist: " << iZweite << std::endl;
    }

    // Ausserhalb des Blocks ist wieder die urspruengliche Variable sichtbar
    std::cout << "iZweite ausserhalb des Blocks ist: " << iZweite << std::endl;
    std::cout << std::endl;


    // Umwandlung der ersten beiden Buchstaben des Vornamens in ihre ASCII-Werte
    //6.把用户输入的 sVorname 的第一个和第二个字母，根据 ASCII 表转换成数字

    int iName1 = 0;
    int iName2 = 0;

    iName1 = static_cast<int>(sVorname[0]);
    iName2 = static_cast<int>(sVorname[1]);

    std::cout << "ASCII-Wert des ersten Buchstabens: " << iName1 << std::endl;
    std::cout << "ASCII-Wert des zweiten Buchstabens: " << iName2 << std::endl;
    std::cout << std::endl;


    // Bestimmung der Position der Buchstaben im Alphabet mit dem Restoperator
    // Gross- und Kleinbuchstaben liefern dabei dieselbe Position
    //7.用 % 计算字母在字母表中的位置,不区分大小写
    //in asc2, A=65, a=97, mod32  

    int iPosition1 = 0;
    int iPosition2 = 0;

    iPosition1 = iName1 % 32;
    iPosition2 = iName2 % 32;

    std::cout << "Position des ersten Buchstabens im Alphabet: " << iPosition1 << std::endl;
    std::cout << "Position des zweiten Buchstabens im Alphabet: " << iPosition2 << std::endl;
    std::cout << std::endl;

    return 0;
    
}
