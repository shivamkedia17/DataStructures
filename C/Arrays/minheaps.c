#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN(A) (sizeof(A)/sizeof(A[0]))

int insert(int *H, int l,int val);
void swap(int *H, int a, int b);
void heapify_up(int *H, int child);
void heapify_down(int *H, int l, int parent);
bool isparent(int n, int l);
int swapleast(int *H, int l, int p);
void extract_min(int *H, int l);
int findchild_left(int p);
int findchild_right(int p);
int findparent(int c);
int min(int *H, int l, int a, int b);

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

void swap(int *H, int a, int b)
{
    int temp = H[a];
    H[a] = H[b];
    H[b] = temp;
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

bool isparent(int n, int l)
{
    if(findchild_right(n) >= l)     {return false;}
    else                            {return true; }  
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

int findchild_left(int p)
{
    int c = (2*p) + 1;
    return c;
}

int findchild_right(int p)
{
    int c = (2*p) + 2;
    return c;
}

int findparent(int c)
{
    int p = (c-1) / 2;
    return p;
}

//takes two indexes, returns the index containing the lesser value
int min(int *H, int l, int a, int b)
{
    if (a >= l || b >= l) {return -1;}

    int lesser_ind = H[a] < H[b] ? a:b;
    return lesser_ind;
}