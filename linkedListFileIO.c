#include "header.h"

void createDataFile(const char* name) {
    FILE* fptr = fopen(name, "w");
    if (fptr == NULL) {
        printf("could not create file %s\n", name);
        exit(2);
    }
    // unsigned short a;
    unsigned short intCount = 1;
    for (int i = 0; i < RAND_COUNT; i++, intCount++) {
        if(intCount <= MAX_INTS_PER_LINE-1) {
            fprintf(fptr, "%d ", rand() % RAND_RANGE + 1);
        }
        else {
            // newlines every 10 integers for readability
            fprintf(fptr, "%d\n", rand() % RAND_RANGE + 1);
            intCount = 0;
        }
        // printf("number of characters written: %d\n", (int)a);
    }
    fclose(fptr);
    return;
}

int* readFromFile(const char* name, short* size) {
    FILE* fptr = fopen(name, "r");
    if (fptr == NULL) {
        printf("could not open the file for reading\n");
        exit(-4);
    }
    int* arr = malloc(sizeof(int)); // malloc single block at first
    short numScanned = 0;
    int a;
    while(fscanf(fptr, "%d \n", &a) != EOF) {
        numScanned += 1;
        arr = realloc(arr, sizeof(int) * (numScanned+2));
        arr[numScanned-1] = a;
    }
    *size = numScanned;
    return arr;
    fclose(fptr);
}

short getNumberOfCharsInInt(int num) {
    short c = 1;
    if (num < 0) {
        num *= -1;
    }
    while (num / 10 > 0) {
        c++;
        num /= 10;
    }
    return c;
}