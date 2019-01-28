#include "StudentInterface.h"
typedef Student Item;

#define MAXQUEUESIZE 100
typedef struct {
	Item items[MAXQUEUESIZE];
	int size;
  int head;
} Queue;