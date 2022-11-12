#include <stdio.h>
#include <stdlib.h>
#include "maxheaps.c"

int* heap_sort(int *A, int l);

int* heap_sort(int *A, int l)
{
    if (l < 1) {return NULL;}
    build_maxheap_array(A, l);
    for (int i = 0; i < l; i++) {extract_max(A, l-i);}
    return A;
}