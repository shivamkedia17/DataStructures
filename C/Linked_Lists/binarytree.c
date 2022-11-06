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
        printf("Inserting at NULL root: %p\n", root);
        root = createNode(value);
        printf("Inserted at new root: %p, value: %d, left: %p, right: %p\n",root,root->val,root->left, root->right);
        return root;
    }
    else
    {
        if      (value < root->val)  
        {
            if (root->left == NULL) 
            {
                printf("Inserting at left root: %p\n", root);
                root->left = createNode(value);
                printf("Inserted at new root: %p, value: %d, left: %p, right: %p\n",root->left,root->left->val,root->left->left, root->left->right);
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
                printf("Inserting at right root: %p\n", root);
                root->right = createNode(value);
                printf("Inserted at new root: %p, value: %d, left: %p, right: %p\n",root->right,root->right->val,root->right->left, root->right->right);
                return root->right;
            }
            else            
            {
                return insert(root->right, value);
            }
        }
        else                         
        {
            printf("Value already exists at root: %p, value: %d, left: %p, right: %p\n",root,root->val,root->left, root->right);
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
            printf("\n");
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
    bTree Mainroot = NULL;
    for (int i = 0; i < l; i++)
    {
        printf("%d\n", A[i]);
        if (i == 0) {Mainroot   = insert(Mainroot, A[i]);}
        else        {bTree leaf = insert(Mainroot, A[i]);}
        //showTree_infix(root);
        printf("Root val: %d\n", Mainroot->val);
        printf("A i :%d\n", A[i]);
        printf("\n");
    }
    return Mainroot;
}