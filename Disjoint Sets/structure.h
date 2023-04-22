#ifndef STRUCTURE_H
#define STRUCTURE_H
#endif

// Define the Disjoint Set Data Structure
struct disjointSetItem;
struct ListNode;
struct List;
struct disjointSet;

typedef struct disjointSet*     Set;
typedef struct disjointSetItem* Item;
typedef struct ListNode*        Node;
typedef struct List*            List;

struct disjointSetItem{
    int value;  // Integer in the node
    Set set;   // pointer to the set to which it belongs
};

// Define the Disjoint Set Data Structure
struct ListNode {
    Item    item;
    Node    next;
};

struct List {
    Node head;
    Node tail;
    int size;
};

struct disjointSet{
    Item parent; // Representative of the Set
    List list;              // Store linked list of items in the set
};


// functions

Node createNode(Item x);
List initList(Item x);
void appendNode(List list, Node x);
void joinLists(List first, List second);
void freeList(List list);
void assignSet(List list, Set set);
Set MakeSet(Item element);
Set FindSet(Item element);
void Union(Item x, Item y, Set* sets, int n);
void FreeSet(Set x);


void printSet(Set x);
void printSets(Set* sets, int l);

void printList(List list);
void printItem(Item x);