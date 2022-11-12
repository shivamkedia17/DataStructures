#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "maxheaps.c"


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
    
    extract_max(H,l);// no errors
    printArray(l,H);
    

    extract_max(H,l-1);
    printArray(l,H);
    
    // extract_max(H,l); // Decrement length of array accordingly if 
    // printArray(l,H);

    // extract_max(H,l);
    // printArray(l,H);

    // extract_max(H,l);
    // printArray(l,H);
    
    // extract_max(H,l);
    // printArray(l,H);

    // l = extract_max_pop(H, l);
    // printArray(l,H);

    // l = insert(H, l, 500);
    // printArray(l,H);

    free(H);
}
