#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include "arrays.c"

nodePointer chunk_reverseList(nodePointer head, int chunk_size)
{   
    nodePointer startNode = head;
    nodePointer newHead  = NULL;
    nodePointer prevTail = NULL;

    while (startNode != NULL)
    {   
        nodePointer iterNode = startNode;
        nodePointer chunkHead = startNode;

        // Last node in a chunk will (chunk-size - 1) steps from chunkHead 
        for (int i = 1; (iterNode->next != NULL) && (i < chunk_size); i++)
        {iterNode = iterNode->next;}

        if (iterNode != NULL)
        {
            nodePointer chunkEnd = iterNode;

            // Extract chunk of given size 
            startNode = chunkEnd->next;

            //Sever chunk from main list
            chunkEnd->next = NULL;

            // Assert: 
            // Broken into two lists:
            // [ChunkHead...ChunkEnd][startNode...end_of_list]

            //Store end of chunk (where start becomes end after reversing)
            chunkEnd = chunkHead;

            // newHead ... prevTail = list of reversed chunks

            if(newHead == NULL)
            {
                newHead  = reverseList(chunkHead); // Append to emptylist
                prevTail = chunkEnd; // Update prevTail
            }
            else
            {
                prevTail->next = reverseList(chunkHead); // Append to list of reversed chunks
                prevTail = chunkEnd;
            }
        }
    }

    return newHead;
}