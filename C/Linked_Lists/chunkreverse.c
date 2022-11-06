#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include "arrays.c"

// typedef struct List_Start_End
// {
//     nodePointer StartNode;
//     nodePointer EndNode;
// }
// *List_Start_End

nodePointer chunk_reverseList(nodePointer head, int chunk_size)
{   
    //int *revlist = malloc(chunk_size * sizeof(int));
    
    //readlist in chunk sizes from end of array
    //if node->next is NULL, realloc array to whatever it is now.
    //create list using reversed array
    //OR
    //create list of chunk_size using current array

    nodePointer startNode = head;
    nodePointer endNode;
    while (startNode->next != NULL)
    {
        nodePointer tempHead = malloc(sizeof(nodePointer));
        tempHead->val = 0;
        tempHead->next = NULL;

        nodePointer tempNode = tempHead;

        nodePointer prevEnd;
        nodePointer nextStart;

        
        //store start and end,
        //snip list at prev start and end next (set them to NULL)
            //check for edge cases,
            // i.e if start = head OR end -> next = NULL
        // reverse(start)
        //prev-start->next = reverse(start)
        //reverse.end->next = end next

        //optimize for concat:
            //either create struct and get start,end from reverse()
            //or create different function


        for (int i = 1; i <= chunk_size; i++)
        {
            if (currentNode)
            {
                if (startNode == head) {prevEnd = NULL;}
                
                if (i == chunk_size)
                {
                    endNode = currentNode;
                }
            }
            
            
            //free temp
        }
        
    }
}

