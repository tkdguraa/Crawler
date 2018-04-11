#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
public:
	string str;
	char str2[1000];
	MyString()
	{
		memset(str2,'\0',sizeof(str2));
	}
public:
	int indexOf(char *obj);
	string substring(int a,int b);
	void concat(char *st,char *obj);
	void assign(char *st,char *obj);
	int cmp(char*str,char *obj);
};

#endif
