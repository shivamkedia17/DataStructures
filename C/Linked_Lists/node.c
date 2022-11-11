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
        char* chars;
        if(newNode->next == NULL) {chars = ".";}
        else {chars = ", ";}
        printf("%d%s", newNode->val,chars);
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
        HEAD = malloc(sizeof(struct node));
        HEAD->val = A[0];
        HEAD->next = NULL;
        currentNode = HEAD;
    }

    for(int i = 1; i < l; i++)
    {
        //creating new node
        currentNode->next = malloc(sizeof(struct node));
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

    current->next = malloc(sizeof(struct node));
    current = current->next;
    current->val = val;
    current->next = NULL;
    return start;
}

nodePointer concatLists(nodePointer start, nodePointer tail)
{
    nodePointer current = start;
    
    //seek to end of list
    while (current->next)
    {
        current = current->next;
    }

    current->next = tail;
    return start;
}

nodePointer duplicatelist(nodePointer head)
{
    if (head == NULL) {return NULL;}
    
    nodePointer newHead;
    
    newHead = malloc(sizeof(struct node));
    newHead->val  = head->val;
    newHead->next = NULL;

    nodePointer currentNode = head;
    nodePointer newNode = newHead;
   
    while (currentNode->next)
    {
        //Iterating
        currentNode = currentNode->next;

        //creating new node
        newNode->next = malloc(sizeof(struct node));
        //attaching new node to list
        newNode = newNode->next;
        //assigning value to new node
        newNode->val = currentNode->val;
        //Demarcating the end of list
        newNode->next = NULL;
    }
    return newHead;
}

nodePointer reverseList(nodePointer head)
{
    if(head == NULL)
    {
        fprintf(stderr,"Cannot reverse null list.\n");
        return NULL;
    }

    nodePointer prevNode = head; //set to first node
    nodePointer currentNode = head->next; // set to second node
    head = head->next; // move to second node

    prevNode->next = NULL; 
    
    printf("3");
    while (head)
    {
        printf("4");
        head = head->next; //move to next node
        currentNode->next = prevNode; //connect previous node
        prevNode = currentNode; //move the new Head
        currentNode = head; //move to next node
    }

    head = prevNode; //set head to end of list (aka start of new one)
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