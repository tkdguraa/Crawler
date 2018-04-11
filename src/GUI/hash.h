#ifndef HASH_H
#define HASH_H
#include<string>
#include"MyString.h"
#include"Term.h"
using namespace std;
class Hash
{
public:
     char voca[50];
     Hash *nextalpha;
public:
    int *HashID;//如果要用到该单词那么给他ID
    Hash()
    {
        HashID=NULL;
    }
};
void saveHash(char *str);
 //Hash *head;
#endif
