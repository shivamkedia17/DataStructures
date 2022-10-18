#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include "arrays.c"


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
    printLinkedList(head);

    /* Appends to a list
    int x;
    printf("Enter Element to append : ");
    scanf("%d",&x); 
    head = append(head, x);
    */

    head = reverseList(head); 
    printf("Linked List After Reversing: ");
    printLinkedList(head);

    free(A);
    freeList(head);
}