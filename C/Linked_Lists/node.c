#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
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

    if (HEAD == NULL) 
    {
        HEAD = malloc(sizeof(nodePointer));
        HEAD->val = A[0];
        HEAD->next = NULL;
        currentNode = HEAD;
    }

    for(int i = 1; i < l; i++)
    {
        //creating new node
        currentNode->next = malloc(sizeof(nodePointer));
        //attaching new node to list
        currentNode = currentNode->next;
        //assigning value to new node
        currentNode->val = A[i];
        //Demarcating the end of list
        currentNode->next = NULL;
    }
    return HEAD;
}

nodePointer append(nodePointer start, int val)
{
    nodePointer current = start;
    
    //seek to end of list
    while (current->next)
    {
        current = current->next;
    }

    current->next = malloc(sizeof(nodePointer));
    current = current->next;
    current->val = val;
    current->next = NULL;
    return start;
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