/***************************************tictactoend.c***************************************
Student Name: Nic Durish                        Student Number:  0757227
Date: Jan 28, 2013                         Course Name: Intermediate Programming
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
*******************************************************************************************/
#include "tictactoend.h"


void gameIntro() {
  printf("  ______  _   ___   \n");
  printf("  __  __ | | | __|  \n");
  printf("    ||   | | ||     \n");
  printf("    ||   | | ||     \n");
  printf("    ||   | | ||__   \n");
  printf("    ||   |_| |___|  \n");
  printf("______   ___    ___ \n");
  printf("__  __  |   |  | __|\n");
  printf("  ||    | A |  ||   \n");
  printf("  ||    | _ |  ||   \n");
  printf("  ||    || ||  ||__ \n");
  printf("  ||    || ||  |___|\n");
  printf("______   ___    ___ \n");
  printf("__  __  | _ |  | __|\n");
  printf("  ||    || ||  ||__ \n");
  printf("  ||    || ||  | __|\n");
  printf("  ||    ||_||  ||__ \n");
  printf("  ||    |___|  |___|\n\n");
  printf("********************\n");
  printf("[arrows]-move cursor\n");
  printf("[space] -place piece\n");
  printf("   [q] -quit game   \n");
  printf("********************\n");
  printf("Hit [Enter] To Start\n");
  getchar();
}


void initCurses() {
  initscr ();
  cbreak ();
  noecho ();
  keypad (stdscr, TRUE);
}


void drawBoard () {
  
  /*
  Initialize an integer; i for counting 
  Enter a loop to set '-' horizontally across the screen at two locations y= 3 & 7 
  Enter a loop to set'|' vertically across the screen at two loations x= 5 & 11
  */
  int i;
  for (i=0; i<17; i++){     
    mvaddch (3, i, '-');
    mvaddch (7, i, '-');
  }
  for (i=0; i<11; i++){    
	mvaddch (i, 5, '|');
	mvaddch (i, 11, '|');  
  }
  
  /*
  Move the cursor to position (1,2) and refresh the window.
  */
  move (1,2);
  refresh ();
}


void printMessage (char *s)
{
  /*
  Initialize an integer; x for the x coordinate and integer; y for the y coordinate.
  Call a function to set our x and y variables to the x and y position of the cursor.
  */
  int x, y;
  getyx(stdscr, y, x);

  /*
  Turn on the text attributes; bold and colour pair 3(black on white).
  Print the string s on line 12.
  Turn off the text attributes, turned on above .
  */
  attron(A_BOLD);
  attron(COLOR_PAIR(3));
  mvwprintw (stdscr, 12, 0, s);
  attroff(COLOR_PAIR(3));
  attroff(A_BOLD); 

  /*
  Move the cursor to positions referenced by variables x and y and refresh the window.
  */
  move(y, x);
  refresh ();
}


void moveCursor(int dir){
 
  /*
  Initialize an integer; x for the x coordinate and integer; y for the y coordinate.
  Call a function to set our x and y variables to the x and y position of the cursor. 
  */
  int x, y;    
  getyx(stdscr, y, x);
  
  /*
  If the direction is UP and y is more than 3, decrease y by four.
  If the direction is DOWN and y is less than 7, increase y by four.
  If the direction is LEFT and x is more than 5, decrease y by six.
  If the direction is RIGHT and x is less than 11, decrease y by six.
  */
  switch (dir) {
  case UP:
    if (y>3)
      y=y-4;
  break;
  case DOWN:
    if (y<7)
      y=y+4;
  break;
  case LEFT:
    if (x>5)
      x=x-6;
  break;
  case RIGHT:
    if (x<11)
      x=x+6;
  break;
  }

  /* 
  Move the cursor to positions referenced by variables x and y and refresh the window
  */
  move(y, x);
  refresh ();
}


void setBoardData (int * boardData, int playerNum){  
  
  /*
  Initialize an integer; x for the x coordinate and integer; y for the y coordinate.
  Call a function to set our x and y variables to the x and y position of the cursor. 
  */
  int x,y;
  getyx(stdscr, y,x);
  
  /*
  Go through 3x3 inbedded if in if statements to find boardData element which corresponds
  to the cell location. y can be 1,5 or neither and x can be 2,8 or 14.
  Set the respective boardData element to the players number. 
  */
  if (y==1){
    if (x==2)
      boardData[0] = playerNum;
    if (x==8)
      boardData[1] = playerNum;
    if (x==14)
      boardData[2] = playerNum;
  }  
  else if (y==5){
    if (x==2)
      boardData[3] = playerNum;
    if (x==8)
      boardData[4] = playerNum;
    if (x==14)
      boardData[5] = playerNum;
  }
  else {
    if (x==2)
      boardData[6] = playerNum;
    if (x==8)
      boardData[7] = playerNum;
    if (x==14)
      boardData[8] = playerNum;
  }
}


void drawPieces(int playerNum){

  /*
  Initialize an integer; x for the x coordinate and integer; y for the y coordinate.
  Call a function to set our x and y variables to the x and y position of the cursor. 
  */
  int x,y;
  getyx(stdscr, y,x);
 
  /*
  If the current player is 1 then;
  Turn on the text attribute colour pair 1(cyan on white).
  Add an 'X' to the location (x,y)
  Add '/' and'\' to make the x larger
  Turn off the text attribute colour pair 1(cyan on white).
  */ 
  if (playerNum == 1){
    attron(COLOR_PAIR(1));
    mvaddch (y, x, 'X');
    mvaddch(y-1, x-1, '\\');
    mvaddch(y-1, x+1, '/');
    mvaddch(y+1, x-1, '/');
    mvaddch(y+1, x+1, '\\');
    attroff(COLOR_PAIR(1));
  }
  
  /*
  If the current player is not 1 then;
  Turn on the text attribute colour pair 2(magenta on white).
  Add an 'O' to the location (x,y)
  Add '/' and'\' to make the O larger
  Turn off the text attribute colour pair 2(magenta on white).
  */
  else {
    attron(COLOR_PAIR(2));
    mvaddch (y, x, '0');
    mvaddch(y-1, x-1, '/');  
    mvaddch(y, x-1, '|');
    mvaddch(y+1, x-1, '\\');
    mvaddch(y-1, x+1, '\\');
    mvaddch(y, x+1, '|');
    mvaddch(y+1, x+1, '/');
    attroff(COLOR_PAIR(2));

  }
   
  /*
  Move the cursor to position (1,2) and refresh the window.
  */ 
  move (1,2);
  refresh();
}


int checkIsGameOver(int * boardData){

  /*
  Initialize an integer; 'i' for counting and integer and winner for winning scenario.
  Declare winner equal to 3 (tie game)
  */
  int i, winner;
  winner = 3;
  
  /*
  Enter a loop to check if each element of boardData is 0
  If TRUE than declare winner as 0 (game not over yet)
  */
  for (i=0; i<9; i++){
   if (boardData[i] == 0) 
      winner = 0;    
  }
       
  /*
  If the following combinations of boardData elements all equal one than set 
  winner equal to one; 012,345,678,136,247,358,148,346
  */
  if (boardData[0] == 1 && boardData[1] == 1 && boardData[2] == 1)
    winner = 1;
  if (boardData[3] == 1 && boardData[4] == 1 && boardData[5] == 1)
    winner = 1;
  if (boardData[6] == 1 && boardData[7] == 1 && boardData[8] == 1)
    winner = 1;
  if (boardData[0] == 1 && boardData[3] == 1 && boardData[6] == 1)
    winner = 1;
  if (boardData[1] == 1 && boardData[4] == 1 && boardData[7] == 1)
    winner = 1;
  if (boardData[2] == 1 && boardData[5] == 1 && boardData[8] == 1)
    winner = 1;
  if (boardData[0] == 1 && boardData[4] == 1 && boardData[8] == 1)
    winner = 1;
  if (boardData[2] == 1 && boardData[4] == 1 && boardData[6] == 1)
    winner = 1;
              
  /*
  If the following combinations of boardData elements all equal two than set 
  winner equal to two; 012,345,678,136,247,358,148,346
  Then return the winner to main
  */
  if (boardData[0] == 2 && boardData[1] == 2 && boardData[2] == 2) 
    winner = 2;
  if (boardData[3] == 2 && boardData[4] == 2 && boardData[5] == 2) 
    winner = 2;
  if (boardData[6] == 2 && boardData[7] == 2 && boardData[8] == 2) 
    winner = 2;
  if (boardData[0] == 2 && boardData[3] == 2 && boardData[6] == 2)
    winner = 2;
  if (boardData[1] == 2 && boardData[4] == 2 && boardData[7] == 2) 
    winner = 2;
  if (boardData[2] == 2 && boardData[5] == 2 && boardData[8] == 2) 
    winner = 2;
  if (boardData[0] == 2 && boardData[4] == 2 && boardData[8] == 2) 
    winner = 2;
  if (boardData[2] == 2 && boardData[4] == 2 && boardData[6] == 2)
    winner = 2;              
  
  return winner;
}