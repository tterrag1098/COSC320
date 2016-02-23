OBJS = main.o Node.o LinkedList.o
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11 -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Lab2

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

Node.o:
	$(CC) $(CFLAGS) Node.cpp Node.h

LinkedList.o:
	$(CC) $(CFLAGS) LinkedList.cpp LinkedList.h

main.o:
	$(CC) $(CFLAGS) main.cpp LinkedList.cpp LinkedList.h Node.h

clean:
	rm *.o *~ $(EXE)
