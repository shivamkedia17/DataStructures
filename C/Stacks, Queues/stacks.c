#include <stdio.h>
#include <stdlib.h>
#pragma once
#include "arrays.c"
#include "node.c"

int main (void)
{

}

struct Stack {
    int* s;
    size_t size;   // max no. of elements allowed in Stack
    int start;  // index of where the stack starts
    int n;      // no. of current elements present in Stack
};

typedef struct Stack * stackPointer;

stackPointer initStack(size_t stack_size)
{
    stackPointer stack = malloc(sizeof(struct Stack));
    stack->s = (int *) malloc(stack_size * sizeof(int));
    stack->start = 0;
    stack->n = 0;
}

stackPointer resizeStack(size_t newsize, int start)
{s

}

void insert(stackPointer stack)
{
    
}

void extract(stackPointer stack)
{
    
}

stackPointer peek(stackPointer stack)
{

}

void freeStack(stackPointer stack)
{
    free(stack->s);
    free(stack);
}