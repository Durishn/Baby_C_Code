CC     =     gcc

#Flags
CFLAGS = -Wall -std=c99 -pthread
LDFLAGS = 

#Directories
INCLUDES =
LIBDIRS =
LIBS =
BINDIR = 
SRCDIR =

#Source
SOURCE1 = $(SRCDIR)dine.c
SOURCE2 = $(SRCDIR)holes.c

#Objects
OBJS1 = dine.o
OBJS2 = holes.o

#Binary Programs
PROGNAME1 = $(BINDIR)dine
PROGNAME2 = $(BINDIR)holes


all:	dine holes
dine:	$(OBJS1)
	$(CC) $(CFLAGS) $(SOURCE1) $(INCLUDES) $(LIBDIRS) -o $(PROGNAME1)	
holes: 	$(OBJS2)
	$(CC) $(CFLAGS) $(SOURCE2) $(INCLUDES) $(LIBDIRS) -o $(PROGNAME2)	
clean:
	@ rm *.o
