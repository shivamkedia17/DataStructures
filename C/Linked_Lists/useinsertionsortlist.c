#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.c"
#include "insertionsortlist.c"

int main(int argc, char** argv)
{
    int l;
    // l = 10;
    switch (argc)
    {
        case 1:
            printf("Enter Size of List: ");
            scanf("%d",&l);  
            break;

        case 2:
            sscanf(argv[1], "%d", &l);
            break;

        default:
            fprintf(stderr, "Usage: %s [list_size]\n", argv[0]);
            return 1; 
            break;
    }

    srandom(time(NULL));
    int *A = genArray(l);
    printArray(l, A);

    nodePointer head = genlistFromArray(l, A); 

    printf("Linked List: \n");
    printLinkedList(head);

    printf("After Insertion Sorting: \n");
    head = insertionsortlist(head);
    printLinkedList(head);
    
    free(A);
    freeList(head);

    return 0;
}