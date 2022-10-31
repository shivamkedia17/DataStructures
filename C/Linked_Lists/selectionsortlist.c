#include <stdio.h>
#include <stdlib.h>
#include "node.c"

nodePointer selectionSortlist(nodePointer HEAD)
{
    if (HEAD ==  NULL) {return NULL;}

    int n = countNodes(HEAD);

    nodePointer startNode = HEAD;

    //Refer to SelectionSort (Array version), does the same thing
    for (int start = 0; start < n-1; start++)
    {
        nodePointer minNode = startNode;
        nodePointer currentNode = startNode->next;

        for (int current = start+1 ; current < n; current++)
        {
            if(currentNode->val < minNode->val)
            {
                minNode = currentNode;
            }
            currentNode = currentNode->next;
        }
        
        if (minNode != startNode)
        {
            int temp = startNode->val;
            startNode->val = minNode->val;
            minNode->val = temp;
        }
        startNode = startNode->next;
    }
    return HEAD;
}