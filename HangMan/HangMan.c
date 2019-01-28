/*
Author:		Nic Durish (ndurish@uoguelph.ca)	
Date Created:	November 2012
Description:	This program runs a game of Hangman and calculates the game winner.
		Given the game word, the letter which the user would like to guess 
		for each round, and if the user would like to replay. Includes stdio 
		and string library.  
References:	University of Guelph, School of Computer Sciences Assignment #5
*/

#include<stdio.h>
#include<string.h>

//Function Prototypes.
void show_logo(void);
void game_graphics(int);
int play_game(char*);

//Main Function.
int main(void)
{
    /*	
    Variable Declaration.
    'full_word' is the game word with a maximum of 6 letters
    'replay' shows whether the game is to be replayed, it is preloaded with 'A'
    'score' is the amount of wrong guesses the user had.
    */
    char full_word[6], replay = 'A';
    int score;

    //Welcome the user to Hangman.
    printf("\n\n---*---*---*---*---*---*---*---*---*---*---*---*\n");
    printf("*Welcome to the game of Hangman* \n");
    
    //First loop the game and loop again if the user enters Y or y as 'replay'
    do {
      
        //Ask the user for a word between 3 and 6 letters, ask again if it is not between 3 and 6 letters
        do {
            printf("Please a random word between 3 and 6 letters (case-sensitive):");
            scanf(" %s", full_word);
	} while (strlen(full_word) > 6 || strlen(full_word) < 3);
	
	//Go to function 'show_logo'
	show_logo();
	
	//If it is the first time playing the game than print rules 
        if (replay != 'Y' && replay != 'y') {
            printf("The rules are simple: \n");
            printf("-The point of the game is to guess the word before the man is hung!\n");
            printf("-Each unguessed letter is represented by a '-'\n");
            printf("-You may guess any of the 28 letters, but if you guess wrong 10 times, than you lose.\n");
            printf("-Keep in mind that the word and your guesses are case-sensitive (upper-case is recommended).\n");
	    printf("-If you guess the entire word before your man is hung than you win!\n");
        }
    
        //Set score equal to the return of the function 'play_game'
	score = play_game(full_word);
	
	//If the user had 10 wrong guesses than print the loss, if not than print the win.
	if (score == 10)
            printf("Awww... Your lack of literacy killed an innocent man!\n");
	else 
            printf("YAAY! Your ability to guess letters saved a man's life!\n");
    
        //Print the full game word
	printf("The Mystery Word was: %s!\n", full_word);
	
	//Ask you user to play again, if not Y, y, N or n than ask again
        do {
 	    printf("Would you like to play again? [Y/N] ");	
	    scanf(" %c" , & replay);
	} while  (replay != 'Y' && replay != 'y' && replay != 'N' && replay != 'n');
    } while (replay == 'Y' || replay == 'y');
    
    //Print goodbye and exit program by returning 0 to Operating System
    printf("Goodbye.\n");
    printf("---*---*---*---*---*---*---*---*---*---*---*---*\n");
    return 0;
}

//Function which retrives the game word and plays the game. Returns the final score
int play_game(char *full_word)
{

    /*
    Variable Declaration;
    'i' is a counter
    'guess_wrong' is the amount of wrong guesses starting at 0
    'correct' is the amount of letters found in the game word
    'guess_word' is the string of guessed letters, it is the same length as the game word
    'guess' is the letter the user wishes to guess
    'guess_previous' is a string which shows all previous guesses, it is 52 characters long
    */
    int i, guess_wrong = 0, correct; 
    char guess_word[strlen(full_word)], guess, guess_previous[52] = " "; 
    
    //Print the length of the game word
    printf("\nYou must attempt to guess a word of length: %d\n" , (int)strlen(full_word));
   
    //Set each character in the string of guessed letters to '-'
    for (i = 0; i < strlen(full_word); i++)
        guess_word[i] = '-';
   
    //Loop the gameplay while the user hasn't guessed wrong 10 times or guess the game word
    while (guess_wrong < 10 && strcmp(guess_word, full_word) != 0) {
        
        //Print the string of guessed letters, previous guesses and prompt for a user guess
        printf("Mystery Word: %s\n", guess_word);
	printf("Previous Guesses:%s\n", guess_previous);
        printf("Guess a Letter:");
        scanf(" %c", &guess);
	
	//If the user guesses a letter that has been previously guessed than ask again
        for (i = 0; i < strlen(guess_previous); i++) {
            while (guess == guess_previous[i]) {
	        printf("Guess a Letter:");
                scanf(" %c", &guess);
	        i = -1;
	    }  
	}
	
	//add the user's guess and a comma to the end of the guess_previous string
	guess_previous[strlen(guess_previous)] = guess;
	guess_previous[strlen(guess_previous)] = ',';
	
	//Set correct equal to zero than increase by 1 for each time the guess occurs in the game word
	correct = 0;
        for (i = 0; i < strlen(full_word); i++) {
	    if (full_word[i] == guess) {
	        guess_word[i] = guess;
		correct++;
	    }
	}
	
	//If the guess was correct than print it was correct
        if (correct > 0)
	    printf("'%c' was in the mystery word!\n\n", guess);
	
	//If not than print incorrect, add one to the amount of wrong guesses and go to function game_graphics
	else if (correct == 0) {
	    printf("'%c' was not in the word!\n\n", guess);
	    guess_wrong++;
	    game_graphics (guess_wrong);
	}    
    }
  
    //Return the amount of wrong guesses
    return guess_wrong;
}

//Function which retrieves the amount of wrong guesses and prints the Hangman game board.
void game_graphics(int guess_wrong)
{
    //If the amount of wrong guesses is 0 than print... if 1 than print...
    switch (guess_wrong) {
    case 0:
         printf("\n"); 
    break;
    case 1:
         printf("\n");
         printf("\n");
         printf("__/ \\______ \n");
    break;     
    case 2:
         printf("\n");
         printf("   |/ \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;   
    case 3:
         printf("   _______ \n");
         printf("   |/ \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;        
    case 4:
         printf("   _______ \n");
         printf("   |/   \\| \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;      
    case 5:
         printf("   _______ \n");
         printf("   |/   \\| \n");
         printf("   |     O \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;     
    case 6:
         printf("   _______ \n");
         printf("   |/   \\| \n");
         printf("   |     O \n");
         printf("   |     | \n");
         printf("   |     | \n");
         printf("   | \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;    
    case 7:
         printf("   _______ \n");
         printf("   |/   \\| \n");
         printf("   |     O \n");
         printf("   |    /| \n");
         printf("   |     | \n");
         printf("   | \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;  
    case 8:
         printf("   _______ \n");
         printf("   |/   \\| \n");
         printf("   |     O \n");
         printf("   |    /|\\ \n");
         printf("   |     | \n");
         printf("   | \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;
    case 9:
         printf("   _______ \n");
         printf("   |/   \\| \n");
         printf("   |     O \n");
         printf("   |    /|\\ \n");
         printf("   |     | \n");
         printf("   |    / \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;
    case 10:
         printf("   _______ \n");
         printf("   |/   \\| \n");
         printf("   |     X \n");
         printf("   |    /|\\ \n");
         printf("   |     | \n");
         printf("   |    / \\ \n");
         printf("   | \n");
         printf("__/|\\______ \n");
    break;
    default:
        printf("Program Error.\n");
    break;
    }
    
    //Print the amount of turns left, which is ten minus the amount of wrong guesses
    printf("The man will die in %d turns.\n\n", 10 - guess_wrong);
}


//Function which prints the game logo
void show_logo(void) {
    //Print game logo
    printf("----------------------------------------------------------------------------------\n");
    printf("--------------------------------------READY?--------------------------------------\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("---------------------------------------NOW----------------------------------------\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("-------------------------------------__--___-|--__--------------------------------\n");
    printf("--------------------------------|---|__---|----|__--------------------------------\n");
    printf("--------------------------------|__-|__---|-----__|-------------------------------\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("---------------------------_____----------____------------------------------------\n");
    printf("---------------------------|----|-|------|----|-\\-----/--------------------------\n");
    printf("---_______-----------------|----|-|------|----|--\\---/----------------------------\n");
    printf("---|/----\\|----------------|____|-|------|____|---\\-/-----------------------------\n");
    printf("---|------?----------------|------|------|----|----|------------------------------\n");
    printf("---|-----/|\\---------------|------|_____-|----|----|------------------------------\n");
    printf("---|------|-----------------------------------------------------------------------\n");
    printf("---|-----/-\\----------------------------------------------------------------------\n");
    printf("---|------------------------------------------------------------------------------\n");
    printf("__/|\\______-----------------------------------------------------------------------\n\n");

}
