/** @mainpage
 *
 * Praktikum Informatik 1 MMXXVI <BR>
 * Versuch 6: Standard Template Library - STL
 *
 */

/**
 * @file main.cpp
 * @brief Menu-driven main program for managing a student database with std::vector.
 */

 #include <iostream>
 #include <limits>
 #include <string>

#include <vector>
#include <fstream>
#include <algorithm>

#include "Student.h"

namespace
{
/**
 * @brief Removes the remaining characters of the current input line from the input buffer.
 */
void clearInputLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Reads an unsigned integer and handles invalid input.
 *
 * @param prompt Prompt to display for input
 * @param value Reference to store the read value
 * @return true if a number was successfully read, otherwise false
 */
bool readUnsignedInt(const std::string& prompt, unsigned int& value)
{
    std::cout << prompt;

    if (!(std::cin >> value))
    {
        std::cin.clear();
        clearInputLine();
        return false;
    }

    clearInputLine();
    return true;
}

/**
 * @brief Reads student data from the console and returns a Student object.
 *
 * @return A Student object with the entered data
 */
Student readStudentFromConsole()
{
    unsigned int matNr = 0;
    std::string name;
    std::string geburtstag;
    std::string adresse;

    std::cout << "Bitte geben Sie die Daten fuer den Studenten ein." << std::endl;

    while (!readUnsignedInt("Matrikelnummer: ", matNr))
    {
        std::cout << "Ungueltige Matrikelnummer. Bitte erneut eingeben." << std::endl;
    }

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Geburtsdatum: ";
    std::getline(std::cin, geburtstag);

    std::cout << "Adresse: ";
    std::getline(std::cin, adresse);

    return Student(matNr, name, geburtstag, adresse);
}


//Search directly in the vector instead of a linked list.
/**
 * @brief Finds a student by matriculation number in the vector.
 *
 * @param studenten Reference to the vector of students
 * @param matNr Matriculation number to search for
 * @return Iterator to the found student, or studenten.end() if not found
 */
std::vector<Student>::iterator findStudentByMatNr(std::vector<Student>& studenten, unsigned int matNr)
{
    return std::find_if(studenten.begin(), studenten.end(),
        [matNr](const Student& student)
        {
            return student.getMatNr() == matNr;
        });
}

//Print the entries from front to back using a const iterator.
/**
 * @brief Prints all students in the vector in forward order.
 *
 * @param studenten Reference to the vector of students
 */
void printStudentsForward(const std::vector<Student>& studenten)
{
    for (std::vector<Student>::const_iterator it = studenten.begin(); it != studenten.end(); ++it)
    {
        it->ausgabe();
    }
}

//Print the entries in reverse order using a reverse iterator.
/**
 * @brief Prints all students in the vector in reverse order.
 *
 * @param studenten Reference to the vector of students
 */
void printStudentsBackward(const std::vector<Student>& studenten)
{
    for (std::vector<Student>::const_reverse_iterator it = studenten.rbegin();
         it != studenten.rend();
         ++it)
    {
        it->ausgabe();
    }
}

// Load student records from a text file into the vector.
/**
 * @brief Loads student records from a text file into the vector.
 *
 * @param dateiname Name of the file to read from
 * @param studenten Reference to the vector of students to populate
 * @return true if loading was successful, otherwise false
 */
bool loadStudentsFromFile(const std::string& dateiname, std::vector<Student>& studenten)
{
    std::ifstream eingabe(dateiname.c_str());
    if (!eingabe)
    {
        return false;
    }

    std::vector<Student> geladeneStudenten;
    std::string zeile;

    while (std::getline(eingabe, zeile))
    {
        if (zeile.empty())
        {
            continue;
        }

        unsigned int matNr = 0;
        try
        {
            matNr = static_cast<unsigned int>(std::stoul(zeile));
        }
        catch (...)
        {
            return false;
        }

        std::string name;
        std::string geburtstag;
        std::string adresse;

        if (!std::getline(eingabe, name) ||
            !std::getline(eingabe, geburtstag) ||
            !std::getline(eingabe, adresse))
        {
            return false;
        }

        geladeneStudenten.push_back(Student(matNr, name, geburtstag, adresse));
    }

    studenten = geladeneStudenten;
    return true;
}

// Save the current vector contents back to a file.
/**
 * @brief Saves the current vector contents to a text file.
 *
 * @param dateiname Name of the file to write to
 * @param studenten Reference to the vector of students to save
 * @return true if saving was successful, otherwise false
 */
bool saveStudentsToFile(const std::string& dateiname, const std::vector<Student>& studenten)
{
    std::ofstream ausgabe(dateiname.c_str(), std::ios::trunc);
    if (!ausgabe)
    {
        return false;
    }

    for (std::vector<Student>::const_iterator it = studenten.begin(); it != studenten.end(); ++it)
    {
        ausgabe << it->getMatNr() << '\n'
                << it->getName() << '\n'
                << it->getGeburtstag() << '\n'
                << it->getAdresse() << '\n';
    }

    return true;
}
}

/**
 * @brief Runs the interactive menu for managing the student database.
 *
 * @return Program exit status
 */
int main()
{
    // Versuch06: The doubly linked list is replaced by std::vector.
    std::vector<Student> studentenListe;
    char abfrage = '0';

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl        //在末尾添加数据元素
                  << "(2): Datenelement hinten entfernen" << std::endl          //从末尾删除数据元素
                  << "(3): Datenbank vorwaerts ausgeben" << std::endl           //当前数据显示
                  << "(4): Datenbank rueckwaerts ausgeben" << std::endl         //数据逆序输出
                  << "(5): Student loeschen" << std::endl                       //根据学号删除
                  << "(6): Datenelement vorne hinzufuegen" << std::endl         //在前面添加数据元素 
                  << "(7): Datenelement vorne entfernen" << std::endl           //从前面删除数据元素
                  //new added
                  << "(8): Daten aus einer Datei einlesen" << std::endl         //从文件中读取数据
                  << "(9): Daten in einer Datei speichern" << std::endl         //将数据保存到文件
                  << "(0): Beenden" << std::endl;                           
        std::cin >> abfrage;
        clearInputLine();

        switch (abfrage)
        {

            //1. Benutzen Sie die push und pop Funktionen der Klasse vector, um Elemente am Ende hinzuzufügen  oder zu löschen.

            case '1':
                //push_back appends a new element to the end of the vector.
                //read从终端读取数据并返回一个Student对象
                //push_back把这个新建好的Student对象追加到studentenListe这个vector的末尾
                studentenListe.push_back(readStudentFromConsole());
                break;

            case '2':
                //pop_back removes the last element.
                if (!studentenListe.empty())
                {
                    std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                    studentenListe.back().ausgabe();        //back()返回vector的最后一个元素
                    studentenListe.pop_back();              //pop_back()删除vector的最后一个元素
                }
                else
                {
                    std::cout << "Die Datenbank ist leer!" << std::endl;
                }
                break;

            //数据正序输出
            case '3':
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Datenbank in fortlaufender Reihenfolge:" << std::endl;
                    printStudentsForward(studentenListe);
                }
                else
                {
                    std::cout << "Die Datenbank ist leer!" << std::endl;
                }
                break;

            //数据逆序输出    
            case '4':
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Datenbank in umgekehrter Reihenfolge:" << std::endl;
                    printStudentsBackward(studentenListe);
                }
                else
                {
                    std::cout << "Die Datenbank ist leer!" << std::endl;
                }
                break;

            //根据学号删除学生
            case '5':
            {
                unsigned int matNr = 0;
                if (!readUnsignedInt(
                        "Bitte geben Sie die Matrikelnummer des Studenten ein, der geloescht werden soll: ",
                        matNr))
                {
                    std::cout << "Ungueltige Matrikelnummer." << std::endl;
                    break;
                }

                //erase removes an element at an arbitrary position in the vector.
                std::vector<Student>::iterator it = findStudentByMatNr(studentenListe, matNr);
                if (it != studentenListe.end())
                {
                    std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                    it->ausgabe();
                    studentenListe.erase(it);
                }
                else
                {
                    std::cout << "Kein Student mit der Matrikelnummer " << matNr
                              << " gefunden." << std::endl;
                }
                break;
            }

            //从vector的前面添加数据元素
            case '6':
                //insert at begin() places a new element at the front.
                studentenListe.insert(studentenListe.begin(), readStudentFromConsole());
                break;

            //从vector的前面删除数据元素
            case '7':
                if (!studentenListe.empty())
                {
                    std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                    studentenListe.front().ausgabe();
                    studentenListe.erase(studentenListe.begin());
                }
                else
                {
                    std::cout << "Die Datenbank ist leer!" << std::endl;
                }
                break;

            //从文件中读取数据到vector中
            case '8':
            {
                std::string dateiname;
                std::cout << "Bitte geben Sie den Dateinamen zum Einlesen an: ";
                std::getline(std::cin, dateiname);

                if (loadStudentsFromFile(dateiname, studentenListe))
                {
                    std::cout << "Die Daten wurden erfolgreich aus der Datei geladen." << std::endl;
                }
                else
                {
                    std::cout << "Die Datei konnte nicht gelesen werden oder hat ein ungueltiges Format."
                              << std::endl;
                }
                break;
            }

            //从vector中保存数据到文件中
            case '9':
            {
                std::string dateiname;
                std::cout << "Bitte geben Sie den Dateinamen zum Speichern an: ";
                std::getline(std::cin, dateiname);

                if (saveStudentsToFile(dateiname, studentenListe))
                {
                    std::cout << "Die Daten wurden erfolgreich gespeichert." << std::endl;
                }
                else
                {
                    std::cout << "Die Datei konnte nicht zum Schreiben geoeffnet werden." << std::endl;
                }
                break;
            }

            case '0':
                std::cout << "Das Programm wird nun beendet." << std::endl;
                break;

            default:
                std::cout << "Falsche Eingabe, bitte nochmal." << std::endl;
                break;
        }
    } while (abfrage != '0');

    return 0;
}
