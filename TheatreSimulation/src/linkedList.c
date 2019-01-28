/***************************************linkedList.c***************************************
Student Name: Nic Durish                        Student Number:  0757227
Date: April 3, 2013                         Course Name: Intermediate Programming
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
*******************************************************************************************/
#include "linkedList.h"

/*******************
*Patron Functions *
*******************/

Patron * createPatron(char * id, bool movie, bool snack, int time) {
	
  /*Initialize a Patron pointer; newPatron and malloc memory*/
  Patron * newPatron;
  newPatron = malloc(sizeof(Patron));
  
  /*If id is NULL set id to '0NULL0' malloc some memory and copy it into the newPatron struct*/
  if (id == NULL){
    id = "0NULL0";
  }
  newPatron->id = malloc(sizeof(char*)*(6+1));
  strcpy(newPatron->id, id);

  /*If movie is less than 0 or larger than 1 set it to 0*/
  if ((movie < 0) || (movie > 1))
    movie = 0;
  newPatron->movie = movie;
	  
  /*If snack is less than 0 or larger than 1 set it to 0*/
  if ((snack < 0) || (snack > 1))
    snack = 0;
  newPatron->snack = snack;

  /*If time is less than 0 set time to 0 and return newPatron*/
  if (time < 0)
    time = 0;
  newPatron->time = time;
	
  return(newPatron);
}

char * getID(Patron * thePatron) {
  
  /*Initialize id. if the Patron or the next Patron are NULL set id to '0NULL0'
  * else set id to thePatron's id. Return ID*/
  char * id;
  if ((thePatron == NULL) || (thePatron->id == NULL))
    id = "0NULL0";
  else 
    id = thePatron->id;
  return id;
}

int getTime(Patron * thePatron){
  
  /*Initialize time. if the Patron is NULL set time to 0
  * else set time to thePatron's time. Return time*/
  int time;
  if ((thePatron == NULL))
    time = 0;
  else 
    time = thePatron->time;
  return time; 
}

bool getMovie(Patron * thePatron){
  
  /*Initialize movie the Patron is NULL set movie to 0
  * else set movie to thePatron's movie. Return movie*/
  bool movie;
  if ((thePatron == NULL))
    movie = 0;
  else 
    movie = thePatron->movie;
  return movie;
}

bool getSnack(Patron * thePatron){
  
  /*Initialize snack. if the Patron is NULL set snack to 0
  * else set snack to thePatron's snack. Return snack*/
  bool snack;
  if ((thePatron == NULL))
    snack = 0;
  else 
    snack = thePatron->snack;
  return snack;
}

void destroyPatron(Patron * thePatron){

  /*If thePatron is not NULL. If thePatron id is not NULL free thePatron id
  * Then set the Patrons movie snack and time value to 0*/
  if (thePatron != NULL) {
    if (thePatron->id != NULL) 
      free(thePatron->id);
    thePatron->movie = 0;
    thePatron->snack = 0;
    thePatron->time = 0;
  }
}

Patron * getNextPatron(Patron * thePatron){
  
  /*Initialize nextPatron, then set nextPatron to the patron after  thePatron
  *If the patron or nextPatron is NULL return NULL. Else return nextPatron*/
  Patron * nextPatron;
  nextPatron = thePatron->next;
  if ((thePatron == NULL) || (nextPatron == NULL))
    return NULL; 
  return nextPatron;

}

/************************
* Linked List Functions *
************************/

bool isEmpty(ListHeadPtr theList) {
  
  if ((theList->next == NULL) && (theList->id == NULL) && (theList->movie == 0) 
  && (theList->snack == 0) && (theList->time == 0))
    return true;
  return false;
}

ListHeadPtr addToFront(ListHeadPtr theList, Patron * toBeAdded) {
  
  if ((toBeAdded->id != NULL) && (toBeAdded != NULL)) {
    toBeAdded->next = theList;
    theList = toBeAdded;
  }
  return theList;
}

ListHeadPtr removeFromFront(ListHeadPtr theList){
  
  Patron * tempPatron;
  tempPatron = theList;
  
  if (theList->next == NULL )
    return NULL;
    
  theList = theList->next;
  tempPatron->next = NULL;
  return theList;
  
}

Patron * getFront(ListHeadPtr theList){
  return theList;
}

ListHeadPtr addToBack(ListHeadPtr  theList, Patron * toBeAdded){
  
  Patron * index;
  index = theList;
  
  if ((theList == NULL) || (theList->id == NULL))
    return toBeAdded;
    
  if ((toBeAdded->id != NULL) && (toBeAdded != NULL)) {
    while (index->next != NULL)
      index = index->next;
    index->next = toBeAdded;
  }
  return theList;
  
}

ListHeadPtr removeFromBack(ListHeadPtr  theList){
  
  Patron * index;
  index = theList;
  
  if ((theList->next == NULL) || (theList == NULL))
    return NULL;
  
  while ((index->next)->next != NULL)
    index = index->next;
  destroyPatron(index->next);
  index->next = NULL;
  return theList;
  
}

Patron * getBack(ListHeadPtr theList){
  
  Patron * index;
  index = theList;
  if(theList == NULL)
    return NULL;
  while (index->next != NULL)
    index = index->next;
  return index;
}

char * printList(ListHeadPtr  theList){
  
  
  Patron * index;
  int length;
  char * patronList;
  
  if ((theList == NULL) || (theList->id == NULL))
    return NULL;
  
  length = 1;
  index = theList;
  
  while (index->next != NULL){
    length++;
    index = index->next;
  }
  
  patronList = malloc(sizeof(char)*(7*length));
  index = theList;
    
  strcpy(patronList, index->id);
  strcat(patronList, "\n");
  while (index->next != NULL){
    index = index->next;
    strcat(patronList, index->id);
    strcat(patronList, "\n"); 
  }
  return patronList;
}

int length(ListHeadPtr theList){
  
  int length;
  Patron * index;
  
  if ((theList == NULL) || ((theList->id == NULL) && (theList->next == NULL)))
    return 0;
    
  length = 1;
  index = theList;
  while (index->next != NULL){
    length++;
    index = index->next;
  }
  
  return length;
}

void destroyPatronList(ListHeadPtr theList){
  
  Patron * index, * toDestroy;
  index = theList;
  if (theList->id != NULL){
    while(index != NULL){
      toDestroy = index;
      index = toDestroy->next;
      destroyPatron(toDestroy);
      free(toDestroy);
    } 
  }
}