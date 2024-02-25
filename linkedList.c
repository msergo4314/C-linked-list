#include "header.h"
#include <time.h> // for random values


int main(int argc, char* argv[]) {
    srand(time(0));
    Node* root = NULL; // root points to first element

    // snprintf(filePath, sizeof(filePath) - 4, "../%s", fileName);
    //char absFolderPath[] = "C:\\Users\\marti\\Downloads\\";
    char absFolderPath[] = "";
    char* fileName = "linkedListData.txt";
    char* fileNameSorted = "linkedListDataSorted.txt";
    char fullFilePath[251] = "";
    strcpy(fullFilePath, absFolderPath);
    strcat(fullFilePath, fileName);

    createDataFile(fullFilePath);
    // printf("made the file\n");
    short size;
    int* myArr = readFromFile(fullFilePath, &size); // this will malloc so must free later
    printf("Printing array of ints with size %hd:\n", size);

    if (0) {
        for (int i = 0, j = 1; i < size; i++, j++) {
            // or use max ints per line
            if (j < 10) {
                printf("%5d ", myArr[i]);
            }
            else {
                j = 0;
                printf("%5d\n", myArr[i]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        insertDataSorted(&root, myArr[i]);
        // addNodeAtEnd(&root, myArr[i]);
    }

    for (short i = 0; i < 6; i++) {
        insertDataSorted(&root, 500); // insert 20x
        // addNodeAtEnd(&root, 500);
    }
    addNodeAtEnd(&root, 123);
    addNodeAtStart(&root, 500);
    addNodeAtEnd(&root, 500);
    //printLinkedList(root);
    // Node* myNode = getNodeAtSpecifiedIndex(root, 0);
    // if (myNode == NULL) {
    //     printf("you tried to access a NULL pointer\n");
    //     deleteLinkedList(&root);
    //     return 0;
    // }
    // printf("Value at the node %p (index %d) is %d\n", myNode, 0,myNode->num);
    // deleteSpecifiedNode(&root, myNode);
    // addNodeAtStart(&root, 1);
    // insertAfterNode(getNodeAtSpecifiedIndex(root, 0), 10); // insert as second element
    //printLinkedList(root);
    printLinkedListToFile(root, fileNameSorted);
    printf("Attempting to search linked list for value %d\n", 500);
    bool found = listHasValue(root, 500);
    switch (found) {
        case true:
            printf("found the value 500\n");
            break;
        default:
            printf("not found\n");
            break;
    }
    printf("Attempting to delete any values between 0 and 800...\n");
    //printLinkedList(root);
    for (short i = 0; i < 801; i++) {
        deleteSpecifiedValue(&root, (int)i, 'r');
    }
    // reverseLinkedList(&root);
    printLinkedList(root);
    printLinkedListToFile(root, "new.txt");
    printf("Size of the new linked list is: %d elements\n", getNumberOfElementsInList(root));
    deleteLinkedList(&root);
    //deleteLR(root);
    free(myArr);
    if(1) {
        if (remove("new.txt") == 0) {
            printf("Removed the file \"%s\".\n", "new.txt");
            printf("full file path: %s\n", fullFilePath);
        }
        if (remove("linkedListData.txt") == 0) {
            printf("Removed the file \"%s\".\n", fullFilePath);
        }
        if (remove(fileNameSorted) == 0) {
            printf("Removed the file \"%s\".\n", fileNameSorted);
        }
    }
    // int code = system("run.exe");
    // printf("%d\n", code);
    _CrtDumpMemoryLeaks(); // need Visual studio for this
    return 0;
}