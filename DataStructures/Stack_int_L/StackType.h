/*********************************************************************
 * FILE NAME: StackType.h
 * PURPOSE: Concrete data structure definition of Int Stack.
 * AUTHOR: N. Durish (CIS2520, Assignment 2)
 * DATE: 10/10/2013
 *********************************************************************/

typedef int Item;

typedef struct StackNodeTag {
	Item item;
	struct StackNodeTag *next;
} StackNode;

typedef struct {
	int size;
	StackNode *first;
} Stack;