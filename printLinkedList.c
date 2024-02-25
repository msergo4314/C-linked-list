#include "header.h"

void printLinkedList(Node* head) {
    Node* curr = head; 
    if (hasLoops(head)) {
        printf("Loops detected in linked list.\n");
        return;
    }
    if (head == NULL) {
        printf("Currently, the linked list is empty.\n");
        return;
    }

    int i = 1;
    while (curr != NULL) {
        printf("node %-4d with address %p has data element: %-4d\n", i, curr, curr->num);
        curr = curr->next;
        i++;
    }
    printf("\n");
    return;
}

void printLinkedListToFile(Node* head, char* filePath) {
    Node* curr = head; 
    if (hasLoops(head)) {
        printf("List has loops!\n");
        return;
    }
    FILE* fptr = fopen(filePath, "w");
    if (fptr == NULL) {
        printf("Could not open the file %s\n", filePath);
    }
    if (head == NULL) {
        fprintf(fptr, "Currently, the linked list is empty.\n");
        fprintf(stdin, "The linked list is empty.\n");
        return;
    }

    int i = 1;
    while (curr != NULL) {
        fprintf(fptr, "node %-4d with address %p has data element: %-4d\n", i, curr, curr->num);
        curr = curr->next;
        i++;
    }
    fclose(fptr);
    return;
}

bool listHasValue(Node* root, int valueToCheck) {
    if (isEmptyList(root)) {
        return false;
    }
    Node* current = root;

    // while still in linked list...
    while (current != NULL) {
        if (current->num == valueToCheck) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int getNumberOfElementsInList(Node* head) {
    Node* curr = head;

    if (head == NULL) {
        return 0;
    }

    int count = 0;
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}

int getElementsRecursively(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return getElementsRecursively(root->next) + 1;
}

bool hasLoops(Node* root) {
    Node* slow = root;
    Node* fast = root;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        } 
    }
    return false; 
}