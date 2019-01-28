#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*Global Variable Initialization*/
void philosopherAction(int philNum);
pthread_t *philosophers;
pthread_mutex_t *chopsticks;
int eatTotal;
int philTotal;

int main (int argc, char ** argv){
	
	/*Variable Initialization*/
	int i;
	void * text;

	/*Print Title*/
	printf("\n-The Dining Philosopher's Problem-\n");

	/*Check Arguments*/
	if (argc != 3){
		printf("ERROR: Please include;\n  1) The number of philosophers.\n  "
		"2) The number of times each philosopher should eat.\n\n"); exit(1);}
	else if (atoi(argv[1])<3){
		printf("Error:\n\t The number of philosphers must be above 2.\n\n");
		exit(1);}
	else if ((atoi(argv[2])<1) || (atoi(argv[2])>1000)){
		printf("Error:\n  The number of times each philosopher should eat\n"
			"   must be in the range 1..1000\n\n");exit(1);}
	philTotal = atoi(argv[1]);
	eatTotal = atoi(argv[2]);

	/*Allocate memory for threads and mutex's*/
	philosophers = (pthread_t*) malloc(sizeof(philosophers)*philTotal+1);
	chopsticks = (pthread_mutex_t*) malloc(sizeof(chopsticks)*philTotal+1);
	if ((philosophers == NULL) || (chopsticks == NULL)){
		printf("Error:\n  Not enough memory.\n"); exit(1);}

	/*Print Header*/
	printf("\t  %d Philosophers,\n"
		"\t  eating %d time(s).\n----------------------------------\n"
		, philTotal, eatTotal);

	/*Initialize mutex's*/
	for(i=0; i<philTotal; i++){
		if(pthread_mutex_init(&chopsticks[i],NULL) == -1){
			printf("Error:\n  Mutex could not initialize.\n\n");exit(1);
		}
	}

	/*Create Threads*/
	for(i=0; i<philTotal; i++){
		if(pthread_create(&philosophers[i],NULL,(void *)philosopherAction
			,(void*)(intptr_t)i) != 0){
			printf("Error:\n  Thread could not be created.\n\n");exit(1);
		}
	}

	/*Join Threads*/
	for(i=0; i<philTotal; i++){
		if(pthread_join(philosophers[i],&text) != 0){
			printf("Error:\n  Thread could not be joined.\n\n");exit(1);
		}
	}

	/*Destroy mutex's*/
	for(i=0; i<philTotal; i++){
		if(pthread_mutex_destroy(&chopsticks[i]) != 0){
			printf("Error:\n  Mutex could not be destroyed.\n\n");exit(1);
		}
	}

	/*Print Footer and free memory*/
	printf("----------------------------------\n\n");
	free (philosophers);
	free (chopsticks);
	return 0;
}

/*Define Philosophers Actions*/
void philosopherAction(int temp){
	int i;
	int philNum = (intptr_t)temp;
	printf("     Philosopher %d is thinking\n", philNum+1);
	for (i=0; i<eatTotal; i++){
		pthread_mutex_lock(&chopsticks[philNum]);
		pthread_mutex_lock(&chopsticks[(philNum+1) %philTotal]);
		printf("     Philosopher %d is eating\n", philNum+1);
		sleep(3);
		pthread_mutex_unlock(&chopsticks[philNum]);
		pthread_mutex_unlock(&chopsticks[(philNum+1) %philTotal]);
		printf("     Philosopher %d is thinking\n", philNum+1);
	}
}