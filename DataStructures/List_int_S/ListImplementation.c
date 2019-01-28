/*********************************************************************
 * FILE NAME: ListImplementation.c
 * PURPOSE: Sequential implementation of the Student List ADT.
 * AUTHOR: N.Durish (CIS2520, Assignment 3)
 * DATE: 06/11/2013
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only these static functions will need to be modified
 *          if the type of the list items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the List ADT changes.
 *        . As we will see, there is a better way to check whether
 *          the preconditions and postconditions are met.
 * REFERENCES: P. Matsakis CIS2520 Assignment 1.
 *********************************************************************/


#include "ListInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <time.h>

#define DEBUG

static void destroyItem (int *X) {
}


static int equalItems (int X, int Y) {
  
	if(X!=Y) 
	  return 0;
	else 
	  return 1;
}


void Initialize (List *L) {
  
	L->size=0;
	
#ifdef DEBUG
	if(!Empty(L) || Full(L) || Length(L)!=0) {
		printf("Violated postcondition for Initialize!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Insert (int X, int position, List *L) {
  
#ifdef DEBUG
	int oldLength=Length(L);
	if(position<0 || position>oldLength || Full(L)) {
		printf("Violated precondition for Insert!\n");
		exit(EXIT_FAILURE);
	}
#endif

	int i;
	
	for (i=L->size; i>position; i--) { 
		L->items[i] = L->items[i-1];
		destroyItem(&L->items[i-1]);
	}
  L->items[position] = X;
	L->size++;
	
#ifdef DEBUG
	int Y;
	Peek(position,L,&Y);
	if(Empty(L) || Length(L)!=oldLength+1 || !equalItems(X,Y)) {
		printf("Violated postcondition for Insert!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Remove (int position, List *L) {
  
#ifdef DEBUG
	int oldLength=Length(L);
	if(position<0 || position>=oldLength || Empty(L)) {
		printf("Violated precondition for Remove!\n");
		exit(EXIT_FAILURE);
	}
#endif

	int i;
	
	L->size--;
	for (i=position; i<L->size; i++) {
		destroyItem(&L->items[i]);
		L->items[i] = L->items[i+1] ;
	}
	destroyItem(&L->items[L->size]);
	
#ifdef DEBUG
	if(Full(L) || Length(L)!=oldLength-1) {
		printf("Violated postcondition for Remove!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


int Full (List *L) {
  
	return L->size==MAXLISTSIZE;
}


int Empty (List *L) {
  
	return L->size==0;
}


int Length (List *L) {
  
	return L->size;
}


void Peek (int position, List *L, int *X) {
  
#ifdef DEBUG
	if(position<0 || position>=Length(L) || Empty(L)) {
		printf("Violated precondition for Peek!\n");
		exit(EXIT_FAILURE);
	}
#endif

  *X = L->items[position];
}


void Destroy (List *L) {
  
	int i;
	
	for(i=0;i<L->size;i++)
		destroyItem(&L->items[i]);
}


float testBubbleSort1 (List *L){
  
  float sec;
  clock_t t1, t2;
  t1=clock();
  BubbleSort1(L);
  t2=clock();
  sec=(t2-t1)/(float)CLOCKS_PER_SEC;
  return sec;
}


void BubbleSort1 (List *L){
  
  int j, i, temp;
  
  for (j=1; j<=(Length(L)-1); j++){
    for (i=1; i<=(Length(L)-j);i++){
      if (L->items[i-1] > L->items[i]){
        temp = L->items[i-1];
        L->items[i-1] = L->items[i];
        L->items[i] = temp;
      }
    }
  }
}


float testBubbleSort2 (List *L){
  
  float sec;
  clock_t t1, t2;
  t1=clock();
  BubbleSort2(L);
  t2=clock();
   sec=(t2-t1)/(float)CLOCKS_PER_SEC;
  return sec;
}


void BubbleSort2 (List *L){
  
  int swapped,i,k, temp;
  
  k= Length(L);
  do {
    swapped = 0;
    for (i=1; i<=(k-1); i++){
      if (L->items[i-1] > L->items[i]){
        temp = L->items[i-1];
        L->items[i-1] = L->items[i];
        L->items[i] = temp;
        swapped = 1;
      }
    }
  } while (swapped == 1); 
}


float testMergeSort (List *L){
  
  float sec;
  clock_t t1, t2;
  t1=clock();
  MergeSort(L, 0, Length(L)-1);
  t2=clock();
   sec=(t2-t1)/(float)CLOCKS_PER_SEC;
  return sec;
}


void MergeSort (List *A, int first, int last){

  if (first<last){
    int middle = floor((first+last)/2);
    MergeSort(A, first, middle);
    MergeSort(A, middle+1, last);
    Merge (A, first, middle, last);
  }
}


void Merge (List *A, int first, int middle, int last){

  int i, j, k;
  List L, R;
  
  Initialize (&L);
  Initialize (&R);
  
  for(i=0;i<=(middle-first);i++)
    L.items[i] = A->items[first+i];
  L.items[middle-first +1] = 9999;
  for(j=0;j<=(last-middle-1);j++)
    R.items[j]= A->items[middle+j+1];
  R.items[last-middle] = 9999;
  i = j = 0;
  for(k=first;k<=last;k++){
    if (L.items[i]<=R.items[j]){
      A->items[k]=L.items[i];
      i++;
    }
    else {
      A->items[k]=R.items[j];
      j++;
    }
  }
}


void Randomize (List *L){
  
  int i, buffer, j;
  
  if (Length(L) > 1){
    for (i=0; i<Length(L); i++) {
            j = (rand()%(Length(L)))+1;        
            /*Swap Algorithm*/
            buffer = L->items[j];
            L->items[j] = L->items[i];
            L->items[i] = buffer;
    }
  }
}

