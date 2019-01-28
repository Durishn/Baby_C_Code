/***************************************fileGets.c***************************************
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
#include "fileGets.h"

char ** readFile (int argc, char *argv) {
	
  /*Initialize an integer; 'i' is a counter
  * Initialize a 2-d String; 'patronList' is all the patron information.
  * Initialize a string; lineBuffer is a buffer for reading each line in the file
  * Initializing a file 'inputFile' is the file inputed by the user during excecution*/
	
  int i, j;
  char ** patronList, * token;	
  char lineBuffer[20];
  FILE *inputFile = NULL;	
  i=0;
	
  if ((argc != 2) && (argc != 3)) {
    printf("Error: Please supply the program with the name of one or two input file\n");
  exit (1); }
	
  /*Set inputFile equal to the file inputed by the user 
  * If inputFile is NULL print an error message and exit program*/
	
  inputFile = fopen (argv, "r");
  if (inputFile == NULL) {
    printf ( "Error: Could not find input file\n");
    return NULL;
  }	

  else {
    /*Malloc 800 char * slots for patronList, exit if no memory is allocated*/

    patronList = malloc(sizeof(char*) * 800);
    if(patronList==NULL) {  printf("Out of memory\n"); exit(0);}

    /*If inputFile isn't NULL tokenize the first lineBuffer 
    * Malloc memory for patronList[i] based on the size of the token
    * Copy the contents of lineBuffer into patronList[i] 
    * Copy the next three pointers into lineBuffer with a for loop*/
		
    while((fgets (lineBuffer, 20, inputFile)) != NULL) {
      token = strtok(lineBuffer, " ");
      patronList[i]= malloc(sizeof(char) * (strlen(token)+1));
      if(patronList[i]==NULL) {  printf("Out of memory\n"); exit(0);}
      strcpy(patronList[i], token);
      for (j=1; j<4; j++){
        token = strtok(NULL, " ");
        patronList[i+j]= malloc(sizeof(char) * (strlen(token)+1));
    	if(patronList[i+j]==NULL) {  printf("Out of memory\n"); exit(0);}
	strcpy(patronList[i+j], token);
      }
      i+=4;
    }


  /*Close the input file. 
  * Return the 2-D string 'roomsList' to main*/

  fclose(inputFile);
  return patronList;	
  }
}

FILE * writeFile (char *outputFileContent) {
  
  /*Initialate a file called outFile and set it to NULL*/
  FILE * outputFile;
  outputFile = NULL;
  
  /*Open the file called report.txt in write mode
  * Print the characterstring outputFileContent into the file
  * Close the file and return 0*/
  outputFile = fopen ("report.txt", "w");
  fprintf(outputFile, "%s", outputFileContent);
  fclose(outputFile);
  return outputFile;
}
