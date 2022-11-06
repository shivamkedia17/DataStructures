#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrays.c"

//generates a bit array of size m
bool* generateEmptyArray(int m)
{
    bool *A = (bool) malloc(m* (sizeof(bool)));
    for (int i = 0; i < m; i++)
    {
        A[i] = 0;
    }
}

//Generates k different hash functions
void hash_function_generator(int k)
{
    //
}

void generate_new_hash()
{
    //
}

void hash_template()
{
    //Inputs: Start of array, End of array, Data object
    //Output: 1 index b/w start and end (inclusive)
}

//Returns the values of k hashes for any given input objects
int* hashmain()
{
    //Inputs: Start of array, End of array, Data object
    //Outputs: k indexes
}

void add();

bool search();

