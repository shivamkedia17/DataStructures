#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include "arrays.c"

int main(int argc, char** argv)
{
    /*
    if (argc != 2){
        printf("Usage: ./main file_containing_input.txt");
        return 1;
    }
    int *A = getArray_File(argv[1]);
    */

    // if (argc != 2){
    //     printf("Usage: ./main size_list");
    //     return 1;
    // }
    // int l = (int) argc[1];
    int l = 0;
    printf("Enter Size of List: ");
    scanf("%d",&l);
    printf("%d\n",l);
    int *A = genArray(l);
    printArray(l, A);
    printf("Linked List: ");
    printLinkedList(genlistFromArray(l, A));
}