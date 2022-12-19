#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "arrays.c"


unsigned int find_base(const int size)
{
    unsigned int base;
    // base = newtons_method(size, max_element);
    return base;
}

int* generate_hashkey(const unsigned int base, const unsigned int size)
{
    // Please seed before calling 

    unsigned int *A = (unsigned int*) malloc(size * sizeof(unsigned int));

    //generate a random number in range(0, base)

    for (int i = 0; i < size; i++) {A[i] = random() % base;}
    return A; 
}

/// @brief Find <A,B> given vectors A and B. Assuming Sizes of A and B are the same
/// @param A 1st Vector
/// @param B 2nd Vector 
/// @param r length of both vectors
/// @return <A,B>
int dotproduct(unsigned int* A, unsigned int* B, const unsigned int r)
{
    if (r == 0)        {return 0;} // Dot product of zero vectors is 0.

    unsigned int sum = 0;
    for (int i = 0; i < r; i++)
    {
        sum = sum + (A[i] * B[i]);
    }

    return (sum);
}

/// @brief Implement Dot-Product Hash
/// @param K Vector of Size r with Ki 0...r-1
/// @param A Vector of Size r with Ai 0...r-1
/// @param r Size of the two vectors
/// @param m Size of hash-table
/// @return <K,A> mod m
unsigned int hash(unsigned int* K, unsigned int* A, const unsigned int r, int m)
{
    // Returned remainder will never be negative.
    int index = dotproduct(K, A, r) % m;
    return index;
}