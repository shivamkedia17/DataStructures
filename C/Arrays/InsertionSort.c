#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"

int  findcorrect_index(int *A, int current);
void insert(int *A, int dest, int src);
void insertionsort(int *A, int n);

void insertionsort(int *A, int n)
{
    int done;
    for (done = 1; done < n; done++)
    {
        int dest = findcorrect_index(A, done);
        if (done != dest) {insert(A, dest, done);}
    }
    //return A;
}

void insert(int *A, int dest, int src)
{
    if(!A || src == dest || dest < 0) {return;}
    
    int temp = A[src];
    for(int i = src; i > dest; i--)
    {
        A[i] = A[i-1];
    }
    A[dest] = temp;
}

int findcorrect_index(int *A, int current)
{
    if(!A || current < 1) {return -1;}

    int correct_index = 0;
    while(A[current] > A[correct_index])
    {
        correct_index++;
    }

    return correct_index;
}
