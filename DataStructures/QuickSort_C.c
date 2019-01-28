#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAYSIZE 100
#define ALGLOOPNUM 50


void quicksortController(int, int*);
void quicksort(int *,int,int);
int partition(int *,int,int);
void printList(int*);

int main(int argc, char ** argv){

  int i, intList[ARRAYSIZE];
  FILE* inputFile;
  i=0;

  // Check for appropriate File
  if (argc != 2){
    fprintf(stderr, "ERROR: Include a filename\n");
    exit(1);
  }
  if ((inputFile = fopen (argv[1], "r")) == NULL){
    fprintf(stderr, "ERROR: File \"%s\" not found\n", argv[1]);
    exit(1);
  }

  // Scan File into integer array
  fscanf (inputFile, "%d", &intList[i]);    
  while (!feof (inputFile)) {  
      i++;
      fscanf (inputFile, "%d", &intList[i]);      
    }

  quicksortController(ALGLOOPNUM, intList);

  return (0);
}

void quicksortController(int algNum, int * intList){

  int listBuff[ARRAYSIZE];
  int i,j;
  double time[algNum], timeAv;

  for (i=0; i<algNum; i++) {

    // Copy intList into listBuff
    for(j=0; j<ARRAYSIZE; j++)
      listBuff[j] = intList[j];

    // Start Clock
    clock_t start = clock();

    quicksort(listBuff,0,ARRAYSIZE-1);

    //End Clock & Calculate
    time[i] = (double) (clock()-start) / CLOCKS_PER_SEC;
    timeAv += time[i];

    printf("Algorithm Time: %f\n",time[i]);
  }

  //Calculate Average Time
  timeAv /= algNum; 
  printf("\nAverage Algorithm Time: %f\n",timeAv);
  //printList(listBuff);
}

void quicksort(int *alist,int first,int last){
    int splitpoint;
   if( first < last ) {
      splitpoint = partition( alist, first, last);
      quicksort( alist, first, splitpoint-1);
      quicksort( alist, splitpoint+1, last);
   }
}

int partition( int alist[], int first, int last) {
  int pivotvalue, leftmark, rightmark, temp;

  pivotvalue = alist[last];
  leftmark = first-1; 

  for (rightmark = first; rightmark < last; rightmark++){
    if (alist[rightmark] <= pivotvalue){
      leftmark = leftmark + 1;
      temp = alist[leftmark];
      alist[leftmark] = alist[rightmark];
      alist[rightmark] = temp;
    }
  }

  temp = alist[last]; 
  alist[last] = alist[leftmark+1]; 
  alist[leftmark+1] = temp;
  return leftmark+1;
}

void printList(int *x){
  int i;
  for (i=0; i<ARRAYSIZE; i++)
    printf("%d ", x[i]);
  printf("\n");
}