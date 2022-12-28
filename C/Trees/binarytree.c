#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct treeNode
{
    int val;
    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *parent;
}*bTree;

enum children{left_child = -1, not_child = 0, right_child = 1};

typedef enum children whichChild;

bTree createNode(int value)
{
    bTree Node  = malloc(sizeof(struct treeNode));
    Node->left  = NULL;
    Node->right = NULL;
    Node->parent = NULL;
    Node->val   = value; 
    return Node;   
}

bTree insert(bTree root, int value)
{
    if      (root==NULL)     {return createNode(value);}
    
    if      (value < root->val)  
    {
        if (root->left == NULL) 
        {
            root->left = createNode(value);
            root->left->parent = root;
            return root->left;
        }
        else            {return insert(root->left, value);}
    }
    else if (value > root->val)  
    { 
        if (root->right == NULL) 
        {
            root->right = createNode(value);
            root->right->parent = root;
            return root->right;
        }
        else            {return insert(root->right, value);}
    }
    else                {return root;}
}

int countChild(bTree Node)
{
    if (Node == NULL) {return -1;}
    bool r = false;
    bool l = false;
    if (Node->right != NULL) {r = 1;}
    if (Node->left  != NULL) {l = 1;}
    int c = l + r;
    return c;
}

int which_Child(bTree Node)
{
    if (Node == NULL) 
    {
        perror("NULL Node passed as argument to which_child().");
        exit(EXIT_FAILURE);
    }
    if (Node->parent == NULL) {return 0;}
    else
    {
        if (Node->parent->left  == Node) {return -1;}
        if (Node->parent->right == Node) {return  1;}
    }
    return -5; // Unexpected Error, should ideally never be reached
}

bTree which_one_child(bTree Node)
{
    if (!Node) {return NULL;}
    //assuming Node has only one child
    if (!(Node->right) && (Node->left )) {return Node->left ;}
    if (!(Node->left ) && (Node->right)) {return Node->right;}
    return NULL;
}


bTree delete(bTree Root, bTree Node)
{
    if (Root == NULL)   {return NULL;}
    if (Node == NULL)   {return Root;}

    int ct = countChild(Node);
    switch (ct)
    {
    case 0: // set parent->node to NULL
        
        whichChild info = which_Child(Node);

        switch (info)
        {
        case left_child:
            Node->parent->left = NULL;
            free(Node);
            break;
        
        case right_child:
            Node->parent->right = NULL;
            free(Node);
            break;
        
        default:
            break;
        }
        break;
    //-----------------------------------------------------------------------------------------------

    case 1: // replace parent->node with parent->node_child

        whichChild info = which_Child(Node);
        bTree child = which_one_child(Node);

        switch (info)
        {
        default:
            break;

        case left_child:
            Node->parent->left = child;
            child->parent = Node->parent;
            free(Node);
            break;
        
        case right_child:
            Node->parent->right = child;
            child->parent = Node->parent;
            free(Node);
            break;
        }
        break;

    //-----------------------------------------------------------------------------------------------

    case 2:
        break;

    default:
        break;
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
    void (*printfunc) (bTree root);
    switch (type)
    {
        case 1:     //In-order traversal
            printfunc = showTree_infix;
            break;

        case 2:     //Preorder traversal
            printfunc = showTree_prefix;
            break;

        case 3:     //Postorder traversal
            printfunc = showTree_postfix;
            break;
        
        default:    //Inorder as default
            printfunc = showTree_infix;
            break;

    }
    printfunc(root);
    printf("\n");
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

bTree findMin(bTree root)
{
    bTree current = root;
    while (current->left) {current = current->left;}
    return current;
}

bTree findMax(bTree root)
{
    bTree current = root;
    while (current->right) {current = current->right;}
    return current;
}

bTree find_successor(bTree Root, int val)
{
    if (!Root) {return NULL;}
    bTree current = search(Root, val);
    if (!current) {return NULL;}

    bTree succ = NULL;
    if (current->right != NULL) {succ = findMin(current->right);}
    else 
    {
        bTree c = current  ; // current
        bTree p = c->parent; // current's parent

        while (p && p->right == c)
        {
            p = p->parent;
            c = c->parent;
        }
        succ = p;
    }
    return succ;
}

bTree find_predecessor(bTree Root, int val)
{
    if (!Root) {return NULL;}
    bTree current = search(Root, val);
    if (!current) {return NULL;}

    bTree pred = NULL;
    if (current->left != NULL) {pred = findMax(current->left);}
    else 
    {
        bTree c = current  ; // current
        bTree p = c->parent; // current's parent

        while (p && p->left == c)
        {
            p = p->parent;
            c = c->parent;
        }
        pred = p;
    }
    return pred;
}

void printNode(bTree pNode)
{
    if(!pNode)  {printf("NULL node.\n");}
    else        {printf("Address: %p, Val:%d\n", pNode, pNode->val);}
}