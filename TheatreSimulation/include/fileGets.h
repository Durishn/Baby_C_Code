/*Include the stdio.h library to add basic input output functions.
* Include the stdlib.h library to add memory allocating functions.												
* Include the string.h library to add string manipulating functions.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*This function takes in a file and filecount (argv and argv) and outputs a the file as 
a double character pointer. Seperating each Patron into a seperate string.*/
char ** readFile(int, char *);

/*This function takes in a character string and writes it into a file.*/
FILE * writeFile(char *);
