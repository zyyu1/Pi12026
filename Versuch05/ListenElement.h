//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement         //定义一个类 ListenElement
{
private:
    Student data;           //保存学生数据，是一个 Student 对象
    ListenElement* next;    //指向下一个链表节点
    ListenElement* prev;    //单向链表变成双向链表，增加一个指向前一个节点的指针

public:

    // pNext 指向下一个节点
    // pPrev 指向前一个节点
    ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrev); 

    void setData(Student pData);        //setter成员函数设置学生数据
    void setNext(ListenElement* pNext); //setter成员函数设置下一个节点指针
    void setPrev(ListenElement* pPrev); //setter成员函数设置前一个节点指针

    Student getData() const;            //getter成员函数返回当前节点的学生对象
    ListenElement* getNext() const;     //返回指向下一个节点的指针
    ListenElement* getPrev() const;     //增加一个成员函数，返回指向前一个节点的指针
};

#endif
