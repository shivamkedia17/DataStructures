#include <stdbool.h>

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

//takes two indexes, returns the index containing the greater value
int max(int *H, int l, int a, int b)
{
    if (a >= l || b >= l) {return -1;}

    int greater_ind = H[a] > H[b] ? a:b;
    return greater_ind;
}

bool isparent(int n, int l)
{
    if(findchild_right(n) >= l)     {return false;}
    else                            {return true; }  
}

void swap(int *H, int a, int b)
{
    int temp = H[a];
    H[a] = H[b];
    H[b] = temp;
}