#ifndef TERM_H
#define TERM_H
#include<iostream>
class Doc
{
public:
	int DocID;
	int DocTime;
	Doc()
	{
		extern int total;
		DocID=total;//url的序数
		DocTime=1;//第DocID个url中单词Term的出现次数
		next=NULL;
	}
	Doc *next;
	void add(Doc *record,Doc *key);
	void Edit(Doc *Docinfo,int number);
	Doc *search(Doc *record,Doc *key);
	Doc *remove(Doc *record,Doc *key);
};
class Term
{
public:
	char name[50];
	Doc *Docinfo;
	int DF;
	int ID;
	int Occur;
	int height;
	Term()
	{
		DF=0;
		Occur=0;
		Docinfo=new Doc;
		next=NULL;
		rchild=NULL;
		lchild=NULL;
		height=0;
		memset(name,NULL,sizeof(name));
		ID=-1;
	}
	void addTerm(Term *Dlt,char *obj,int number,int HashID);
	void Edit(Term *key);
	void search(Term *Dlt,char *str);
	Term *rotatell(Term *head);
	Term *rotaterr(Term *head);
	Term *rotaterl(Term *head);
	Term *rotatelr(Term *head);
	Term *next;
	Term *rchild;
	Term *lchild;
};

#endif