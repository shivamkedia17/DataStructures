#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "QuickSortDoublyList.c"

int main(int argc, char** argv)
{
    int A[] = {21,222,19,18,16,24,1,9};
    int l = sizeof(A) / sizeof(A[0]);

    nodePointer head = genlistFromArray(l, A); 

    printf("Linked List: ");
    printLinkedList(head);

    printf("%p,%d\n",head,head->val);

    nodePointer end = findTail(head);
    printf("%d\n",end->val);

    printf("After Quick Sorting: ");
    quicksortlist(head, end);

    printLinkedList(head);
    
    // free(A);
    freeList(head);
}