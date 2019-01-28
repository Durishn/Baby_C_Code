/*********************************************************************
 * FILE NAME: QueueInterface.h
 * PURPOSE: Interface of the Student Queue ADT
 * AUTHOR: N.Durish (CIS2520, Assignment 3)
 * DATE: 06/11/2013
 * NOTES: . If the user includes QueueInterface.h in a source file,
 *          they should not include StudentInterface.h. Including 
 *          both header files in the same source file would cause 
 *          a compilation error, because QueueInterface.h indirectly 
 *          includes StudentInterface.h, and the type Student would 
 *          therefore be defined twice. (As we will see, however,  
 *          there is a way to go around this.)
 *        . Peek calls InitializeStudent, and it is the user's
 *          responsibility to call FreeStudent when appropriate
 *          (see StudentInterface.h).
 *        . In the following,
 *          the word Item may be replaced by the word Student.
 * REFERENCES: P. Matsakis CIS2520, Assignment 3
 *********************************************************************/
#include "QueueType.h"

/*********************************************************************
 * FUNCTION NAME: Initialize
 * PURPOSE: Sets a Queue variable to the empty Queue.
 * ARGUMENTS: The address of the Queue variable to be initialized 
 *            (Queue *) 
 * ENSURES (postconditions):
 *          . Empty will return true (a nonzero integer).
 *          . Full will return false (0).
 *          . Length will return 0.
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Queue variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void Initialize (Queue *L);

/*********************************************************************
 * FUNCTION NAME: Enqueue
 * PURPOSE: Inserts an Item in a Queue.
 * ARGUMENTS: . The Item to be inserted (Item)
 *              where the Item should be inserted in (int) 
 *            . The address of the Queue (Queue *L)
 * REQUIRES (preconditions):
 *            . The Queue should not be full.
 * ENSURES: . Empty will return false (0).
 *          . Length will return the first integer greater
 *            than the length of the Queue before the call.
 *          . Tail will find the Item that was inserted.
 *********************************************************************/
extern void Enqueue (Item X, Queue *L);

/*********************************************************************
 * FUNCTION NAME: Dequeue
 * PURPOSE: Removes an Item from a Queue.
 * ARGUMENTS: . The address of the Queue (Queue *L)
 * REQUIRES: . The Queue should not be empty.
 * ENSURES: . Full will return false (0).
 *          . Length will return the first integer lower
 *            than the length of the Queue before the call.
 *********************************************************************/
extern void Dequeue (Queue *L);

/*********************************************************************
 * FUNCTION NAME: Full
 * PURPOSE: Determines whether a Queue is full.
 * ARGUMENTS: The address of the Queue (Queue *) 
 * RETURNS: True (a nonzero integer) if the Queue is full,
 *          false (0) otherwise
 *********************************************************************/
extern int Full (Queue *L);

/*********************************************************************
 * FUNCTION NAME: Empty
 * PURPOSE: Determines whether a Queue is empty.
 * ARGUMENTS: The address of the Queue (Queue *) 
 * RETURNS: True (a nonzero integer) if the Queue is empty,
 *          false (0) otherwise
 *********************************************************************/
extern int Empty (Queue *L);

/*********************************************************************
 * FUNCTION NAME: Size
 * PURPOSE: Finds the size of a Queue.
 * ARGUMENTS: The address of the Queue (Queue *) 
 * RETURNS: The size of the Queue (int)
 *********************************************************************/
extern int Size (Queue *L);

/*********************************************************************
 * FUNCTION NAME: Head
 * PURPOSE: Finds the Item at the head of the Queue.
 * ARGUMENTS: . The address of the Queue (Queue *L)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES: . The Queue should not be empty.
 *********************************************************************/
extern void Head (Queue *L, Item *X);

/*********************************************************************
 * FUNCTION NAME: Tail
 * PURPOSE: Finds the Item at the tail of the Queue.
 * ARGUMENTS: . The address of the Queue (Queue *L)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES: . The Queue should not be empty.
 *********************************************************************/
extern void Tail (Queue *L, Item *X);

/*********************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: Frees memory that may have been allocated
 *          by Initialize, Insert or Remove.
 * ARGUMENTS: The address of the Queue to be destroyed (Queue *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void Destroy (Queue *L);


