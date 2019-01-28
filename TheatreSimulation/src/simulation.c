/**************************************simulation.c***************************************
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
/*Include the linkedList.h library for linked list functions.
* Include the fileGets.h library for file manipulating functions*/
#include <linkedList.h>
#include <fileGets.h>

/*Function Prototypes*/
void simIntro(void);

int main (int argc, char * argv[]) {
  
  
  /*Initialize all Variables*/
  Patron * newPatron, * listLine[2], * listSnack, *listSeating;
  char ** patronList[2],* id,* listLine1Str,* listLine2Str, * listSnackStr, *listSeatingStr;
  char  outFile[1000],  buffer[20];
  bool movie, snack;
  int maxTime, minTime, totalTime, avgTime, time, i, j, line1Clock, line2Clock, snackClock;
  int values[3]= {3600, 60, 1}, finalTime[3];
  
  /*Load values into variables*/
  simIntro();
  maxTime = 0, minTime = 500, totalTime = 0, avgTime = 0, i = 0;
  listLine[0] = NULL, listLine[1] = NULL, listSnack = NULL, listSeating = NULL;
  patronList[0] = readFile(argc, argv[1]);
  patronList[1] = readFile(argc, argv[2]);
  
  /*Create the Initial ticket and snack lines. While the two char *'s aren't NULL
  * Set id, movie, snack and time equal to their respetive token. 
  * Create a Patron with these elements and sets its next to NULL*/
  while((patronList[0][i] != NULL) || (patronList[1][i] !=NULL)){
    for (j=0; j <=(argc-2); j++) {
      id = patronList[j][i];
      movie = atoi(patronList[j][i+1]);
      snack = atoi(patronList[j][i+2]);
      time = atoi(patronList[j][i+3]);
      newPatron = createPatron(id, movie, snack, time);
      newPatron->next = NULL;
      
      /*if movie is 0 and snack is 1 add newPatron to the back of listSnack
      * but if movie is 1 add it to the seating line
      *if movie and snack are 0 destroy the patron*/
      if ((movie == 0) && (snack == 1))
        listSnack = addToBack(listSnack, newPatron);
      if (movie == 1)
        listLine[j] = addToBack(listLine[j], newPatron);
      else if ((movie == 0) && (snack == 0))
        destroyPatron(newPatron);
    }
    i+=4;
  }
  
  /*Print out all the Initial Lines. First Set the three LinesStrings to their printList return
  * If List 1 isn't NULL set newPatron equal to List 1 and print its elements.
  * Then set newPatron equal to its next and print again until NULL */
  listLine1Str = printList(listLine[0]);
  listLine2Str = printList(listLine[1]);
  listSnackStr = printList(listSnack);  
  if (listLine[0] != NULL){
    newPatron = listLine[0];
    printf("The initial line at Door 1 is;\n");
    for (i=0; i<=(length(listLine[0])-1); i++){
      printf("%s:%d:%d:%d\n", newPatron->id, newPatron->movie, newPatron->snack, newPatron->time);
      newPatron = newPatron->next;    
    }
  }
  
  /* If List 1 isn't NULL set newPatron equal to List 1 and print its elements.
  * Then set newPatron equal to its next and print again until NULL */
  if (listLine[1] != NULL){
    newPatron = listLine[1];
    printf("\nThe initial line at Door 2 is;\n");
    for (i=0; i<=(length(listLine[1])-1); i++){
      printf("%s:%d:%d:%d\n", newPatron->id, newPatron->movie, newPatron->snack, newPatron->time);
      newPatron = newPatron->next;    
    }
  }
  
  /* If List 1 isn't NULL set newPatron equal to List 1 and print its elements.
  * Then set newPatron equal to its next and print again until NULL */
  if (listSnack != NULL){
    newPatron = listSnack;
    printf("\nThe initial line at the Snack-Table is;\n");
    for (i=0; i<=(length(listSnack)-1); i++){
      printf("%s:%d:%d:%d\n", newPatron->id, newPatron->movie, newPatron->snack, newPatron->time);
      newPatron = newPatron->next;    
    }
  }
  
  /*SET THE CLOCKS*/
  line1Clock=listLine[0]->time, line2Clock=listLine[1]->time, snackClock=listSnack->time;
  
  /*RUN THE SIMULATION WHILE THE SNACK AND MOVIE LINES ARENT EMPTY*/
  while ((listLine[0] != NULL) || (listLine[1] != NULL) || (listSnack != NULL)){
    
    if ((((line1Clock <= line2Clock) || (listLine[1] == NULL))
     && ((line1Clock <= snackClock) || (listSnack == NULL))) && (listLine[0] != NULL)){
      newPatron = listLine[0];
      newPatron->waitTime = line1Clock;
      listLine[0] = removeFromFront(listLine[0]);
      if (listLine[0] != NULL)
        line1Clock += (listLine[0])->time;
      if (newPatron->snack == 1) {
        listSnack = addToBack(listSnack, newPatron);
        if (length(listSnack) == 1)
	  snackClock = (line1Clock + newPatron->time);
      }
      else {
        listSeating = addToBack(listSeating, newPatron);
        /*TRACK MAX TIME, MIN TIME AND TOTAL TIME*/
        totalTime += newPatron->waitTime;
        if (newPatron->waitTime > maxTime)
          maxTime = newPatron->waitTime;
        if (newPatron->waitTime < minTime)
          minTime = newPatron->waitTime;
      }
    }  
    
    else if ((((line2Clock < line1Clock) || (listLine[0] == NULL))
     && ((line2Clock <= snackClock)|| (listSnack == NULL))) && (listLine[1] != NULL)) {
      newPatron = listLine[1];
      newPatron->waitTime = line2Clock;
      listLine[1] = removeFromFront(listLine[1]);
      if (listLine[1] != NULL)
        line2Clock += (listLine[1])->time;
      if (newPatron->snack == 1){
        listSnack = addToBack(listSnack, newPatron);
        if (length(listSnack) == 1)
	  snackClock = (line2Clock + newPatron->time);
      }
      else {
        listSeating = addToBack(listSeating, newPatron);
        
        /*TRACK MAX TIME, MIN TIME AND TOTAL TIME*/
        totalTime += newPatron->waitTime;
        if (newPatron->waitTime > maxTime)
          maxTime = newPatron->waitTime;
        if (newPatron->waitTime < minTime)
          minTime = newPatron->waitTime;
      }
    }
    
    else if ((((snackClock < line1Clock) || (listLine[0] == NULL))
     && ((snackClock < line2Clock) || (listLine[1] == NULL)) && (listSnack != NULL))) {
      newPatron = listSnack;
      newPatron->waitTime = snackClock;
      listSnack = removeFromFront(listSnack);
      if (listSnack != NULL)
        snackClock += (listSnack)->time;
      
     
      if (newPatron->movie == 1) {
        listSeating = addToBack(listSeating, newPatron);
        
        /*TRACK MAX TIME, MIN TIME AND TOTAL TIME*/
        totalTime += newPatron->waitTime;
        if (newPatron->waitTime > maxTime)
          maxTime = newPatron->waitTime;
        if (newPatron->waitTime < minTime)
          minTime = newPatron->waitTime;
      }
      else
        destroyPatron(newPatron);
    }
    
    else {
      printf("Error.\n");
      break;
    }
    
  }
 
  /*PRINT THE FINAL STATS AND SEATING LINE*/
  listSeatingStr = printList(listSeating);
  if (length(listSeating) != 0)
    avgTime = totalTime / length(listSeating);
  newPatron = listSeating;
  
  for (i=0; i < 3; i++) {
          finalTime[i] = maxTime / values[i];
           maxTime %= values[i];
      }
  sprintf( outFile, "Max:%02d:%02d:%02d\n", finalTime[0], finalTime[1], finalTime[2]);
  for (i=0; i < 3; i++) {
          finalTime[i] = minTime / values[i];
           minTime %= values[i];
      }
  sprintf( buffer, "Min:%02d:%02d:%02d\n", finalTime[0], finalTime[1], finalTime[2]);
  strcat(outFile, buffer);
  for (i=0; i < 3; i++) {
          finalTime[i] = avgTime / values[i];
           avgTime %= values[i];
      }
  sprintf( buffer, "Avg:%02d:%02d:%02d\n", finalTime[0], finalTime[1], finalTime[2]);
  strcat(outFile, buffer);
  for (i=0; i<=(length(listSeating)-1); i++){
 
    for (j=0; j < 3; j++) {
      finalTime[j] = newPatron->waitTime / values[j];
      newPatron->waitTime %= values[j];
    }
    sprintf(buffer, "%s:%02d:%02d:%02d\n", newPatron->id, finalTime[0], finalTime[1], finalTime[2]);
    strcat(outFile, buffer);
    newPatron = newPatron->next;    
  }
  
  writeFile(outFile);
  printf("\nThe Final Seating List:\n%s", outFile);
  
  return 0;
}

void simIntro() {
	
	/* Print the sim introduction, controls, and legend then get an input from the user*/
	
	printf(".............................\n");
	printf(".CINEMA LINE TIME SIMULATION.\n");
	printf("..see readme for extra info..\n");
	printf("*****************************\n");
	printf(".....Hit [Enter] To Start....\n");
	getchar();
}
