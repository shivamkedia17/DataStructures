#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heaps.c"

int insert(int *H, int l,int val);
void heapify_up(int *H, int child);
void heapify_down(int *H, int l, int parent);
int swapleast(int *H, int l, int p);
void extract_min(int *H, int l);
int extract_min_pop(int *H, int l);

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

void extract_min(int *H, int l)
{
    swap(H, 0, l-1);
    heapify_down(H, l, 0);
}

//returns new length of H
int extract_min_pop(int *H, int l)
{
    swap(H, 0, l-1);
    heapify_down(H, l, 0);

    int newlen = l - 1;
    
    //delete last element
    H = realloc(H, newlen * sizeof(int));

    return newlen;
}

void heapify_up(int *H, int child)
{
    int p = findparent(child);
    if (p != child && H[p] > H[child]) 
    {
        swap(H, p, child);
        heapify_up(H, p);
    }
    return;
}

void heapify_down(int *H, int l, int parent)
{
    if (isparent(parent,l))
    {
        int least = swapleast(H, l, parent);
        heapify_down(H, l, least);
    }
    return;
}

int swapleast(int *H, int l, int p)
{
    //find left and right child, 
    int left  = findchild_left (p);
    int right = findchild_right(p);

    //swap with least of the 3
    int least = min(H, l, p, min(H, l, left, right));
    if (p != least) {swap(H, p, least);}
    return least;
}