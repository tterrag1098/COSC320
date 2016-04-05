OBJS = main.o Hashtable.o
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11 -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Lab6

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

Hashtable.o:
	$(CC) $(CFLAGS) Hashtable.cpp Hashtable.h

main.o:
	$(CC) $(CFLAGS) main.cpp Hashtable.h

clean:
	rm *.o *.gch *~ $(EXE)
