#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int val;
    int height;
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
    return Node;   
}

avlTree insert(avlTree root, int value)
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

avlTree search(avlTree root, int value)
{
    if      (root==NULL)         {return root;}
    if      (value < root->val)  {return search(root->left, value);}
    else if (value > root->val)  {return search(root->right, value);}
    else                         {return root;}
}

void presentInsideTree(avlTree root, int value)
{
    avlTree result = search(root,value);
    if(result != NULL)
    {
        printf("Value contained in tree at: %p.\n",result);
    }
    else
    {
        printf("Value NOT contained in tree.\n");
    }
}

void freeTree(avlTree root)
{
    if(root)
    {
        if (root->right) {freeTree(root->right);}
        if (root->left ) {freeTree(root->left );}
        free(root);
    }
}

void showTree_infix(avlTree root) // LEFT ROOT RIGHT
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

void showTree_prefix(avlTree root) // ROOT LEFT RIGHT
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

void showTree_postfix(avlTree root) // LEFT RIGHT ROOT
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

void printTree(avlTree root, int type)
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

avlTree genTree_Array(int l, int *A)
{
    avlTree Mainroot = NULL;
    for (int i = 0; i < l; i++)
    {
        if (i == 0) {Mainroot   = insert(Mainroot, A[i]);}
        else        {avlTree leaf = insert(Mainroot, A[i]);}
    }
    return Mainroot;
}

avlTree findRoot(avlTree Node)
{
    if (!Node)          {return NULL;}
    while (Node->parent != NULL) {Node = Node->parent;}  
    return Node;
}