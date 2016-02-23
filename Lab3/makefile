OBJS = main.o Heap.o
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11 -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Lab3

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

Heap.o:
	$(CC) $(CFLAGS) Heap.cpp Heap.h

main.o:
	$(CC) $(CFLAGS) main.cpp Heap.h

clean:
	rm *.o *~ $(EXE)
