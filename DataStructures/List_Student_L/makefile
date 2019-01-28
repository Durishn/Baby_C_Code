DEBUG = DEBUG
FLAG = -D$(DEBUG)

a.out: myProgram.o StudentImplementation.o ListImplementation.o
	gcc myProgram.o StudentImplementation.o ListImplementation.o $(FLAG)

myProgram.o: myProgram.c StudentInterface.h StudentType.h ListInterface.h ListType.h
	gcc -c myProgram.c $(FLAG)

StudentImplementation.o: StudentImplementation.c StudentInterface.h StudentType.h
	gcc -c StudentImplementation.c $(FLAG)

ListImplementation.o: ListImplementation.c ListInterface.h ListType.h StudentInterface.h StudentType.h
	gcc -c ListImplementation.c $(FLAG)


















