#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"others.h"
#include"mystring.h"
#include"avl.h"
#include"Hash.h"
#include<fstream>
#include<sstream>
#include<Qdebug>
#include<QLayout>
#include<QLabel>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include"thread.h"
#include <QMovie>
#include<QPushButton>
int change=0;
QLabel *loading;
QPushButton *btn;
   QMovie *movie;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    loading=ui->load;
    btn=ui->pushButton_2;


    movie=new QMovie(":/new/img/loading.gif");

    loading->setMovie(movie);
    movie->start();
  //readdata();
    this->setCentralWidget(ui->stackedWidget);

    ui->stackedWidget->setCurrentWidget(ui->page_4);
    ui->logo->setStyleSheet("QLabel{border-image: url(:/new/img/Waagle.jpg);}");
    ui->logo_2->setStyleSheet("QLabel{border-image: url(:/new/img/Waagle.jpg);}");
    ui->logo_3->setStyleSheet("QLabel{border-image: url(:/new/img/Waagle.jpg);}");
    ui->logo_4->setStyleSheet("QLabel{border-image: url(:/new/img/Waagle.jpg);}");

    ui->logo_4->setStyleSheet("QLabel{border-image: url(:/new/img/Waagle.jpg);}");

    ui->topage1_1->setStyleSheet("background-color:green");
    ui->topage2_2->setStyleSheet("background-color:green");
    ui->topage3_3->setStyleSheet("background-color:green");
    ui->page_4->setStyleSheet("QWidget{background-color:white;}");
    ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/img/next.jpg);}");
    ui->pushButton_2->setVisible(false);
    a.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
MyStack contents[2003];
AVLTree tree;
Term *saveID;
int ID=0;
Hash tp[10000];
int total=1;
void readdata()
{
    ifstream inputStream1;
    ifstream inputStream2;
    MyStack buffer;
    char buf[100];
    inputStream1.open("contents.csv");
    if (!inputStream1.is_open())
           { cout << "Error opening file"; exit (1); }
           while (!inputStream1.eof() )
           {  
               inputStream1.getline(contents[total].str,10000);
               total++;
           }
    initDictionary(inputStream2,buffer.str);
    for(total=1;total<2001;total++)
    divideWords(contents[total]);
}
void saveHash(char *str)//制作哈希表
{
    Hash *q,*p,*tail;
    tail=q=NULL;
    p=new Hash;
    strcpy(p->voca,str);
    q=&tp[abs(str[0]*10+str[1])%10000];
    if(q==NULL)
        {
        q=p;
        p->nextalpha=tail;
        }
    while(1)
    {
        if(q->nextalpha==NULL)
        {
            q->nextalpha=p;
            p->nextalpha=tail;
            break;
        }
        else
        {
            q=q->nextalpha;
        }
    }
}
int getID=0;
void divideWords(MyStack msk)
{
    int i=0;
    int j=5;
    int m=i*2;
    int n=j*2;
    int k=4;
    int sw=0;
    int l=0;
    MyString get;
    MyStack omo;
    Hash *p;
    for(i=0;i<strlen(msk.str);i++)
    {
        m=i;
        sw=0;
    //	m=i*2;
        l=i;
        if(strlen(msk.str)<=4)
            k=strlen(msk.str);
        else
        k=4;
        if(strlen(msk.str)==n)
        {
            k--;
            if(k==-1)
            break;
        }
        for(j=i+k;j>=0;j--)
        {
            //n=j*2;
            n=j;
            msk.substr(m,n+1,omo.str);
            get.assign(get.str2,omo.str);
            p=&tp[abs(get.str2[0]*10+get.str2[1])%10000];
            while(1)
            {
                if(strcmp(get.str2,p->voca)==0)
                {
                    if(p->HashID==NULL)//如果该单词第一次出现那么给他一个ID
                    {
                        p->HashID=new int;
                        p->HashID[0]=getID;
                        getID++;
                    }
                    Term *key;
                    key=new Term;
                    key->ID=p->HashID[0];
                    strcpy(key->name,p->voca);
                    tree.head=tree.insert(tree.head,key);//加节点
                    memset(get.str2,NULL,sizeof(get.str2));
                    sw=1;
                    break;
                }
                else
                {
                    p=p->nextalpha;
                    if(p==NULL)
                    {
                    memset(get.str2,NULL,sizeof(get.str2));
                    break;
                    }
                }
            }
            if(sw==1)
            {
                break;
            }
        }
    }
}
void MainWindow::resizeEvent(QResizeEvent *event)//设置部件大小及坐标
{
    ui->lineEdit->setGeometry(width()/6,height()/10+height()/3,(7*width())/12,height()/20);
    ui->search->setGeometry(3*width()/4,height()/10+height()/3,width()/12,height()/20);
    ui->logo->setGeometry(width()/4,height()/10,width()/2,height()/3);
    ui->scrollArea->setGeometry(width()/6,height()/10+height()/3+height()/20,width()/12+(7*width()/12),height()/3+height()/10);

    ui->lineEdit_2->setGeometry(width()/6,height()/10+height()/3,(7*width())/12,height()/20);
    ui->search_2->setGeometry(3*width()/4,height()/10+height()/3,width()/12,height()/20);
    ui->logo_2->setGeometry(width()/4,height()/10,width()/2,height()/3);
    ui->scrollArea_2->setGeometry(width()/6,height()/10+height()/3+height()/20,width()/12+(7*width()/12),height()/3+height()/10);

    ui->lineEdit_3->setGeometry(width()/6,height()/10+height()/3,(7*width())/12,height()/20);
    ui->search_3->setGeometry(3*width()/4,height()/10+height()/3,width()/12,height()/20);
    ui->logo_3->setGeometry(width()/4,height()/10,width()/2,height()/3);
    ui->scrollArea_3->setGeometry(width()/6,height()/10+height()/3+height()/20,width()/12+(7*width()/12),height()/3+height()/10);

    ui->load->setGeometry(width()/4,height()/2,width()/2,height()/3);
    ui->pushButton_2->setGeometry(5*width()/12,height()/2,width()/6,2*height()/9);
    ui->logo_4->setGeometry(width()/4,height()/10,width()/2,height()/3);

    ui->topage1_1->setGeometry(0,0,width()/6,height()/20);
    ui->topage2_1->setGeometry(width()/6,0,width()/6,height()/20);
    ui->topage3_1->setGeometry(width()/3,0,width()/6,height()/20);
    ui->topage1_2->setGeometry(0,0,width()/6,height()/20);
    ui->topage2_2->setGeometry(width()/6,0,width()/6,height()/20);
    ui->topage3_2->setGeometry(width()/3,0,width()/6,height()/20);
    ui->topage1_3->setGeometry(0,0,width()/6,height()/20);
    ui->topage2_3->setGeometry(width()/6,0,width()/6,height()/20);
    ui->topage3_3->setGeometry(width()/3,0,width()/6,height()/20);

}
int giveID(const char *str)//查找输入的单词的ID
{
     Hash *q;
        q=&tp[abs(str[0]*10+str[1])%10000];
           while(1)
        {
            if(q==NULL)	//如果我输入的单词不在词典里
                {
                return -1;
                }

            if(strcmp(str,q->voca)==0)
            {
                if(q->HashID==NULL)	//如果我输入的单词没有出现过
                {
                    return -1;
                }
                else
                {
                    return q->HashID[0];
                }
            }
            else
            {
                q=q->nextalpha;
            }
        }
}

int count=0;
QVBoxLayout *vlayout = new QVBoxLayout;
QVBoxLayout *vlayout2 = new QVBoxLayout;
QVBoxLayout *vlayout3 = new QVBoxLayout;
QLabel **dlt;
QLabel **dlt2;
QLabel **dlt3;
int num=0;
int num2=0;
int num3=0;
int i1=0;
int i2=0;
int i3=0;
void MainWindow::on_search_clicked()
{
    Doc *tp;
    Doc *record;
   // QVBoxLayout *vlayout = new QVBoxLayout;
    if(!ui->lineEdit->text().isEmpty())
    {
    for(int j=0;j<num;j++)
    {
        delete(dlt[j]);
    }
    i1=0;
    num=0;
    record=new Doc;
    int jud=0;
    int id=-1;
    int wordsnum=1;
    QString temp;
    temp=ui->lineEdit->text();  //如果点击search按钮，获得窗口中的文字
    vlayout->setContentsMargins(0,0,0,1);
    std::string str = temp.toStdString();
    const char* search = str.c_str();
    char **savesearch;
    wordsnum=getWordsnum(search);
    savesearch=new char*[wordsnum];
        for(int i=0;i<wordsnum;i++)
         {
            savesearch[i]=new char[40];
         }
    makewords(search,savesearch,wordsnum);
    for(int i=0;i<wordsnum;i++)//把所有输入的单词都查找一变
        {
             id=giveID(savesearch[i]);
             if(id!=-1)
             {
             tree.search(tree.head,id,record);//如果该单词在树中存在那么在书中查找
             jud=1;
             }
        }

  //  if(id!=-1)
   // {
    record=record->next;
    Doc *tmp;
    tmp=record;
    while(1)
    {
        if(tmp==NULL)
            break;
        else
        {
            num++;
            tmp=tmp->next;
        }
    }
    dlt=new QLabel*[num];
    for(int j=0;j<num;j++)
        dlt[j]=new QLabel;
      if(jud==1)//
      {//
     if(record!=NULL)
      {
            while(1)
              {
                 if(record==NULL)
                   {
                    break;
                  }
                        else
                      {
                        tp=record;
                        makelabel(contents[record->DocID].str,vlayout,savesearch,wordsnum);//按单词中的url序号，输出其信息
                        record=record->next;
                        delete(tp);
                      }
               }
            ui->searchscroll->setLayout(vlayout);
            ui->topage1_1->setText(ui->lineEdit->text());//同步几个其他画面
            ui->topage1_2->setText(ui->lineEdit->text());
            ui->topage1_3->setText(ui->lineEdit->text());
            for(int i=0;i<wordsnum;i++)
              {
                 memset(savesearch[i],NULL,sizeof(char[40]));//为下次搜索初始化
                 delete(savesearch[i]);
             }
       }
    }
    else
    {
        makelabel("no search words in these url",vlayout,savesearch,wordsnum);
        ui->topage1_1->setText(ui->lineEdit->text());
        ui->topage1_2->setText(ui->lineEdit->text());
        ui->topage1_3->setText(ui->lineEdit->text());
        ui->searchscroll->setLayout(vlayout);
        num++;
        qDebug()<<"2";
    }
   }
}

void MainWindow::makelabel(char *str, QVBoxLayout *vlayout,char **savesearch,int wordsnum)
{
    //<font color = red> str </font>

    QString tmp = QString::fromUtf8(str);
    QLabel *label = new QLabel(changecolor(tmp,savesearch,wordsnum));//换我查找的单词的颜色
    dlt[i1]=label;
    i1++;
    vlayout->addWidget(label);
}
void MainWindow::makelabel2(char *str, QVBoxLayout *vlayout,char **savesearch,int wordsnum)
{
    //<font color = red> str </font>
    QString tmp = QString::fromUtf8(str);
    QLabel *label = new QLabel(changecolor(tmp,savesearch,wordsnum));
    dlt2[i2]=label;
    i2++;
    vlayout->addWidget(label);
}
void MainWindow::makelabel3(char *str, QVBoxLayout *vlayout,char **savesearch,int wordsnum)
{
    //<font color = red> str </font>
    QString tmp = QString::fromUtf8(str);
    QLabel *label = new QLabel(changecolor(tmp,savesearch,wordsnum));
    dlt3[i3]=label;
    i3++;
    vlayout->addWidget(label);
}
QString changecolor(QString str,char **savesearch,int wordsnum)
{
    QString ft1="<font color=\"red\">";
    QString ft2="</font>";
    QString str2=str;
    for(int j=0;j<wordsnum;j++)
    {
    int longer=0;
    QString changeToQST=QString::fromUtf8(savesearch[j]);
    int index=0;
    int start=0;
    QRegularExpression regularExpression(changeToQST);
    QRegularExpressionMatch match;
    do {
           match = regularExpression.match(str, index);
           if(match.hasMatch()) {
               index = match.capturedEnd();
               qDebug()<<"("<<match.capturedStart()<<","<<index<<") "<<match.captured(0);
               str2.insert(match.capturedStart()+longer,ft1);
               str2.insert(index+ft1.length()+longer,ft2);
               longer=longer+ft1.length()+ft2.length();
           }
           else
           {
               break;
           }
        } while(index <str.length());
    }
    return str2;
}

void MainWindow::on_search_2_clicked()//与search一样
{
    Doc *tp;
    Doc *record;
   // QVBoxLayout *vlayout = new QVBoxLayout;
    if(!ui->lineEdit_2->text().isEmpty())
    {
    for(int j=0;j<num2;j++)
    {
        delete(dlt2[j]);
    }
    i2=0;//
    int jud=0;
    num2=0;//
    record=new Doc;
    int id=-1;
    int wordsnum=1;
    QString temp;
    temp=ui->lineEdit_2->text();//
    vlayout2->setContentsMargins(0,0,0,1);
    std::string str = temp.toStdString();
    const char* search = str.c_str();
    char **savesearch;
    wordsnum=getWordsnum(search);
    savesearch=new char*[wordsnum];
        for(int i=0;i<wordsnum;i++)
         {
            savesearch[i]=new char[40];
         }
    makewords(search,savesearch,wordsnum);
    for(int i=0;i<wordsnum;i++)//把所有输入的单词都查找一变
        {
             id=giveID(savesearch[i]);
             if(id!=-1)
            {
                 tree.search(tree.head,id,record);
                jud=1;
             }
        }

  //  if(id!=-1)
   // {
    record=record->next;
    Doc *tmp;
    tmp=record;
    while(1)
    {
        if(tmp==NULL)
            break;
        else
        {
            num2++;//
            tmp=tmp->next;
        }
    }
    dlt2=new QLabel*[num2];
    for(int j=0;j<num2;j++)
        dlt2[j]=new QLabel;
      if(jud==1)//
      {//
     if(record!=NULL)
      {
            while(1)
              {
                 if(record==NULL)
                   {
                    break;
                  }
                        else
                      {
                        tp=record;
                        makelabel2(contents[record->DocID].str,vlayout2,savesearch,wordsnum);//
                        record=record->next;
                        delete(tp);
                      }
               }
            ui->searchscroll_6->setLayout(vlayout2);//
            ui->topage2_1->setText(ui->lineEdit_2->text());//
            ui->topage2_2->setText(ui->lineEdit_2->text());//
            ui->topage2_3->setText(ui->lineEdit_2->text());//
            for(int i=0;i<wordsnum;i++)
              {
                 memset(savesearch[i],NULL,sizeof(char[40]));//为下次搜索初始化
                 delete(savesearch[i]);
             }
       }
    }
    else
    {
        makelabel2("no search words in these url",vlayout2,savesearch,wordsnum);//
        ui->topage2_1->setText(ui->lineEdit_2->text());//
        ui->topage2_2->setText(ui->lineEdit_2->text());//
        ui->topage2_3->setText(ui->lineEdit_2->text());//
        ui->searchscroll_6->setLayout(vlayout2);//
        num2++;//
    }
   }
}

void MainWindow::on_search_3_clicked()//与search一样
{
    Doc *tp;
    Doc *record;
   // QVBoxLayout *vlayout = new QVBoxLayout;
    if(!ui->lineEdit->text().isEmpty())
    {
    for(int j=0;j<num3;j++)
    {
        delete(dlt3[j]);
    }
    i3=0;//
    num3=0;
    record=new Doc;
    int id=-1;
    int wordsnum=1;
    int jud=0;
    QString temp;
    temp=ui->lineEdit_3->text();//
    vlayout->setContentsMargins(0,0,0,1);
    std::string str = temp.toStdString();
    const char* search = str.c_str();
    char **savesearch;
    wordsnum=getWordsnum(search);
    savesearch=new char*[wordsnum];
        for(int i=0;i<wordsnum;i++)
         {
            savesearch[i]=new char[40];
         }
    makewords(search,savesearch,wordsnum);
    for(int i=0;i<wordsnum;i++)//把所有输入的单词都查找一变
        {
             id=giveID(savesearch[i]);
             if(id!=-1)
                {
             tree.search(tree.head,id,record);
               jud=1;
             }
        }

  //  if(id!=-1)
   // {
    record=record->next;
    Doc *tmp;
    tmp=record;

    while(1)
    {
        if(tmp==NULL)
            break;
        else
        {
            num3++;//
            tmp=tmp->next;
        }
    }
    dlt3=new QLabel*[num3];
    for(int j=0;j<num3;j++)
        dlt3[j]=new QLabel;

      if(jud==1)//
      {//
     if(record!=NULL)
      {
            while(1)
              {
                 if(record==NULL)
                   {
                    break;
                  }
                        else
                      {
                        tp=record;
                        makelabel3(contents[record->DocID].str,vlayout3,savesearch,wordsnum);//
                        record=record->next;
                        delete(tp);
                      }
               }
            ui->searchscroll_7->setLayout(vlayout3);//
            ui->topage3_1->setText(ui->lineEdit_3->text());//
            ui->topage3_2->setText(ui->lineEdit_3->text());//
            ui->topage3_3->setText(ui->lineEdit_3->text());//
            for(int i=0;i<wordsnum;i++)
              {
                 memset(savesearch[i],NULL,sizeof(char[40]));//为下次搜索初始化
                 delete(savesearch[i]);
             }
       }
    }
    else
    {
        makelabel3("no search words in these url",vlayout3,savesearch,wordsnum);//
        ui->topage3_1->setText(ui->lineEdit_3->text());//
        ui->topage3_2->setText(ui->lineEdit_3->text());//
        ui->topage3_3->setText(ui->lineEdit_3->text());//
        ui->searchscroll_7->setLayout(vlayout3);//
        num3++;//
        qDebug()<<"2";
    }
   }
}
void MainWindow::on_topage1_1_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::on_topage2_1_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_topage3_1_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

void MainWindow::on_topage1_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::on_topage2_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_topage3_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

void MainWindow::on_topage1_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::on_topage2_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_topage3_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
void MainWindow::Thread::run()//用多线程，把数据读进来
{

    qDebug()<<change;
     readdata();
     delete loading;
     change++;
     btn->setVisible(true);
     movie->stop();
     this->stop();
}
void MainWindow::Thread::stop()
{
    stopped=true;
}

void MainWindow::on_pushButton_2_clicked()//读完数据到下一页
{    
    qDebug()<<change;
    //if(change==0)
    //a.start();
    if(change==1)
    {
    ui->stackedWidget->setCurrentWidget(ui->page);
    change++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}

