#include <stdio.h>
#include "bubblesort.c"

int main(){
    // hello darkness my old friend, 
    // I've come to talk with you again
    //
    //Bubble Sort an array
    int l = 20;
    int *a = genArray(l);
    printf("Before Sorting: ");
    printArray(l, a);
    printf("---------------------------------------\n");
    printf("After Sorting: ");
    printArray(l, bubbleSort(l, a));

    free(a);
    return 0;
}