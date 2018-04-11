	#ifndef MYSTACK_H
#define MYSTACK_H
#define MAXSTACKSIZE 10000
#include<string>
using namespace std;
class MyStack
{
public:
	char str[MAXSTACKSIZE];
	int num;
	MyStack()
	{
		memset(str,'\0',sizeof(str));
		num=0;
	}
public:
	void push(char c);
	void pop();
	char top();
	int empty();
	char substr( int a, int b,char *str);
	void concat(char *st,char *obj);
};

#endif