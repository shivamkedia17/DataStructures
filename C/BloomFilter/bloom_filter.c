#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrays.c"

int m;
int k;
bool *bitArray;
int **A;

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

int* changebase(int element, int base)
{

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
