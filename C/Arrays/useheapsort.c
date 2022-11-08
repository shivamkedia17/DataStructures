#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "heapsort.c"


int main(void)
{
    int l = 12;
    int *H = malloc(l * sizeof(int));

    int A[] = {99, 88, 73, 69, 57, 49, 42, 35, 20, 11, 4, 3};

    for (int i = 0; i < l; i++)
    {
        H[i] = A[i];
    }
    printArray(l,H);

    H = heap_sort(H, l);
    
    printf("After Sorting: ");
    printArray(l, H);
    free(H);
}