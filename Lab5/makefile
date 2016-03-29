OBJS = main.o TNode.o BST.o
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11 -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Lab5

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

TNode.o:
	$(CC) $(CFLAGS) TNode.cpp TNode.h BST.h

BST.o:
	$(CC) $(CFLAGS) BST.cpp BST.h TNode.h

main.o:
	$(CC) $(CFLAGS) main.cpp TNode.h BST.h

clean:
	rm *.o *.gch *~ $(EXE)
