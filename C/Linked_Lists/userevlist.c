#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chunkreverse.c"

int main(int argc, char** argv)
{
    int l;
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

    // l = 12;

    srandom(time(NULL));
    int *A = genArray(l);
    printArray(l, A);

    nodePointer head = genlistFromArray(l, A); 

    printf("Linked List: \n");
    printLinkedList(head);

    head = reverseList(head); 
    printf("Linked List After Reversing: \n");
    printLinkedList(head);

    nodePointer newhead = chunk_reverseList(head, 7); 
    printf("Linked List Chunk Reversing: \n");
    printLinkedList(newhead);

    free(A);
    freeList(head);
}