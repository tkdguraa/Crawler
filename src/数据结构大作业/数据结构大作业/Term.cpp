#include"Term.h"
#include"OtherS.h"
#include<iostream>
#include<cstring>
using namespace std;
Term *Term::rotatell(Term *head)//LL��ת
{
	Term *child=head->lchild;
		head->lchild=new Term;
		head->lchild=child->rchild;
	head->lchild=child->rchild;
	child->rchild=head;
	head->height=MAX(IFNULL(head->lchild),IFNULL(head->rchild))+1;//��ڵ�߶�
	child->height=MAX(IFNULL(child->lchild),IFNULL(head))+1;
	return child;
}
Term *Term::rotaterr(Term *head)//RR��ת
{
	Term *child=head->rchild;
	head->rchild=child->lchild;
	child->lchild=head;
	head->height=MAX(IFNULL(head->lchild),IFNULL(head->rchild))+1;//��ڵ�߶�
	child->height=MAX(IFNULL(child->rchild),IFNULL(head))+1;
	return child;
}
Term *Term::rotaterl(Term *head)//RL��ת
{
	Term *child=head->rchild;
	head->rchild=rotaterr(child);
	return rotatell(head);
}
Term *Term::rotatelr(Term *head)//LR��ת
{
	Term *child=head->lchild;
	head->lchild=rotatell(child);
	return rotaterr(head);
}

void Term::Edit(Term *key)//�����ʳ����ڵڼ�url�У��ҳ��ִ���Ϊ����
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
			else//�Ѹõ��ʵ�����url�г��ֵĴ����������������ܹ��ж��ٸ�url
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
			if(q->DocID==p->DocID)//����õ��ʵ��ĵ��������Ѿ����� ��һ�� url
			{
				q->DocTime++;
				delete(p);
				break;
			}
				else
				{
					if(q->next==NULL)//���û�г��ֹ����½�һ��
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
	if(record->DocID==key->DocID)//�������Ҫɾ����������ôɾ��
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
			if(q->DocID==p->DocID)//����õ��ʵ��ĵ��������Ѿ����� ��һ�� url
			{
				q->DocTime++;
				delete(p);
				break;
			}
				else
				{
					if(q->next==NULL)//���û�г��ֹ����½�һ��
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
		if(tp->DocID==key->DocID)//�������Ҫ���ҵ���ô����
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
