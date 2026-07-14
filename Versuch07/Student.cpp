//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "Student.h"

/**
 * @file Student.cpp
 * @brief Implementation of the Student class.
 */

Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
    matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{
}

/**
 * @brief Creates a student with empty default values.
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{
}

/**
 * @brief Returns the matriculation number.
 *
 * @return Student matriculation number
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Returns the name.
 *
 * @return Student name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Returns the date of birth.
 *
 * @return Student date of birth
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Returns the address.
 *
 * @return Student address
 */
std::string Student::getAdresse() const
{
    return adresse;
}

//////////////////////////////////////////////////////////////////////////
// versuch07 new added
/////////////////////////////////////////////////////////////////////////


//////////////// oprtator //////////////////////////////////////////////
//在比较整数时,可以直接用运算符.但是比较对象时,就需要overload operator, 比较对象的特定属性

/**
 * @brief Compares two students by their matriculation numbers.
 *
 * @param other Student to compare with
 * @return true if this student has a smaller matriculation number
 */
//给Student类的operator<重载
bool Student::operator<(const Student& other) const
{
    return matNr < other.matNr;
}

/**
 * @brief Compares two students by their matriculation numbers.
 *
 * @param other Student to compare with
 * @return true if this student has a larger matriculation number
 */
bool Student::operator>(const Student& other) const
{
    return matNr > other.matNr;
}

/**
 * @brief Compares two students by their matriculation numbers.
 *
 * @param other Student to compare with
 * @return true if both students have the same matriculation number
 */
bool Student::operator==(const Student& other) const
{
    return matNr == other.matNr;
}

/**
 * @brief Writes all stored student data to the specified output stream.
 *
 * @param out Output stream to print to
 */
//重新定义Student类的ausgabe函数,使得它可以输出到任何输出流,而不仅仅是std::cout
void Student::ausgabe(std::ostream& out) const  //out指给当前已有的输出流起一个别名 out 来用
{
    //这个函数接收一个输出流 out，然后把学生信息写进去
    out << name << ", MatNr. " << matNr << ", geb. am " << geburtstag << ", wohnhaft in " << adresse;
}

/**
 * @brief Writes a Student object to an output stream.
 *
 * @param out Output stream to write to
 * @param student Student object to output
 * @return Reference to the output stream
 */
//重载<<运算符,使得可以直接用cout << student来输出学生信息
//定义当一个输出流out遇到一个 Student 时，该怎么输出它
std::ostream& operator<<(std::ostream& out, const Student& student)
{
    student.ausgabe(out);
    return out;
}
