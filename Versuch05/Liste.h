//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                  // Zeiger auf das erste Listenelement
    ListenElement* back;                                   // Zeiger auf das letzte Listenelement

public:
    Liste();                                               // Konstruktor mit Zeigerinitialisierung
    ~Liste();                                              // 释放链表中所有动态申请的结点，避免内存泄漏
    // 链表结点通过 new 动态创建，禁止拷贝可避免多个对象共享同一批结点后重复释放。
    /**
     * @brief Kopierkonstruktor ist deaktiviert, um flache Kopien der Listenknoten zu verhindern.
     *
     * @param other Zu kopierende Liste
     */
    Liste(const Liste&) = delete;
    /**
     * @brief Zuweisungsoperator ist deaktiviert, um flache Kopien der Listenknoten zu verhindern.
     *
     * @param other Zuzuweisende Liste
     * @return Referenz auf diese Liste
     */
    Liste& operator=(const Liste&) = delete;
    void pushBack(Student pData);
    void pushFront(Student pData);                         //增加一个成员函数，在链表头部插入一个学生对象
    void popFront();
    bool empty();
    Student dataFront();
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const; //增加一个成员函数，输出链表的内容，顺序是从后往前
    
    //增加一个成员函数，找到并删除指定学号的学生
    bool loeschen(unsigned int matNr); //找到并删除：返回 true ; 没找到：返回 false
};

#endif /*LISTE_H_*/
