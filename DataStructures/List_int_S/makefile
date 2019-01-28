CC = gcc
CFLAGS = -W -lm
all:  test.out sort.out

test.out: test.o ListImplementation.o
	$(CC) -o test.out test.o ListImplementation.o $(CFLAGS)

sort.out: sort.o ListImplementation.o
	$(CC) -o sort.out sort.o ListImplementation.o $(CFLAGS)

sort.o: sort.c ListInterface.h ListType.h
	$(CC) -c sort.c

test.o: test.c ListInterface.h ListType.h
	$(CC) -c test.c

ListImplementation.o: ListImplementation.c ListInterface.h ListType.h
	$(CC) -c ListImplementation.c


















