#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "avlTree.c"

int main(int argc, char** argv)
{
    int A[] = {4,2,1,3,6,5,7};
    int l = 7;

    avlTree Root = genTree_Array(l, A);
    printTree(Root, 1);

    presentInsideTree(Root, 45);

    insert(Root, 45);
    printTree(Root, 1);

    presentInsideTree(Root, 45);
    freeTree(Root);
}
