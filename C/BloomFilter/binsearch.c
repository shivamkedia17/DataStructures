#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//in A[0...n-1], upper = n-1, lower = 0
int binarysearch_file(int key, size_t upper, size_t lower)
{
    if (key > 1099997) {return -1;} // too large

    if (upper == lower) // edge case
    {
        if (key == [upper])
        {return [upper];}
        else
        {return -1;} //not found
    }

    size_t mid = (upper + lower) / 2; 
    
    if (key == [mid]) {
        return [mid];
    }
    else if (key > [mid]) {return binarysearch_file(key, mid+1, upper);}
    else if (key < [mid]) {return binarysearch_file(key, lower, mid);}
    else {return -1;}
}