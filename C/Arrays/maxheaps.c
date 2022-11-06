#include <stdio.h>
#include <stdlib.h>
#include "heaps.c"

int swapgreatest(int *H, int l, int p);

void heapify_up(int *H, int child)
{
    int p = findparent(child);
    if (p != child && H[p] < H[child]) 
    {
        swap(H, p, child);
        heapify_up(H, p);
    }
    return;
}

//returns new length of H
int insert(int *H, int l, int val)
{
    int newlen = l + 1;
    
    //make space for new element
    H = realloc(H, newlen * sizeof(int));
    
    //put new element in last spot
    H[newlen - 1] = val;
    heapify_up(H, (newlen-1));
    
    return newlen;
}

void heapify_down(int *H, int l, int parent)
{
    if (isparent(parent,l))
    {
        int least = swapgreatest(H, l, parent);
        heapify_down(H, l, least);
    }
    return;
}

void extract_max(int *H, int l)
{
    swap(H, 0, l-1);
    heapify_down(H, l, 0);
}

//returns new length of H
int extract_max_pop(int *H, int l)
{
    swap(H, 0, l-1);
    heapify_down(H, l, 0);

    int newlen = l - 1;
    
    //delete last element
    H = realloc(H, newlen * sizeof(int));

    return newlen;
}

int swapgreatest(int *H, int l, int p)
{
    //find left and right child, 
    int left  = findchild_left (p);
    int right = findchild_right(p);

    //swap with least of the 3
    int greatest = max(H, l, p, max(H, l, left, right));
    if (p != greatest) {swap(H, p, greatest);}
    return greatest;
}

