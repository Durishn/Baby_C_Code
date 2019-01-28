/*********************************************************************
 * FILE NAME: StackImplementation.c
 * PURPOSE: Stack implementation of the int Stack ADT.
 * AUTHOR: N.Durish (CIS2520, Assignment 2)
 * DATE: 10/10/2013
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only these static functions will need to be modified
 *          if the type of the list items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the List ADT changes.
 *        . As we will see, there is a better way to check whether
 *          the preconditions and postconditions are met.
 *********************************************************************/


#include "StackInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

void Initialize (Stack *S) {
  
  S->size=0;
	S->first=NULL;
	
  assert ((Empty(S) == 1) && (Full(S) == 0) && (Size(S) == 0));
}


void Push (Item X, Stack *S) {
  
  assert((Full(S) == 0));
  int length = Size(S);
  
  StackNode *q;
	S->size++;
	q=(StackNode *)malloc(sizeof(StackNode));
  q->item = X;
			 
	q->next=S->first;
	S->first=q;
  
	assert ((Empty(S) == 0) && (Size(S) == length + 1)); 
}


void Pop (Stack *S) {

  assert(Empty(S) == 0);

  int length = Size(S);
 	StackNode *q;
  S->size--;
 	q = S->first;
 	S->first = q->next;
  
  free(q);
  
 	assert ((Full(S) == 0) && (Size(S) == length - 1));
}


int Full (Stack *S) {
  return 0;
}


int Empty (Stack *S) {
  return S->size == 0;
}


int Size (Stack *S) {
  return S->size;
}


void Top (Stack *S, Item *X) {
  
  assert (Empty(S) == 0);
  
	StackNode *p = S->first;
  *X = p->item;
}


void Destroy (Stack *S) {
  
  int i;
	StackNode *p, *q;
	
	p=S->first;
	for(i=0;i<S->size;i++) {
		q=p;
		p=p->next;
		free(q);
	}
}

