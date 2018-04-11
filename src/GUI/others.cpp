#include"others.h"
int getWordsnum(const char *str)//数我输入了 几个单词
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
void makewords(const char *str, char **save, int wordsnum)//把我输入的单词分开来
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
