#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} *nodePointer;

//Assume linked list is without loops
void printLinkedList(nodePointer HEAD)
{
    if(HEAD == NULL)
    {
        printf("Can't print empty list.\n");
        return;
    }
    nodePointer newNode = HEAD;
    while(newNode != NULL)
    {
        printf("%d ", newNode->val);
        newNode = newNode->next;
    }
    printf("\n");
}

int countNodes(nodePointer HEAD)
{
    int count = 0;
    nodePointer currentNode = HEAD;
    while(currentNode != NULL)
    {
        count++;
        currentNode = currentNode->next;
    }
    return count;
}

nodePointer findTail(nodePointer HEAD)
{
    nodePointer current = HEAD;
    
    //seek to end of list
    while (current->next)
    {
        current = current->next;
    }

    return current;
}

//returns HEAD of a new linked list generated from values in Array
nodePointer genlistFromArray(int l, int *A)
{
    nodePointer HEAD = NULL;
    
    if (l==0 || A == NULL)
    {
        printf("Empty Array.\n");
        return NULL; //CHECK WARNING
    }

    //allocate space for head
    //set currentnode
    //allocate space for newnode
    //set current -> next = newNode
    nodePointer currentNode;
    nodePointer previousNode;

    if (HEAD == NULL) 
    {
        HEAD = malloc(sizeof(nodePointer));
        HEAD->val = A[0];
        HEAD->next = NULL;
        HEAD->prev = NULL;
        currentNode = HEAD;
        previousNode = HEAD;
    }

    for(int i = 1; i < l; i++)
    {
        //creating new node
        currentNode->next = malloc(sizeof(nodePointer));
        //attaching new node to list
        currentNode = currentNode->next;
        currentNode->prev = previousNode;
        //assigning value to new node
        currentNode->val = A[i];
        //Demarcating the end of list
        currentNode->next = NULL;

        previousNode = previousNode->next;
    }
    return HEAD;
}

nodePointer append(nodePointer start, int val)
{
    if(start == NULL)
    {
        start = malloc(sizeof(nodePointer));
        start->val  = val; 
        start->next = NULL;
        start->prev = NULL;
        return start;
    }

    nodePointer current = start;
    
    //seek to end of list
    while (current->next)
    {
        current = current->next;
    }

    current->next = malloc(sizeof(nodePointer));

    nodePointer previous = current;
    current = current->next;
    current->val = val;
    current->next = NULL;
    current->prev = previous;
    return start;
}

nodePointer concatLists(nodePointer start, nodePointer tail)
{
    if(!start && !tail) {return NULL;}
    if(!tail)  {return start;}
    if(!start) {return tail; }

    nodePointer current = start;
    
    //seek to end of list
    while (current->next)
    {
        current = current->next;
    }

    current->next = tail;
    tail->prev = current;
    return start;
}

//TODO: chicken

// nodePointer reverseList(nodePointer head)
// {
//     if(head == NULL)
//     {
//         fprintf(stderr,"Cannot reverse null list.\n");
//         return NULL;
//     }

//     nodePointer prevNode = head; //set to first node
//     nodePointer currentNode = head->next; // set to second node
//     head = head->next; // move to second node

//     prevNode->next = NULL; 
    
//     printf("3");
//     while (head)
//     {
//         printf("4");
//         head = head->next; //move to next node
//         currentNode->next = prevNode; //connect previous node
//         prevNode = currentNode; //move the new Head
//         currentNode = head; //move to next node
//     }

//     head = prevNode; //set head to end of list (aka start of new one)
//     return head;
// }

void freeList(nodePointer HEAD)
{
    nodePointer prev;
    while (HEAD)
    {
        prev = HEAD;
        HEAD = HEAD->next;
        free(prev);
    }
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//