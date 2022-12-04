#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "avlTree.c"

int main(int argc, char** argv)
{
    // int A[] = {4,2,1,3,6,5,7};
    int A[] = {1,2,3,4,5,6,7};
    int l = 7;

    avlTree Root = genTree_Array(l, A);
    printTree(Root, 1);
    printf("\n");
    print2D(Root);
    printf("\n");

    freeTree(Root);
}
