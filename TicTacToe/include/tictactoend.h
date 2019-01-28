/*********************************************
Include the ncurses.h library to add cursor functions.
Define the words UP, DOWN, LEFT and RIGHT as 1,2,3 and 4 respectively.
 -This will allow us to send directions as words instead of numbers.
**********************************************/
#include<ncurses.h> 
#define UP	1
#define DOWN	2
#define LEFT	3
#define RIGHT	4

/*********************************************
Tic Tac Toe Introduction Screen Function.
 -This function prints the game title and instruction
 -It prompts the user to hit [enter] to play the game
**********************************************/
void gameIntro();

/*********************************************
Curses Initialization Function.
 -This function initializes curses mode
 -Takes input chars individual
 -Enables keyboard mapping
**********************************************/
void initCurses();

/*********************************************
Board Mapping Function.
 -This function draws the horizontal and vertical line
 on the game board
 -Sets the cursor location to cell one.
**********************************************/
void drawBoard ();

/*********************************************
Message Printing Function.
  -This function requires a message as input
  -It prints a bolded white message onto a black background
**********************************************/
void printMessage (char *);

/*********************************************
Cursor Moving Function.
   -This function requires a integer corresponding to 
a direction as input
   -It moves the cursor one cell in the direction that 
the user pressed on their arrow keys
**********************************************/
void moveCursor(int);

/*********************************************
boardData Array Allocating Function.
 -This function requires the boardData string and the 
current player turn as input
 -It sets the boardData element which corresponds
to the cell which was chosen, to the players number
**********************************************/
void setBoardData(int *, int);

/*********************************************
Game Piece Drawing Function.
 -This function requires the player number as input
 -It draws an X for player 1 and O for player 2
in the cell they chose.
**********************************************/
void drawPieces(int);

/*********************************************
Game Over Detecting Function.
 -This function requires the boardData string
 -It checks to see if a player won or the game is tied
and returns a corresponding number to main
**********************************************/
int checkIsGameOver(int *);