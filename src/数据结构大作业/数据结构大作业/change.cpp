#include <iostream>
#include<string>
#include<Windows.h>
#include"MyString.h"
#include"MyStack.h"
#include"OtherS.h"
using namespace std;
extern MyStack Chinese;
std::string string_To_UTF8(const std::string & str)  //string转化为UTF8的函数，从网上引用的
{  
int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);  
  
wchar_t * pwBuf = new wchar_t[nwLen + 1];
ZeroMemory(pwBuf, nwLen * 2 + 2);  
  
::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);  
  
int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);  
  
char * pBuf = new char[nLen + 1];  
ZeroMemory(pBuf, nLen + 1);  
  
::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);  
  
std::string retStr(pBuf);  
  
delete []pwBuf;  
delete []pBuf;  
  
pwBuf = NULL;  
pBuf = NULL;  
  
return retStr;  
}  
char* ioi(std::wstring& strGBK)//转unicode编码为中文  
{   
	int n;
	n = WideCharToMultiByte(CP_ACP, 0,&strGBK[0], -1, NULL, 0, NULL, NULL);  
	char ok[10000]={NULL};
    WideCharToMultiByte(CP_ACP, 0,&strGBK[0], -1, &ok[0], n, NULL, NULL);  

    return ok;  
}

void Change2(char *str , MyString &ms)//去掉nbsp
{
	int i=0;
	int j=0;
	int length=strlen(str);
	int len=strlen(str);
	for(i=0;i<length;i++)
	{
		if(str[i]=='&')
		i=i+5;
		if(str[i]!=';')
		{
		ms.str2[j]=str[i];
		j++;
		}
	}
	//cout<<ms.str2<<endl;
}
void Change(char *str)//分离出数字并进行转换
{
	wstring a;
	MyString save;
	MyString save2;
	int sw1=0;
	int sw2=0;
	int j=0;
	int k=0;
	int data;

	if(str[strlen(str)-1]!=';')
	{
		str[strlen(str)]=';';
	}
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]=='#')
		{
			sw1=1;
			i++;
		}
		if(sw1==0&&str[i]!='&')
		{
			sw1=2;
		}
		if(str[i]==';'||str[i]=='&')
		{
			data=atoi(save.str2);
			a=data;
			if(sw1==1&&(strcmp(save.str2,"nbsp")!=0))
			Chinese.concat(Chinese.str,ioi(a));
			if(sw1==2&&(strcmp(save2.str2,"nbsp")!=0))
			{
			Chinese.concat(Chinese.str,save2.str2);
			memset(save2.str2,NULL,sizeof(save2.str2));
			memset(save.str2,NULL,sizeof(save.str2));
			}
			if(strcmp(save2.str2,"nbsp")==0)
			memset(save2.str2,NULL,sizeof(save2.str2));
			sw1=0;
			j=0;
			k=0;
		}
		if(sw1==1)
		{
			save.str2[j]=str[i];
			j++;
		}
			if(sw1==2)
			{
				save2.str2[k]=str[i];
				k++;
			}
	}
}
int getWordsnum(char *str)//数我输入了 几个单词
{ 
	int wordsnum=1;
	int i=0;
	int j=0;
	int k=0;
	for(int i=0;i<strlen(str);i++)
	 {
		if(str[i]==' ')
		wordsnum++;
	 }
	return wordsnum;
}
void makewords(char *str,char **save,int wordsnum)//把我输入的单词分开来
{
	int i=0;
	int j=0;
	int k=0;
	memset(save[0],NULL,sizeof(char[40]));
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]!=' ')
		{
			save[j][k]=str[i];
			k++;
		}
		else
		{
			j++;
			memset(save[j],NULL,sizeof(char[40]));
			k=0;
		}
	}
}
void sort(Doc *head)//对我保存下来的单词的信息，按大小排序
{
	Doc *tmp;
	Doc *p;
	Doc *q;
	p=new Doc;
	int n=1;
	int i,j;
	int t1,t2;
	tmp=head;
	p->DocTime=-1;
	while(1)
	{
		tmp=tmp->next;
		if(tmp==NULL)
		break;
		else
		n++;
	}
	tmp=head;
	  
    for(p=head;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
			if(p->DocTime<q->DocTime)//降序（只交换信息不交换链表）
            {
                t1=q->DocID;
				t2=q->DocTime;
                q->DocTime=p->DocTime;
				q->DocID=p->DocID;
                p->DocID=t1;
				p->DocTime=t2;
            }
        }
    }
}