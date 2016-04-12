OBJS = main.o TNode.o RBT.o
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11 -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Lab7

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

TNode.o:
	$(CC) $(CFLAGS) TNode.cpp TNode.h RBT.h

RBT.o:
	$(CC) $(CFLAGS) RBT.cpp RBT.h TNode.h

main.o:
	$(CC) $(CFLAGS) main.cpp TNode.h RBT.h

clean:
	rm *.o *.gch *~ $(EXE)
