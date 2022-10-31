#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"

int pickrand(start, stop)
{
    if      (start > stop) {return -1;}
    else if (start == stop) {return start;}

    int random_pos = (rand() % (stop - start + 1)) + start;
    return random_pos;
}

void swap(int *A, int pos1, int pos2)
{
    if (!A || pos1 < 0 || pos2 < 0) {return;}
    
    int temp = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = temp;
    return;
}

int partition(int *A, int start, int stop)
{
    // Input validation
    if (!A || start > stop || start < 0 || stop < 0) {return -1;}
    else if  (start == stop)  {return start;}

    // Pick random number from the array,
    // to lessen the bad choices of pivot

    int random_pos = pickrand(start, stop);
    swap(A, start, random_pos);

    int pivot = A[start];
    int i = start + 1;      //Everything Left  of i <= pivot
    int j = stop;           //Everything Right of j >  pivot

    while(i <= j)
    {
        // At one point i and j will meet in the middle, 
        // but we don't stop there because we can't gurantee
        // whether that element at i = j is in the correct position,
        // so we stop AFTER that step,
        // i.e, when either i and j have crossed and are adjacent to each other
    
        if (A[i] > pivot)
        {
            swap(A, i, j);
            j = j - 1 ;
        }
        else //(A[i] <= pivot)
        {
            i = i + 1;
        }
    }

    /*
    (i has crossed j) so:
    Assuming that whole array has now been sorted into two sections: 
    - start to j containing elements lesser  than pivot
    - i to stop  containing elements greater than pivot
    */

    swap(A, start, j);
    return j; //Since now contains pivot
}

void quicksort(int *A, int start, int stop)
{
    // check if A exists //check start >=0 //check stop  >=0
    if (!A || start >= stop || start < 0) {return;}

    // P is the pivot
    int p = partition(A, start, stop);

    quicksort(A, start, p-1 );
    quicksort(A, p+1  , stop);

}