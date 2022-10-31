#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.c"

void selectionsort(int *A, int n)
{
    int done;
    for (done = 0; done < n-1; done++)
    {
        int min_index = done;
        for (int current = done+1; current < n; current++)
        {
            if(A[current] < A[min_index])
            {
                min_index = current;
            }
        }
        if (min_index != done)
        {
            int temp = A[done];
            A[done] = A[min_index];
            A[min_index] = temp;
        }
    }
    //return A;
}