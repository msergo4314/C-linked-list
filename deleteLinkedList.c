#include "header.h"

void deleteLinkedList(Node** root) {

    if (*root == NULL) {
        printf("You have no linked list to delete!\n");
        return;
    }
    Node* currentNode = *root;

    Node* aux; // auxillary node
    while(currentNode != NULL) {
        aux = currentNode;
        currentNode = currentNode->next;
        free(aux);
        // printf("deallocated at block %p\n", aux);
        // printf(" Size of block: %d\n", (int)sizeof(Node));
    }
    *root = NULL;

}

void deleteLR(Node* root) {
    if (root == NULL) {
        //printf("You have no linked list to delete!\n");
        return;
    }
    Node* nextNode = root->next;
    //printf("freeing root with address %p and number: %d\n", root, root->num);
    free(root);
    deleteLR(nextNode);
}

void deleteAtIndex(Node** root, int index) {
    Node* curr = *root;
    Node* aux;
    int i = 0;

    if (*root == NULL) {
        printf("You have no nodes!\n");
        return;
    }
    if (index < 0) {
        printf("cannot pass in negative index for deleting node\n");
        exit(2);
    }

    if (index == 0) {
        *root = (*root)->next;
        // Set *root to be *root->next and then free the original *root
        free(curr);
        return;
    }

    while (i < index && curr->next != NULL) {
        aux = curr;
        curr = curr->next;
        i++;
    }

    // Check if the index is valid (within the list)
    if (i == index) {
        aux->next = curr->next;
        free(curr); // Free the node at the specified index
    } else {
        printf("Index out of range!\n");
    }
}

void deleteSpecifiedNode(Node** root, Node* nodeToDelete) {
    Node* curr = *root;
    Node* aux;
    if (nodeToDelete == NULL || *root == NULL || root == NULL) {
        printf("error with deletion\n");
        exit(2);
    }
    if (*root == nodeToDelete) {
        // remove first node in list
        curr = *root;
        *root = (*root)->next;
        free(curr);
        return;
    }

    while (curr != NULL && curr->next != nodeToDelete) {
        aux = curr;
        curr = curr->next;
    }
    if(curr == NULL) {
        printf("Node was not found in list\n");
    }
    aux->next = curr->next;
    free(curr);
}

void deleteSpecifiedValue(Node** root, int valueToDelete, char userMode) {
    // userMode should be 'r' for recursion or 's' for single
    if (isEmptyList(*root)) {
        printf("Your linked list is empty!\n");
        return;
    } else if (!listHasValue(*root, valueToDelete)) {
        // printf("The value %d was not found in the linked list!\n", valueToDelete);
        return;
    }

    Node* curr, *toRemove;
    int c = 0;

    while ((*root)->num == valueToDelete) {
        toRemove = *root;
        *root = (*root)->next;
        free(toRemove);
        c++;
        if (userMode == 'r' && listHasValue(*root, valueToDelete)) {
            deleteSpecifiedValue(root, valueToDelete, userMode);
        }
        return;
    }

    curr = *root;
    while (curr->next != NULL) {
        if (curr->next->num == valueToDelete) {
            toRemove = curr->next;
            curr->next = curr->next->next;
            free(toRemove);
            c++; // Increment the count of deleted instances
            if (userMode == 'r' && listHasValue(*root, valueToDelete)) {
                deleteSpecifiedValue(root, valueToDelete, userMode);
            }
            return;
        }
        else {
            curr = curr->next;
        }
    }
    
    // printf("Deleted %d instances of %d\n", c, valueToDelete);
}

// void checkRecursion (Node** root, int valueToDelete, char mode) {
//     switch(mode) {
//         case 'r':
//             deleteSpecifiedValue(root, valueToDelete);
//         break;
//         default:
//     }
// }

