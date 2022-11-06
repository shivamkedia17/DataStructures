#include <stdio.h>
#include <stdlib.h>
#include "maxheaps.c"

int* heap_sort(int *A, int l);

int* heap_sort(int *A, int l)
{
    if (l < 1) {return NULL;}

    for (int i = 0; i < l; i++)
    {
        extract_max(A, l-i);
        printArray(l, A);
    }

    return A;
}