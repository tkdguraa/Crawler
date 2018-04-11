#include"Term.h"
#include"AVL.h"
#include"Term.h"

#include<iostream>
using namespace std;
extern int total;

int MAX(int a,int b)//��maxֵ
{
	if (a>b)
		return a;
	else 
		return b;
}
int IFNULL(Term *root)//���ظ߶ȣ���Ϊ��NULL��
{
	if(root==NULL)
		return -1;
	else
		return root->height;
}
Term* AVLTree::insert(Term *root,Term *key)
{
	if(root==NULL)
	{
		root=key;
		return root;
	}
	else if(key->ID<root->ID)
		root->lchild=insert(root->lchild,key);//����ƽ�������ص㣬��������ֵС�ڽڵ㣬��ô�����ƶ�
	else if(key->ID>root->ID)
		root->rchild=insert(root->rchild,key);
	else if(key->ID==root->ID)
	{
		//root->Edit(root->Docinfo,total);
		root->Docinfo->Edit(root->Docinfo,total);//�������ӵĵ����Ѿ������д�����ô������
		return root;
	}
	root->height=MAX(IFNULL(root->rchild),IFNULL(root->lchild))+1;//��߶�
	if(IFNULL(root->lchild)-IFNULL(root->rchild)>1)
	{
		if(key->ID<root->lchild->ID)
			root= root->rotatell(root);
		else
			root= root->rotatelr(root);
	}
	else if(IFNULL(root->rchild)-IFNULL(root->lchild)>1)
	{
		if(key->ID<root->rchild->ID)
			root=root->rotaterl(root);
		else
			root=root->rotaterr(root);
	}
	return root;
}
void AVLTree::search(Term *head,int id,Doc *record)
{
	Term *p;
	p=head;
	Doc *tmp;
	tmp=new Doc;
	while(1)
	{
		if(p->ID==id)
		{
			tmp=p->Docinfo;
			cout<<p->name;
			while(1)
			{
				if(tmp==NULL)
				{
					//p->Edit(p);
					return;
				}
				record->add(record,tmp);//�ҵ��������ĵ��ʣ�������������
				tmp=tmp->next;
			}
		}
		else if(p->ID<id)//������ҵ�ID�����еĴ���ô�����ƶ�
		{
			p=p->rchild;
		}
		else if(p->ID>id)//��֮�����ƶ�
		{
			p=p->lchild;
		}
	}
}
void AVLTree::Edit(Term *root)
{
	Term *tmp;
	tmp=root;
	while(1)
	{
		if(tmp->Docinfo!=NULL)
		{
			tmp->DF=tmp->DF++;
			tmp->Occur=tmp->Occur+tmp->Docinfo->DocTime;//����Ѿ�������ô������
		}
		if(tmp->Docinfo==NULL)
			break;
		tmp->Docinfo=tmp->Docinfo->next;
	}
}
Term * AVLTree::Adjust(Term *root,Term *key)//����������
{
	if(IFNULL(root->lchild)-IFNULL(root->rchild)>1)
	{
		if(key->ID<root->lchild->ID)
			root= root->rotatell(root);
		else
			root= root->rotatelr(root);
	}
	else if(IFNULL(root->rchild)-IFNULL(root->lchild)>1)
	{
		if(key->ID<root->rchild->ID)
			root=root->rotaterl(root);
		else
			root=root->rotaterr(root);
	}
	return root;
}
Term* AVLTree::Remove(Term* root, Term *key)
{
	if(!root)
		return NULL;
	if(root->ID == root->ID)
	{
		if(root->rchild == NULL)
		{
			Term* temp = root;
			root = root->lchild;
			delete(temp);
			return root;
		}
		else
		{
			Term* temp = root->rchild;
			while(temp->lchild)
				temp = temp->lchild;
			//����
			root->ID = temp->ID;
			//ɾ���ڵ�
			root->rchild = Remove(root->rchild, temp);
		}
	}
	else if(key->ID < root->ID)
		root->lchild = Remove(root->lchild, key);
	else
		root->rchild = Remove(root->rchild, key);
	
	root->height = MAX(IFNULL(root->lchild), IFNULL(root->rchild)) + 1;//��߶�
	if(IFNULL(root->rchild) - IFNULL(root->lchild) == 2)//�������ĸ߶ȵ���������״
	{
		if(IFNULL(root->rchild->rchild) >= IFNULL(root->rchild->lchild))
			root = root->rotatell(root);
		else
			root = root->rotaterl(root);
	}
	else if(IFNULL(root->lchild) - IFNULL(root->rchild) == 2)
	{
		if(IFNULL(root->lchild->lchild) >= IFNULL(root->lchild->rchild))
			root = root->rotaterr(root);
		else
			root = root->rotatelr(root);
	}
	return root;
}
