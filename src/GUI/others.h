#ifndef OTHERS_H
#define OTHERS_H
#include"mylink.h"
#include"mystack.h"
#include"Term.h"
#include<QString>
void readdata();
int giveID(const char *str);
void initDictionary(ifstream &in,char *buffer);
void divideWords(MyStack msk);
int MAX(int a,int b);
int IFNULL(Term *root);
int getWordsnum(const char *str);
void makewords(const char *str,char **save,int wordsnum);
QString changecolor(QString str, char **savesearch, int wordsnum);
#endif // OTHERS_H
