#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define errorf(str, ...) fputs("\x1b[31m", stderr); fprintf(stderr, str, __VA_ARGS__); fputs("\x1b[0m", stderr); exit(1);

enum Heavy{doublyleft = -2, left = -1, neutral = 0, balanced = 0, right = 1, doublyright = 2};
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

void print2DUtil(avlTree root, int space);
void print2D(avlTree root);
avlTree insert(avlTree root, int value);
avlTree fixup(avlTree mainRoot, avlTree Node);
avlTree rotate(avlTree mainRoot, avlTree Node);
avlTree leftRotate(avlTree root, avlTree x);
avlTree rightRotate(avlTree root, avlTree y);
int* max(int* a , int* b);

void setHeight(avlTree Node)
{
    if (!Node) {return;}

    int rightHeight = -1;
    int leftHeight = -1;

    if (Node->right) {rightHeight = Node->right->height;}
    if (Node->left)  {leftHeight  = Node->left->height; }

    Node->height = *(max(&leftHeight, &rightHeight)) + 1;
    Node->heavy = rightHeight - leftHeight;
}

avlTree createNode(int value)
{
    avlTree Node  = malloc(sizeof(struct treeNode));
    Node->left  = NULL;
    Node->right = NULL;
    Node->parent = NULL;
    Node->val   = value; 
    return Node;   
}

//set height
//set heavy
//set parent
avlTree insert(avlTree root, int value)
{
    if      (root==NULL)     
    {
        root = createNode(value);
        root->parent = NULL;
        return root;
    }
    
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

avlTree which_child(avlTree Node)
{
    // if avlTree
}

// assuming that the node to be deleted exists in tree
avlTree delete(avlTree mainRoot, avlTree Node)
{
    if (!mainRoot) {return NULL;}

    // if Root is deleted:

    // if Node is NOT root:
        //check whether Node is left or right child
        // set Dynamic = left/right
    //if (Node->right == NULL && Node->left == NULL) {Node->parent->"Dynamic"}
}


// used to update tree and respective pointers after an insertion:
    // set correct heights of parents
    // perform rotation if necessary
avlTree fixup(avlTree mainRoot, avlTree Node)
{
    if (!mainRoot)  {return NULL;}
    if (!Node)      {return mainRoot;}
    // Node is the address where the last insert() took place
    avlTree p = Node->parent;
    
    setHeight(Node);

    if (Node->heavy == doublyleft || Node->heavy == doublyright)
    {mainRoot = rotate(mainRoot, Node);}

    if (p)      {return fixup(mainRoot, p);}
    else        {return mainRoot;}
}

// fix heights after rotation
avlTree rotate(avlTree mainRoot, avlTree Node)
{
    if (!mainRoot)  {return NULL;}
    if (!Node)      {return mainRoot;}

    if      (Node->heavy == doublyright)
    {
        /*doubly rotn*/
        if (Node->right->heavy == left)
        {
            // first right rotate along Node's rightchild
            mainRoot = rightRotate(mainRoot, Node->right);
            mainRoot = leftRotate(mainRoot, Node);
        }
        /* single left rotation */
        else if  (Node->right->heavy == right || Node->right->heavy == balanced) 
        {
            mainRoot = leftRotate(mainRoot, Node);
        }
    }

    else if (Node->heavy == doublyleft)
    {
        /*doubly rotn*/
        if (Node->left->heavy == right)
        {
            // first left rotate along Node's rightchild
            mainRoot = leftRotate(mainRoot, Node->left);
            mainRoot = rightRotate(mainRoot, Node);
        }
        /* single right rotation */
        else if  (Node->left->heavy == left || Node->left->heavy == balanced) 
        {
            mainRoot = rightRotate(mainRoot, Node);
        }
    }

    return mainRoot;
}

avlTree leftRotate(avlTree root, avlTree x)
{
    if (!x) {return NULL;}

    // y is initially the right child of x, 
    // it becomes the parent of x

    avlTree p = x->parent;
    avlTree y = x->right;

    x->right = y->left; 
    if (y->left) {y->left->parent = x;}

    y->parent = p;
    if      (!p)             {root = y;}
    else if (p->left  == x)  {p->left = y;}
    else                     {p->right = y;}

    y->left = x;
    x->parent = y;

    setHeight(x);
    setHeight(y);

    return root;
}

avlTree rightRotate(avlTree root, avlTree y)
{
    if (!y) {return NULL;}

    // y is initially the left child of x, 
    // it becomes the parent of x

    avlTree p = y->parent;
    avlTree x = y->left;

    y->left = x->right; 
    if (x->right) {x->right->parent = y;}

    x->parent = p;
    if      (!p)             {root = x;}
    else if (p->right  == y)  {p->right = x;}
    else                     {p->left = x;}

    x->right = y;
    y->parent = x;

    setHeight(y);
    setHeight(x);

    return root;
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
        else        
        {
            avlTree leaf = insert(Mainroot, A[i]);
            Mainroot = fixup(Mainroot, leaf);
        }
    }
    return Mainroot;
}

avlTree findMin(avlTree root)
{
    avlTree current = root;
    while (current->left) {current = current->left;}
    return current;
}

avlTree findMax(avlTree root)
{
    avlTree current = root;
    while (current->right) {current = current->right;}
    return current;
}

avlTree find_successor(avlTree Root, int val)
{
    if (!Root) {return NULL;}
    avlTree current = search(Root, val);
    if (!current) {return NULL;}

    avlTree succ = NULL;
    if (current->right != NULL) {succ = findMin(current->right);}
    else 
    {
        avlTree c = current  ; // current
        avlTree p = c->parent; // current's parent

        while (p && p->right == c)
        {
            p = p->parent;
            c = c->parent;
        }
        succ = p;
    }
    return succ;
}

avlTree find_predecessor(avlTree Root, int val)
{
    if (!Root) {return NULL;}
    avlTree current = search(Root, val);
    if (!current) {return NULL;}

    avlTree pred = NULL;
    if (current->left != NULL) {pred = findMax(current->left);}
    else 
    {
        avlTree c = current  ; // current
        avlTree p = c->parent; // current's parent

        while (p && p->left == c)
        {
            p = p->parent;
            c = c->parent;
        }
        pred = p;
    }
    return pred;
}

avlTree findRoot(avlTree Node)
{
    if (!Node)          {return NULL;}
    while (Node->parent != NULL) {Node = Node->parent;}  
    return Node;
}

void printNode(avlTree pNode)
{
    if(!pNode)  {printf("NULL node.\n");}
    else        {printf("Address: %p, Val:%d\n", pNode, pNode->val);}
}

int* max(int* a , int* b)
{
    return (*a > *b ? a : b);
}


// stolen code here onwards
#define COUNT 3
void print2DUtil(avlTree root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(avlTree root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}