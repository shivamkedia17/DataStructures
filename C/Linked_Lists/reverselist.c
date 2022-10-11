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


nodePointer reverseList(nodePointer head)
{
    if(head == NULL)
    {
        fprintf(stderr,"Cannot reverse null list.");
        return NULL;
    }

    nodePointer prevNode, currentNode = head;
    
    head = head->next;
    currentNode = head;
    prevNode->next = NULL; 
    
    while (head)
    {
        head = head->next; //move to next node
        currentNode->next = prevNode; 
        prevNode = currentNode;
        currentNode = head;
    }

    head = prevNode;
    return head;
}
