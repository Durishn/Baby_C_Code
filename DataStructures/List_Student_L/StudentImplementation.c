/*********************************************************************
 * FILE NAME: StudentImplementation.c
 * PURPOSE: A second implementation of the Student ADT.
 * AUTHOR: N.Durish (CIS2520, Assignment 2)
 * DATE: 10/10/2013
 * NOTES: For preconditions and postconditions,
 *        see the first implementation (no changes).
 *********************************************************************/


#include "StudentInterface.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>


void InitializeStudent (char *name, int grade, Student *S) {
	S->name=(char *)malloc(strlen(name)+1);
	strcpy(S->name,name); 
	S->grade=grade;
	
  assert ((strcmp(NameOfStudent(*S),name) == 0) && (GradeOfStudent(*S) == grade));
}


char *NameOfStudent (Student S) {
	static char *name=NULL;
	name=realloc(name,strlen(S.name)+1);
	strcpy(name,S.name);
	return name;
}


int GradeOfStudent (Student S) {
	return S.grade;
}


void FreeStudent (Student *S) {
	free(S->name);
}
