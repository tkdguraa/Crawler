#ifndef MYLINK_H
#define MYLINK_H
#include"MyString.h"
#include<iostream>
class MyLink
{
public:
    MyString Link;
    MyLink *next;
    MyLink()
    {
        next=NULL;
    }
public:
    void add(MyLink *head,char *obj);
    void remove(MyLink *head,MyString front);
    int search(MyLink *head,MyString obj);
};

#endif
