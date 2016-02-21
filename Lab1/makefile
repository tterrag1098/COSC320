CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = BubbleSorter.cpp InsertionSorter.cpp MergeSorter.cpp SelectionSorter.cpp main.o
OBJECTS = $(SOURCES:.cpp=.o)
EXE = Lab1

all: $(SOURCES) $(EXE)

	$(EXE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

	.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
