#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#pragma once
#include "showheap.c"
#include "heaps.c"

int findsmallestchild(int *H, int l, int p);

void heapify_up(int *H, int l, int child)
{
    if (l < 1) {return;}

    int p = findparent(child);
    if (p != child && H[p] < H[child]) //op
    {
        assert(H[p] < H[child]);
        swap(H, p, child);
        heapify_up(H, l, p);
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
    heapify_up(H, l, (newlen-1));
    
    return newlen;
}

void heapify_down(int *H, int l, int parent)
{
    if (l < 0) {return;}

    if (isparent(parent,l))
    {
        int least = findsmallestchild(H, l, parent);
        if (parent != least) 
        {
            swap(H, parent, least);
            heapify_down(H, l, least);
        }
    }
    return;
}

void extract_max(int *H, int l)
{
    if (l < 2) {return;}
    swap(H, 0, l-1); 
    heapify_down(H, l-1, 0);
}

//returns new length of H
int extract_max_pop(int *H, int l)
{
    if (l < 0) {return -1;}

    swap(H, 0, l-1);
    heapify_down(H, l, 0);

    int newlen = l - 1;
    
    //delete last element
    H = realloc(H, newlen * sizeof(int));

    return newlen;
}

int findsmallestchild(int *H, int l, int p)
{
    if (p < 0 || p >= l) {return -1;}
    
    //find left and right child, 
    int left  = findchild_left (p);
    int right = findchild_right(p);

    //swap with least of the 3
    int least;
    if (right >= l) {least = min(H, l, left, p);}
    else            {least = min(H, l, p, min(H, l, left, right));}
    return least;
}

void build_minheap_array(int*H, int l)
{
    int start = findlastparent(l); // get index of last parent
    for (int i = start; i >= 0; i--) {heapify_down(H, l, i);}   
}


