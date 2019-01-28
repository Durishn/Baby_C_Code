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

int main(void) {

  /*
  Initialize an integer; i for counting, 'inputChar' for user inputs, 'dir' for directions
  'replay' to check for replays and 'winner' to find the winning scenario
  Initialize an array; 'boardData' to hold 9 character for each cell in the gameboard
  Initialize a string; 'msg' to print messages through
  */
  int i, playerNum, inputChar, dir, replay, winner;
  int  boardData[9];
  char msg[65];
  
  /*
  Call functions; gameIntro and initCurses
  */
  gameIntro();
  initCurses();

  /*
  Iterate this loop once, and repeat while replay is ' '
  */
  do {

    /*
    Enter a loop nine times to declare boardData elements equal to 0
    Declare playerNum as 1 and winner as 0
    */
    for(i=0; i<9;i++) 
      boardData[i] = 0;
    playerNum=1;
    winner=0;

    /*
    Start color mode
    Initialize color pair 1; cyan on black black
    Initialize color pair 2; magenta on black
    Initialize color pair 3; black on white
    Call function drawBoard
    */
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    drawBoard(); 
    
    /*
    Use sprintf to declare 'msg' as appropriate message with reference to playerNum
    Call printmessage function outputting 'msg'
    */
    sprintf(msg, " Player %d Start! \n                 \n", playerNum);
    printMessage(msg);
 
    /*
    Prompt the user for an input, while the input doesn't equal 'q' enter loop.
    Use sprintf to declare 'msg' as appropriate message with reference to playerNum
    Call printmessage function outputting 'msg'
    */
    while ((inputChar = getch()) != 'q') {
      sprintf(msg, " Player %d's Turn \n                 \n", playerNum);
      printMessage(msg);
      
      /*
      If the inputChar isn't a space;
       Enter a switch statement to declare 'dir'as the direction of the arrow key entered, 
       If the input also isn't an arrow key then use sprintf to declare 'msg' 
       as 'Invalid Entry' then call printmessage function outputting 'msg'
       Then call function moveCursor outputting 'dir
      */
      if (inputChar !=' ' ){ 
        switch (inputChar) {
        case KEY_UP: 
  	  dir = UP;
        break;
        case KEY_DOWN: 
  	  dir = DOWN;
        break;
        case KEY_LEFT: 
	  dir = LEFT;
        break;
        case KEY_RIGHT: 
	  dir = RIGHT;
        break;
        default:
  	  sprintf (msg, "  Invalid Entry  \n                 \n");
	  dir = 0;
	  printMessage(msg);
        break;
        }
        moveCursor(dir);
      }   

      /*
      If inputChar is a space and the cursor is on a space; 
       Call setBoardData function outputting boardData and playerNum
       Call drawPieces function outputting playerNum
       Set playerNum equal to (playerNum mod 2) plus one 
       Use sprintf to declare 'msg' as appropriate message with reference to playerNum
       Call printmessage function outputting 'msg'
       Set winner equal to the return of checkIsGameOver outputting boardData 
      */
      else {  
        if (winch(stdscr) == ' ') {
          setBoardData(boardData, playerNum);
    	  drawPieces(playerNum);	
          playerNum = playerNum %2+1;
	  sprintf (msg, "      Nice!      \n Player %d's Turn \n", playerNum);
	  printMessage(msg);
          winner = checkIsGameOver(boardData);
        }

        /*
	If inputChar is a space and the cursor is not on a space;
	 Use sprintf to declare 'msg' as 'That Squares Taken'
         Call printmessage function outputting 'msg'
	*/
        else {
  	  sprintf(msg, "  That Square's  \n      Taken!     \n");
	  printMessage(msg);
        }  
      }

      /*
      If winner is not zero then break through loop
      */
      if (winner != 0)
        break;  
    }

    /*
    If winner is 1 or winner is 2;
     Use sprintf to declare 'msg' as appropriate message with reference to playerNum
     Call printmessage function outputting 'msg'
    */
    if (winner == 1 || winner == 2) {
      sprintf(msg, "  Player %d Wins! \n[space] - Replay \n    [q] - Quit   ", winner);
      printMessage(msg); 
    }

    /*
    If winner is  not 1 2;
     Use sprintf to declare 'msg' as "Tie Game, Play Again?"
     Call printmessage function outputting 'msg'
    */
    else {
      sprintf(msg, "    Tie Game.    \n[space] - Replay \n    [q] - Quit   ");
      printMessage(msg); 
    }
    
    /*
    Declare replay equal to the user input
    While replay does not equal space or 'q' 
     Prompt the user to try again
     Declare replay equal to the user input
    */
    replay = getch();
    while  (replay != ' '&& replay != 'q') {
      sprintf(msg, "  Invalid Entry  \n[space] - Replay \n    [q] - Quit   ");
      printMessage(msg);
      replay = getch();
    }
    
    /*
    Clear the board and restart if replay is ' '
    */
    clear();
  } while (replay == ' ');
  
  /*
  Call function endwin to close the game window
  */
  endwin();
  return 0;
}