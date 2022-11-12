#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "maxheaps.c"


int main(void)
{
    int l = 12;
    int *H = malloc(l * sizeof(int));

    // int A[] = {99, 88, 73, 69, 57, 49, 42, 35, 20, 11, 4, 3};
    int A[] = {88, 99, 4, 42, 11, 35, 57, 3, 49, 69, 73, 20};

    for (int i = 0; i < l; i++)
    {
        H[i] = A[i];
    }
    printArray(l,H);

    build_maxheap_array(H, l);
    printArray(l, H);
    
    extract_max(H,l);// no errors
    printArray(l,H);
    

    extract_max(H,l);
    printArray(l,H);


    extract_max(H,l);
    printArray(l,H);



    extract_max(H,l);
    printArray(l,H);


    free(H);
}
