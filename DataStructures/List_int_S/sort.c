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


static void showListContent (List *L) {
	int i;
  int listInt;
	for(i=0;i<Length(L);i++) {
		Peek(i,L,&listInt);
		printf("%d ",listInt);
	}
}			   

int main(int argc, char * argv[]) {
  
  /*Initialize Variables*/
  FILE *test;
	int listNode, position, grade;
  float bubbleSort1RT, bubbleSort2RT, mergeSortRT;
  float fastBS1RT =1 , fastBS2RT=1 , fastMSRT=1;
  float slowBS1RT=0 , slowBS2RT=0 , slowMSRT=0;
  float avBS1RT=0 , avBS2RT=0 , avMSRT=0;
  int m, n, i, j;
  int * list;
	List BS1L, BS2L, MSL; 
	
	/*Check for correct command-line input*/
	if (argc != 3){
    printf("Please include parameters in the command line\n");
    printf("type: ./sort.out <number_of_lists> <size_of_lists>\n");
    exit(0);
	}
	if((sscanf(argv[1], "%d", &i) == 0) || (sscanf(argv[2], "%d", &i) == 0)){
    printf("Command Line Parameters must be integers\n");
    exit(0);	  
	}
  m = atoi(argv[1]);
  n = atoi(argv[2]);
	
	
	
	/*Populate Lists*/
  for(i=0;i<m;i++){
    Initialize(&BS1L);
    Initialize(&BS2L);
    Initialize(&MSL);
    if (i==0){
      for(j=1;j<=n;j++){
        Insert(j, Length(&BS1L), &BS1L);
        Insert(j, Length(&BS2L), &BS2L);
        Insert(j, Length(&MSL), &MSL);
      }
    }
    else if (i==1){
      for(j=n;j>=1;j--){
        Insert(j, Length(&BS1L), &BS1L);
        Insert(j, Length(&BS2L), &BS2L);
        Insert(j, Length(&MSL), &MSL);
      } 
    }
    else {
      for(j=1;j<=n;j++){
        Insert(j, Length(&BS1L), &BS1L);
        Insert(j, Length(&BS2L), &BS2L);
        Insert(j, Length(&MSL), &MSL);
      }
      Randomize(&BS1L);
      Randomize(&BS2L);
      Randomize(&MSL);
    }
    
   /*Print List & run sort tests*/
   /*NEED TO TAKE OUT PRINT STATEMENTS AND SHOWLISTCONTENT CALL*/
   printf("List: ");
   showListContent(&BS1L);   
   bubbleSort1RT = testBubbleSort1(&BS1L);
   printf("\nBubbleSort1 in %f seconds\n", bubbleSort1RT);
 	 bubbleSort2RT = testBubbleSort2(&BS2L);
   printf("BubbleSort2 in %f seconds\n", bubbleSort2RT);
   mergeSortRT= testMergeSort(&MSL);
   printf("MergeSort in %f seconds\n", mergeSortRT);
   
   /*Summate Average*/
   avBS1RT=avBS1RT+bubbleSort1RT;
   avBS2RT=avBS2RT+bubbleSort2RT;
   avMSRT=avMSRT+mergeSortRT;
   
   /*Compare Fastest*/
   if (bubbleSort1RT<fastBS1RT)
     fastBS1RT = bubbleSort1RT;
   if (bubbleSort2RT<fastBS2RT)
     fastBS2RT = bubbleSort2RT;
   if (mergeSortRT<fastMSRT)
     fastMSRT = mergeSortRT;
     
   /*Compare Slowest*/
   if (bubbleSort1RT>slowBS1RT)
     slowBS1RT = bubbleSort1RT;
   if (bubbleSort2RT>slowBS2RT)
     slowBS2RT = bubbleSort2RT;
   if (mergeSortRT>slowMSRT)
     slowMSRT = mergeSortRT;     
   
   /*Destroy Lists*/
   Destroy(&BS1L);
   Destroy(&BS2L);
   Destroy(&MSL);
  }
  
  /*Divide Averages*/
  avBS1RT=avBS1RT/m;
  avBS2RT=avBS2RT/m;
  avMSRT=avMSRT/m;

  /*Print Results*/
  printf("BubbleSort1\n");
  printf("%f sec\n%f sec\n%f sec\n",fastBS1RT, avBS1RT, slowBS1RT);
  printf("BubbleSort2\n");
  printf("%f sec\n%f sec\n%f sec\n",fastBS2RT, avBS2RT, slowBS2RT);
  printf("MergeSort\n");
  printf("%f sec\n%f sec\n%f sec\n",fastMSRT, avMSRT, slowMSRT);
	
	return EXIT_SUCCESS;
}

