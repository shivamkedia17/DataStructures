#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include "arrays.c"

int main(int argc, char** argv)
{
    int l1 = 0;
    int l2 = 0;
    switch (argc)
    {
        case 1:
            printf("Enter Size of 1st List: ");
            scanf("%d",&l1);  

            printf("Enter Size of 1st List: ");
            scanf("%d",&l2); 
            break;

        case 3:
            sscanf(argv[1], "%d", &l1);
            sscanf(argv[2], "%d", &l2);
            break;

        default:
            fprintf(stderr, "Usage: %s [list1_size] [list2_size]\n", argv[0]);
            return 1; 
            break;
    }

    int *A = genArray(l1);
    int *B = genArray(l2);
    printArray(l1, A);
    printArray(l2, B);

    nodePointer head1 = genlistFromArray(l1, A); 
    nodePointer head2 = genlistFromArray(l2, B); 

    printf("Linked List1: ");
    printLinkedList(head1);
    
    printf("Linked List2: ");
    printLinkedList(head2);

    /* Appends to a list
    int x;
    printf("Enter Element to append : ");
    scanf("%d",&x); 
    head = append(head, x);
    */

    nodePointer head = concatLists(head1, head2); 
    printf("Linked List After Concatting: ");
    printLinkedList(head);
    
    head = reverseList(head);
    printf("Linked List After Reversing: ");
    printLinkedList(head);

    free(A);
    free(B);
    // freeList(head1);
    // freeList(head2);//already freed, when freeing head1 so yeah no need
    freeList(head);
}