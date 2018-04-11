#include"Term.h"
#include"OtherS.h"
#include<iostream>
#include<cstring>
#include"avl.h"
#include"Hash.h"
#include<fstream>
#include<sstream>
#include<qDebug>
using namespace std;
extern AVLTree tree;
extern Hash *tp;
Term *Term::rotatell(Term *head)//LL旋转
{
    Term *child=head->lchild;
        head->lchild=new Term;
        head->lchild=child->rchild;
    head->lchild=child->rchild;
    child->rchild=head;
    head->height=MAX(IFNULL(head->lchild),IFNULL(head->rchild))+1;
    child->height=MAX(IFNULL(child->lchild),IFNULL(head))+1;
    return child;
}
Term *Term::rotaterr(Term *head)//RR旋转
{
    Term *child=head->rchild;
    head->rchild=child->lchild;
    child->lchild=head;
    head->height=MAX(IFNULL(head->lchild),IFNULL(head->rchild))+1;
    child->height=MAX(IFNULL(child->rchild),IFNULL(head))+1;
    return child;
}
Term *Term::rotaterl(Term *head)//RL旋转
{
    Term *child=head->rchild;
    head->rchild=rotaterr(child);
    return rotatell(head);
}
Term *Term::rotatelr(Term *head)//LR旋转
{
    Term *child=head->lchild;
    head->lchild=rotatell(child);
    return rotaterr(head);
}
extern int ID;
void Term::addTerm(Term *Dlt,char *obj)//加单词
{
    Term *p,*q,*tail;
    tail=p=q=NULL;
    p=new Term;
    strcpy(p->name,obj);
    p->ID=ID;
    q=Dlt;
    if(Dlt==NULL)
    {
        p=Dlt;
    }
    else
    while(1)
    {
        if(strcmp(q->name,obj)==0)
        {
            p->ID=q->ID;
            tree.insert(tree.head,p);
            break;
        }
            else
            {
                if(q->next==NULL)
                {
                    q->next=p;
                    ID++;
                    tree.insert(tree.head,p);
                    break;
                }
                    else
                {
                    q=q->next;
                }
            }
    }
}
void Term::Edit(Term *key)//数单词出现在第几url中，且出现次数为多少
    {
        Doc *p,*q,*tail;
        tail=p=q=NULL;
        int DF=0;
        int Occur=0;
        p=new Doc;
        q=key->Docinfo;
        while(1)
        {
            if(q==NULL)
                break;
            else
            {
                q=q->next;
                DF++;
                Occur=Occur+q->DocTime;
            }
        }
        key->DF=DF;
        key->Occur=Occur;
        cout<<DF<<"urls and "<<Occur<<"times";
    }

void Doc::add(Doc *record,Doc *key)
{
        Doc *p,*q,*tail;
        tail=p=q=NULL;
        p=new Doc;
        p->DocID=key->DocID;
        p->DocTime=key->DocTime;
        q=record;
        while(1)
        {
            if(q->DocID==p->DocID)//如果该单词的文档链表中已经存在 这一个 url
            {
                q->DocTime++;
                delete(p);
                break;
            }
                else
                {
                    if(q->next==NULL)//如果没有出现过就新建一个
                    {
                        q->next=p;
                      //qDebug()<<"ID:"<<p->DocID;
                        break;
                    }
                        else
                    {
                        q=q->next;
                    }
                }
        }
}
Doc *Doc::remove(Doc *record,Doc *key)
{
    Doc *tp;
    tp=record;
    if(record->DocID==key->DocID)
    {
        record=record->next;
    }
    else
    while(1)
    {
        if(tp->next->DocID==key->DocID)
        {
            tp->next=tp->next->next;
        }
        else
        {
            if(tp->next==NULL)
                break;
            else
              tp=tp->next;
        }
    }
    return record;
}
void Doc::Edit(Doc *Docinfo,int number)
{
        Doc *p,*q,*tail;
        tail=p=q=NULL;
        p=new Doc;
        p->DocID=number;
        q=Docinfo;
        while(1)
        {
            if(q->DocID==p->DocID)//如果该单词的文档链表中已经存在 这一个 url
            {
                q->DocTime++;
                delete(p);
                break;
            }
                else
                {
                    if(q->next==NULL)//如果没有出现过就新建一个
                    {
                        q->next=p;
                        break;
                    }
                        else
                    {
                        q=q->next;
                    }
                }
        }
}
Doc *Doc::search(Doc *Docinfo,Doc *key)
{
    Doc *tp;
    tp=Docinfo;
    while(1)
    {
        if(tp->DocID==key->DocID)
        {
            return tp;
        }
        else
        {
            if(tp->next==NULL)
                break;
            else
              tp=tp->next;
        }
    }
}

void initDictionary(ifstream &in,char *buffer)//把词典中的单词放入哈希表中
{
    in.open("dictionary.dic");
     if (! in.is_open())
       { cout << "Error opening file"; exit (1); }
       while (!in.eof() )
       {
           in.getline(buffer,100);
           saveHash(buffer);
       }
       cout<<"1";
}
