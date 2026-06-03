/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

// Dieses Programm zeigt den Umgang mit Strukturen,
// das Einlesen von Daten und das Kopieren von Strukturvariablen.
#include <iostream> // Fuer Ein- und Ausgabe
#include <string>   // Fuer Zeichenketten in der Struktur

// Definition einer Struktur zur Speicherung von Personendaten
//定义Person结构体, 包含多种类型的数据 (和数组比较)
struct Person
{
    std::string sNachname = "";             // Nachname der Person
    std::string sVorname = "";              // Vorname der Person
    int iGeburtsjahr = 0;                   // Geburtsjahr der Person
    int iAlter = 0;                         // Alter der Person
};

// Hauptfunktion des Programms
int main()
{

    // Strukturvariable fuer die Benutzereingaben
    //定义Person类型的变量nBenutzer
    Person nBenutzer = {};

    // Einlesen der Personendaten
    //让用户输入数据,并把数据输入到结构体变量里
    std::cout << "Bitte geben Sie den Nachnamen ein: " << std::endl;
    std::cin >> nBenutzer.sNachname;

    std::cout << "Bitte geben Sie den Vornamen ein: " << std::endl;
    std::cin >> nBenutzer.sVorname;

    std::cout << "Bitte geben Sie das Geburtsjahr ein: " << std::endl;
    std::cin >> nBenutzer.iGeburtsjahr;

    std::cout << "Bitte geben Sie das Alter ein: " << std::endl;
    std::cin >> nBenutzer.iAlter;
    std::cout << std::endl;

    // Ausgabe der eingegebenen Daten
    //输出结构体
    std::cout << "Ihre Eingaben:" << std::endl;
    std::cout << "Nachname: " << nBenutzer.sNachname << std::endl;
    std::cout << "Vorname: " << nBenutzer.sVorname << std::endl;
    std::cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;
    std::cout << "Alter: " << nBenutzer.iAlter << std::endl;
    std::cout << std::endl;

    //  Kopie der Struktur durch Zuweisung aller einzelnen Mitglieder
    //复制到新的结构体变量
    //1.逐个元素复制
    //jedes Element einzeln kopieren
    Person nKopieEinzeln = {};

    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    // Ausgabe der einzeln kopierten Struktur
    //输出复制结果
    std::cout << "Kopie jedes Elements einzeln: " << std::endl;
    std::cout << "Nachname: " << nKopieEinzeln.sNachname << std::endl;
    std::cout << "Vorname: " << nKopieEinzeln.sVorname << std::endl;
    std::cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << std::endl;
    std::cout << "Alter: " << nKopieEinzeln.iAlter << std::endl;
    std::cout << std::endl;

    // Kopie der gesamten Struktur durch direkte Zuweisung
    //2.整个结构体直接赋值复制
    //die gesamte Struktur mit einer Zuweisung赋值 direkt kopieren
    Person nKopieGesamt = {};

    nKopieGesamt = nBenutzer;

    // Ausgabe der komplett kopierten Struktur
    //输出复制结果
    std::cout << "Kopie der gesamten Struktur: " << std::endl;
    std::cout << "Nachname: " << nKopieGesamt.sNachname << std::endl;
    std::cout << "Vorname: " << nKopieGesamt.sVorname << std::endl;
    std::cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << std::endl;
    std::cout << "Alter: " << nKopieGesamt.iAlter << std::endl;
    std::cout << std::endl;

    return 0;
    
}
