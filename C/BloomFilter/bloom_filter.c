#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "hashing.c"

unsigned int m;
unsigned int r;
unsigned int* * hashes;
unsigned int count;
bool *filter;

//generates a bit array of size m
bool* generateBitArray(unsigned int m)
{
    bool *b = (bool *) calloc(m, sizeof(bool));
    // for (int i = 0; i < m; i++) {b[i] = false;} // TEST IF NEEDED
    return b;
}

unsigned int** create_hashvectors(unsigned int count, unsigned int m, unsigned int r)
{
    unsigned int** hashes = (unsigned int* *) calloc(count, sizeof(unsigned int *));
    for (int i = 0; i < count; i++) {hashes[i] = generate_hash(m, r);}
    return hashes;
}

/// @brief Create Bloom filter with necessary parameters
/// @param size Size input by the user, m -> prime number chosen as size.
/// @param n No. of hash functions
void create_filter(unsigned int size, unsigned int n)
{
    char* filename = "numbers.txt";         // file containing primes before 1,100,000
    m = find_prime_file(size, filename);    // Size of bit array we choose
    r = set_r(INT32_MAX, m);                   // Size of vector
    count = n;
    hashes = create_hashvectors(count, m, r);
    filter = generateBitArray(m);
}


unsigned int* use_hash(int key)
{
    unsigned int* indices = (unsigned int *) calloc(count, sizeof(unsigned int));

    unsigned int *K = (unsigned int *) calloc(r, sizeof(unsigned int));
    changebase(key, m, K, r);

    for (int i = 0; i < count; i++)
    {   
        unsigned int index = hash(K, hashes[i], r, m);
        // printf("Key: %d, Index: %d\n", key, index);
        indices[i] = index;
    }

    free(K);
    return indices;
}

void insert_filter(int key)
{
    unsigned int* indices = use_hash(key);
    for (int i = 0; i < count; i++) 
    {
        filter[indices[i]] = true;
    }
    free(indices);
}

void print_search_result(bool result, int key)
{
    // printf("%s\n", bool ? "true" : "false");

    if (result) {printf ("%d is Probably In the Set.\n", key);}
    else        {printf ("%d is NOT In the Set.\n", key);}
}

bool search_filter(int key)
{
    if (pow(m, r) <= key) {return false;} // Such a large key has never been seen

    bool result = true; // Indicates key is probably in filter
    unsigned int* indices = use_hash(key);
    for (int i = 0; i < count; i++) 
    {
        if (filter[indices[i]] == false) 
        {
            result = false; // Indicates key is DEFINITELY not in filter
            break;
        }
    }

    free(indices);
    print_search_result(result, key);
    return(result);
}

void print_filter(bool *b, unsigned int m)
{
    for (int i=0; i < m; i++)
    {   
        printf(i? ", %d":"%d", b[i]);
    }
    printf(".\n");
}

void printArray(int* A, unsigned int l)
{
    //printf("l%d\n",l);
    for (int i=0; i < l; i++)
    {   
        printf(i? ", %d":"%d", A[i]);
    }
    printf(".\n");
}  

void free_everything()
{
    free(filter);
    for (int i = 0; i < count; i++)     {free(hashes[i]);}
    free(hashes);
}