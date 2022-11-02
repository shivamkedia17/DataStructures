#include <stdio.h>
#include <stdlib.h>
#include "arrays.c"
#include "binarytree.c"

int main(int argc, char** argv)
{
    // int l = 0;
    // switch (argc)
    // {
    //     case 1:
    //         printf("Enter No. of nodes in Tree: ");
    //         scanf("%d",&l);  
    //         break;

    //     case 2:
    //         sscanf(argv[1], "%d", &l);
    //         break;

    //     default:
    //         fprintf(stderr, "Usage: %s [Tree_nodeCount]\n", argv[0]);
    //         return 1; 
    //         break;
    // }

    // int *A = genArray(l);
    // printArray(l, A);
    int A[] = {4,2,1,3,6,5,7};
    // int A[] = {3,1,4};

    bTree Root = genTree_Array(7, A);
    showTree_infix(Root);

    // free(&A);
    freeTree(Root);
}
