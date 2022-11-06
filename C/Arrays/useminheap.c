#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "minheaps.c"

int main(void)
{
    int l = 10;
    int *H = malloc(l * sizeof(int));

    for (int i = 0; i < l; i++)
    {
        H[i] = 10*i + i;
    }
    printArray(l,H);
    
    // extract_min(H, l);
    // printArray(l,H);

    l = insert(H, l, 9);
    printArray(l,H);

    free(H);
}
