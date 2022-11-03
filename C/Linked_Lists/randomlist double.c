#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "QuickSortDoublyList.c"

int main(int argc, char** argv)
{
    // int l = 0;
    // switch (argc)
    // {
    //     case 1:
    //         printf("Enter Size of List: ");
    //         scanf("%d",&l);  
    //         break;

    //     case 2:
    //         sscanf(argv[1], "%d", &l);
    //         break;

    //     default:
    //         fprintf(stderr, "Usage: %s [list_size]\n", argv[0]);
    //         return 1; 
    //         break;
    // }

    // int *A = genArray(l);
    // printArray(l, A);

    int A[] = {21,222,19,18,16,24,1,9};
    int l = sizeof(A) / sizeof(A[0]);

    nodePointer head = genlistFromArray(l, A); 

    printf("Linked List: ");
    printLinkedList(head);

    printf("%p,%d\n",head,head->val);


    printf("hehe\n");
    nodePointer end = findTail(head);
    printf("%d\n",end->val);

    // /* Appends to a list
    // int x;
    // printf("Enter Element to append : ");
    // // scanf("%d",&x); 
    // head = append(head, 66);
    // */

    // head = reverseList(head); 
    // printf("Linked List After Reversing: ");
    // printLinkedList(head);

    // printf("\n%d\n",countNodes(head));

    // swap(head,end);

    // nodePointer ind = partition(head,end);
    // printf("%p,%d\n",ind,ind->val);
    // printLinkedList(head);

    printf("After Quick Sorting: ");
    quicksortlist(head, end);

    printLinkedList(head);

    
    // free(A);
    freeList(head);
}