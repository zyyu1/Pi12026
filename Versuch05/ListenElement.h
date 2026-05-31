//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

/**
 * @brief Reprasentiert einen Knoten einer doppelt verketteten Studentenliste.
 */
class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* prev;

public:
    /**
     * @brief Erstellt ein neues Listenelement.
     *
     * @param pData Studentendaten des Knotens
     * @param pNext Zeiger auf das naechste Listenelement
     * @param pPrev Zeiger auf das vorherige Listenelement
     */
    ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrev);

    /**
     * @brief Ersetzt die gespeicherten Studentendaten des Knotens.
     *
     * @param pData Neue Studentendaten
     */
    void setData(Student pData);

    /**
     * @brief Setzt den Zeiger auf das naechste Listenelement.
     *
     * @param pNext Neues naechstes Listenelement
     */
    void setNext(ListenElement* pNext);

    /**
     * @brief Setzt den Zeiger auf das vorherige Listenelement.
     *
     * @param pPrev Neues vorheriges Listenelement
     */
    void setPrev(ListenElement* pPrev);

    /**
     * @brief Liefert die gespeicherten Studentendaten.
     *
     * @return Studentendaten des Knotens
     */
    Student getData() const;

    /**
     * @brief Liefert den Zeiger auf das naechste Listenelement.
     *
     * @return Zeiger auf das naechste Listenelement
     */
    ListenElement* getNext() const;

    /**
     * @brief Liefert den Zeiger auf das vorherige Listenelement.
     *
     * @return Zeiger auf das vorherige Listenelement
     */
    ListenElement* getPrev() const;
};

#endif
