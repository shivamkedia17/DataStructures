# DataStructures
Repository for CS-1203 (Monsoon 2022), Ashoka University.


## Codefile Descriptions

- ### Arrays
	- *arrays.c* - Basic array functions like print and generate (from a file OR a randomised input depending on the size of the array required).
	- *arraydata.txt* - Contains sample input to be read from file and fed into array.
	- *SelectionSort.c*
	- *InsertionSort.c*
	- *BubbleSort.c*
	- *QuickSort.c*
	- *HeapSort.c* - in progress

- ### Linked Lists
	Usually, the files with `main()` can accept the size of the list as a Command-line argument to create a random list.
	- *node.c* - Basic singly linked list functions like:
		- print, free, append, concat, reverse, countNodes, duplicate, etc.
		- generate (from a randomly created array depending on the size of the list).
	- *doublynode.c* - Similar basic functions for doubly linked lists, alongwith (findTail, etc.)
	- *Sorting lists*:
		- *SelectionSort.c*
		- *InsertionSort.c*
		- *BubbleSort.c*
		- *QuickSort.c* - Uses doubly linked lists. (Singly lists *in progress*)
	- *chunkreverse.c* - Reverses a list of length N in chunks of K (where K ≤ N). (*in progress*)

- ### Binary Trees
	- *binarytree.c* - createNode(), insert(), search(), generateTree(), freeTree(), printTree, etc.
		 - printTree() - Accepts 1, 2 or 3 as input for inorder, preorder and postorder traversal of the tree.

- ### Heaps
	**Implemention assumes arrays are contiguous and can be represented as heaps.**
	- *heaps.c* - Find parent, left-child, right-child, swap, min, max, etc.
	- *minheaps.c* - insert(),  extract_min(), extract_min()_pop, siftup(), siftdown() for MinHeaps.
	- *maxheaps.c* - insert(),  extract_max(), extract_max()_pop, siftup(), siftdown() for MaxHeaps.

- ### Pointers
	- *PointerExperiments.c* - Explore how int, char and pointers to pointers work.
	- *pointers.c* - Similar

- ### Misc
	1. *forloop* - See where forloop goes wrong due to precision constraints in computers
	2. *decimal_addition* - Checks if adding 0.1 3 times is 0.3 (for a computer)

## How to Use
Most functions implementing basic features of data structures have been written in separate files. These files (dependencies) have been included in other files that implement these functions.

Similarly, there are separate files with the `main()` that abstract the implementation away and focus only running the code. Usually, these files will be called `use[filename].c`.

Please refer to the function signatures if you want to provide custom inputs and accordingly modify/create files with a`main()`.

------------
© Shivam Kedia.
