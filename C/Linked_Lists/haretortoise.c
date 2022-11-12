#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include "arrays.c"

void printfirsthalf(nodePointer HEAD)
{
    if (HEAD == NULL) {return;}
    nodePointer hare     = HEAD;
    nodePointer tortoise = HEAD;
    
    while (hare != NULL)
    {
        nodePointer nextHare = NULL;
        // nextHare = (hare->next) ? ((hare->next->next) ? (hare->next->next) : (hare->next)) : (hare->next);
        nextHare = (hare->next) ? (hare->next->next) : (hare->next);

        char* chars;
        if(nextHare == NULL) {chars = ".";}
        else {chars = ", ";}

        printf("%d%s", tortoise->val,chars);

        tortoise = tortoise->next;
        hare = nextHare;
    }
    printf("\n");
    return;
}