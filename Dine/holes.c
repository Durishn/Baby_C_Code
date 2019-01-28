#include <stdio.h>
#include <stdlib.h>

/*Global Variable Initialization*/
#define MEMORYSIZE 128

/**********************
*Structure Definitions*
**********************/

/*Define Memory*/
typedef struct {
	char memSlots[MEMORYSIZE];
	int loadCount;
	float memUsage;
	float procs;
	float holes;
} Mem;

/*Define ListNode and the Linked List*/
typedef struct ListNodeTag {
	char pid;
	int psize;
	int swapCount;
	int active;
	struct ListNodeTag *next;
} ListNode;
typedef struct {
	int size;
	ListNode *first;
} List;

/********************
*Function Prototypes*
********************/

/*Sets a List variable to the empty List.
ARGS:	-The address of the List variable to be initialized (List*) */
void InitializeList (List *L);

/*Sets a Mem variable to the empty Memory.
ARGS:	-The address of the Memory variable to be initialized (Mem*) */
void InitializeMem (Mem *M);

/*Copies a given List.
ARGS:	-The address of the List variable to be copied (List*) */
List CopyList (List *L);

/*Inserts an Item in a List.
ARGS:	-The parts of item to be inserted (pid, pzise, swapCount, active)
		-The position in the List where 
 			the Item should be inserted in (int) 
		-The address of the List (List *L)*/
void Insert (char pid, int psize, int swapCount
	, int active, int position, List *L);

/*Removes an Item from a List.
ARGS:	-The position in the List
			where the Item to be removed is in (int) 
		-The address of the List (List *L)*/
void Remove (int position, List *L);

/*Frees memory that may have been allocated 
	by Initialize, Insert or Remove.*/
void Destroy (List *L);

/*Prints all contents of List
ARGS:	-The Memory to be printed (Mem*)*/
void PrintList (List *L, Mem *M);

/*Counts holes in Memory
ARGS:	-The Memory to be scanned (Mem*)
RETURN:	-The number of holes in memory (int)*/
int holeCount (Mem *M);

/*Counts process
ARGS:	-The Memory to be scanned (List*)
RETURN:	-The current memUsage in memory (int)*/
int procCount (List *L);

/*Counts memUsage
ARGS:	-The Memory to be scanned (Mem*)
RETURN:	-The current memUsage in memory (int)*/
int memCount (Mem *M);

/*finds worst hole in memory
ARGS:	-The Memory to be scanned (Mem*)
RETURN:	-The index of the largest hole (int)*/
int worstHole (Mem *M, int size);

/*finds best hole in memory for the size
ARGS:	-The Memory to be scanned (Mem*)
RETURN:	-The index of the largest hole (int)*/
int bestHole (Mem *M, int size);

/*Loads the memory based on first fit simulation
ARGS:	-The memory to be loaded (Mem *)
		-The List to be scanned (List *)*/
void FirstFit(List *L, Mem *M);

/*Loads the memory based on next fit simulation
ARGS:	-The memory to be loaded (Mem *)
		-The List to be scanned (List *)*/
void NextFit(List *L, Mem *M);

/*Loads the memory based on best fit simulation
ARGS:	-The memory to be loaded (Mem *)
		-The List to be scanned (List *)*/
void BestFit(List *L, Mem *M);

/*Loads the memory based on worst fit simulation
ARGS:	-The memory to be loaded (Mem *)
		-The List to be scanned (List *)*/
void WorstFit(List *L, Mem *M);

/*Prints final content text
ARGS:	-The Memory to be printed (Mem*)*/
void PrintAVG (Mem *M);

/**********************
*Function Definitions*
**********************/

/*Main Program*/
int main (int argc, char ** argv){

	/*Variable Initialization*/
	int psize;
	char pid;
	FILE *fp = NULL;
	List L, Ltemp;
	Mem M;

	/*Print Title & Open File*/
	printf("\n---------------------------------"
		"The Process Simulator---------------------------------\n");

	/*Check Arguments, Open File & Initialize Mem and List*/
	if (argc != 2){
		printf("ERROR:\n  Please include a filename.\n"); exit(1);}
	fp = fopen(argv[1], "r");
	if (fp == NULL){
		printf("ERROR:\n  Please include a valid file.\n");exit(1);}
	InitializeMem(&M);
	InitializeList(&L);

	/*Parse file and load into List*/
	while (feof(fp) != 1){
		fscanf(fp, "%c %d\n", &pid, &psize);
		Insert(pid, psize, 0, 0, L.size, &L);
	}

	/*Begin First Fit Simulation*/
	Ltemp = CopyList(&L);
	printf("\t\t\t\t-------First Fit-------\t\t\t\t\n");
	FirstFit(&Ltemp,&M);
	PrintAVG(&M);
	InitializeMem(&M);

	/*Begin Next Fit Simulation*/
	Ltemp = CopyList(&L);
	printf("\n\t\t\t\t-------Next  Fit-------\t\t\t\t\n");
	NextFit(&Ltemp,&M);
	PrintAVG(&M);
	InitializeMem(&M);
	
	/*Begin Best Fit Simulation*/
	Ltemp = CopyList(&L);
	printf("\n\t\t\t\t-------Best  Fit-------\t\t\t\t\n");
	BestFit(&Ltemp,&M);
	PrintAVG(&M);
	InitializeMem(&M);


	/*Begin Worst Fit Simulation*/
	Ltemp = CopyList(&L);
	printf("\n\t\t\t\t-------Worst Fit-------\t\t\t\t\n");
	WorstFit(&Ltemp,&M);
	PrintAVG(&M);
	InitializeMem(&M);

	/*Print Footer, Destroy List & close file*/
	printf("--------------------------------------"
		"-------------------------------------------------\n\n");
	Destroy(&L);
	Destroy(&Ltemp);
	fclose(fp);
	return EXIT_SUCCESS;
}


/*Set List Size to 0 and first to NULL*/
void InitializeList (List *L){
	L->size=0;
	L->first=NULL;
}

/*Set each memSlot to 0 and set holes, procs, loadCount & memUsage*/
void InitializeMem (Mem *M){
	int i;
	for (i=0; i<MEMORYSIZE; i++)
		M->memSlots[i] = '0';
	M->holes = M->procs = M->loadCount = M->memUsage = 0;
}

/*Copy the value of each ListNode into a new List*/
List CopyList (List *L){
	List Ltemp;
	ListNode *p;
	InitializeList(&Ltemp);
	p=L->first;
	while (p != NULL){
		Insert(p->pid, p->psize, 0, 0, Ltemp.size, &Ltemp);
		p = p->next;
	}
	return Ltemp;
}

/*Insert value into list, shift all other Nodes respectively*/
void Insert (char pid, int psize, int swapCount, int active
	, int position, List *L){
	int i;
	ListNode *p, *q;
	L->size++;
	q = (ListNode *) malloc(sizeof(ListNode));
	q->active = active;
	q->psize = psize;
	q->pid = pid;
	q->swapCount = swapCount;
	if (position == 0) {
		q->next = L->first;
		L->first = q;
	}
	else {
		p = L->first;
		for(i=0; i<position-1; i++) p=p->next;
		q->next=p->next;
		p->next=q;
	}
}

/*Remove value from list, shift all other Nodes respectively*/
void Remove (int position, List *L) {
	int i;
	ListNode *p, *q;
	if(position == 0) {
		q = L->first;
		L->first = q->next;
	}
	else {
		p = L->first;
		for(i=0; i<position-1; i++) p=p->next;
		q=p->next;
		p->next=q->next;
	}
	free(q);
	L->size--;
}

/*Trace through list in order and free memory*/
void Destroy (List *L) {
	int i;
	ListNode *p, *q;
	p=L->first;
	for(i=0; i<L->size; i++) {
		q=p;
		p=p->next;
		free(q);
	}
}

/*Print output line containing info about loaded process*/
void PrintList(List *L, Mem *M){
	ListNode *p;
	p=L->first;
	while (p->next != NULL)
		p=p->next;
	printf("    P-%c loaded, #processes = %d, #holes = %d, %%memusage = %d,"
		" cumulative %%mem = ", p->pid, procCount(L), holeCount(M)
		, memCount(M));
	if (M->loadCount == 0)
		printf("0.\n");
	else
		printf("%.0f.\n", M->memUsage/M->loadCount);
}

/*Trace through List and count slots that are active*/
int procCount(List *L){
	ListNode *p;
	int procCount;
	procCount=0;
	p = L->first;
	while (p != NULL){
		if (p->active == 1)
			procCount++;
		p=p->next;
	}
	return procCount;
}

/*Trace through Memory and count holes*/
int holeCount (Mem *M){
	int i;
	int holeCount = 0;
	for (i=0; i<MEMORYSIZE; i++){
		if (M->memSlots[i] == '0'){
			holeCount++;
			while ((M->memSlots[i] == '0') && i<MEMORYSIZE)
				i++;
		}
	}
	return holeCount;
}

/*Trace through memory and count used slots*/
int memCount (Mem *M){
	int i;
	double processCount = 0;
	for (i=0; i<MEMORYSIZE; i++){
		if (M->memSlots[i] != '0')
			processCount++;
	}
	return ((processCount/MEMORYSIZE)*100);
}

/*Find index of largest hole, if it is smaller than size, return -1*/
int worstHole (Mem *M, int size){
	int holeMax = 0, holeSize = 0, holeIndex = 0, i;
	for (i=0; i<MEMORYSIZE; i++){
		holeSize = 0;
		if (M->memSlots[i] == '0'){
			while ((M->memSlots[i] == '0') && (i<MEMORYSIZE)){
				holeSize++;
				i++;
			}
		}
		if (holeSize >= holeMax){
			holeMax = holeSize;
			holeIndex = i - holeSize;
		}
	}
	if (holeMax >= size)
		return holeIndex;
	else
		return -1;
}

/*Find index of smalles hole that fits size, if non-existant return -1*/
int bestHole (Mem *M, int size){
	int holeMax = 128, holeSize = 0, holeIndex = 0, i;
	for (i=0; i<MEMORYSIZE; i++){
		holeSize = 0;
		if (M->memSlots[i] == '0'){
			while ((M->memSlots[i] == '0') && (i<MEMORYSIZE)){
				holeSize++;
				i++;
			}
		}
		if ((holeSize - size <= holeMax) && (holeSize - size >= 0)){
			holeMax = holeSize - size;
			holeIndex = i - holeSize;
		}
	}
	if ((holeMax != 128))
		return holeIndex;
	else
		return -1;
}

/*Simulate process loading based on first fit*/
void FirstFit (List *L, Mem *M){
	ListNode *p, *q;
	int i, holeIndex, holeSize, tempPsize, tempSwapCount;
	int index = 0, completeFlag = 0;
	char tempPid;

	while((L->first != NULL) && (completeFlag != 1)){
		p = L->first;
		holeSize = holeIndex = -1;

		/*If already active*/
		index = 0;
		while ((p->active == 1) && (index<L->size)){
			tempPid = p->pid;
			tempPsize = p->psize;
			tempSwapCount = p->swapCount;
			Remove(0, L);
			if (tempSwapCount < 3)
				Insert(tempPid, tempPsize, tempSwapCount, 1,  L->size, L);
			p = L->first;
			index++;
		}

		/*If all processes are active*/
		if (p->active == 1)
			completeFlag = 1;

		else {

			/*Check for large enough hole*/
			for (i=0; i<MEMORYSIZE; i++){
				if (M->memSlots[i] == '0'){
					holeSize=0;
					while ((M->memSlots[i] == '0') && i<MEMORYSIZE){
						holeSize++;
						i++;
					}
				}
				if (holeSize >= p->psize){
					holeIndex = i - holeSize;
					i = MEMORYSIZE;
				}
			}

			/*If a hole is large enough*/
			if (holeSize >= p->psize){
				for (i=holeIndex; i<p->psize+holeIndex; i++)
					M->memSlots[i] = p->pid;

				tempPid = p->pid;
				tempPsize = p->psize;
				tempSwapCount = p->swapCount;
				Remove(0, L);
				if (tempSwapCount < 3)
					Insert(tempPid, tempPsize, tempSwapCount, 1,  L->size, L);
				
				M->memUsage += memCount(M);
				M->holes += holeCount(M);
				M->procs += procCount(L);
				M->loadCount++;
				PrintList(L, M);
			}

			/*If a hole is not large enough*/
			else {
				q = L->first->next;
				index = 1;
				while ((q->active != 1) && (q != NULL)){
					q = q->next;
					index++;
				}
				for (i=0; i<MEMORYSIZE; i++){
					if (M->memSlots[i] == q->pid)
						M->memSlots[i] = '0';
				}
				
				q->active = 0;
				q->swapCount++;
				if (q->swapCount >= 3)
					Remove(index, L);
			}
		}
	}
}  

/*Simulate process loading based on next fit*/
void NextFit (List *L, Mem *M){
	ListNode *p, *q;
	int i, holeIndex, holeSize, tempPsize, tempSwapCount;
	int lastIndex = 0, index = 0, completeFlag = 0;
	char tempPid;

	while((L->first != NULL) && (completeFlag != 1)){
		p = L->first;
		holeSize = holeIndex = -1;

		/*If already active*/
		index = 0;
		while ((p->active == 1) && (index<L->size)){
			tempPid = p->pid;
			tempPsize = p->psize;
			tempSwapCount = p->swapCount;
			Remove(0, L);
			if (tempSwapCount < 3)
				Insert(tempPid, tempPsize, tempSwapCount, 1,  L->size, L);
			p = L->first;
			index++;
		}

		/*If all processes are active*/
		if (p->active == 1)
			completeFlag = 1;

		else {

			/*Check Next spot for large enough hole*/
			for (i=lastIndex; i<MEMORYSIZE; i++){
				if (M->memSlots[i] == '0'){
					holeSize=0;
					while ((M->memSlots[i] == '0') && i<MEMORYSIZE){
						holeSize++;
						i++;
					}
				}
				if (holeSize >= p->psize){
					holeIndex = i - holeSize;
					i = MEMORYSIZE;
				}
			}

			/*Check for large enough hole if next not available*/
			if (holeSize < p->psize){
				for (i=0; i<lastIndex; i++){
					if (M->memSlots[i] == '0'){
						holeSize=0;
						while ((M->memSlots[i] == '0') && i<MEMORYSIZE){
							holeSize++;
							i++;
						}
					}
					if (holeSize >= p->psize){
						holeIndex = i - holeSize;
						i = MEMORYSIZE;
					}
				}
			}

			/*If a hole is large enough*/
			if (holeSize >= p->psize){
				for (i=holeIndex; i<p->psize+holeIndex; i++)
					M->memSlots[i] = p->pid;

				tempPid = p->pid;
				tempPsize = p->psize;
				tempSwapCount = p->swapCount;
				Remove(0, L);
				if (tempSwapCount < 3)
					Insert(tempPid, tempPsize, tempSwapCount, 1,  L->size, L);
				
				M->memUsage += memCount(M);
				M->holes += holeCount(M);
				M->procs += procCount(L);
				M->loadCount++;
				PrintList(L, M);
			}

			/*If a hole is not large enough*/
			else {
				q = L->first->next;
				index = 1;
				while ((q->active != 1) && (q != NULL)){
					q = q->next;
					index++;
				}
				for (i=0; i<MEMORYSIZE; i++){
					if (M->memSlots[i] == q->pid)
						M->memSlots[i] = '0';
				}
				
				q->active = 0;
				q->swapCount++;
				if (q->swapCount >= 3)
					Remove(index, L);
			}
		}
	}
}

/*Simulate process loading based on best fit*/
void BestFit (List *L, Mem *M){
	ListNode *p, *q;
	int i, holeIndex, tempPsize, tempSwapCount;
	int index = 0, completeFlag = 0;
	char tempPid;

	while((L->first != NULL) && (completeFlag != 1)){
		p = L->first;

		/*If already active*/
		index = 0;
		while ((p->active == 1) && (index<L->size)){
			tempPid = p->pid;
			tempPsize = p->psize;
			tempSwapCount = p->swapCount;
			Remove(0, L);
			if (tempSwapCount < 3)
				Insert(tempPid, tempPsize, tempSwapCount, 1,  L->size, L);
			p = L->first;
			index++;
		}

		/*If all processes are active*/
		if (p->active == 1)
			completeFlag = 1;

		else {

			/*Check for large enough hole*/
			holeIndex = bestHole(M, p->psize);

			/*If a hole is large enough*/
			if (holeIndex != -1){
				for (i=holeIndex; i<p->psize+holeIndex; i++)
					M->memSlots[i] = p->pid;

				tempPid = p->pid;
				tempPsize = p->psize;
				tempSwapCount = p->swapCount;
				Remove(0, L);
				if (tempSwapCount < 3)
					Insert(tempPid, tempPsize, tempSwapCount, 1,  L->size, L);
				
				M->memUsage += memCount(M);
				M->holes += holeCount(M);
				M->procs += procCount(L);
				M->loadCount++;
				PrintList(L, M);
			}

			/*If a hole is not large enough*/
			else {
				q = L->first->next;
				index = 1;
				while ((q->active != 1) && (q != NULL)){
					q = q->next;
					index++;
				}
				for (i=0; i<MEMORYSIZE; i++){
					if (M->memSlots[i] == q->pid)
						M->memSlots[i] = '0';
				}
				
				q->active = 0;
				q->swapCount++;
				if (q->swapCount >= 3)
					Remove(index, L);
			}
		}
	}
}

/*Simulate process loading based on worst fit*/
void WorstFit (List *L, Mem *M){
	ListNode *p, *q;
	int i, holeIndex, tempPsize, tempSwapCount;
	int index = 0, completeFlag = 0;
	char tempPid;

	while((L->first != NULL) && (completeFlag != 1)){
		p = L->first;

		/*If already active*/
		index = 0;
		while ((p->active == 1) && (index<L->size)){
			tempPid = p->pid;
			tempPsize = p->psize;
			tempSwapCount = p->swapCount;
			Remove(0, L);
			if (tempSwapCount < 3)
				Insert(tempPid, tempPsize, tempSwapCount, 1,  L->size, L);
			p = L->first;
			index++;
		}

		/*If all processes are active*/
		if (p->active == 1)
			completeFlag = 1;

		else {

			/*Check for large enough hole*/
			holeIndex = worstHole(M, p->psize);

			/*If a hole is large enough*/
			if (holeIndex != -1){
				for (i=holeIndex; i<p->psize+holeIndex; i++)
					M->memSlots[i] = p->pid;

				tempPid = p->pid;
				tempPsize = p->psize;
				tempSwapCount = p->swapCount;
				Remove(0, L);
				if (tempSwapCount < 3)
					Insert(tempPid, tempPsize, tempSwapCount, 1,  L->size, L);
				
				M->memUsage += memCount(M);
				M->holes += holeCount(M);
				M->procs += procCount(L);
				M->loadCount++;
				PrintList(L, M);
			}

			/*If a hole is not large enough*/
			else {
				q = L->first->next;
				index = 1;
				while ((q->active != 1) && (q != NULL)){
					q = q->next;
					index++;
				}
				for (i=0; i<MEMORYSIZE; i++){
					if (M->memSlots[i] == q->pid)
						M->memSlots[i] = '0';
				}
				
				q->active = 0;
				q->swapCount++;
				if (q->swapCount >= 3)
					Remove(index, L);
			}
		}
	}
}

/*Print final line containing output averages of entire simulation*/
void PrintAVG (Mem *M){
	if (M->loadCount != 0)
		printf("Total loads = %d, average #processes = %.2f, average #holes"
			" = %.2f, cumulative %%mem = %.2f\n", M->loadCount
			, M->procs/M->loadCount, M->holes/M->loadCount
			, M->memUsage/M->loadCount);
	else 
		printf("Total loads = 0, average #processes = 0, average #holes"
			" = 0, cumulative %%mem = 0\n");
}