#include <stdio.h>
#include <stdlib.h>

int* genArray(unsigned int l)
{   
    int *A = (int*) malloc(l * sizeof(int));

    //generate a random num less in range(0,MAX)
    for (unsigned int i = 0; i < l; i++)
    {
        A[i] = (random() % INT32_MAX) - (random() % INT32_MAX)/2;
    }
    return A; 
}