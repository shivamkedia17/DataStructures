#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "maxheaps.c"


int main(void)
{
    int l = 12;
    int *H = malloc(l * sizeof(int));

    // int A[] = {99, 88, 73, 69, 57, 49, 42, 35, 20, 11, 4, 3};
    int A[] = {40, 28, 40, 73, 2, 85, 7, 71, 87, 22, 29, 77};

    for (int i = 0; i < l; i++) {H[i] = A[i];}
    // srandom(time(NULL));
    
    // int l = 12;
    // int *H = genArray(l);
    
    printf("Array: \n");
    printArray(l,H);

    build_maxheap_array(H, l);
    printf("Heap: \n");
    printArray(l, H);
    showTree(H, l);
    
    free(H);
}
