#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int* genArray(int l)
{
    const int MAX = l<50?50:(50* l/50);
    srandom(time(NULL));
    //int A[l]; Doesn't work: stack memory of A is freed after returning to caller
    int *A = malloc(l * sizeof(int));

    for (int i = 0; i < l; i++)
    {   
        A[i] = random() % MAX;
    }
    //printf("l%d\n",l);
    return A; 
}

void printArray(int l, int* A)
{
    //printf("l%d\n",l);
    for (int i=0; i<l; i++)
    {   
        printf(i? ", %d":"%d", A[i]);
    }
    printf(".\n");
}   


int* bubbleSort(int n, int *A)
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
    return A;
}

/*
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

typedef struct node
{
    int val;
    struct node *next;
} *nodePointer;

//Assume linked list is without loops
void printLinkedList(nodePointer HEAD)
{

}

nodePointer bubbleSortLlist(nodePointer HEAD)
{
    return HEAD;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
*/