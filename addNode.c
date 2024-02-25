#include "header.h"

void addNodeAtEnd(Node** root, int data) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Not enough memory to allocate a new node\n");
        exit(1);
    }
    newNode->num = data;
    newNode->next = NULL;

    if (*root == NULL) {
        *root = newNode;
        return; // immediately quit or else dereferencing a null pointer
    }

    Node* curr = *root;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    return;
}

void addNodeAtStart(Node** root, int data) {
    // note that this function is O(1)
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(5);
    }
    newNode->num = data;
    newNode->next = *root;
    *root = newNode;

}

void insertAfterNode(Node* node, int data) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "error occurred while creating a new node\n");
        exit(3);
    }
    newNode->num = data;
    newNode->next = node->next;
    if(node == NULL) {
        printf("cannot add a node after a NULL pointer node! Use \"addNodeAtStart\" function\n");
        return;
    }
    node->next = newNode;
}

void addNodeAtIndex(Node** root, int indexToInsertAt, int data) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "error occurred while creating a new node\n");
        exit(3);
    }
    newNode->num = data;
    if (isEmptyList(*root)) {
        newNode->next = NULL;
        *root = newNode;
        return;
    }
    if (indexToInsertAt < 0) {
        printf("cannot pass in negative index for adding new node\n");
        exit(2);
    }

    if (indexToInsertAt == 0) {
        newNode->next = *root; // Insert at the beginning
        *root = newNode; // Update root
    } else {
        Node* prevNode = getNodeAtSpecifiedIndex(*root, indexToInsertAt - 1);
        if (prevNode == NULL) {
            fprintf(stderr, "Invalid index to insert at\n");
            free(newNode);
            return;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

Node* getNodeAtSpecifiedIndex(Node* root, int index) {
    Node* curr = root; 

    if (root == NULL) {
        return NULL;
    }

    int i = 0;
    while (curr != NULL && i < index) {
        curr = curr->next;
        i++;
    }
    return curr;
}

void insertDataSorted(Node** root, int data) {
    // in the case of inserting the first element into an empty linked list
    if (isEmptyList(*root) || data <= (*root)->num) {
        addNodeAtStart(root, data);
        return;
    }
    Node* curr = *root; // pointer to current node
    for (int i = 0; curr->next != NULL;i++) {
        if (data <= curr->next->num) {
            break;
        } else {
            curr = curr->next;
        }
    }
    // if largest element yet seen just add to end
    insertAfterNode(curr, data);
}

bool isEmptyList (Node* head) {
    return head == NULL;
}