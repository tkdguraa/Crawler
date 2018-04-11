#include<iostream>
#include"Hash.h"
#include"MyString.h"
#include<fstream>
#include<sstream>
#include <curl/curl.h>
#include"MyStack.h"
#include"MyLink.h"
#include"OtherS.h"
#include"Term.h"
#include"AVL.h"
void initDictionary(ifstream &in,char *buffer)//把词典中的单词放入哈希表中
{
	in.open("词库.dic");
     if (! in.is_open())  
       { cout << "Error opening file"; exit (1); }  
       while (!in.eof() )  
       {  
           in.getline(buffer,100);
		   saveHash(buffer); 
       }
	 cout<<"Dictionary loaded successfully"<<endl;
	 cout<<"HashTabel made successfully"<<endl;
}
Hash tp[10000];
int total=1;

MyString sucs[2001];
MyStack Chinese;
Term *head;
MyLink *Dlt;
int getID=0;
AVLTree tree;

void saveHash(char *str)//制作哈希表
{
	Hash *q,*p,*tail;
	tail=q=NULL;
	p=new Hash;
	strcpy(p->voca,str);
	q=&tp[abs(str[0]*10+str[1])%10000];
	//q=&tp[abs(str[0])%1000];
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
static int writer(char *data, size_t size, size_t nmemb, std::string *buffer)  
{  
 int result = 0;  
 if (buffer != NULL)  
 {  
  buffer->append(data, size * nmemb);  
  result = size * nmemb;  
 }  
 return result;  
}  
void readintoString(CURL *curl,MyString &temp, char *HTML)//读入网址，并把它保存在string中
{
  if(curl) 
  {
	curl_easy_setopt(curl, CURLOPT_URL,HTML);
	curl_easy_setopt(curl, CURLOPT_HEADER, 0);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &temp); 
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
}

MyStack readSource(ifstream &inPutStream,char *url2,ofstream &outPutStream2)
{
	int i=0;
	int ioi=0;
	int sw=0;//输入<div>等<>内容判断
	int sw2=0;//<div class="z">的判断
	int j=0;
	int k=0;
	int count=0;
	int sw3=0;//对<div class="z">的提取判断
	int sw4=0;//对"authi"判断
	int sw5=0;//对"t_fsz"判断
	int sw6=0;//对"ts z h1"判断 
	int tp[2];
	int juniel=0;
	int GL=0;
	char space[3]={NULL};
	MyStack stack;
	MyString want;//保存<>中的内容
	MyStack wantsmall;// 保存发帖大小类，发帖标题
	MyStack save;
	MyStack omo;
	MyStack savefordivide;//保存去掉数字的
	MyStack name;//保存作者名字
	MyStack content;//保存帖子内容
	MyString content2;
	MyStack ymd;//保存日期
	MyStack getWords;
	MyStack sort;//保存类
	MyString read;
	MyString readtmp;
	MyString xushu;
	MyStack title;
	MyLink *saveWords;//test
	MyLink *Words;
	saveWords=new MyLink;
	int judout=0;
	char kong[3]=" ";
	space[0]=',';
	//saveWords=new MyLink; 
	Words=saveWords;
	inPutStream.open("out.txt");
     if (! inPutStream.is_open())  
       { cout << "Error opening file"; exit (1); }  
       while (!inPutStream.eof() )  
       {  
		   inPutStream.getline(read.str2,1000000);
		   for(i=0;i<strlen(read.str2);i++)
		   {
			   if(read.str2[i]=='<')//遇到<开始压栈
				  sw=1;
				if(sw==1)
				{
					stack.push(read.str2[i]);
				}
			  if(read.str2[i]=='>')//遇到>结束压栈，并在下面判断<>内的内容是否我们需要的
			  {
				 sw=0;
				 count++;
				 tp[count%2]=i;
				 //cout<<stack.str<<endl;
				 want.str=stack.str;
				  if(want.str=="<div class=\"z\">")
				  {
					sw2=1;
				  }
				/*  if(want.str=="<div class=\"authi\">"&&sw4==0)
				  {
					sw4=1;
				  }*/
				  if(sw4==1&&want.str=="</a>")
				  {
					for(int q=0;q<(i-tp[(count+1)%2]-4);q++)
					{
						name.str[q]=read.str2[tp[(count+1)%2]+q+1];
					}
					sw4=0;
				  }//
				  if(sw4==1&&want.str=="</em>")
				  {
					  for(int q=0;q<(i-tp[(count+1)%2]-21);q++)
					{
						ymd.str[q]=read.str2[tp[(count+1)%2]+q+8];
					}
					sw4=2;
				  }

				/*  if(want.str=="<div class=\"ts z h1\">")
				  {
					sw6=1;
				  }*/
				  if(sw6==1&&want.str=="</a>")
				  {
					for(int q=0;q<(i-tp[(count+1)%2]-6);q++)
					{
					 sort.str[q]=read.str2[tp[(count+1)%2]+q+2];
					}
					sw6=0;
					//cout<<sort.str<<endl;
				  }
		
				  if(want.str=="<div class=\"t_fsz\">"&&sw5==0)//帖子内容
				  {
					sw5=1;
				  }
				  if(sw5==1&&want.str=="</p>")
				  {
					for(int q=0;q<(i-tp[(count+1)%2]-4);q++)
					{
						if(read.str2[tp[(count+1)%2]+q+1]!=',')
						{
							content.str[k]=read.str2[tp[(count+1)%2]+q+1];	
							k++;
						}
					}
					sw5=2;
					Change(content.str);
					for(int m=0;m<strlen(content.str);m++)
					{
						if(Chinese.str[m]<'0'||Chinese.str[m]>'9')
						{
							savefordivide.str[GL]=Chinese.str[m];
							GL++;
						}
					}		
					divideWords(savefordivide,saveWords,getWords);	
					judout=1;
					break;
				  }
				  //
				 if(sw5==1&&want.str=="<br>")
				  {
					while(1)
					{
						if(read.str2[ioi]==' ')
							ioi++;
						else break;
					}
					  for(int q=0;q<i-ioi-3;q++)
					{
						if(read.str2[ioi+q]!=',')
						{
							content.str[k]=read.str2[ioi+q];
							k++;
						}			
					}
					  Change2(content.str,content2);	  
					  for(int m=0;m<strlen(content.str);m++)
					{
						if(Chinese.str[m]<'0'||Chinese.str[m]>'9')//为了分词便利去除数字
						{
							savefordivide.str[GL]=content.str[m];
							GL++;
						}
					}
					sw5=3;
					divideWords(savefordivide,saveWords,getWords);	
					judout=1;
					break; 
				  }
				 //
				  if(sw5==1&&want.str=="<ignore_js_op>")
				  {
					 for(int ak=0;ak<strlen(readtmp.str2);ak++)
					 {
						if(readtmp.str2[ak]!=' ')
						{
							content.str[k]=readtmp.str2[ak];
							k++;
						}
					 }
					  Change2(content.str,content2);//
					  for(int m=0;m<strlen(content.str);m++)
					{
						if(Chinese.str[m]<'0'||Chinese.str[m]>'9')//为了分词便利去除数字
						{
							savefordivide.str[GL]=content.str[m];
							GL++;
						}
					}
					sw5=3;
					divideWords(savefordivide,saveWords,getWords);	
					judout=1;
					break; 
				  }
				 //
				  if(sw5==1&&want.str=="</td>")
				  {
					while(1)
					{
						if(read.str2[ioi]==' ')
							ioi++;
						else break;
					}
					  for(int q=0;q<i-ioi-4;q++)
					{
						if(read.str2[ioi+q]!=',')
						{
							content.str[k]=read.str2[ioi+q];
							k++;
						}			
					}
					  Change2(content.str,content2);	  
					  for(int m=0;m<strlen(content.str);m++)
					{
						if(Chinese.str[m]<'0'||Chinese.str[m]>'9')//为了分词便利去除数字
						{
							savefordivide.str[GL]=content.str[m];
							GL++;
						}
					}
					sw5=3;
					divideWords(savefordivide,saveWords,getWords);	
					judout=1;
					break; 
				  }

				     if(want.str=="<div class=\"z\">")
				  {
					sw2=1;
				  }
				  if(want.str=="</a>"&&sw2==1)
				  {
					  if(sw3>1)
					  {
						 // save.substr(tp[(count+1)%2]+2,i-3,omo.str);
						  //wantsmall.concat(wantsmall.str,omo.str);
						  //wantsmall.concat(wantsmall.str,space);	
						  if(sw3==4)
						  {
							 save.substr(tp[(count+1)%2]+2,i-3,omo.str);
							 title.concat(title.str,omo.str); 
						     divideWords(title,saveWords,getWords);	
						  }
					  }
					  sw3++;
				  }
				  if(sw2==1&&want.str=="</div>")//读到这，保存内容
				  {
					sw2=0;
					sw3=0;
				  }
				while(!stack.empty())//清除栈，保存下一个<>
				{
					stack.pop();
				}
				memset(stack.str,NULL,sizeof(stack.str));
			  }
			    if(sw2==1)
				{
					save.str[j]=read.str2[i];
					j++;
				}
		   }
		   if(judout==1)
			   break;
		   memset(readtmp.str2,NULL,sizeof(readtmp.str2));
		   strcpy(readtmp.str2,read.str2);
	   }


	 /*  	while(1)
	{
		Dlt=saveWords;
		getWords.concat(getWords.str,saveWords->Link.str2);
		getWords.str[strlen(getWords.str)]='\n';
		saveWords=saveWords->next;
		delete(Dlt);
		if(saveWords==NULL)
			break;
	}*/
	/*   while(1)
	{
		cout<<saveWords->Link.str2;
		cout<<Dlt->Link.str2;
		getWords.concat(getWords.str,Dlt->Link.str2);
		getWords.concat(getWords.str,kong);
		Dlt=Dlt->next;
		if(Dlt==NULL)
			break;
	}*/
	   itoa(total,xushu.str2,10);
	   sucs[total].concat(sucs[total].str2,xushu.str2);
	   sucs[total].concat(sucs[total].str2,space);
	   sucs[total].concat(sucs[total].str2,title.str);
	   sucs[total].concat(sucs[total].str2,space);
	   //sucs[total].concat(sucs[total].str2,url2);
	   //sucs[total].concat(sucs[total].str2,space);
	  // sucs[total].concat(sucs[total].str2,wantsmall.str);
	  // sucs[total].concat(sucs[total].str2,space);
	  	  if(sw5==2)
	  sucs[total].concat(sucs[total].str2,Chinese.str);
	  else if(sw5==3)
	  {
	  sucs[total].concat(sucs[total].str2,content2.str2);
	  }
		   else if(sw5==4)
	  {
	  sucs[total].concat(sucs[total].str2,content.str);
	  }
	  	if (outPutStream2.is_open())   
			{  
			 title.str[strlen(title.str)]='\n';
			  outPutStream2<<string_To_UTF8(title.str);
			}
	  sucs[total].str2[strlen(sucs[total].str2)]='\n';
	  cout<<xushu.str2<<" completed"<<endl;
	  memset(Chinese.str,NULL,sizeof(Chinese.str));
	  total++;
}
MyLink divideWords(MyStack &msk,MyLink *saveWords,MyStack &getWords)
{
	int i=0;
	int j=5;
	int m=i*2;
	int n=j*2;	
	int k=4;
	int sw=0;
	int l=0;
	MyString get;
	MyLink *temp;
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
			//p=&tp[abs(get.str2[0])%1000];
			while(1) 
			{
				if(strcmp(get.str2,p->voca)==0)
				{
					//saveWords->add(saveWords,p->voca);
					if(p->HashID==NULL)//如果该单词第一次出现那么给他一个ID
					{
						p->HashID=new int;
						p->HashID[0]=getID;
						getID++;
					}
				//	Dlt->addTerm(Dlt,p->voca,total,p->HashID[0]);
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
	return *saveWords;
}
Doc *record;
void extractInfo()
{
  CURL *curl;
  CURLcode res;
  ofstream outPutStream("contents.csv");
  ifstream inPutStream;
  ifstream inPutStream2;
  Hash *p;
  p=NULL;
  MyString buffer;
  MyString url;
  MyString url2;
 // MyString sortname={"序号,网址,发帖大类,发帖小类,发帖标题1,发帖内容,发帖人,发帖日期,发帖类型,分词结果"};
  MyString sortname;
  int sw=0;
  int j=0;
  int k=0;
  char str[100]={NULL};
  ifstream in;
  ifstream inputStream;
  MyString temp;
  MyString NEW;
  Dlt=new MyLink;
  cout<<"Ready to load dictionary and make hash table"<<endl;
 initDictionary(inPutStream2,buffer.str2);
  ofstream outPutStream2("title.csv");
 if (outPutStream2.is_open())   
			{  
				const char *sange="\xef\xbb\xbf";
				outPutStream2<<sange;
		   }
  //sortname.str2[strlen(sortname.str2)]='\n';
  //sucs[0].assign(sucs[0].str2,sortname.str2);
  curl = curl_easy_init();
  cout<<"Ready to read the source"<<endl;
  in.open("input\\url.csv");
     if (! in.is_open())  
       { cout << "Error opening file"; exit (1); }  
		 while (!in.eof() )  
		{  
			curl = curl_easy_init();
			//char url2[100000]={NULL};
			memset(url2.str2,NULL,sizeof(url2.str2));
			temp = NEW;
			sw=0;
			j=0;
			in.getline(url.str2,100);
			if(k<=2000)//修改数量
			for(int i=0;i<strlen(url.str2)-1;i++)
			{
				if(url.str2[i]==',')
				{
					sw=1;
				}
				if(sw==1&&url.str2[i+1]!='"')
				{
					url2.str2[j]=url.str2[i+1];
					j++;
				}
			}
			 if(total<=2000)//修改数量
			{
				ofstream out("out.txt");
				ifstream inPutStream;
				if(url2.str2[0]=='h')
					{
						readintoString(curl,temp,url2.str2);
						if (out.is_open())   
						{  
							out <<temp.str;  
							out.close();  
						}
						
						readSource(inPutStream,url2.str2,outPutStream2);
					}
			}
			 k++;
		 }
		 outPutStream2.close();
		 cout<<"Source read successfully"<<endl;
		  if (outPutStream.is_open())   
			{  
				const char *sange="\xef\xbb\xbf";
				outPutStream<<sange;
				for(int m=0;m<=2000;m++)
				{
					outPutStream<<string_To_UTF8(sucs[m].str2);
				}
					outPutStream.close();
			}
			 int wtget=-1;
			 char search[200]={NULL};
			 char **savesearch;
			 int wordsnum=1;
			 record=new Doc;
			 Doc *tp;
			 tp=new Doc;
			// while(1)
		ofstream outresult("result.txt");
		inputStream.open("query.txt");
	  if (! inputStream.is_open())  
				  { cout << "Error opening file"; exit (1); }  
					 while (!inputStream.eof() )  
				{
				 inputStream.getline(search,1000);
				 wordsnum=getWordsnum(search);
				 savesearch=new char*[wordsnum];
					for(int i=0;i<wordsnum;i++)
					{
					savesearch[i]=new char[40];
					}
				 makewords(search,savesearch,wordsnum); 
				 for(int i=0;i<wordsnum;i++)//把所有输入的单词都查找一变
				 {
					if(strlen(savesearch[i])!=0)
					 wtget=giveID(savesearch[i]);
					 if (outresult.is_open()) 
					outresult<<savesearch[i]<<" ";
					if(wtget!=-1)
					tree.search(tree.head,wtget,record);
				 }
				 record=record->next;
				 if(record!=NULL)//输出得到的数据
				 {
				 sort(record); 
				 while(1)
				 {
					 if(record==NULL)
					 {
						 break;
					 }
					 else
					 cout<<"("<<record->DocID<<","<<record->DocTime<<") ";
					 if (outresult.is_open())   
						{  
							outresult <<"("<<record->DocID<<","<<record->DocTime<<") ";  
						}
					 tp=record;
					 record=record->next;
					 delete(tp);
				 }
				 }
				 record=new Doc;
				 for(int i=0;i<wordsnum;i++)
				 {
				 memset(savesearch[i],NULL,sizeof(char[40]));//为下次搜索初始化
				 delete(savesearch[i]);
				 memset(search,NULL,sizeof(search));
				 }		
				  if (outresult.is_open())   
						{  
							outresult <<"\n\n";  
						}
			 }	
			 	outresult.close();  
		  cout<<"Get result successfully"<<endl;
}
int giveID(char *str)//查找输入的单词的ID
{
	 Hash *q;
		q=&tp[abs(str[0]*10+str[1])%10000];	
		   while(1)		
		{
			if(q==NULL)	//如果我输入的单词不在词典里
				{
				cout<<"No Words \""<<str<<"\" in these url"<<endl;	
				return -1;
				}

			if(strcmp(str,q->voca)==0)
			{
				if(q->HashID==NULL)	//如果我输入的单词没有出现过
				{
					cout<<"No Words \""<<str<<"\" in these url"<<endl;
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
