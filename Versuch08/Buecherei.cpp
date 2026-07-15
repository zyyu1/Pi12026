/*!
 * Praktikum Informatik 1 MMXXVI
 *
 * @file Buecherei.cpp
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 08: Vererbung und Polymorphie
//
// File:    Buecherei.cpp
// Content: Main program
//////////////////////////////////////////////////////////////////////////////

/* This switch controls whether the derived classes should be enabled.
 * If set to true, all derived classes (Buch, DVD, Magazin) are available.
 * If set to false, only the base class Medium is available.
 */
 
//#define UNTERKLASSENVORHANDEN false
#define UNTERKLASSENVORHANDEN true

#include <iostream>
#include <string>
#include <vector>
#include "Medium.h"
#include "Datum.h"

#if UNTERKLASSENVORHANDEN

    #include "Magazin.h"
    #include "Buch.h"
    #include "DVD.h"

#endif

//////////////////////////////////////////////////////////////////////////
// header
/////////////////////////////////////////////////////////////////////////

/*!
 * @brief Fills the library database with predefined media
 *
 * \param medien Vector that stores pointers to all media objects
 */
void fuelleDatenbank(std::vector<Medium*>& medien);

/*!
 * @brief Adds a new medium to the library database
 *
 * \param medien Vector that stores pointers to all media objects
 */
void mediumHinzufuegen(std::vector<Medium*>& medien);

/*!
 * @brief Removes a medium from the library database
 *
 * \param medien Vector that stores pointers to all media objects
 */
void mediumEntfernen(std::vector<Medium*>& medien);

/*!
 * @brief Lends a medium to a person
 *
 * \param medien Vector that stores pointers to all media objects
 * \param aktuellesDatum Current date used as the borrowing date
 */
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum);

/*!
 * @brief Returns a borrowed medium to the library
 *
 * \param medien Vector that stores pointers to all media objects
 */
void mediumZurueckgeben(std::vector<Medium*>& medien);

/*!
 * @brief Outputs all media currently stored in the database
 *
 * \param medien Vector that stores pointers to all media objects
 */
void alleMedienAusgeben(std::vector<Medium*>& medien);

/*!
 * @brief Outputs all currently borrowed media
 *
 * \param medien Vector that stores pointers to all media objects
 */
void ausgelieheneMedienAusgeben(std::vector<Medium*>& medien);


//////////////////////////////////////////////////////////////////////////
// main program
/////////////////////////////////////////////////////////////////////////
/*!
 * @brief Main program of the library application
 *
 * Initializes the media database, shows the menu, and dispatches the
 * selected user actions until the program is terminated.
 *
 * \return Exit status of the program
 */
int main()
{
    // Vector containing all media items in the library
    std::vector<Medium*> medien;

    // Current date
    Datum aktuellesDatum;
    std::cout << "Aktuelles Datum: " << aktuellesDatum << std::endl;

    // Fill the database depending on whether the derived classes are available
    fuelleDatenbank(medien);

    char abfrage;
    do
    {
        std::cout << std::endl
                  << "Menue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Medium hinzufuegen" << std::endl
                  << "(2): Medium loeschen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Ein Medium verleihen" << std::endl
                  << "(5): Ein Medium zuruecknehmen" << std::endl
                  << "(6): Ausgeliehene Medien ausgeben" << std::endl
                  << "(7): Beenden" << std::endl;

        // Read the menu choice
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Add a medium to the database
            case '1':
            {
                mediumHinzufuegen(medien);
                break;
            }

            // Remove a medium from the database
            case '2':
            {
                mediumEntfernen(medien);
                break;
            }

            // Output all media in the database
            case '3':
            {
                alleMedienAusgeben(medien);
                break;
            }

            // Lend a medium
            case '4':
            {
                mediumAusleihen(medien, aktuellesDatum);
                break;
            }

            // Return a medium to the library
            case '5':
            {
                mediumZurueckgeben(medien);
                break;
            }

            // Output all currently borrowed media
            case '6':
            {
                ausgelieheneMedienAusgeben(medien);
                break;
            }

            // Exit the program
            case '7':
            {
                std::cout << "Das Menue wird nun beendet." << std::endl;
                break;
            }

            default :
            {
                std::cout << "Falsche Eingabe, bitte nochmal versuchen.";
                break;
            }
        }
    }
    while (abfrage != '7');

    // Delete all media before terminating the program
    for (std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        delete (*it);
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////
// functions 
/////////////////////////////////////////////////////////////////////////


/*!
 * @brief Fills the library database automatically
 *
 * Depending on the compile-time switch, this function either inserts
 * predefined derived media objects or prints a message that derived classes
 * are disabled.
 *
 * \param medien Vector that stores pointers to all media objects
 */
void fuelleDatenbank(std::vector<Medium*>& medien)
{
#if UNTERKLASSENVORHANDEN
    {
        // Fill the database with media
        Medium* neuesMedium = new Buch("Das Parfum", "Patrick Suskind");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Harry Potter und der Stein der Weisen", "J. K. Rowling");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Tom Sawyer", "Mark Twain");
        medien.push_back(neuesMedium);

        neuesMedium = new Magazin("Chip", Datum(1, 3, 2026), "Computer");
        medien.push_back(neuesMedium);

        neuesMedium = new DVD("Fluch der Karibik", 12, "Actionkomoedie");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Huckleberry Finn", "Mark Twain");
        medien.push_back(neuesMedium);
    }
#else
    {
        // Fill the database with media
        std::cout << "Unterklassen sind nicht aktiviert." << std::endl;
    }
#endif
}

/*!
 * @brief Adds a new medium to the database
 *
 * Lets the user choose the media type and enter the corresponding data,
 * then creates the appropriate object and appends it to the media vector.
 *
 * \param medien Vector that stores pointers to all media objects
 */
void mediumHinzufuegen(std::vector<Medium*>& medien)
{
    #if UNTERKLASSENVORHANDEN  //all derived classes (Buch, DVD, Magazin) are available.
    {
        std::cout << "Geben Sie die Art des Mediums ein: " << std::endl
                  << "(1): Buch" << std::endl
                  << "(2): Magazin" << std::endl
                  << "(3): DVD" << std::endl;

        // Read the selection
        char abfrage;
        std::cin >> abfrage;
        
        // consumes the trailing newline so that the next getline call will wait for user input as expected.
        std::cin.ignore(10,'\n');  //去除回车,不然接下来的getline会直接读到一个空行,导致输入被跳过

        switch (abfrage)
        {
            // Case 1: Book
            case '1':
            {
                // Read the book title
                std::string titel;
                std::cout << "Bitte geben Sie den Titel des Buchs ein: " << std::endl;
                std::getline(std::cin, titel);

                // Read the book author
                std::string autor;
                std::cout << "Bitte geben sie den Autor des Buchs ein: " << std::endl;
                std::getline(std::cin, autor);

                // Create a new book
                Medium* neuesMedium = new Buch(titel,autor); //neuesMedium是指向 Medium 的指针(因为Buch是Medium的子类,所以可以用Buch对象初始化Medium指针)
                medien.push_back(neuesMedium);               //将新创建的buch对象的指针添加到medien vector里
            }
            break;

            // Case 2: Magazine
            case '2':
            {
                // Read the magazine title
                std::string titel;
                std::cout << "Geben Sie den Titel des Magazins ein:" << std::endl;
                getline(std::cin, titel);

                // Read the magazine category
                std::string sparte;
                std::cout << "Geben Sie die Sparte an:" << std::endl;
                getline(std::cin, sparte);

                // Read the publication date
                Datum datumAusgabe;
                std::cout << "Geben Sie das Erscheinungsdatum der Ausgabe an:" << std::endl;
                std::cin >> datumAusgabe;
                std::cin.ignore(10, '\n');

                // Create a new magazine
                Medium* neuesMedium = new Magazin(titel, datumAusgabe, sparte);
                medien.push_back(neuesMedium);
            }
            break;

            // Case 3: DVD
            case '3':
            {
                // Read the DVD title
                std::string titel;
                std::cout << "Bitte geben Sie den Titel der DVD ein:" << std::endl;
                getline(std::cin, titel);

                // Read the DVD genre
                std::string genre;
                std::cout << "Geben Sie das Genre an:" << std::endl;
                getline(std::cin, genre);

                // Read the DVD age rating
                int altersfreigabe;
                std::cout << "Geben Sie die Altersfreigabe ein:" << std::endl;
                std::cin >> altersfreigabe;
                std::cin.ignore(10, '\n');

                Medium* neuesMedium = new DVD(titel, altersfreigabe, genre);
                medien.push_back(neuesMedium);
            }
            break;

            // Invalid input
            default:
                std::cout << "Ungueltige Eingabe!" << std::endl;
                break;
        }
    }
    #else //UNTERKLASSEVORHANDEN
    {
        // Read the title
        std::string titel;
        std::cout << "Bitte geben sie den Titel des Mediums ein:\n";
        getline(std::cin, titel);

        std::cout << "Unterklassen sind nicht aktiviert." << std::endl;
    }
    #endif
}

/*!
 * @brief Removes a medium from the database
 *
 * Prompts the user for an ID, searches for the matching medium, and removes
 * it from the vector if it exists.
 *
 * \param medien Vector that stores pointers to all media objects
 */
void mediumEntfernen(std::vector<Medium*>& medien)
{
    // ID of the medium to be deleted
    unsigned int id;

    std::cout << "Geben Sie die ID des Mediums ein, welches geloescht werden soll: " ;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    //准备一个标记变量, 来标记是否找到了对应的id,初始值为false
    bool success = false;

    // 遍历medien,it, 一个指向 medien 容器当前元素位置的小指针
    for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); ++it)
    {
        //it指向的是vector里Medum*指针的地址,*it指对象,即vector里存储的Medium*指针, (*it)->getID()是调用Medium对象的getID()方法
        if((*it)->getID() == id)
        {
            delete (*it);       //删除指针所指的对象, 即删除Medium*指针, 为了释放内存,防止内存泄漏

            medien.erase(it);   //在指针列表里,删除指针本身,从vector中移除该元素

            success = true;
            break;
        }
    }
    if(!success)
    {
        std::cout << "Keine gueltige ID!" << std::endl;
    }
}

/*!
 * @brief Lends a medium from the database
 *
 * Reads the medium ID and borrower information from the user and forwards
 * the borrowing request to the selected medium.
 *
 * \param medien Vector that stores pointers to all media objects
 * \param aktuellesDatum Current date used as the borrowing date
 */
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum)
{
    // Read the ID
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein:" << std::endl;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    // Read the name of the borrowing person
    std::string name;
    std::cout << "Geben Sie den Namen der Person ein: ";
    getline(std::cin, name);

    // Read the birth date
    Datum geburtsdatum;
    std::cout << "Geben Sie das Geburtsdatum der Person ein: (Format TT.MM.JJJJ) ";
    std::cin >> geburtsdatum;
    std::cin.ignore(10, '\n');

    //创建一个Person对象,用来存储新输入借阅者的信息,包括姓名和出生日期
    Person person(name,geburtsdatum);

    //标记变量, 用来标记是否找到了对应的id,初始值为false
    bool id_find = false;

    // Search the matching medium
    for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            (*it)->ausleihen(person,aktuellesDatum); //对对应的Medium对象调用ausleihen方法,传入借阅者信息和当前日期
            id_find = true;
        }
    }
    if (!id_find)
    {
        std::cout << "Keine gueltige ID!" << std::endl;
    }
}

//the structure is same as mediumAusleihen()
/*!
 * @brief Returns a borrowed medium
 *
 * Prompts the user for an ID and forwards the return request to the selected
 * medium.
 *
 * \param medien Vector that stores pointers to all media objects
 */
void mediumZurueckgeben(std::vector<Medium*>& medien)
{
    // Read the ID
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein: ";
    std::cin >> id;
    std::cin.ignore(10,'\n');

    bool id_find = false;

    // Search the matching medium
    for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            (*it)->zurueckgeben();
            id_find = true;
        }
    }
    if (!id_find)
    {
        std::cout << "Keine gueltige ID!" << std::endl;
    }
}

/*!
 * @brief Outputs all media stored in the database
 *
 * Iterates over the complete media vector and prints each medium using the
 * overloaded stream operator.
 *
 * \param medien Vector that stores pointers to all media objects
 */
void alleMedienAusgeben(std::vector<Medium*>& medien)
{
    std::cout << "Vorhandene Medien in der Buecherei:" << std::endl;

    //遍历medien中的所有元素,并输出每个元素的内容,每个元素是一个Medium*指针,通过重载的<<运算符输出Medium对象的信息
    for (unsigned int index = 0; index < medien.size(); index++)
    {
        std::cout << "*************************************************************" << std::endl;
        std::cout << *medien[index];
    }
}

/*!
 * @brief Outputs all currently borrowed media stored in the database
 *
 * Iterates over the media vector and prints only those media whose status
 * indicates that they are currently lent out.
 *
 * \param medien Vector that stores pointers to all media objects
 */
void ausgelieheneMedienAusgeben(std::vector<Medium*>& medien)
{
    std::cout << "Ausgeliehene Medien in der Buecherei:" << std::endl;

    //标记变量, 用来标记是否找到了借出的媒体,初始值为false
    bool medium_found = false;

    for (unsigned int index = 0; index < medien.size(); index++)
    {
        if (medien[index]->getStatus() == true)  //如果该Medium对象的状态为借出状态,则输出该Medium对象的信息
        {
            std::cout << "*************************************************************" << std::endl;
            std::cout << *medien[index];
            medium_found = true;
        }
    }

    if (!medium_found)
    {
        std::cout << "Es sind zurzeit keine Medien ausgeliehen." << std::endl;
    }
}
