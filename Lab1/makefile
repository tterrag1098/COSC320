OBJS = main.o BubbleSorter.o InsertionSorter.o MergeSorter.o SelectionSorter.o
CC = g++
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Lab1

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

BubbleSorter.o:
	$(CC) $(CFLAGS) BubbleSorter.cpp Sorter.h

InsertionSorter.o:
	$(CC) $(CFLAGS) InsertionSorter.cpp Sorter.h

MergeSorter.o:
	$(CC) $(CFLAGS) MergeSorter.cpp Sorter.h

SelectionSorter.o:
	$(CC) $(CFLAGS) SelectionSorter.cpp Sorter.h

main.o:
	$(CC) $(CFLAGS) main.cpp BubbleSorter.cpp InsertionSorter.cpp \
MergeSorter.cpp SelectionSorter.cpp Sorter.h

clean:
	rm *.o *~ $(EXE)
