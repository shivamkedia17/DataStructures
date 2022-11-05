#include <stdio.h>
#include <stdlib.h>
#include "node.c"

nodePointer insertionsort(nodePointer HEAD);
void find_insert(nodePointer HEAD, nodePointer movedNode, nodePointer prevMoved);

nodePointer insertionsort(nodePointer HEAD)
{
    nodePointer current;
    nodePointer prev;

    //sorted -- insert point -- sorted -- [current -- unsorted]
    for (prev = HEAD, current = HEAD->next;
         current != NULL;
         prev = prev->next, current = current->next)
    {
        find_insert(HEAD, current, prev);
        printf("called\n");
        printLinkedList(HEAD);
    }

    return HEAD;
}

void find_insert(nodePointer HEAD, nodePointer movedNode, nodePointer prevMoved)
{
    if(!HEAD || !movedNode) {return;}

    nodePointer prevNode = HEAD;
    nodePointer nextNode;

    //                 movedNode ||
    //                           \/
    //(sorted) prevNode -- insert point -- nextNode (sorted)- [*was here*] - unsorted

    if (prevNode->next) {nextNode = prevNode->next;}
    else                {nextNode = NULL;}

    printf("Listprev: %p, Current: %p, Listnext: %p\n", prevNode, movedNode, nextNode);
    printf("Started\n");
    while((nextNode != NULL) && (prevNode->val < movedNode->val))
    {
        prevNode = prevNode->next;
        nextNode = nextNode->next;
        printf("Listprev: %p, Current: %p, Listnext: %p\n", prevNode, movedNode, nextNode);
    }

    printf("Loop Exited \n");
    if (nextNode != movedNode)
    {
        prevMoved = movedNode->next;
        prevNode->next  = movedNode;
        movedNode->next = nextNode;
    }
    return;
}
