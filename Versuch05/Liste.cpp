//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @file Liste.cpp
 * @brief Implementierung der doppelt verketteten Studentenliste.
 */

/**
 * @brief Erstellt eine leere Liste.
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Zerstoert die Liste und gibt alle Listenelemente frei.
 */
Liste::~Liste()
{
    while (!empty())
    {
        popFront();
    }
}

/**
 * @brief Fuegt einen Studenten am Ende der Liste ein.
 *
 * @param pData Einzufuegender Student
 */
void Liste::pushBack(Student pData)
{
    // Das neue Element wird hinter dem bisherigen Listenende eingehangen.
    ListenElement* neuesElement = new ListenElement(pData, nullptr, back);

    if (front == nullptr)
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

/**
 * @brief Fuegt einen Studenten am Anfang der Liste ein.
 *
 * @param pData Einzufuegender Student
 */
void Liste::pushFront(Student pData)
{
    // Das neue Element wird vor dem bisherigen Listenanfang eingehangen.
    ListenElement* neuesElement = new ListenElement(pData, front, nullptr);

    if (front == nullptr)
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        front->setPrev(neuesElement);
        front = neuesElement;
    }
}

/**
 * @brief Entfernt das erste Element der Liste.
 */
void Liste::popFront()
{
    if (front == nullptr)
    {
        return;
    }

    ListenElement* cursor = front;

    if (front == back)
    {
        // Spezialfall: Die Liste enthaelt genau ein Element.
        delete front;
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Prueft, ob die Liste leer ist.
 *
 * @return true, wenn die Liste keine Elemente enthaelt, sonst false
 */
bool Liste::empty()
{
    return front == nullptr;
}

/**
 * @brief Liefert die Daten des ersten Listenelements.
 *
 * @return Student am Listenanfang oder ein leerer Student bei leerer Liste
 */
Student Liste::dataFront()
{
    if (front == nullptr)
    {
        return Student();
    }

    return front->getData();
}

/**
 * @brief Gibt die Liste von vorne nach hinten aus.
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    // Iteration vom Listenanfang bis zum Listenende.
    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Gibt die Liste von hinten nach vorne aus.
 */
//给出列表的逆序输出
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    //迭代从列表末尾到列表开头
    // Iteration vom Listenende bis zum Listenanfang.
    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

/**
 * @brief Sucht einen Studenten ueber die Matrikelnummer.
 *
 * @param matNr Matrikelnummer des gesuchten Studenten
 * @param gefundenerStudent Referenz fuer die Rueckgabe der gefundenen Studentendaten
 * @return true, wenn ein passender Student gefunden wurde, sonst false
 */
bool Liste::suchen(unsigned int matNr, Student& gefundenerStudent) const
{
    ListenElement* cursor = front;

    //遍历列表并比较学号
    // Durchlaeuft die Liste linear und vergleicht die Matrikelnummern.
    while (cursor != nullptr)
    {
        if (cursor->getData().getMatNr() == matNr)
        {
            gefundenerStudent = cursor->getData();
            return true;
        }

        cursor = cursor->getNext();
    }

    return false;
}

/**
 * @brief Sucht einen Studenten ueber die Matrikelnummer und entfernt ihn aus der Liste.
 *
 * @param matNr Matrikelnummer des zu loeschenden Studenten
 * @return true, wenn ein passender Student gefunden und geloescht wurde, sonst false
 */
bool Liste::loeschen(unsigned int matNr)
{
    ListenElement* cursor = front;

    // Suche linear nach der gewuenschten Matrikelnummer.
    while (cursor != nullptr)
    {
        if (cursor->getData().getMatNr() == matNr)
        {
            // 删除前先输出该学生的完整信息，满足题目对成功提示的要求。
            std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
            cursor->getData().ausgabe();

            if (cursor == front && cursor == back)
            {
                delete cursor;
                front = nullptr;
                back = nullptr;
            }
            else if (cursor == front)
            {
                // Am Listenanfang kann die vorhandene popFront-Logik genutzt werden.
                popFront();
            }
            else if (cursor == back)
            {
                // Am Listenende muss nur der Rueckwaertszeiger aktualisiert werden.
                back = back->getPrev();
                back->setNext(nullptr);
                delete cursor;
            }
            else
            {
                ListenElement* prevElement = cursor->getPrev();
                ListenElement* nextElement = cursor->getNext();

                prevElement->setNext(nextElement);
                nextElement->setPrev(prevElement);

                delete cursor;
            }

            return true;
        }

        cursor = cursor->getNext();
    }

    return false;
}
