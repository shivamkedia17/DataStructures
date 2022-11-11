#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.c"

nodePointer insertionsortlist(nodePointer HEAD);
nodePointer insert_sorted(nodePointer head, nodePointer new);

nodePointer insertionsortlist(nodePointer HEAD)
{
    // empty list
    if(!HEAD) {return NULL;}

    // single element list
    if(HEAD->next == NULL) {return HEAD;}

    // 2-element list onwards: create list second element onwards
    nodePointer unsortedList_start = HEAD->next;

    //sever head
    HEAD->next = NULL;

    //Loop through unsorted list
    while(unsortedList_start != NULL)
    {
        nodePointer NextUnsorted = unsortedList_start->next;
        // take first element of unsorted list, insert into sorted list
        HEAD = insert_sorted(HEAD, unsortedList_start);
        unsortedList_start = NextUnsorted;
    }
    return HEAD;
}

nodePointer insert_sorted(nodePointer head, nodePointer new)
{
    //Create Dummy Node before head to use as iterator
    nodePointer iterNode = &((struct node) {0, head}); 

    while (iterNode->next != NULL && iterNode->next->val < new->val) 
    {iterNode = iterNode->next;}

    //Assert: 
    // Head ... iterNode < newNode
    // newNode <= iterNode->next ... end_of_list

    if (iterNode->next == head)
    {
        new->next = head;
        return new;
    }
    else
    {
        // Insert between iterNode and iterNode->next:
        // ... iterNode -> new Node -> iterNode->next ...
        nodePointer temp = iterNode->next;
        iterNode->next = new;
        new->next = temp;
        return head;
    }
}