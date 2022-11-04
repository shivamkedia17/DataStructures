#include <stdio.h>
#include <stdlib.h>
#include "InsertionSort.c"

int main(int argc, char** argv)
{
    int l = 0;
    switch (argc)
    {
        case 1:
            printf("Enter Size of Array: ");
            scanf("%d",&l);  
            break;

        case 2:
            sscanf(argv[1], "%d", &l);
            break;

        default:
            fprintf(stderr, "Usage: %s [array_size]\n", argv[0]);
            return 1; 
            break;
    }

    int *A = genArray(l);
    printf("Array : \n");
    printArray(l, A);
    printf("\n");

    insertionsort(A, l);
    printf("Insertion Sorted Array: \n");
    printArray(l, A);
    printf("\n");

    free(A);
}