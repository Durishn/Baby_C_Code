/*********************************************************************
 * FILE NAME: ListImplementation.c
 * PURPOSE: One-way linked implementation of the Student List ADT.
 * AUTHOR: N.Durish (CIS2520, Assignment 2)
 * DATE: 10/10/2013
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only the first two functions will need to be modified
 *          if the type of the list items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the List ADT changes.
 *        . For preconditions and postconditions,
 *          see the sequential implementation (no changes).
 *********************************************************************/


#include "ListInterface.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>


static void copyItem (Item *Y, Item X) {
	InitializeStudent(NameOfStudent(X),GradeOfStudent(X),Y);
}


static void destroyItem (Item *X) {
	FreeStudent(X);
}


static ListNode *moveTo (int position, List *L) {
	int i;
	ListNode *p=L->first;
	for(i=0;i<position;i++) p=p->next;
	return p;
}


void Initialize (List *L) {
	L->size=0;
	L->first=NULL;
	
  assert ((Empty(L) == 1) && (Full(L) == 0) && (Length(L) == 0));
}


void Insert (Item X, int position, List *L) {
  
  assert((position >= 0) && (position <= Length(L)) && (Full(L) == 0));
  
  int length = Length(L);
	ListNode *p, *q;
	
	L->size++;
	q=(ListNode *)malloc(sizeof(ListNode));
	copyItem(&q->item,X);
			 
	if(position==0) {
		q->next=L->first;
		L->first=q;
	}
	else {
		p=moveTo(position-1,L);
		q->next=p->next;
		p->next=q;
	}
	
  Item S;
  Peek(position, L, &S);
	assert ((Empty(L) == 0) && (Length(L) == length + 1) && (strcmp(X.name, S.name) == 0)); 
  FreeStudent(&S);
}


void Remove (int position, List *L) {
  
  assert((position >= 0) && (position < Length(L)) && (Empty(L) == 0));
  
  int length = Length(L);
	ListNode *p, *q;
	
	if(position==0) {
		q=L->first;
		L->first=q->next;
	}
	else {
		p=moveTo(position-1,L);
		q=p->next;
		p->next=q->next;
	}
	
	destroyItem(&q->item);
	free(q);
	L->size--;
	
	assert ((Full(L) == 0) && (Length(L) == length - 1));
}


int Full (List *L) {
	return 0;
}


int Empty (List *L) {
	return L->size==0;
}


int Length (List *L) {
	return L->size;
}


void Peek (int position, List *L, Item *X) {
  
  assert ((position >= 0) && (position < Length(L)) && (Empty(L) == 0));
  
	ListNode *p;
	p=moveTo(position,L);
	copyItem(X,p->item);
}


void Destroy (List *L) {
	int i;
	ListNode *p, *q;
	
	p=L->first;
	for(i=0;i<L->size;i++) {
		q=p;
		p=p->next;
		destroyItem(&q->item);
		free(q);
	}
}

