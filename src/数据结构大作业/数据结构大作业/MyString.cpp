#include<iostream>
#include"MyString.h"
#include <cstdio>
#include <cstring>
#include <vector>
const int MAX = 10000;
using namespace std;
int MyString::indexOf(char *obj)
{
    int M, N; 
	N = strlen(str2);
    M = strlen(obj);
   int fail[MAX] = {0};
    for(int i=1, j=0; i<M; i++)
	{
        while(j > 0 && str2[i] != str2[j]) j = fail[j-1];
        if(str2[i] == str2[j]) fail[i] = ++j;
    }
    vector<int> result;
    for(int i=0, j=0; i<N; i++)
	{
        while(j > 0 && obj[i] != str2[j]) j = fail[j-1];
        if(obj[i] == str2[j])
		{
            if(j == M-1)
			{
                result.push_back(i-M+2);
                j = fail[j];
            }
            else j++;
        }
    }
    for(int i: result)
     return i;
}
int MyString::cmp(char *str,char *obj)
{
	int len=strlen(str);
	int i;
	for(i=0;i<len;i++)
	{
		if(str[i]!=obj[i])
		{
			return 0;			
		}
	}
	return 1;
}
string MyString::substring(int a,int b)
{
	char temp[10000]={NULL};
	int i=0;
	int j=0;
	for(i=a;i<=b;i++)
	{
		temp[j]=str[i];
		j++;
	}
	return temp;
}
void MyString::concat(char *st,char *obj)
{
	int i,j=0;
	int len=strlen(st);
	for(i=0;i<strlen(obj);i++)
	{
		st[i+len]=obj[i];
	}
}
void MyString::assign(char *st,char *obj)
{
	memset(st,NULL,sizeof(char *));
	int i;
	for(i=0;i<strlen(obj);i++)
	{
		st[i]=obj[i];
	}
}