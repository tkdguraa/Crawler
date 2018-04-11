#include"MyStack.h"
#include<iostream>
void MyStack::push(char c)
{
	str[num]=c;
	num++;
}
void MyStack::concat(char *st,char *obj)
{
	int i,j=0;
	int len=strlen(st);
	for(i=0;i<strlen(obj);i++)
	{
		st[i+len]=obj[i];
	}
}
void MyStack::pop()
{
	if(num<=0)
		return;
	else
	num--;
}
char MyStack::top()
{
	return str[num];
}
int MyStack::empty()
{
	if(num<=0)
	return 1;
	else
	return 0;
}
char MyStack::substr(int a,int b,char *str1)
{
	char temp[MAXSTACKSIZE]={NULL};
	//string temp;
	
	memset(str1,NULL,sizeof(str1));
	int i=0;
	int j=0;
	for(i=a;i<=b;i++)
	{
		temp[j]=str[i];
		j++;
	}
	strcpy(str1,temp);
	//cout<<temp<<endl;
	return 0;
}