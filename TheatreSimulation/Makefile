CC     =     gcc

#Flags
CFLAGS =     -Wall -ansi -pedantic -g -Iinclude
LDFLAGS = 

#Directories
INCLUDES = -Iinclude
LIBDIRS =
LIBS =
BINDIR = bin/
SRCDIR = src/

#Source
SOURCE1 = $(SRCDIR)llTest.c $(SRCDIR)linkedList.c  $(SRCDIR)fileGets.c  
SOURCE2 = $(SRCDIR)simulation.c $(SRCDIR)linkedList.c  $(SRCDIR)fileGets.c
 
#Objects
OBJS1 = llTest.o linkedList.o fileGets.o
OBJS2 = simulation.o linkedList.o fileGets.o
 
#Binary Programs
PROGNAME1 = $(BINDIR)lltest
PROGNAME2 = $(BINDIR)sim

all : prog1 prog2

prog1 : $(SOURCE1)
	$(CC) $(CFLAGS)  $(SOURCE1) $(INCLUDES) $(LIBDIRS) -o $(PROGNAME1) $(LIBS)

prog2 : $(SOURCE2)
	$(CC) $(CFLAGS)  $(SOURCE2) $(INCLUDES) $(LIBDIRS) -o $(PROGNAME2) $(LIBS)

clean:
		@rm *.o