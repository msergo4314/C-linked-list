#ifndef HEADER_H
#define HEADER_H

#define RAND_RANGE 999
#define RAND_COUNT 25
#define MAX_INTS_PER_LINE 5

#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include <string.h>
#include <ctype.h> // if char manipulation needed
#include <stdbool.h>
#include <crtdbg.h>

// Define the structure for a linked list node
typedef struct Node {
    int num;          // Pointer to a string (character array)
    struct Node *next;   // Pointer to the next node
} Node;

void printLinkedList(Node*);

bool hasLoops(Node*);

void reverseLinkedList(Node**);

void printLinkedListToFile(Node*, char*);

void addNodeAtEnd(Node**, int);

void addNodeAtStart(Node**, int);

void deleteLinkedList(Node**);

Node* getNodeAtSpecifiedIndex(Node*, int);

void addNodeAtIndex(Node**, int, int);

void insertAfterNode(Node*, int);

void insertDataSorted(Node**, int);

// void checkRecursion (Node**, int,char);

bool isEmptyList (Node*); 

void deleteLR(Node*); // recursive deletion

void deleteAtIndex(Node**, int);

void deleteSpecifiedNode(Node**, Node*);

int* readFromFile(const char*, short*);

void createDataFile(const char*);

short getNumberOfCharsInInt(int);

void deleteSpecifiedValue(Node**, int, char);

bool listHasValue(Node*, int);

int getNumberOfElementsInList(Node*);

int getElementsRecursively(Node* root);

#endif // HEADER_H