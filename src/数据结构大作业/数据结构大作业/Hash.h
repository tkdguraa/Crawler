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
	 Hash *nextalpha;//ͬһ���ֿ�ͷ
public:
	int *HashID;//���Ҫ�õ��õ�����ô����ID
	Hash()
	{
		HashID=NULL;
	}
};

void saveHash(char *str);
 //Hash *head;
#endif