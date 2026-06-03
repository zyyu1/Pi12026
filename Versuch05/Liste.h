//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

/**
 * @file Liste.h
 * @brief Deklaration einer doppelt verketteten Liste fuer Studenten.
 */

/**
 * @brief Verwaltet eine doppelt verkettete Liste von Studenten.
 */
class Liste
{
private:
    /** Zeiger auf das erste Element der Liste. */
    ListenElement* front;
    /** Zeiger auf das letzte Element der Liste. */
    ListenElement* back;

public:
    /**
     * @brief Erstellt eine leere Liste.
     */
    Liste();

    /**
     * @brief Zerstoert die Liste und gibt alle Listenelemente frei.
     */
    ~Liste();

    /**
     * @brief Kopierkonstruktor ist deaktiviert, um flache Kopien der Listenknoten zu verhindern.
     *
     * @param other Zu kopierende Liste
     */
    Liste(const Liste& other) = delete;

    /**
     * @brief Zuweisungsoperator ist deaktiviert, um flache Kopien der Listenknoten zu verhindern.
     *
     * @param other Zuzuweisende Liste
     * @return Referenz auf diese Liste
     */
    Liste& operator=(const Liste& other) = delete;

    /**
     * @brief Fuegt einen Studenten am Ende der Liste ein.
     *
     * @param pData Einzufuegender Student
     */
    void pushBack(Student pData);

    /**
     * @brief Fuegt einen Studenten am Anfang der Liste ein.
     *
     * @param pData Einzufuegender Student
     */
    void pushFront(Student pData);

    /**
     * @brief Entfernt das erste Element der Liste.
     */
    void popFront();

    /**
     * @brief Prueft, ob die Liste leer ist.
     *
     * @return true, wenn die Liste keine Elemente enthaelt, sonst false
     */
    bool empty();

    /**
     * @brief Liefert die Daten des ersten Listenelements.
     *
     * @return Student am Listenanfang oder ein leerer Student bei leerer Liste
     */
    Student dataFront();

    /**
     * @brief Gibt die Liste von vorne nach hinten aus.
     */
    void ausgabeVorwaerts() const;

    /**
     * @brief Gibt die Liste von hinten nach vorne aus.
     */
    void ausgabeRueckwaerts() const;

    /**
     * @brief Sucht einen Studenten ueber die Matrikelnummer.
     *
     * @param matNr Matrikelnummer des gesuchten Studenten
     * @param gefundenerStudent Referenz fuer die Rueckgabe der gefundenen Studentendaten
     * @return true, wenn ein passender Student gefunden wurde, sonst false
     */
    bool suchen(unsigned int matNr, Student& gefundenerStudent) const;

    /**
     * @brief Sucht einen Studenten ueber die Matrikelnummer und entfernt ihn aus der Liste.
     *
     * @param matNr Matrikelnummer des zu loeschenden Studenten
     * @return true, wenn ein passender Student gefunden und geloescht wurde, sonst false
     */
    bool loeschen(unsigned int matNr);
};

#endif /* LISTE_H_ */
