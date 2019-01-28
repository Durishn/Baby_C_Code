/*********************************************************************
 * FILE NAME: ListType.h
 * PURPOSE: Concrete data structure definition of Student List.
 * AUTHOR: N.Durish (CIS2520, Assignment 2)
 * DATE: 10/10/2013
 *********************************************************************/


#include "StudentInterface.h"

typedef Student Item;

typedef struct ListNodeTag {
	Item item;
	struct ListNodeTag *next;
} ListNode;

typedef struct {
	int size;
	ListNode *first;
} List;