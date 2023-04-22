#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

Node createNode(Item x)
{
    Node node = (Node) malloc(sizeof(struct ListNode));
    if (!node)  {return NULL;}

    node->item = x;
    node->next = NULL;
    return node;
}

List initList(Item x)
{
    Node node = createNode(x);
    List list = (List) malloc(sizeof(struct List));
    if (!list || !node)  {return NULL;}

    list->head = node;
    list->tail = node;
    list->size = 1;

    return list;
}

void appendNode(List list, Node x)
{
    if (!list || !x)    {return;}
    list->tail->next    = x;
    list->tail          = x;
    list->size++;
    return;
}

void joinLists(List first, List second)
{
    if (!first || !second)  {return;}

    first->tail->next = second->head;
    first->tail = second->tail;
    first->size = first->size + second->size;

    // free only the struct, the elements of the list have been concated to first
    free(second);
    // return first;
    return;
}

void assignSet(List list, Set set)
{
    if (!list || !set)  {return;}
    for (Node current = list->head; current; current = current->next)
    {
        current->item->set = set;
    }
}


Set MakeSet(Item element)
{
    Set x = (Set) malloc(sizeof(struct disjointSet));
    x->parent   = element;
    x->list     = initList(element);

    return x;
}

Set FindSet(Item element)
{
    // Assume: x exists in one of the sets

    if (element)
        return element->set;
    else 
        return NULL;
}

void Union(Item x, Item y, Set* sets, int n)
{
    if (!x || !y) 
    {
        fprintf(stderr, "Null Input to Union().\n");
        // return NULL;
        return;
    }

    printf("Joining sets with items %d, %d\n", x->value, y->value);

    Set a = FindSet(x);
    Set b = FindSet(y);

    if (a->list->size >= b->list->size)      
    {
        assignSet(b->list, a);
        joinLists(a->list, b->list);
        for (int i = 0; i < n; i++)
        {
            if (sets[i] == b)
            {
                sets[i] = NULL;
                break;
            }
        }
        free(b);
        // return a;
    }
    else                       
    {
        assignSet(a->list, b);
        joinLists(b->list, a->list);
        for (int i = 0; i < n; i++)
        {
            if (sets[i] == a)
            {
                sets[i] = NULL;
                break;
            }
        }
        free(a);
        // return b; 
    }
    return;
    // return NULL;
}

void printItem(Item x)
{
    if (!x) {return;}
    printf("Set: %p, Value: %d \n", x->set, x->value);
    return;
}

void printValue(Item x)
{
    if (!x) {return;}
    printf("%d ", x->value);
    return;
}

void printList(List list)
{
    // printf("Printing list at %p\n", list);
    for (Node current = list->head; current != NULL; current = current->next)
    {
        printValue(current->item);
        printf(current->next? ", ":" ");
    }
    return;
}

void printSet(Set x)
{
    printf("\n{ ");
    printList(x->list);
    printf("}, ");
    printf("Parent: ");
    printValue(x->parent);
    return;
}

void printSets(Set* sets, int l)
{
    printf("Sets:");
    for (int i = 0; i < l; i++)
    {
        if (sets[i])
            {printSet(sets[i]);}
    }
    printf("\n--------------------------\n");
}

void freeList(List list)
{
    if (!list)  {return;}
    Node current = list->head;
    while(current->next)
    {
        Node temp = current;
        current = current->next;
        free(temp);
    }
    free(current);
    free(list);
    return;
}

void FreeSet(Set x)
{
    // Free the memory
    freeList(x->list);
    free(x);
    return;
}
