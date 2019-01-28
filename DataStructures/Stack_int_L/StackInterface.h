/*********************************************************************
 * FILE NAME: StackInterface.h
 * PURPOSE: Interface of the int Stack ADT
 * AUTHOR: N. Durish (CIS2520, Assignment 2)
 * DATE: 13/09/2013
 * NOTES:   -In the following,
 *          the word Item may be replaced by the word int.
 *********************************************************************/
#include "StackType.h"

/*********************************************************************
 * FUNCTION NAME: Initialize
 * PURPOSE: Sets a List variable to the empty Stack.
 * ARGUMENTS: The address of the Stack variable to be initialized 
 *            (Stack *) 
 * ENSURES (postconditions):
 *          . Empty will return true (a nonzero integer).
 *          . Full will return false (0).
 *          . Length will return 0.
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Stack variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void Initialize (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Push
 * PURPOSE: Inserts an Item into the front of a Stack.
 * ARGUMENTS: . The Item to be inserted (Item) 
 *            . The address of the Stack (Stack *S)
 * REQUIRES (preconditions):
 *            . The List should not be full.
 * ENSURES: . Empty will return false (0).
 *          . Length will return the first integer greater
 *            than the length of the List before the call.
 *********************************************************************/
extern void Push (Item X, Stack *S);

/*********************************************************************
 * FUNCTION NAME: Pull
 * PURPOSE: Removes an Item from the front of a Stack.
 * ARGUMENTS: . The address of the List (List *L)
 * REQUIRES: . The Stack should not be empty.
 * ENSURES: . Full will return false (0).
 *          . Length will return the first integer lower
 *            than the length of the Stack before the call.
 *********************************************************************/
extern void Pop (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Full
 * PURPOSE: Determines whether a Stack is full.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: True (a nonzero integer) if the List is full,
 *          false (0) otherwise
 *********************************************************************/
extern int Full (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Empty
 * PURPOSE: Determines whether a Stack is empty.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: True (a nonzero integer) if the Stack is empty,
 *          false (0) otherwise
 *********************************************************************/
extern int Empty (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Length
 * PURPOSE: Finds the size of a Stack.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: The size of the Stack (int)
 *********************************************************************/
extern int Size (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Top
 * PURPOSE: Returns the first element in the Stack without removing it.
 * ARGUMENTS: . The address of the Stack (Stack *S)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES: . The Stack should not be empty.
 *********************************************************************/
extern void Top (Stack *S, Item *X);

/*********************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: Frees memory that may have been allocated
 *          by Initialize, Insert or Remove.
 * ARGUMENTS: The address of the Stack to be destroyed (Stack *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void Destroy (Stack *S);


