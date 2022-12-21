#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

// get next largest prime number from a file, ONCE
unsigned int find_prime_file(unsigned int size, char* filename)
{
    FILE* fp = fopen(filename, "r");
    int p = 0;
    if (fp == NULL) {return 0;}
    while (1)
    {
        fscanf(fp, "%d\n", &p);
        if (p >= size) {break;}
    } 
    fclose(fp);
    return p;
}

// get the size of the key-vector (for hashing)
unsigned int set_r(int key, unsigned int m)
{
    if (m == 0)     {return -1;}
    unsigned int r;
    for(r = 1; key > 0; r++)    {key = key/m;}
    assert(pow(m,r) > key);
    return r;
}

/// @brief Changes 'key' in base 10 to a vector with digits in base m
/// @param key int element 
/// @param m new base
/// @param K (int vector) <- key in base m
/// @param r size of int vector
void changebase(int key, unsigned int m, unsigned int *K, unsigned int r)
{
    if (m == 0)     {return;}
    for (int i = r-1; i >= 0; i--)
    {
        K[i] = key % m; // Possible Values 0...m-1
        assert(K[i] < m);
        key = key/m;
    }
}

// generate an A[] of size r, with each 0 ≤ A_i ≤ m-1
unsigned int* generate_hash(unsigned int m,  unsigned int r)
{
    // Please seed before calling 
    unsigned int *A = (unsigned int*) calloc(r, sizeof(unsigned int));

    //generate a random number in range(0, m)
    for (int i = 0; i < r; i++)
    {   
        A[i] = random() % m;
        assert(A[i] < m);
    }
    return A; 
}

// expand previous hash to new r
unsigned int* expand_hash(unsigned int* A, unsigned int m,  unsigned int prev_r, unsigned int r)
{
    if (A == NULL)   {return NULL;}
    if (prev_r == r) {return A;}

    assert(prev_r < r);
    for (int i = prev_r; i < r; i++) {A[i] = random() % m;}
    return A; 
}

/// @brief Find <A,B> given vectors A and B. Assuming Sizes of A and B are the same
/// @param A 1st Vector
/// @param B 2nd Vector 
/// @param r length of both vectors
/// @return <A,B>
unsigned int dotproduct(unsigned int* A, unsigned int* B, const unsigned int r)
{
    if (r == 0)        {return 0;} // Dot product of zero vectors is 0.

    unsigned int sum = 0;
    for (int i = 0; i < r; i++) {sum = sum + (A[i] * B[i]);}

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
    unsigned int index = dotproduct(K, A, r) % m;
    assert(index >= 0 && index < m);
    return index;
}

