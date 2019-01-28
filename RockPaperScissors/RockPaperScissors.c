/*
Author:		Nic Durish (ndurish@uoguelph.ca)	
Date Created:	October 2012
Description:	This program runs a Rock-Paper-Scissors competition. It calculates the competition winner,
		number of ties, number of user wins and number of computer wins, in a set number of games
		of Rock-Paper-Scissors. Given the total number of games being played and the users choice
		of 1,2, or 3 (paper, scissors or rock) for each game.   
References:	University of Guelph, School of Computer Sciences Assignment #3
*/

#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#include<time.h>

int main(void)
{
	/*
	Variable Declaration
	'game' is the game number which is currently being played, it starts at 1
	'n_games' is the total number of games to be played, inputted by user
	'total_game' is the total number of games in case user exits program early
	'user_choice' is the users choice of 1,2, or 3, (paper, scissors or rock), inputted by user
	'pc_choice' is the computers choice of 1,2, or 3, (paper, scissors or rock), calculated
	'n_ties' is the total number of ties, it starts at 0
	'n_user_wins' is the total number of wins scored by the user, it starts at 0
	'n_pc_wins' is the total number of wins scored by the computer, it starts at 0
	*/
	int game = 1, n_games, total_game, user_choice, pc_choice, n_ties = 0, n_user_wins = 0, n_pc_wins = 0; 
  
	// Welcome the user and introduce the Rock-Paper-Scissors game	
	printf("\n\n---*---*---*---*---*---*---*---*---*---*---*---*\n");
	printf("*Welcome to the Rock-Paper-Scissors Competition* \nThe rules are simple: \n");
	printf("-You will play a number of games against me\n");
	printf("-We each choose Rock, Paper or Scissors\n");
	printf("-Rock beats Scissors, Scissors beats Paper, and Paper beats Rock\n");
	printf("-The winner of the most games at the end of the competition is the 'Rock-Paper-Scissors Champion'!\n\n");
	
	//Obtain the required number of games from user whilst defending against numbers less than zero.
	printf("How many games would you like to play?:\n");
	scanf("%d", &n_games);

	while (n_games < 0) {
		printf("\nHey Smartass! How do you expect us to play a negative number of games?\n");
		printf("How many games *cough* not negative *cough* would you like to play?\n");
		scanf("%d", &n_games);
	}

	//Begin game loop, which loops as long as the variable game is lower than the number of games entered by user
	for (game = 1; game <= n_games; game++) {
		
		//Ask the user to input 1,2 or 3 (paper, scissors or rock)
		printf("\nGame Number %d/%d.\n", game, n_games);
		printf("Paper is 1, Scissors is 2, Rock is 3 and 0 exits competition.\n");
		printf("What is your choice?\n");
		scanf("%d", &user_choice);

		//Defend against a user choice of less than 0 or greater than 3.
		while (user_choice < 0 || user_choice > 3) {
			printf("Please enter a value of 0,1,2 or 3.\n");
			scanf("%d", &user_choice);
		}
		
		//Convert 1,2 or 3 to 'paper', 'scissors' or 'rock' and output to user
		printf("Your choice is ");
		switch (user_choice) {
		  case 1: 
			printf("Paper.\n");
		  break;
		  case 2:
			printf("Scissors.\n");
		  break;
		  case 3:
			printf("Rock.\n");
		  break;
		  case 0:
			
			//Complete the loop by setting the game number to one above the maximum number of games
			game = n_games + 1;
		  break;
		  default:
			printf("Program Error.\n");
		  break;
		}
		
		//If the user terminates program do not continue with the rest of loop, if not, then continue with program
		if (user_choice == 0) {
			printf("that we end the competition early!\n");
		}
		else {
		//Generate a random number between 1-3 for pc_choice
		srand(time(NULL));
		pc_choice = (rand() % 3) + 1;
		
		//Convert 1,2 or 3 to 'paper', 'scissors' or 'rock' and output to user
		printf("My choice is ");
		switch (pc_choice) {
		  case 1: 
			printf("Paper.\n");
		  break;
		  case 2:
			printf("Scissors.\n");
		  break;
		  case 3:
			printf("Rock.\n");
		  break;
		  default:
			printf("Program Error.\n");
		  break;
		}

		//Print Game number, and calculate winner of game
		printf("Game %d: ", game);

		/*
		Output "We Tied" and increase the count of number of ties by 1 when:
		The user choice and the pc choice are the same number; either 1, 2 or 3
		*/
		if ((user_choice == 1 && pc_choice == 1) || (user_choice == 2 && pc_choice == 2) || (user_choice == 3 && pc_choice == 3)) {
		    printf("We Tied.\n");
		    n_ties++;
		}

		/*
		Output "I Win" and increase the count of number of computer wins by 1 when:
		The user choice is 1 and the pc choice is 2 OR
		The user choice is 2 and the pc choice is 3 OR
		The user choice is 3 and the pc choice is 1		
		*/
		else if ((user_choice == 1 && pc_choice == 2) || (user_choice == 2 && pc_choice == 3) || (user_choice == 3 && pc_choice == 1)) {
		    printf("I Win!\n");
		    n_pc_wins++;
		}

		/*
		Output "You Win" and increase the count of number of user wins by 1 when:
		The user choice is 1 and the pc choice is 3 OR
		The user choice is 2 and the pc choice is 1 OR
		The user choice is 3 and the pc choice is 2
		Else print "program error"	
		*/
		else if ((user_choice == 1 && pc_choice == 3) || (user_choice == 2 && pc_choice == 1) || (user_choice == 3 && pc_choice == 2)) {
		    printf("You Win...\n");
		    n_user_wins++;
		}
		else {
		    printf("Program Error.\n");
		}
		}
	}

	//Output the winner of the competition	
	printf("\nThe Competition is over, and the results are in. The new Rock-Paper-Scissors Champion is...\n");
	
	//If the number of user wins is greater than the number of computer wins than print user wins
	if (n_user_wins > n_pc_wins) {
		printf("You!\n");
	}

	//If the number of computer wins is greater than the number of user wins than print computer wins
	else if (n_user_wins < n_pc_wins) {
		printf("Me!\n");
	}

	// If the number of user wins equals the number of computer wins than print a tie, else print "program error"
	else if (n_user_wins == n_pc_wins) {
		printf("...It's a Tie!\n");
	}
	else {
		printf("Program Error\n");
	}
	
	//In case of user termination, set total_game equal to the sum of ties, pc wins and user wins
	total_game = n_ties + n_user_wins + n_pc_wins;
	
	//Print the statistics: The number of games, ties, number of user wins and number of computer wins, terminate program
	printf("Stats:\nOf %d games there were: \n%d games we tied\n%d games you won\nand %d games I won.\n", total_game, n_ties, n_user_wins, n_pc_wins);
	printf("\nGoodbye.\n---*---*---*---*---*---*---*---*---*---*---*---*\n");
	
	return 0;
        }
