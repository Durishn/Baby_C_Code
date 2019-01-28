*******************************************MTLSS*******************************
*	Nic Durish (#0757227)(ndurish@uoguelph.ca)      Friday, March 28, 2014    *
*	CIS 3110 - Operating Systems         		  	Assignment 3          	  *
*******************************************************************************

I. DESCRIPTION & REQUIREMENTS
II. ASSUMPTIONS & LIMITATIONS
III. COMPILATION & EXECUTION
IV. PROGRAM TEST PLAN

******************
* I. DESCRIPTION *
******************
dine.c
	dine.c is a program which implements a solution to the Dining Philospher Problem. 
The Dining Philosopher problem; Imagine n philosphers who each wish to eat m times.
Between each philosopher lies a chopstick, a philosopher must use the two chopsticks
to either side of him to eat. How can we have all of the philosophers eat enough,
whithout any philosphers starving.
This program, takes two command arguments, the number of philosphers (n) and the 
amount of times they wish to eat (m). The philosphers are implemented using threads and
the chopsticks using Mutex locks. 

holes.c
	holes.c is a program which implements 4 algorithms for placing processes into
holes of memory. It takes a command line argument of a file which include process id's
and process sizes. The processes are of varying size and are swapped into memory when
necessary. If there is not enough room in memory the oldest process is swapped out. 
If a process has been swapped out three times it is considered complete.
The four algorithms the program implements are; First Fit, Next Fit, Best Fit
and Worst Fit. First Fit simply finds the first hole that will fit the next process.
Next Fit finds the next hole (based on the last process) that will fit the next process.
Best Fit finds the hole the fits the next process the snuggest, and Worst Fit finds the 
largest hole in memory.

*********************************
* II. ASSUMPTIONS & LIMITATIONS *
*********************************
	Due to the time constraints and my lack of thorough programming knowledge.
This program has some know limitations;
dine.c
	-The larger the input the longer the program takes as each Philosopher sleeps
	for 3 secondseach time they wish to eat
holes.c
	-The program only accepts up to 128 difference processes
	-Depending on the file input, the algorithms may output the same result

Assumptions:
dine.c
	-There is two valid command line arguments included
	-The first argument is an integer greater than 2
	-The second argument is an integer between 1 and 1000
holes.c
	-Memory is 128MB
	-Size of processes will be integers from 1..128
	-Memory is initially empty
	-Once a process has been swappe out three times it is complete
	-There is only one valid command line included
	-The argument must be a valid file

*********************************
* III. COMPILATION & EXECUTION  *
*********************************
	To compile:
1. First unzip the file A3_durishn.tar.gz
2. Open Console and navigate to the directory /A3_durishn.
3. Type make to link and compile; this will first compile dine.c then holes.c

	To execute the program once it has compiled;
	dine.c
		type "./dine n m" where n is the number of philosophers and m
		is the number of times they wish to eat.
	holes.c
		type "./holes file" where file is a valid file to be inputted
			
*************************
* IV. PROGRAM TEST PLAN *
*************************
 	To ensure that this program included defensive programming, I issued multiple
 testing conditions which the program had to pass.

	DINE.C
	-Validity Check: The program only supports 2 arguments
	-Validity Check: The programs first argument must be an integer above 2
	-Validity Check: The programs second argument must be an integer from 1..1000

	HOLES.C
	-Validity Check: The program only supports 1 argument
	-Validity Check: The programs first argument must be a valid file