#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int val;
    struct treeNode *left;
    struct treeNode *right;
}*bTree;

bTree createNode(int value)
{
    bTree Node;
    Node = malloc(sizeof(bTree));
    Node->left  = NULL;
    Node->right = NULL;
    Node->val   = value; 
    return Node;   
}

bTree insert(bTree root, int value)
{
    if      (root==NULL)         
    {
        root = createNode(value);
        printf("Inserted at new root: %p, value: %d\n",root,root->val);
        return root;
    }
    else
    {
        if      (value < root->val)  
            {
                if (root->left) {return insert(root->left , value);}
                else            
                {
                    root->left = createNode(value);
                    printf("Inserted at root: %p, value: %d\n",root,root->val);
                    return root->left;
                }
            }
        else if (value > root->val)  
            {
                if (root->right){return insert(root->right , value);}
                else            
                {
                    root->right = createNode(value);
                    printf("Inserted at root: %p, value: %d\n",root,root->val);
                    return root->right;
                }
            }
        else                         
            {return root;}
    }
}

bTree search(bTree root, int value)
{
    if      (root==NULL)         {return root;}
    if      (value < root->val)  {return search(root->left, value);}
    else if (value > root->val)  {return search(root->right, value);}
    else                         {return root;}
}


void freeTree(bTree root)
{
    if(root)
    {
        if (root->right) {freeTree(root->right);}
        if (root->left ) {freeTree(root->left );}
        free(root);
    }
}

void showTree_infix(bTree root)
{
    if(root)
    {
        printf(" ");
        if (root-> left) 
        {
            printf(" ");
            showTree_infix(root-> left);
            printf(" ");
        }
        
        printf("%d",root->val);
        
        if (root->right) 
        {
            printf(" ");
            showTree_infix(root->right);
            printf(" ");
        }
        printf(" ");
    }
}

void printTree(bTree root, int type)
{
    switch (type)
    {
        case 1:     //In-order traversal
            showTree_infix(root);
            break;

        // case 2:     //Preorder traversal
        //     showTree_prefix(root);
        //     break;

        // case 3:
        //     showTree_postfix(root);
        //     break;
        
        default:    //Postorder traversal
            showTree_infix(root);
            break;
    }
}

bTree genTree_Array(int l, int *A)
{
    bTree root;
    for (int i = 0; i < l; i++)
    {
        printf("%d\n", A[i]);
        if (i == 0) {root = insert(root, A[i]);}
        else        {       insert(root, A[i]);}
        //showTree_infix(root);
        printf("%d\n", root->val);
        printf("%d\n", A[i]);
        printf("\n");
    }
    return root;
}