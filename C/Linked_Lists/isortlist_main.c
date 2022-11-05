#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "insertionsortlist.c"

int main(int argc, char** argv)
{
    int l = 0;
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

    int *A = genArray(l);
    printArray(l, A);

    nodePointer head = genlistFromArray(l, A); 

    printf("Linked List: ");
    printf("%p\n",head);
    printLinkedList(head);


    printf("After Insertion Sorting: ");
    printLinkedList(insertionsort(head));
    
    free(A);
    freeList(head);
}