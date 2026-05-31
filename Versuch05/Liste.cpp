//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Destruktor zum Freigeben aller Listenelemente.
 */
Liste::~Liste()
{
    // 依次删除所有结点，避免程序结束时遗留动态内存。
    while (!empty())
    {
        popFront();
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    //为什么加back？
    //因为我们需要在链表的末尾添加一个新的元素，所以我们需要一个指针来指向链表的最后一个元素，这样我们就可以直接在最后一个元素之后添加新的元素，而不需要遍历整个链表来找到最后一个元素。
    ListenElement* neuesElement = new ListenElement(pData, nullptr, back);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back); //设置新元素的前一个节点为当前的最后一个节点
        back = neuesElement;
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Daten des neuen Studenten
 */
//增加一个成员函数，在链表头部插入一个学生对象
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement =
        new ListenElement(pData, front, nullptr);

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
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    // 空链表时直接返回，防止访问空指针。
    if (front == nullptr)
    {
        return;
    }

    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr); //设置新的第一个元素的前一个节点为nullptr
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    return front == nullptr;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    // 调用者如果忘记先判空，返回一个默认 Student，避免程序崩溃。
    if (front == nullptr)
    {
        return Student();
    }

    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
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
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev(); //设置新的第一个元素的前一个节点为nullptr
    }
}

/**
 * @brief Finden und Loeschen eines Listenelements mit einer bestimmten Matrikelnummer.
 *
 * @param matNr Die Matrikelnummer des zu loeschenden Studenten
 * @return true, wenn das Element gefunden und geloescht wurde, sonst false
 */
//增加一个成员函数，找到并删除指定学号的学生
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
