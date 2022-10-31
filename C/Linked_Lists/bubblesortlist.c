#include <stdio.h>
#include <stdlib.h>
#include "node.c"

nodePointer bubbleSortlist(nodePointer HEAD)
{
    int done;
    int n = countNodes(HEAD);

    //Refer to BubbleSort (Array version), does the same thing
    for (done = 0; done < n-1; done++)
    {
        nodePointer currentNode = HEAD;

        for (int current = 0; current < n-done-1; current++)
        {
            if(currentNode->val > currentNode->next->val)
            {
                int temp = currentNode->val;
                currentNode->val = currentNode->next->val;
                currentNode->next->val = temp;
            }
            currentNode = currentNode->next;
        }
    }
    return HEAD;
}