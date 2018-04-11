#include"Term.h"
#include"OtherS.h"
#include<iostream>
#include<cstring>
using namespace std;
Term *Term::rotatell(Term *head)//LL旋转
{
	Term *child=head->lchild;
		head->lchild=new Term;
		head->lchild=child->rchild;
	head->lchild=child->rchild;
	child->rchild=head;
	head->height=MAX(IFNULL(head->lchild),IFNULL(head->rchild))+1;//求节点高度
	child->height=MAX(IFNULL(child->lchild),IFNULL(head))+1;
	return child;
}
Term *Term::rotaterr(Term *head)//RR旋转
{
	Term *child=head->rchild;
	head->rchild=child->lchild;
	child->lchild=head;
	head->height=MAX(IFNULL(head->lchild),IFNULL(head->rchild))+1;//求节点高度
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
			else//把该单词的所有url中出现的次数加起来，并数总共有多少个url
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
	if(record->DocID==key->DocID)//如果是我要删除的内容那么删除
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
		if(tp->DocID==key->DocID)//如果是我要查找的那么返回
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
