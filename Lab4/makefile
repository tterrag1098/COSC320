OBJS = main.o QuickSorter.o CountingSorter.o BucketSorter.o InsertionSorter.o
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11 -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Lab4

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

QuickSorter.o:
	$(CC) $(CFLAGS) QuickSorter.cpp QuickSorter.h Sorter.h

CountingSorter.o:
	$(CC) $(CFLAGS) CountingSorter.cpp CountingSorter.h Sorter.h

InsertionSorter.o:
	$(CC) $(CFLAGS) InsertionSorter.cpp InsertionSorter.h Sorter.h

BucketSorter.o:
	$(CC) $(CFLAGS) BucketSorter.cpp BucketSorter.h InsertionSorter.h Sorter.h

main.o:
	$(CC) $(CFLAGS) main.cpp QuickSorter.h CountingSorter.h BucketSorter.h Sorter.h

clean:
	rm *.o *.gch *~ $(EXE)
