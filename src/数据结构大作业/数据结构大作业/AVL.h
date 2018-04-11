#ifndef AVL_H
#define AVL_H
#include"Term.h"
class AVLTree
{
public:
	Term *head;
	Term *insert(Term *root,Term *key);
	void search(Term *head, int id,Doc *record);
	Term *Adjust(Term *head,Term *key);
	Term *Remove(Term *root,Term *key);
	void Edit(Term *head);
	AVLTree()
	{
		head=NULL;
	}
};


#endif