#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "binarytree.c"

int main(int argc, char** argv)
{
    int A[] = {4,2,1,3,6,5,7};
    int l = 7;

    bTree Root = genTree_Array(l, A);
    printTree(Root, 2);

    presentInsideTree(Root, 45);

    insert(Root, 45);
    printTree(Root, 2);

    presentInsideTree(Root, 45);
    
    freeTree(Root);
}
