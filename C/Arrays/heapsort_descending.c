#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "minheaps.c"

int* heap_sort(int *A, int l);

int* heap_sort(int *A, int l)
{
    if (l < 1) {return NULL;}
    build_minheap_array(A, l);
    for (int i = 0; i < l; i++) {extract_min(A, l-i);}
    return A;
}