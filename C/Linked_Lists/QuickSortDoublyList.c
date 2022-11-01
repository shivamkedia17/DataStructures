#include <stdio.h>
#include <stdlib.h>
#include "doublynode.c"

void swap(nodePointer node1, nodePointer node2)
{
    if (node1==NULL || node2 == NULL) {return;}
    
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
    return;
}

nodePointer partition(nodePointer head, nodePointer tail)
{
    // Input validation
    if (head==NULL || tail == NULL) {return NULL;}
    else if  (head == tail)  {return head;}

    int pivot = head->val;
    nodePointer i = head->next;      //Everything Left  of i <= pivot
    nodePointer j = tail;           //Everything Right of j >  pivot

    while(i != j)//??
    {
        // At one point i and j will meet in the middle, 
        // but we don't stop there because we can't gurantee
        // whether that element at i = j is in the correct position,
        // so we stop AFTER that step,
        // i.e, when either i and j have crossed and are adjacent to each other
    
        if (i->val > pivot)
        {
            swap(i, j); //?? What if the value at j is also greater??
                        // i remains at the same place only j is changed
            j = j->prev; //Would require a doubly linked list??
        }
        else //(A[i] <= pivot)
        {
            i = i->next;
        }
    }
    if (i == j)//??
    {
        if (i->val > pivot)
        {
            swap(i, j); //?? What if the value at j is also greater??
                        // i remains at the same place only j is changed
            j = j->prev; //Would require a doubly linked list??
        }
        else //(A[i] <= pivot)
        {
            i = i->next;
        }
    }

    /*
    (i has crossed j) so:
    Assuming that whole array has now been sorted into two sections: 
    - start to j containing elements lesser  than pivot
    - i to stop  containing elements greater than pivot
    */

    swap(head, j);
    return j; //Since now contains pivot
}

void quicksortlist(nodePointer head, nodePointer tail)
{
    //Input validation
    if (head==NULL || tail == NULL || head==tail) {return;}

    // P is the pivot
    nodePointer p = partition(head, tail);

    quicksortlist(head, p->prev); //again??
    quicksortlist(p->next, tail);

}