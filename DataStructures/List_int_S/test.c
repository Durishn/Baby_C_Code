/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for Student List implementations.
 * AUTHOR: N.Durish (CIS2520, Assignment 3)
 * DATE: 06/11/2013
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). 
 * REFERENCES: P. Matsakis CIS2520 Assignment 1.
 *********************************************************************/


#include "ListInterface.h"
#include <stdio.h>
#include <stdlib.h>

/*Print List Contents*/
static void showListContent (List *L) {
	int i;
  int listInt;
	for(i=0;i<Length(L);i++) {
		Peek(i,L,&listInt);
		printf("%d ",listInt);
	}
}			   

int main(void) {
  
  /*Initialize Variables*/
  FILE *test;
	int listNode;
	int position, grade;
  float bubbleSort1RT, bubbleSort2RT, mergeSortRT;	
	List L1, L2, L3; 
	
	/*Initialize Lists*/
	Initialize(&L1);
	Initialize(&L2);
	Initialize(&L3);
	
	/*Open File and write integers into Lists*/
	test=fopen("test.txt","r");
  while (!feof (test))
    {  
      fscanf (test, "%d", &listNode); 
      Insert(listNode, Length(&L1), &L1);
      Insert(listNode, Length(&L2), &L2); 
      Insert(listNode, Length(&L3), &L3);      
    }
  fclose(test);	
  
  /*Test Sorting and print results*/
  showListContent(&L1);
  printf("to sort\n"); 
  bubbleSort1RT = testBubbleSort1(&L1);
  showListContent(&L1);
  printf("BubbleSort1 in %f seconds\n", bubbleSort1RT);
	bubbleSort2RT = testBubbleSort2(&L2);
  showListContent(&L2);
  printf("BubbleSort2 in %f seconds\n", bubbleSort2RT);  
  mergeSortRT= testMergeSort(&L3);
  showListContent(&L3);
  printf("MergeSort in %f seconds\n", mergeSortRT);
  
	Destroy(&L1);
	return EXIT_SUCCESS;
}

