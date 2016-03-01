OBJS = main.o QuickSorter.o
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11 -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Lab4

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

QuickSorter.o:
	$(CC) $(CFLAGS) QuickSorter.cpp QuickSorter.h Sorter.h

main.o:
	$(CC) $(CFLAGS) main.cpp QuickSorter.cpp QuickSorter.h Sorter.h

clean:
	rm *.o *.gch *~ $(EXE)
