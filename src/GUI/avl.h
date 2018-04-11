#ifndef AVL_H
#define AVL_H
#include"term.h"
class AVLTree
{
public:
	Term *head;
	Term *insert(Term *root,Term *key);
    void search(Term *head, int id,Doc *record);
	Term *Adjust(Term *head,Term *key);
	Term *Remove();
	void Edit(Term *head);
	AVLTree()
	{
		head=NULL;
	}
};


#endif
