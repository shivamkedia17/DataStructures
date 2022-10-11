#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include "arrays.c"

nodePointer chunk_reverseList(nodePointer head, int chunk_size)
{   
    //int *revlist = malloc(chunk_size * sizeof(int));
    
    //readlist in chunk sizes from end of array
    //if node->next is NULL, realloc array to whatever it is now.
    //create list using reversed array
    //OR
    //create list of chunk_size using current array

    nodePointer currentNode = head;
    while (currentNode->next != NULL)
    {
        nodePointer templist = malloc(sizeof(nodePointer));
        templist->val = 0;
        templist->next = NULL;

        nodePointer tempNode = templist;


        for (int i=0; i<chunk_size; i++)
        {
            if(currentNode->next)
            {
                templist 
            }
            //free temp
        }
    }
}

