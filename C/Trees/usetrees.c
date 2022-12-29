#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "binarytree.c"

int main(int argc, char** argv)
{
    int A[] = {44, 22, 11, 8, 17, 33, 29, 36, 66, 55, 77, 737};
    int l = 12;

    bTree Root = genTree_Array(l, A);
    print2D(Root);
    printf("---------------------------------------\n");

    Root = delete(Root, 737);
    print2D(Root);
    printf("---------------------------------------\n");

    freeTree(Root);
}
