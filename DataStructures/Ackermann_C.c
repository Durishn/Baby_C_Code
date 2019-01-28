#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ALGLOOPNUM 20


void controller(int, int, int);
int ackermann(int,int);

int main(int argc, char ** argv){

  // Check for appropriate File
  if (argc != 3){
    fprintf(stderr, "ERROR: Include two integers\n");
    exit(1);
  }
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
 
  controller(ALGLOOPNUM, x, y);

  return (0);
}

void controller(int algNum, int x, int  y){

  int i,j;
  double time[algNum], timeAv;

  for (i=0; i<algNum; i++) {

    // Start Clock
    clock_t start = clock();

    ackermann(x, y);

    //End Clock & Calculate
    time[i] = (double) (clock()-start) / CLOCKS_PER_SEC;
    timeAv += time[i];

    printf("Algorithm Time: %f\n",time[i]);
  }

  //Calculate Average Time
  timeAv /= algNum; 
  printf("\nAverage Algorithm Time: %f\n",timeAv);
}

int ackermann(int x, int y)
{
  if(x<0 || y<0)
    return -1;
  if(x==0)
    return y+1;
  if(y==0)
    return ackermann(x-1,1);
  else
    return ackermann(x-1, ackermann(x,y-1));
}
