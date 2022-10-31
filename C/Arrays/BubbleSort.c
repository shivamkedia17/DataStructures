#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.c"

void bubblesort(int *A, int n)
{
    int done;
    for (done = 0; done < n-1; done++)
    {
        //bubble up highest element to A[n-done-1]
        for (int current = 0; current < n-done-1; current++)
        {
            if(A[current] > A[current+1])
            {
                //swap(A[current],A[current+1])
                int temp = A[current];
                A[current] = A[current+1];
                A[current+1] = temp;
            }
        }
    }
    //return A;
}