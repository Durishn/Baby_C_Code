/*********************************************************************
 * FIQE NAME: QueueImplementation.c
 * PURPOSE: Sequential implementation of the Student Queue ADT.
 * AUTHOR: N.Durish (CIS2520, Assignment 3)
 * DATE: 06/11/2013
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only these static functions will need to be modified
 *          if the type of the Queue items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the Queue ADT changes.
 *        . As we will see, there is a better way to check whether
 *          the preconditions and postconditions are met.
 * REFERENCES: P. Matsakis CIS2520, Assignment 3
 *********************************************************************/


#include "QueueInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define DEBUG


static void copyItem (Item *Y, Item X) {
	InitializeStudent(NameOfStudent(X),GradeOfStudent(X),Y);
}


static void destroyItem (Item *X) {
	FreeStudent(X);
}


static int equalItems (Item X, Item Y) {
	/* Why couldn't we write the following?
	   if(strcmp(NameOfStudent(X),NameOfStudent(Y))!=0 ||
	      GradeOfStudent(X)!=GradeOfStudent(Y)) return 0;
	   else return 1; */
	int i;
	char *s;
	s=(char *)malloc(strlen(NameOfStudent(X))+1);
	strcpy(s,NameOfStudent(X));
	i=strcmp(s,NameOfStudent(Y));
	free(s);
	if(i!=0 || GradeOfStudent(X)!=GradeOfStudent(Y)) return 0;
	else return 1;
}


void Initialize (Queue *Q) {
	Q->size=0;
  Q->head=0;
#ifdef DEBUG
	if(!Empty(Q) || Full(Q) || Size(Q)!=0) {
		printf("Violated postcondition for Initialize!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Enqueue (Item I, Queue *Q) {
#ifdef DEBUG
	int oldSize=Size(Q);
	if(Full(Q)) {
		printf("Violated precondition for Insert!\n");
		exit(EXIT_FAILURE);
	}
#endif
  
  copyItem(&Q->items[((Q->head + Q->size)%MAXQUEUESIZE)],I);
  Q->size++;

#ifdef DEBUG
	Item Y;
	Tail(Q,&Y);
	if(Empty(Q) || Size(Q)!=oldSize+1 || !equalItems(I,Y)) {
		printf("Violated postcondition for Insert!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Dequeue ( Queue *Q) {
#ifdef DEBUG
	int oldSize=Size(Q);
	if(Empty(Q)) {
		printf("Violated precondition for Remove!\n");
		exit(EXIT_FAILURE);
	}
#endif

  destroyItem(&Q->items[Q->head]);
  Q->head = (Q->head + 1)%MAXQUEUESIZE;
  Q->size--;
	
#ifdef DEBUG
	if(Full(Q) || Size(Q)!=oldSize-1) {
		printf("Violated postcondition for Remove!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


int Full (Queue *Q) {
	return Q->size==MAXQUEUESIZE;
}


int Empty (Queue *Q) {
	return Q->size==0;
}


int Size (Queue *Q) {
	return Q->size;
}


void Head (Queue *Q, Item *X) {

	copyItem(X,Q->items[Q->head]);
}

void Tail (Queue *Q, Item *X) {
#ifdef DEBUG
	if(Empty(Q)) {
		printf("Violated precondition for Tail!\n");
		exit(EXIT_FAILURE);
	}
#endif
	copyItem(X,Q->items[((Q->head + Q->size -1)%MAXQUEUESIZE)]);
}

void Destroy (Queue *Q) {
	int i;
	for(i=0;i<Q->size;i++)
		destroyItem(&Q->items[i]);
}

