#include"treeCodes.h"

void calTreeDepth(TreeNode *t);
void setPrintBuffer(TreeNode *t);

// Generate a binary tree from a two-dimensional array
struct TreeNode *createTreeFromArray(int *nums, int numsSize) {
	struct TreeNode *nodes = (struct TreeNode*)calloc(numsSize, sizeof(struct TreeNode));
	for (int i = 0; i < numsSize; i++) {
		nodes[i].val = nums[i];
		int child = i * 2 + 1;
		nodes[i].left = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
		child = i * 2 + 2;
		nodes[i].right = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
	}
	return &nodes[0];
}

// depth of current node
int depth = 0;
// The depth of the tree, if there is only the root node, the depth is 1
int depthMax = 0;
// The width of the print buffer, the number of columns that should be printed currently, and the number of columns at the previous printing position
int width = 0, column = 0, lastColumn = 0;
char **printBuffer = NULL;

void bt_print(TreeNode *bt) {
	depth = 0;
	column = 0;
	lastColumn = 0;
	depthMax = 0;
	// Apply memory according to the size of the tree
	calTreeDepth(bt);
	width = 3 * ((1 << (depthMax - 1)) * 2 - 1);
	int height = 1 + (depthMax - 1) * 3;
	printBuffer = (char**)malloc(height *sizeof(char*));
	for (int i = 0; i < height; i++) {
		printBuffer[i] = (char*)malloc(width * sizeof(char));
		memset(printBuffer[i],' ',width);
		printBuffer[i][width - 1] = '\0';
	}

	depth = 0;
	column = width / 2;
	lastColumn = column;
	setPrintBuffer(bt);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", printBuffer[i][j]);
		}
		printf("\n");
	}

}

// find the maximum depth of the tree recursively
void calTreeDepth(TreeNode *t) {
	if (t) {
		depth++;
		depthMax = depthMax < depth ? depth : depthMax;
		calTreeDepth(t->left);
		calTreeDepth(t->right);
		depth--;
	}
}

// First traverse, set the data to the print buffer
void setPrintBuffer(TreeNode *t) {
	if (t) {
		depth++;

		int val = t->val;
		for (int i = 0; i < 3; i++) {
			printBuffer[(depth - 1) * 3][column+1-i] = val%10 + 0x30;
			val /= 10;
		}
		if (depth > 1) {
			int linkLineInterval =  (column- lastColumn)/3;
			char linkChar = linkLineInterval > 0 ? '\\' : '/';
			printBuffer[(depth - 1) * 3 - 1][column - linkLineInterval] = linkChar;
			printBuffer[(depth - 1) * 3 - 2][column - 2*linkLineInterval] = linkChar;
		}
		
		int step = (1<<(depthMax-depth-1))*3;

		lastColumn = column;
		column -= step;
		setPrintBuffer(t->left);
		column += step;

		lastColumn = column;
		column += step;
		setPrintBuffer(t->right);
		column -= step;
		depth--;
	}
}

