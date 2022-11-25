/*Binary tree generation and printing program*/
#pragma once
#include<stdio.h>
#include<vector>
#include<math.h>
#include<stdlib.h>

// Elements such as values ​​in the array and this value will be treated as empty nodes in the binary tree
#define numMeansNull -1

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Generate a binary tree from the nums array. The elements of the array must be positive integers less than and equal to 999, and empty nodes are represented by the macro definition numMeansNull.
struct TreeNode *createTreeFromArray(int *nums, int numsSize);
// print binary tree bt
void bt_print(TreeNode *bt);

