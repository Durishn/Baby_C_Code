/***************************************llTest.c***************************************
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
#include "llTest.h"

int main (int argc, char * argv[]) {
	
  int structPass = 0, llPass = 0, totalPass;
	
  printf("***************************************************************\n");
  printf("Welcome to the Linked List and Structure Function Tester\n");
  printf("Here You can perform different tests on LL & Struct functions\n\n");
  
  printf("Structure Functions:\n--------------------\n");
	structPass += createPatronTest();
  structPass += getIDTest();
  structPass += getTimeTest();
  structPass += getMovieTest();
  structPass += getSnackTest();
  structPass += destroyPatronTest();
  structPass += getNextPatronTest();

  
  printf("\nLinked List Functions:\n------------------------\n");
  llPass += isEmptyTest();
  llPass += addToFrontTest();
  llPass += removeFromFrontTest();
  llPass += getFrontTest();
  llPass += addToBackTest();
  llPass += removeFromBackTest();
  llPass += getBackTest();
  llPass += printListTest();
  llPass += lengthTest();
  llPass += destroyPatronListTest();
  
  totalPass = structPass + llPass;
  printf("***************************************************************\n");
  printf("Your functions passed:\n      %d/17 -Structure tests.\n", structPass);
  printf("      %d/25 -LinkedList tests.\n", llPass);
  printf("    Totalling to %d/42 tests.\n", totalPass);
  printf("***************************************************************\n");
	return 0;
}


int createPatronTest(void) {
	char * id;
	bool movie, snack;
	int time, pass=0;
	Patron * patron;
	
	printf("Testing 'createPatron':\n");
	
	/*Regular Values*/
  printf(" Regular Values\n");
	id = "123456", movie = 0, snack = 0, time = 120;
	if (DEBUG) {printf("  Function Input: %s,%d,%d,%d\n", id, movie, snack, time);}
	patron = createPatron(id, movie, snack, time);
	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
	, patron->id, patron->movie, patron->snack, patron->time);}
  if (((strcmp(patron->id, id)) == 0) && (patron->movie == movie) && 
  (patron->snack == snack) && (patron->time == time)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
	
	/*If id is NULL*/
  printf(" NULL id\n");
	id = NULL, movie = 0, snack = 0, time = 0;
	if (DEBUG) {printf("  Function Input: %s,%d,%d,%d\n", id, movie, snack, time);}
	patron = createPatron(id, movie, snack, time);
	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
	, patron->id, patron->movie, patron->snack, patron->time);}
	if (patron->id != NULL) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
		

	/*If movie, snack and time are negative*/
	printf(" Negative movie, snack and time values\n");
	id = "123456", movie = -999999, snack = -999999, time = -999999;
	if (DEBUG) {printf("  Function Input: %s,%d,%d,%d\n", id, movie, snack, time);}
	patron = createPatron(id, movie, snack, time);
	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
	, patron->id, patron->movie, patron->snack, patron->time);}
	if (((strcmp(patron->id, id)) == 0) && (patron->movie == 0) && 
	(patron->snack == 0) && (patron->time == 0)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}

	/*If movie and snack are large*/
	printf(" Large movie and snack values\n");
	id = "123456", movie = 999999, snack = 999999, time = 5000;
	if (DEBUG) {printf("  Function Input: %s,%d,%d,%d\n", id, movie, snack, time);}
	patron = createPatron(id, movie, snack, time);
	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
	, patron->id, patron->movie, patron->snack, patron->time);}
	if (((strcmp(patron->id, id)) == 0) && (patron->movie == 0) && 
	(patron->snack == 0) && (patron->time == time)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}

  printf("    %d/4 tests passed.\n\n", pass);
  return pass;
}

int getIDTest(void) {
	
  int pass = 0;
  char * id;
  Patron * patron, * nullPatron;
  
	printf("Testing 'getID':\n");
	
	/*Regular Values*/
  printf(" Regular Values\n");
  patron = createPatron("000000", 0, 0, 0);
	if (DEBUG) {printf("  Function Input: %s\n", patron->id);}
  id = getID(patron);
  if (DEBUG) {printf ("  Function Output: %s\n"	, id);}
  if (((strcmp(patron->id, id)) == 0)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
	
	/*Null Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
	if (DEBUG) {printf("  Function Input: %s\n", nullPatron->id);}
  id = getID(nullPatron);
  if (DEBUG) {printf ("  Function Output: %s\n"	, id);}
  if (strcmp(id, "0NULL0") == 0) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
	
	printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int getTimeTest(void) {
	
  int pass = 0;
  int time;
  Patron * patron, * nullPatron;
  
	printf("Testing 'getTime':\n");
	
	/*Regular Values*/
  printf(" Regular Values\n");
  patron = createPatron("111111", 0, 0, 48);
	if (DEBUG) {printf("  Function Input: %d\n", patron->time);}
  time = getTime(patron);
  if (DEBUG) {printf ("  Function Output: %d\n"	, time);}
  if (patron->time == time) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
		
	/*Null Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));;
	if (DEBUG) {printf("  Function Input: %d\n", nullPatron->time);}
  time = getTime(nullPatron);
  if (DEBUG) {printf ("  Function Output: %d\n"	, time);}
  if (time == 0) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
	
	printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int getMovieTest(void) {
	
  int pass = 0;
  bool movie;
  Patron * patron, * nullPatron;
  
	printf("Testing 'getMovie':\n");
	
	/*Regular Values*/
  printf(" Regular Values\n");
  patron = createPatron("222222", 1, 1, 0);
	if (DEBUG) {printf("  Function Input: %d\n", patron->movie);}
  movie = getMovie(patron);
  if (DEBUG) {printf ("  Function Output: %d\n"	, movie);}
  if (patron->movie == movie) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
	
	/*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));;
	if (DEBUG) {printf("  Function Input: %d\n", nullPatron->movie);}
  movie = getMovie(nullPatron);
  if (DEBUG) {printf ("  Function Output: %d\n"	, movie);}
  if (movie == 0) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
		
	printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int getSnackTest(void) {
	
  int pass = 0;
  bool snack;
  Patron * patron, * nullPatron;
  
	printf("Testing 'getSnack':\n");
	
	/*Regular Values*/
  printf(" Regular Values\n");
  patron = createPatron("333333", 0, 1, 0);
	if (DEBUG) {printf("  Function Input: %d\n", patron->snack);}
  snack = getSnack(patron);
  if (DEBUG) {printf ("  Function Output: %d\n"	, snack);}
  if (patron->snack == snack) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
	
	
	/*Null Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
	if (DEBUG) {printf("  Function Input: %d\n", nullPatron->snack);}
  snack = getSnack(nullPatron);
  if (DEBUG) {printf ("  Function Output: %d\n"	, snack);}
  if (snack == 0) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
	
	printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int destroyPatronTest(void){
  
  char * id;
  bool movie, snack;
  int time, pass = 0;
  Patron * thePatron, * nullPatron;
  
  printf("Testing 'destroyPatron':\n");
	
	/*Regular Values*/
  printf(" Regular Values\n");
  id = "333333", movie = 1, snack = 1, time = 64;
  thePatron = createPatron(id, movie, snack, time);
	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d\n"
	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
  destroyPatron(thePatron);
	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
  if ((thePatron->id != id) && (thePatron->movie == 0) && 
  (thePatron->snack == 0) && (thePatron->time == 0)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
  
	/*NULL Pointer*/
  printf(" NULL Values\n");
  id = NULL, movie = 0, snack = 0, time = 0;
  nullPatron = malloc(sizeof(Patron));
	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d\n"
	, id, movie, snack, time);}
  destroyPatron(nullPatron);
	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
	, nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  if ( (nullPatron->movie == 0) && 
  (nullPatron->snack == 0) && (nullPatron->time == 0)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
	}
	else {
    if (DEBUG) {printf("  fail\n");}  
	}
  
	printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int getNextPatronTest(void){
  
  int pass = 0;
  char * id;
  Patron * thePatron,* nextPatron, * endPatron, * nullPatron;
  
  printf("Testing 'getNextPatron':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  id = "444444";
  thePatron = createPatron(id, 1, 1, 49);
  nextPatron = createPatron("444555", 1, 1, 50);
  thePatron->next = nextPatron;
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
  , thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
  if (DEBUG) {printf ("%s,%d,%d,%d,noNext. \n"
  , nextPatron->id, nextPatron->movie, nextPatron->snack, nextPatron->time);}
  thePatron = getNextPatron(thePatron);
  if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d,noNext\n"
  , thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
  if (((strcmp(thePatron->id,id)) != 0)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
  
	/*NULL Next*/
  printf(" NULL Next\n");
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
  endPatron = getNextPatron(thePatron);
  if (DEBUG) {printf ("  Function Output: \n");}
  if (endPatron == NULL) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
  
  /*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  thePatron = getNextPatron(nullPatron);
  if (DEBUG) {printf ("  Function Output: \n");}
  if (thePatron == NULL) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
  
  printf("    %d/3 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int isEmptyTest(void){
  
  int pass = 0;
  bool empty;
  Patron * thePatron, * nextPatron, * nullPatron;
  
  printf("Testing 'isEmpty':\n");
  
  /*One Value*/
  printf(" One Node\n");
  thePatron = createPatron("555555", 1, 1, 82);
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext\n"
 	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
  empty = isEmpty(thePatron);
 	if (DEBUG) {printf ("  Function Output: %d\n"
 	, empty);}
   if (empty == false) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
  
  /*Regular Values*/
  printf(" Multiple Noded List\n");
  thePatron = createPatron("555555", 1, 1, 82);
  nextPatron = createPatron("555666", 1, 1, 22);
  thePatron->next = nextPatron;
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next\n"
 	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
  empty = isEmpty(thePatron);
 	if (DEBUG) {printf ("  Function Output: %d\n"
 	, empty);}
   if (empty == false) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
	/*NULL Pointer*/
  printf(" NULL List\n");
  nullPatron = malloc(sizeof(Patron));
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext\n"
 	, nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  empty = isEmpty(nullPatron);
 	if (DEBUG) {printf ("  Function Output: %d\n"
 	, empty);}
   if (empty == true) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
  
  printf("    %d/3 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int addToFrontTest(void){
  
  int pass = 0;
  Patron * thePatron, * addedPatron, * nullPatron, *list;

  printf("Testing 'addToFront':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  thePatron = createPatron("666666", 1, 1, 82);
  addedPatron = createPatron("777777", 1, 0, 32);
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
 	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
 	if (DEBUG) {printf ("%s,%d,%d,%d. \n"
 	, addedPatron->id, addedPatron->movie, addedPatron->snack, addedPatron->time);}
  list = addToFront(thePatron, addedPatron);
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, list->id, list->movie, list->snack, list->time);}
   if (((strcmp(list->id, addedPatron->id)) == 0) && (list->movie == addedPatron->movie) && 
    (list->snack == addedPatron->snack) && (list->time == addedPatron->time)) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	/*NULL List*/
  printf(" NULL List\n");
  nullPatron = malloc(sizeof(Patron));
  addedPatron = createPatron("888888", 1, 0, 39);
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
 	, nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
 	if (DEBUG) {printf ("%s,%d,%d,%d. \n"
 	, addedPatron->id, addedPatron->movie, addedPatron->snack, addedPatron->time);}
  list = addToFront(nullPatron, addedPatron);
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, list->id, list->movie, list->snack, list->time);}
  if (((strcmp(list->id, addedPatron->id)) == 0) && (list->movie == addedPatron->movie) && 
  (list->snack == addedPatron->snack) && (list->time == addedPatron->time)) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	/*NULL Added*/
  printf(" NULL Added Node\n");
  thePatron = createPatron("999999", 1, 0, 121);
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
 	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
 	if (DEBUG) {printf ("%s,%d,%d,%d. \n"
 	, nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  list = addToFront(thePatron, nullPatron); 
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, list->id, list->movie, list->snack, list->time);}
  if ((list->id != NULL) && (list->movie == thePatron->movie) && 
  (list->snack == thePatron->snack) && (list->time == thePatron->time)) {
  if (DEBUG) {printf("  pass\n");}
   pass++;
 	}
 	else {
   if (DEBUG) {printf("  fail\n");}  
 	}
  
  printf("    %d/3 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int removeFromFrontTest(void){
  
  int pass = 0;
  Patron * thePatron, * secondPatron, * nullPatron, *list;

  printf("Testing 'removeFromFront':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  list = createPatron("AAAAAA", 1, 1, 82);
  secondPatron = createPatron("BBBBBB", 1, 0, 34);
  list->next = secondPatron;
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
    , list->id, list->movie, list->snack, list->time);}
 	if (DEBUG) {printf ("%s,%d,%d,%d,noNext. \n"
 	, secondPatron->id, secondPatron->movie, secondPatron->snack, secondPatron->time);}
  list = removeFromFront(list);
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, list->id, list->movie, list->snack, list->time);}
   if (((strcmp(list->id, secondPatron->id)) == 0) && (list->movie == secondPatron->movie) && 
    (list->snack == secondPatron->snack) && (list->time == secondPatron->time)) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	/*NULL Next*/
  printf(" NULL Next\n");
  list->next = NULL;
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , list->id, list->movie, list->snack, list->time);}
  thePatron = removeFromFront(list);
  if (DEBUG) {printf ("  Function Output: \n");}
  if (thePatron == NULL) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
 	
 	/*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  thePatron = removeFromFront(nullPatron);
  if (DEBUG) {printf ("  Function Output: \n");}
  if (thePatron == NULL) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
 	
  printf("    %d/3 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int getFrontTest(void){
  
  int pass = 0;
  Patron * thePatron, * nullPatron, *list;

  printf("Testing 'getFront':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  list = createPatron("CCCCCC", 1, 1, 72);
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next.\n"
    , list->id, list->movie, list->snack, list->time);}
  thePatron = getFront(list);
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
   if (((strcmp(list->id, thePatron->id)) == 0) && (list->movie == thePatron->movie) && 
    (list->snack == thePatron->snack) && (list->time == thePatron->time)) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	
 	/*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  thePatron = getFront(nullPatron);
  if (DEBUG) {printf ("  Function Output: \n");}
  if ((thePatron == NULL) || (thePatron->id == NULL)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
 	
  printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int addToBackTest(void){
  
  int pass = 0;
  Patron * thePatron, * addedPatron, * nullPatron, *list;

  printf("Testing 'addToBack':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  list = createPatron("DDDDDD", 0, 1, 131);
  addedPatron = createPatron("EEEEEE", 1, 0, 93);
  list->next = addedPatron;
  addedPatron = createPatron("FFFFFF", 1, 0, 58);
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
 	, list->id, list->movie, list->snack, list->time);}
 	if (DEBUG) {printf ("%s,%d,%d,%d. \n"
 	, addedPatron->id, addedPatron->movie, addedPatron->snack, addedPatron->time);}
  list = addToBack(list, addedPatron);
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d. "
 	, list->id, list->movie, list->snack, list->time);}
  thePatron = list->next;
  thePatron = thePatron->next;
  if (DEBUG) {printf ("%s,%d,%d,%d.\n", thePatron->id, thePatron->movie
  , thePatron->snack, thePatron->time);}
   if (((strcmp(thePatron->id, addedPatron->id)) == 0)
    && (thePatron->movie == addedPatron->movie) && 
    (thePatron->snack == addedPatron->snack) && (thePatron->time == addedPatron->time)) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	/*NULL List*/
  printf(" NULL List\n");
  nullPatron = malloc(sizeof(Patron));
  addedPatron = createPatron("GGGGGG", 1, 0, 39);
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
 	, nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
 	if (DEBUG) {printf ("%s,%d,%d,%d. \n"
 	, addedPatron->id, addedPatron->movie, addedPatron->snack, addedPatron->time);}
  list = addToBack(nullPatron, addedPatron);
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, list->id, list->movie, list->snack, list->time);}
  if (((strcmp(list->id, addedPatron->id)) == 0) && (list->movie == addedPatron->movie) && 
  (list->snack == addedPatron->snack) && (list->time == addedPatron->time)) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	
 	/*NULL Added*/
  printf(" NULL Added Node\n");
  thePatron = createPatron("HHHHHH", 1, 0, 111);
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
 	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
 	if (DEBUG) {printf ("%s,%d,%d,%d. \n"
 	, nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  list = addToFront(thePatron, nullPatron); 
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, list->id, list->movie, list->snack, list->time);}
  if ((list->next == NULL) && (list->id != NULL) && (list->movie == thePatron->movie) && 
  (list->snack == thePatron->snack) && (list->time == thePatron->time)) {
  if (DEBUG) {printf("  pass\n");}
   pass++;
 	}
 	else {
   if (DEBUG) {printf("  fail\n");}  
 	}
  
  printf("    %d/3 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int removeFromBackTest(void){
  
  int pass = 0;
  Patron * thePatron, * secondPatron, * nullPatron, *list;

  printf("Testing 'removeFromBack':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  list = createPatron("IIIIII", 1, 1, 16);
  secondPatron = createPatron("JJJJJJ", 1, 0, 75);
  list->next = secondPatron;
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next. "
    , list->id, list->movie, list->snack, list->time);}
 	if (DEBUG) {printf ("%s,%d,%d,%d,noNext. \n"
 	, secondPatron->id, secondPatron->movie, secondPatron->snack, secondPatron->time);}
  list = removeFromBack(list);
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, list->id, list->movie, list->snack, list->time);}
  secondPatron = list->next;
   if (secondPatron == NULL) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	/*NULL Next*/
  printf(" NULL Next\n");
  list->next = NULL;
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , list->id, list->movie, list->snack, list->time);}
  thePatron = removeFromBack(list);
  if (DEBUG) {printf ("  Function Output: \n");}
  if (thePatron == NULL) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
 	
 	/*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  thePatron = removeFromBack(nullPatron);
  if (DEBUG) {printf ("  Function Output: \n");}
  if (thePatron == NULL) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
 	
  printf("    %d/3 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int getBackTest(void){
  
  int pass = 0;
  Patron * thePatron, * nullPatron, *list;

  printf("Testing 'getBack':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  list = createPatron("KKKKKK", 1, 1, 12);
  thePatron = createPatron("LLLLLL", 1, 0, 101);
  list->next = thePatron;
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next.\n"
    , list->id, list->movie, list->snack, list->time);}
  thePatron = getBack(list);
 	if (DEBUG) {printf ("  Function Output: %s,%d,%d,%d\n"
 	, thePatron->id, thePatron->movie, thePatron->snack, thePatron->time);}
   if (((strcmp(list->id, thePatron->id)) != 0)) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	
 	/*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  thePatron = getBack(nullPatron);
  if (DEBUG) {printf ("  Function Output: \n");}
  if ((thePatron == NULL) || (thePatron->id == NULL)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
 	
  printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int printListTest(void){
  
  int pass = 0;
  char * patronList;
  Patron * thePatron, * nextPatron, * nullPatron, *list;

  printf("Testing 'printList':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  list = createPatron("MMMMMM", 1, 1, 92);
  thePatron = createPatron("NNNNNN", 1, 0, 11);
  list->next = thePatron;
  nextPatron = createPatron("OOOOOO", 0, 1, 81);
  thePatron->next = nextPatron;
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next.\n"
    , list->id, list->movie, list->snack, list->time);}
  patronList = printList(list);
 	if (DEBUG) {printf ("  Function Output:\n%s", patronList);}
   if (list->id[0] == patronList[0]) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	
 	/*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  patronList = printList(nullPatron);
  if (DEBUG) {printf ("  Function Output: %s\n", patronList);}
  if (patronList == NULL) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
 	
  printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int lengthTest(void){
  
  int pass = 0, listLength;
  Patron * thePatron, * nextPatron, * nullPatron, * list;

  printf("Testing 'length':\n");
  
  /*Regular Values*/
  printf(" Regular Values\n");
  list = createPatron("PPPPPP", 1, 1, 22);
  thePatron = createPatron("PPPPP0", 1, 1, 102);
  list->next = thePatron;
  nextPatron = createPatron("PPPPP1", 1, 0, 11);
  thePatron->next = nextPatron;
 	if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next +2.\n"
    , list->id, list->movie, list->snack, list->time);}
  listLength = length(list);
 	if (DEBUG) {printf ("  Function Output:%d\n", listLength);}
   if (listLength == 3) {
     if (DEBUG) {printf("  pass\n");}
     pass++;
 	}
 	else {
     if (DEBUG) {printf("  fail\n");}  
 	}
 	
 	/*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  listLength = length(nullPatron);
  if (DEBUG) {printf ("  Function Output: %d\n", listLength);}
  if (listLength == 0) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }
  
  printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}

int destroyPatronListTest(void){
  
  int pass = 0;
  Patron * thePatron, * nextPatron, * nullPatron, * list;

  printf("Testing 'destroyPatronList':\n");

  /*Regular Values*/
  printf(" Regular Values\n");
  list = createPatron("QQQQQQ", 1, 1, 62);
  thePatron = createPatron("QQQQQ0", 0, 1, 32);
  list->next = thePatron;
  nextPatron = createPatron("QQQQQQ1", 1, 0, 78);
  thePatron->next = nextPatron;
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,next +2.\n"
  , list->id, list->movie, list->snack, list->time);}
  destroyPatronList(list);
  thePatron = list->next;
  if (DEBUG) {printf ("  Function Output:\n");}
  if ((list == NULL) || (list->id == NULL)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }


  /*NULL Values*/
  printf(" NULL Values\n");
  nullPatron = malloc(sizeof(Patron));
  nullPatron->id = NULL;
  if (DEBUG) {printf ("  Function Input: %s,%d,%d,%d,noNext. \n"
  , nullPatron->id, nullPatron->movie, nullPatron->snack, nullPatron->time);}
  destroyPatronList(nullPatron);
  if (DEBUG) {printf ("  Function Output:\n");}
  if ((nullPatron == NULL) || (nullPatron->id == NULL)) {
    if (DEBUG) {printf("  pass\n");}
    pass++;
  }
  else {
    if (DEBUG) {printf("  fail\n");}  
  }

  printf("    %d/2 tests passed.\n\n", pass);
  free(nullPatron);
  return pass;
}