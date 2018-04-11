#include"MyLink.h"


void MyLink::add(MyLink *head,char *obj)
{
	MyLink *p,*q,*tail;
	tail=p=q=NULL;
	p=new MyLink;
	strcpy(p->Link.str2,obj);
	//memset(p->Link.str2,NULL,sizeof(p->Link.str2));
	q=head;
	while(1)
	{
		if(strcmp(q->Link.str2,p->Link.str2)==0)
			break;		
			{
				if(q->next==NULL)
				{
					q->next=p;
					p->next=tail;
					break;
				}
					else
				{
					q=q->next;
				}
			}	
	}
}
void MyLink::remove(MyLink *head,MyString obj)
{
	MyLink *p;
	MyLink *q;
	p=head;
		if(strcmp(p->Link.str2,obj.str2)==0)
		{
			head=p->next;
			return;
		}
	while(1)
	{
		p=p->next;
		q=p->next;
		if(strcmp(q->Link.str2,obj.str2)==0)
		{
			p->next=q->next;
			return;
		}
		if(q==NULL)
		{
			p->next=NULL;
		}
	}
}
int search(MyLink *head,MyString obj)
{
	MyLink *p;
	int i=0;
	p=head;
	while(1)
	{
		p=p->next;
		if(strcmp(p->Link.str2,obj.str2)==0)
		{
			return i;
		}
		i++;
	}
}