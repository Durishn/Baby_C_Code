/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for Student Queue implementations.
 * AUTHOR: N.Durish (CIS2520, Assignment 3)
 * DATE: 06/11/2013
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). 
 * REFERENCES: P. Matsakis CIS2520, Assignment 3
 *********************************************************************/


#include "QueueInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void showQueueSize (Queue *L) {
	if(Empty(L)) printf("Queue is empty; ");
	else printf("Queue is not empty; ");
	if(Full(L)) printf("Queue is full; ");
	else printf("Queue is not full; ");
	printf("Queue is of length %d:\n",Size(L));
}
	
	
static void showQueueContent (Queue *L) {
	int i;
	Student S;
	for(i=0;i<Size(L);i++) {
		Head(L,&S);
		printf("\t%s %d%%\n",NameOfStudent(S),GradeOfStudent(S));
    Dequeue(L);
    Enqueue(S, L);
		FreeStudent(&S);
	}
}
			   

int main(void) {
  /*Initialize Variables*/
	FILE *test;
	char s[20];
	int grade;	
	Student S;
	Queue L; 
	
	/*Initialize List, and Show Queue*/
	Initialize(&L);
	showQueueSize(&L);
	showQueueContent(&L);
	
	/*Open File, scan and either Enqueue or Dequeue Student*/
	test=fopen("test.txt","r");
	while(fscanf(test,"%s",s)==1) {
		if(strcmp(s,"Enqueue")==0) {
			fscanf(test,"%s %d",s,&grade);
			InitializeStudent(s,grade,&S);
			Enqueue(S,&L);
			FreeStudent(&S);
		}
		if(strcmp(s,"Dequeue")==0)
			Dequeue(&L);
		showQueueSize(&L);
		showQueueContent(&L);
	}
	
	/*Close file, destroy list and return to OS*/
	fclose(test);
	Destroy(&L);
	return EXIT_SUCCESS;
}

