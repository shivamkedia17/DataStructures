#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

int main(void)
{
    // Array to store the actual values in memory,
    // we'll pass pointers to these elements to build our sets
    int l = 10; 
    int A[] = {10, 17, 22, 34, 39, 888, 663, 6969, 2222, 5};

    // Array to store the items
    Item * items = (Item*) malloc(sizeof(Item)*l);
    Set * sets  = (Set*)  malloc(sizeof(Set )*l);

    // Make l singleton sets, 10 in this case
    for (int i = 0; i < l; i++)
    {
        Item x = (Item) malloc(sizeof(struct disjointSetItem));
        if (!x)
        {
            fprintf(stderr, "Malloc failed\n");
            exit(1);
        }
        items[i] = x;
        x->value = A[i];
        x->set = MakeSet(x);
        sets[i] = x->set;
    }

    // 4 unions
    
    printSets(sets, l);
    Union(items[0], items[1], sets, l);
    printSets(sets, l);
    Union(items[2], items[3], sets, l);
    printSets(sets, l);;
    Union(items[4], items[5], sets, l);
    printSets(sets, l);
    Union(items[0], items[2], sets, l);
    printSets(sets, l);

    // 3 finds

    printf("FindSet(39): ");
    printSet(FindSet(items[4]));
    printf("\n");


    printf("FindSet(5): ");
    printSet(FindSet(items[9]));
    printf("\n");

    printf("FindSet(10): ");
    printSet(FindSet(items[0]));
    printf("\n");

    return 1;
}