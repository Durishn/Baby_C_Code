/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Adds two large integers using Stacks.
 * AUTHOR: N.Durish (CIS2520, Assignment 2)
 * DATE: 10/10/2013
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). 
 *********************************************************************/


#include "StackInterface.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *inputFile;
  Stack S,F,Q;
  Item X;
  int i, size, sum, numQ, numF, carry = 0;
  char characterbuffer;
  
  //Call Initialize and print intro
  Initialize(&Q);
  Initialize(&F);
  Initialize(&S);
  printf("------Welcome to the huge integer calculator!------\n");
  
  
  //Opening the file "test.txt" and reading it to inputFile, if NULL, exit.
  inputFile = fopen("test.txt", "r");
  if (inputFile == NULL) {
  	printf ( "Error: Could not find input file\n"); exit(1);}

  //Read the first line and push it into the Stack Q
  printf("First Int:");
  characterbuffer = fgetc(inputFile);
  while ((characterbuffer != EOF) && (characterbuffer != ' ')) {
    characterbuffer = characterbuffer - '0';
    Push(characterbuffer, &Q);
    printf("%d", characterbuffer);
    characterbuffer = fgetc(inputFile);
  } 
  
  //Read the second line a push it into the Stack F
  printf("\nSecond Int:");
  characterbuffer = fgetc(inputFile);
  while ((characterbuffer != EOF) && (characterbuffer != ' ')) {
    characterbuffer = characterbuffer - '0';
    Push(characterbuffer, &F);
    printf("%d", characterbuffer);
    characterbuffer = fgetc(inputFile);
  }
  
  /*While both Stacks are not empty, use an algorithm to find the sum and record the carry
   *This sum is them pushed into the Sum Stack */
  while((Empty(&Q) == 0) && (Empty(&F) == 0)) {
    Top(&Q, &X);
    numQ = X;
    Pop(&Q);
    Top(&F, &X);
    numF = X;
    Pop(&F);

    sum = numF + numQ + carry;
    carry=0;
    if (sum>=10){
      sum = sum - 10;
      carry = 1;
    }
    Push(sum,&S);
  }
  
  //This pushes the rest of whichever integer was longer into the sum StackInterface
  if (Empty(&F)){
    while(Empty(&Q) == 0){
      Top(&Q, &X);
      numQ = X + carry;
      Pop(&Q);
      carry = 0;
      Push(numQ,&S);
    }
  }
  else if (Empty(&Q)){
     while(Empty(&F) == 0){
      Top(&F, &X);
      numF = X + carry;
      Pop(&F);
      carry = 0;
      Push(numF,&S);
    }
  }
  
  
  //This prints out the sum
  printf("\nThe sum is:");
  size = Size(&S);
  for(i=0;i<size;i++){
    Top(&S, &X);
    printf("%d", X);
    Pop(&S);  
  }  

  printf("\n");
  Destroy(&S);
  return 0;
}

