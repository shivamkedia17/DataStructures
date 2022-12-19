#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "arrays.c"

bool *bitArray;
int **A;


// 
int find_prime_file(int m, char* filename)
{
    FILE* fp = fopen(filename, "w");
    fclose(fp);
    return 3203;
}

int main ()
{
    int size; // given size of bit array
    char* fn; // file containing primes before 1,100,000
    int m = find_prime_file(m, fn); // Size of bit array we choose
    int r = 1; // Size of vector
    int *K = NULL;

    int key = 129834708237402; //random key for now, take input ********

    
    if (pow(m, r) <= key) {r = set_r(key, m);} //Set R
    int *K = realloc(K, r * sizeof(int));  
    

}

int set_r(int key, int m)
{
    if (m == 0)     {return -1;}
    int r;
    for(r = 1; key > 0; r++)    {key = key/m;}
    return r;
}

//generates a bit array of size m
void generateEmptyArray(int size)
{
    bitArray = (bool) malloc(size* (sizeof(bool)));
    for (int i = 0; i < size; i++)
    {
        bitArray[i] = false;
    }
}

void createHashKeys(int count)
{
    A = (int*) malloc(count * sizeof(int*));
    srandom(time(NULL));
    for (int i = 0; i < count; i++)
    {
        A[i] = generate_new_hash();
    }
}

int* generate_new_hash()
{
    int *Ai = genArray(m);
    return Ai;
}

//Universal hash function with parameter a, returns hashed index
int hash(int* a, int element)
{
    //convert element to array of size m (convert element to base m)??
    int* E = changebase(element, m);
    for(int i = 0; i < m; i++)
    {

    }
}


/// @brief Changes 'key' in base 10 to a vector with digits in base m
/// @param key int element 
/// @param m new base
/// @param K (int vector) <- key in base m
/// @param r size of int vector
void changebase(int key, int m, int *K, int r)
{
    if (m == 0)     {return -1;}
    for (int i = 0; i < r; i++)
    {
        K[i] = key % m; // Possible Values 0...m-1
        assert(K[i] < m);
        key = key/m;
    }
}
// m = No. of buckets, (or size of bit array in this case)
// k = No. of different hash functions, a_0, a_1, ... , a_k where, a_i is a hash()

// a_i is an m digit number in base m
// so a_i could be an array with m digits each having a value from 0 to m-1

// Key = x with digits x_0,
// Hash(x) = Sum (a_i * x)

void createbloom(int buckets, int hashes)
{
    m = buckets;
    k = hashes;

}

// void add();
// bool search();
//next greatest prime number()


void add(int element)
{
    for (int i = 0; i < k; i++)
    {   
        int* hashkey = A[i];
        int index = hash(hashkey, element);
        bitArray[index] = true;
    }
}


bool isPrime(int n)
{
    if (n < 2) {return false;}
    int i;
    for (i = 2; i <= n/i; i++) 
    {
        if (n%i == 0) 
        {
            return true;
        }
    }
}
