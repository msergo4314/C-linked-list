CC = gcc
CFLAGS = -Wall -std=c99
SRC = linkedList.c
OBJS = $(SRC:.c=.o)
FUNCTIONS = addNode.c printLinkedList.c deleteLinkedList.c linkedListFileIO.c sortLinkedList.c
HEADER = header.h
EXECUTABLE = run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) $(FUNCTIONS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@ -g -pg

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.o $(EXECUTABLE).exe *.out
