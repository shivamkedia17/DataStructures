#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Heavy{doublyleft = -2, left = -1, neutral = 0, right = 1, doublyright = 2};
typedef enum Heavy Heavy;

struct treeNode
{
    int val;
    int height;
    Heavy heavy;
    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *parent;
};

typedef struct treeNode *avlTree;

avlTree createNode(int value) // Todo
{
    avlTree Node  = malloc(sizeof(struct treeNode));
    Node->left  = NULL;
    Node->right = NULL;
    Node->val   = value; 
    //set height
    //set parent
    return Node;   
}

int* max(int* a , int* b)
{
    return (*a > *b ? a : b);
}

int main()
{
    avlTree Node = createNode(12);
    Node->heavy = doublyleft;
    int e = 13;
    int f = 27;
    printf("%d",*(max(&e, &f)));
    printf("%d", Node->heavy);
    free(Node);
}