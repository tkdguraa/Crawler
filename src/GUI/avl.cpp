#include"term.h"
#include"avl.h"
#include<iostream>
#include<QDebug>
using namespace std;
extern int total;
int MAX(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}
int IFNULL(Term *root)
{
    if(root==NULL)
        return -1;
    else
        return root->height;
}
Term* AVLTree::insert(Term *root,Term *key)
{
    if(root==NULL)
    {
        root=key;
        return root;
    }
    else if(key->ID<root->ID)
        root->lchild=insert(root->lchild,key);//根据平衡树特点，如果输入值小于树中的点，那么向左移动
    else if(key->ID>root->ID)
        root->rchild=insert(root->rchild,key);//反之向右移动
    else if(key->ID==root->ID)
    {
        root->Docinfo->Edit(root->Docinfo,total);
        return root;
    }
    root->height=MAX(IFNULL(root->rchild),IFNULL(root->lchild))+1;//求出节点高度
    if(IFNULL(root->lchild)-IFNULL(root->rchild)>1)
    {
        if(key->ID<root->lchild->ID)
            root= root->rotatell(root);
        else
            root= root->rotatelr(root);
    }
    else if(IFNULL(root->rchild)-IFNULL(root->lchild)>1)
    {
        if(key->ID<root->rchild->ID)
            root=root->rotaterl(root);
        else
            root=root->rotaterr(root);
    }
    return root;
}
void AVLTree::search(Term *head,int id,Doc *record)
{
    Term *p;
    p=head;
    Doc *tmp;
    tmp=new Doc;
    while(1)
    {
        if(p->ID==id)
        {
            tmp=p->Docinfo;
            while(1)
            {
                if(tmp==NULL)
                {
                    //p->Edit(p);
                    return;
                }
                record->add(record,tmp);
                tmp=tmp->next;
            }
        }
        else if(p->ID<id)//如果查找的ID比树中的大，那么向右移动
        {
            p=p->rchild;
        }
        else if(p->ID>id)//反之向右移动
        {
            p=p->lchild;
        }
    }
}
void AVLTree::Edit(Term *root)
{
    Term *tmp;
    tmp=root;
    while(1)
    {
        if(tmp->Docinfo!=NULL)
        {
            tmp->DF=tmp->DF++;
            tmp->Occur=tmp->Occur+tmp->Docinfo->DocTime;
        }
        if(tmp->Docinfo==NULL)
            break;
        tmp->Docinfo=tmp->Docinfo->next;
    }
}
Term * AVLTree::Adjust(Term *root,Term *key)
{
    if(IFNULL(root->lchild)-IFNULL(root->rchild)>1)//根据输的高度调整树的结构
    {
        if(key->ID<root->lchild->ID)
            root= root->rotatell(root);
        else
            root= root->rotatelr(root);
    }
    else if(IFNULL(root->rchild)-IFNULL(root->lchild)>1)
    {
        if(key->ID<root->rchild->ID)
            root=root->rotaterl(root);
        else
            root=root->rotaterr(root);
    }
    return root;
}
