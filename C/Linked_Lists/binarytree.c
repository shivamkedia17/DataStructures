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
    bTree Node  = malloc(sizeof(struct treeNode));
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
        return root;
    }
    else
    {
        if      (value < root->val)  
        {
            if (root->left == NULL) 
            {
                root->left = createNode(value);
                return root->left;
            }
            else            
            {
                return insert(root->left, value);
            }
        }
        else if (value > root->val)  
        { 
            if (root->right == NULL) 
            {
                root->right = createNode(value);
                return root->right;
            }
            else            
            {
                return insert(root->right, value);
            }
        }
        else                         
        {
            return root;
        }
    }
}

bTree search(bTree root, int value)
{
    if      (root==NULL)         {return root;}
    if      (value < root->val)  {return search(root->left, value);}
    else if (value > root->val)  {return search(root->right, value);}
    else                         {return root;}
}

void presentInsideTree(bTree root, int value)
{
    bTree result = search(root,value);
    if(result != NULL)
    {
        printf("Value contained in tree at: %p.\n",result);
    }
    else
    {
        printf("Value NOT contained in tree.\n");
    }
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

void showTree_infix(bTree root) // LEFT ROOT RIGHT
{
    if(root)
    {
        if (root-> left) {showTree_infix(root-> left);}
        printf(" ");
        printf("%d",root->val);
        printf(" ");
        if (root->right) {showTree_infix(root->right);}
    }
}

void showTree_prefix(bTree root) // ROOT LEFT RIGHT
{
    if(root)
    {
        printf(" ");
        printf("%d",root->val);
        printf(" ");
        if (root-> left) {showTree_prefix(root-> left);}
        if (root->right) {showTree_prefix(root->right);}
    }
}

void showTree_postfix(bTree root) // LEFT RIGHT ROOT
{
    if(root)
    {
        if (root-> left) {showTree_postfix(root-> left);} 
        if (root->right) {showTree_postfix(root->right);}
        printf(" ");
        printf("%d",root->val);
        printf(" ");
    }
}

void printTree(bTree root, int type)
{
    switch (type)
    {
        case 1:     //In-order traversal
            showTree_infix(root);
            printf("\n");
            break;

        case 2:     //Preorder traversal
            showTree_prefix(root);
            printf("\n");
            break;

        case 3:     //Postorder traversal
            showTree_postfix(root);
            printf("\n");
            break;
        
        default:    //Inorder as default
            showTree_infix(root);
            printf("\n");
            break;
    }
}

bTree genTree_Array(int l, int *A)
{
    bTree Mainroot = NULL;
    for (int i = 0; i < l; i++)
    {
        if (i == 0) {Mainroot   = insert(Mainroot, A[i]);}
        else        {bTree leaf = insert(Mainroot, A[i]);}
    }
    return Mainroot;
}