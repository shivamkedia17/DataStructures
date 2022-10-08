#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include "arrays.c"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename \n", argv[0]);
        return 1; 
    }
    array x = getArray_File(argv[1]);
    printf("Array: ");
    printArray(x->l, x->A);

    nodePointer head = genlistFromArray(x->l, x->A);

    printf("Linked List: ");
    printLinkedList(head);
    
    free(x->A);
    free(x);
    freeList(head);
}