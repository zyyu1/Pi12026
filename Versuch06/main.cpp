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


#include <vector> //push_back()、pop_back()、insert()、erase()、begin()、end()、rbegin()、rend()等

#include <fstream>
#include <algorithm>//find_if()

#include "Student.h"

namespace
{
//////////////////////////////////////////////////////////////////////////////
// functions
//////////////////////////////////////////////////////////////////////////////

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
    std::string name = "";
    std::string geburtstag = "";
    std::string adresse = "";

    std::cout << "Bitte geben Sie die Daten fuer den Studenten ein." << std::endl;

    //如果输入不是合法的无符号整数，就循环
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

    //最后创建并返回一个 Student 对象
    return Student(matNr, name, geburtstag, adresse);
}

//////////////////////////////////////////////////////////////////////////////
// Search and output functions for the student vector
//////////////////////////////////////////////////////////////////////////////

//Search directly in the vector instead of a linked list.
/**
 * @brief Finds a student by matriculation number in the vector.
 *
 * @param studenten Reference to the vector of students
 * @param matNr Matriculation number to search for
 * @return Iterator to the found student, or studenten.end() if not found
 */
//返回迭代器,即返回一个指向vector中某个元素的指针,如果没找到就返回end()，即指向vector最后一个元素的下一个位置
std::vector<Student>::iterator findStudentByMatNr(std::vector<Student>& studenten, unsigned int matNr)
{
    //find_if()在studenten这个vector中查找符合条件的元素,条件是lambda表达式中定义的matNr与学生的matNr相等  
    return std::find_if(studenten.begin(), studenten.end(),

        //[matNr]capture list,让 lambda 能访问外面的 matNr
        [matNr](const Student& student) -> bool
        {
            //返回true表示找到了符合条件的元素,即学生的matNr与输入的matNr相等.find_if()返回对应的迭代器,即指向这个学生的指针
            return student.getMatNr() == matNr;
        });
}

//Print the entries from front to back using a const iterator.
/**
 * @brief Prints all students in the vector in forward order.
 *
 * @param studenten Reference to the vector of students
 */
// const 函数只读这个 vector，不能修改它,& 函数不会复制整个 vector，而是直接引用原来的那个对象
void printStudentsForward(const std::vector<Student>& studenten)
{
    //定义只读迭代器it，初始化, 指向studenten的第一个元素，只要it没有到结尾(end是最后一个元素后面的位置),就循环，每次迭代it++
    for (std::vector<Student>::const_iterator it = studenten.begin(); it != studenten.end(); ++it)
    {
        //输出当前迭代器所指向的学生,即对迭代器当前指向的对象调用成员函数
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
    for (std::vector<Student>::const_reverse_iterator it = studenten.rbegin(); it != studenten.rend(); ++it)
    {
        it->ausgabe();
    }
}
//////////////////////////////////////////////////////////////////////////////
// File input and output functions
//////////////////////////////////////////////////////////////////////////////

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
    //创建了一个输入文件流eingabe,ifsteam从文件中读取数据,并打开指定的文件. cin从console
    std::ifstream eingabe(dateiname.c_str());   //c_str()把string->char*, 因为ifstream的构造函数需要char*类型的参数,而string是C++的类,不是C语言的字符串类型

    //如果文件打开失败,返回false
    if (!eingabe)
    {
        return false;
    }

    //准备临时vector储存学生数据
    std::vector<Student> tempStudenten;
    std::string zeile;

    //只要还能从文件中成功读到一行，就继续循环
    while (std::getline(eingabe, zeile))
    {
        //跳过空行
        if (zeile.empty())
        {
            continue;
        }

        //读取学号
        unsigned int matNr = 0;
        try
        {
            matNr = static_cast<unsigned int>(std::stoul(zeile));  //std::stoul(zeile)把string转换成 unsigned long
        }
        catch (...) //如果转换失败,抛出异常,返回false
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
            return false; //任何一行读取失败,返回false
        }

        tempStudenten.push_back(Student(matNr, name, geburtstag, adresse));
    }

    //如果读取成功,把临时vector赋值给原来的vector
    studenten = tempStudenten;
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
    //创建一个输出文件流ausgabe,ofstream向文件中写入数据,并打开指定的文件. cout向console
    std::ofstream ausgabe(dateiname.c_str(), std::ios::trunc); //std::ios::trunc表示如果文件存在,就清空文件内容,然后再写入新内容

    //检查是否成功打开文件
    if (!ausgabe)
    {
        return false;
    }

    //使用const_iterator遍历vector,输出每个学生的数据到文件中
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

//////////////////////////////////////////////////////////////////////////
// Main program
/////////////////////////////////////////////////////////////////////////

/**
 * @brief Runs the interactive menu for managing the student database.
 *
 * @return Program exit status
 */
int main()
{

    //The doubly linked list is replaced by std::vector.
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
                  //new added menu
                  << "(8): Daten aus einer Datei einlesen" << std::endl         //从文件中读取数据
                  << "(9): Daten in einer Datei speichern" << std::endl         //将数据保存到文件
                  << "(0): Beenden" << std::endl;                           
        std::cin >> abfrage;
        clearInputLine();

        switch (abfrage)
        {
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
                    studentenListe.back().ausgabe();        //用 back() 取出最后一个学生并输出,ausgabe()在student中定义
                    
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
                    printStudentsForward(studentenListe); //use iterator
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

            //find_if()根据学号删除学生
            case '5':
            {
                unsigned int matNr = 0;

                //排除输入不是合法无符号整数的情况
                if (!readUnsignedInt(
                        "Bitte geben Sie die Matrikelnummer des Studenten ein, der geloescht werden soll: ",
                        matNr))
                {
                    std::cout << "Ungueltige Matrikelnummer." << std::endl;
                    break;
                }

                //把找到的学生的迭代器赋值给it
                std::vector<Student>::iterator it = findStudentByMatNr(studentenListe, matNr);

                //在 STL 里，查找失败通常就返回 end()
                if (it != studentenListe.end())
                {
                    std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                    it->ausgabe();

                    //erase()删除迭代器指向的对象,即删除这个学生
                    studentenListe.erase(it);
                }
                else
                {
                    std::cout << "Kein Student mit der Matrikelnummer " << matNr << " gefunden." << std::endl;
                }
                break;
            }

            //insert()从vector的前面添加数据元素
            case '6':
                //insert a new element at the front. vector.insert(位置, 新元素);
                studentenListe.insert(studentenListe.begin(), readStudentFromConsole());
                break;

            //erase()从vector的前面删除数据元素
            case '7':
                //同样先零值判断
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
                std::cin >> dateiname;

                //调用真正的文件读取函数
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
                std::cin >> dateiname;

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
