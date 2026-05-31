//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

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

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Gibt die Liste von hinten nach vorne aus.
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
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

    while (cursor != nullptr)
    {
        if (cursor->getData().getMatNr() == matNr)
        {
            if (cursor == front && cursor == back)
            {
                delete cursor;
                front = nullptr;
                back = nullptr;
            }
            else if (cursor == front)
            {
                popFront();
            }
            else if (cursor == back)
            {
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
