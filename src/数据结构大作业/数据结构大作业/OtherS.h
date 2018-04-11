#ifndef OTHERS_H
#define OTHERS_H
#include<curl\curl.h>
#include"Hash.h"
#include"MyStack.h"
#include"MyLink.h"
Hash searchVoca(Hash *p,char *str);
void readintoString(CURL *curl,MyString &temp, char *HTML);
void initDictionary(ifstream &in,char *buffer);
void Change(char *str);
char* ioi(wstring& strGBK);
std::string string_To_UTF8(const std::string & str);
void Change2(char *str , MyString &ms);//»•µÙnbsp
MyLink divideWords(MyStack &ms,MyLink *MK,MyStack &getWords);//∑÷¿Î¥ ”Ô
MyStack readSource(ifstream &inPutStream,char *url2, ofstream &outPutStream2);
std::wstring UTF8ToWString(const char* lpcszString);
void extractInfo();
int MAX(int a,int b);
int IFNULL(Term *root);
int giveID(char *str);
int getWordsnum(char *str);
void makewords(char *str,char **save,int wordsnum);
void sort(Doc *head);
#endif