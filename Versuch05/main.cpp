/** @mainpage
 *
 * Praktikum Informatik 1 MMXXVI <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

/**
 * @file main.cpp
 * @brief Menuegesteuertes Hauptprogramm zur Verwaltung einer Studentenliste.
 */

#include <iostream>
#include <limits>
#include <string>

#include "Liste.h"
#include "Student.h"

namespace
{
/**
 * @brief Entfernt die restlichen Zeichen der aktuellen Eingabezeile aus dem Eingabepuffer.
 */
void clearInputLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Liest eine vorzeichenlose Ganzzahl ein und behandelt ungueltige Eingaben.
 *
 * @param prompt Auszugebender Eingabehinweis
 * @param value Referenz, in die der gelesene Wert geschrieben wird
 * @return true, wenn erfolgreich eine Zahl eingelesen wurde, sonst false
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
}

int main()
{
    Liste studentenListe;
    Student student;

    char abfrage = '0';
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    clearInputLine();

    if (abfrage != 'j')
    {
        //
        // Beispielbelegung, damit die Listenoperationen sofort getestet werden koennen.
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.pushBack(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.pushBack(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornstr. 55");
        studentenListe.pushBack(student);
        student = Student(64567, "Paula Peters", "09.01.1981", "Weidenweg 12");
        studentenListe.pushBack(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Woelnerstr. 9");
        studentenListe.pushBack(student);
    }

    do
    {
        // Zentrales Menue fuer alle geforderten Listenoperationen.
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl       //在末尾添加数据元素
                  << "(2): Datenelement vorne entfernen" << std::endl          //从前面删除数据元素
                  << "(3): Datenbank ausgeben" << std::endl                    //当前数据显示
                  << "(4): Datenbank rueckwaerts ausgeben" << std::endl        //数据逆序输出
                  << "(5): Student suchen" << std::endl                        //根据学号搜索
                  << "(6): Student loeschen" << std::endl                      //根据学号删除
                  << "(7): Datenelement vorne hinzufuegen" << std::endl       //在前面添加数据元素
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        clearInputLine();

        switch (abfrage)
        {
            case '1':
            {
                //在末尾添加数据元素
                // Neuer Student wird am Listenende angefuegt.
                unsigned int matNr = 0;
                std::string name;
                std::string geburtstag;
                std::string adresse;

                std::cout << "Bitte geben Sie die Daten fuer den Studenten ein.\nName: ";
                std::getline(std::cin, name);

                std::cout << "Geburtsdatum: ";
                std::getline(std::cin, geburtstag);

                std::cout << "Adresse: ";
                std::getline(std::cin, adresse);

                if (!readUnsignedInt("Matrikelnummer: ", matNr))
                {
                    std::cout << "Ungueltige Matrikelnummer. Der Student wurde nicht angelegt." << std::endl;
                    break;
                }

                student = Student(matNr, name, geburtstag, adresse);
                studentenListe.pushBack(student);
                break;
            }

            case '2':
            {
                //从前面删除数据元素
                // Das erste Element wird gelesen, ausgegeben und anschliessend entfernt.
                if (!studentenListe.empty())
                {
                    student = studentenListe.dataFront();
                    std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                    student.ausgabe();
                    studentenListe.popFront();
                }
                else
                {
                    std::cout << "Die Liste ist leer!" << std::endl;
                }
                break;
            }

            case '3':
            {
                //从前面删除数据元素
                // Ausgabe in natuerlicher Reihenfolge vom Listenanfang zum Listenende.
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    studentenListe.ausgabeVorwaerts();
                }
                else
                {
                    std::cout << "Die Liste ist leer!" << std::endl;
                }
                break;
            }

            case '4':
            {
                //逆序  
                // Rueckwaertsausgabe vom Listenende zum Listenanfang.
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
                    studentenListe.ausgabeRueckwaerts();
                }
                else
                {
                    std::cout << "Die Liste ist leer!" << std::endl;
                }
                break;
            }

            case '5':
            {
                //根据学号搜索
                // Gesucht wird anhand der eindeutig vergebenen Matrikelnummer.
                unsigned int matNr = 0;
                Student gefundenerStudent;

                if (!readUnsignedInt(
                        "Bitte geben Sie die Matrikelnummer des Studenten ein, der gesucht werden soll: ",
                        matNr))
                {
                    std::cout << "Ungueltige Matrikelnummer." << std::endl;
                    break;
                }

                if (studentenListe.suchen(matNr, gefundenerStudent))
                {
                    std::cout << "Der folgende Student wurde gefunden:" << std::endl;
                    gefundenerStudent.ausgabe();
                }
                else
                {
                    std::cout << "Kein Student mit der Matrikelnummer " << matNr
                              << " gefunden." << std::endl;
                }
                break;
            }

            case '6':
            {
                //根据学号删除
                // Geloescht wird anhand der eindeutig vergebenen Matrikelnummer.
                unsigned int matNr = 0;

                if (!readUnsignedInt(
                        "Bitte geben Sie die Matrikelnummer des Studenten ein, der geloescht werden soll: ",
                        matNr))
                {
                    std::cout << "Ungueltige Matrikelnummer." << std::endl;
                    break;
                }

                if (studentenListe.loeschen(matNr))
                {
                    // Erfolgreiche Ausgabe erfolgt bereits in loeschen().
                }
                else
                {
                    std::cout << "Kein Student mit der Matrikelnummer " << matNr
                              << " gefunden." << std::endl;
                }
                break;
            }

            case '7':
            {
                //在前面添加数据元素
                // Neuer Student wird am Listenanfang eingefuegt.
                unsigned int matNr = 0;
                std::string name;
                std::string geburtstag;
                std::string adresse;

                std::cout << "Bitte geben Sie die Daten fuer den Studenten ein.\nName: ";
                std::getline(std::cin, name);

                std::cout << "Geburtsdatum: ";
                std::getline(std::cin, geburtstag);

                std::cout << "Adresse: ";
                std::getline(std::cin, adresse);

                if (!readUnsignedInt("Matrikelnummer: ", matNr))
                {
                    std::cout << "Ungueltige Matrikelnummer. Der Student wurde nicht angelegt." << std::endl;
                    break;
                }

                student = Student(matNr, name, geburtstag, adresse);
                studentenListe.pushFront(student);
                break;
            }

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default:
                std::cout << "Falsche Eingabe, bitte nochmal." << std::endl;
                break;
        }
    } while (abfrage != '0');

    return 0;
}
