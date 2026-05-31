//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "ListenElement.h"

/**
 * @file ListenElement.cpp
 * @brief Implementierung eines Knotens der doppelt verketteten Liste.
 */

/*
 * Die oeffentliche Schnittstelle ist in ListenElement.h dokumentiert.
 */
ListenElement::ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrev) :
    data(pData), next(pNext), prev(pPrev)
{
}

/**
 * @brief Ersetzt die gespeicherten Studentendaten.
 */
void ListenElement::setData(Student pData)
{
    data = pData;
}

/**
 * @brief Aktualisiert den Zeiger auf das naechste Element.
 */
void ListenElement::setNext(ListenElement* pNext)
{
    next = pNext;
}

/**
 * @brief Aktualisiert den Zeiger auf das vorherige Element.
 */
void ListenElement::setPrev(ListenElement* pPrev)
{
    prev = pPrev;
}

/**
 * @brief Liefert die gespeicherten Studentendaten.
 */
Student ListenElement::getData() const
{
    return data;
}

/**
 * @brief Liefert den Nachfolgerknoten.
 */
ListenElement* ListenElement::getNext() const
{
    return next;
}

/**
 * @brief Liefert den Vorgaengerknoten.
 */
ListenElement* ListenElement::getPrev() const
{
    return prev;
}
