//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "ListenElement.h"

/*
 * Die oeffentliche Schnittstelle ist in ListenElement.h dokumentiert.
 */
ListenElement::ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrev) :
    data(pData), next(pNext), prev(pPrev)
{
}

void ListenElement::setData(Student pData)
{
    data = pData;
}

void ListenElement::setNext(ListenElement* pNext)
{
    next = pNext;
}

void ListenElement::setPrev(ListenElement* pPrev)
{
    prev = pPrev;
}

Student ListenElement::getData() const
{
    return data;
}

ListenElement* ListenElement::getNext() const
{
    return next;
}

ListenElement* ListenElement::getPrev() const
{
    return prev;
}
