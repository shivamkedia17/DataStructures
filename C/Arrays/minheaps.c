#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrays.c"

#define LEN(A) (sizeof(A)/sizeof(A[0]))

void insert(int *H)
{

}

void swap(int *H, int a, int b)
{
    int temp = H[a];
    H[a] = H[b];
    H[b] = temp;
}

void heapify_up(int *H, int child)
{
    int l = LEN(H);
    
    //We don't want to heapify the topmost node
    for (int i = l-1; i > 0; i--)
    {
        int p = findparent(i);
        if (p != i && H[p] > H[i]) {swap(H, p, i);}
    }
}

void heapify_down(int *H)
{
    int l = LEN(H);
    for (int i = 0; i < l; i++)
    {
        if (isparent(i,l)) {swapleast(H, i, l);}
    }
}

bool isparent(int n, int l)
{
    if(findchild_right(n) >= l)     {return false;}
    else                            {return true; }  
}

int swapleast(int *H, int p, int l)
{
    //find left and right child, 
    int left  = findchild_left (p);
    int right = findchild_right(p);

    //swap with least of the 3
    int m = min(H, p, min(H, left, right));
    if (p != m) {swap(H, p, m);}
}

int extract_min(int *H)
{

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
int min(int *H, int a, int b)
{
    int l = LEN(H);
    if (a >= l || b >= l) {return -1;}

    int lesser_ind = H[a] < H[b]? a:b;
    return lesser_ind;
}