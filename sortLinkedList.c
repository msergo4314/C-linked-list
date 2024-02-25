#include "header.h"

void reverseLinkedList(Node** root) {
    Node* prev = NULL;
    Node* curr = *root;
    Node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev;
}