#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "arrays.c"



/*
// find prime such that largest element from Universe [Assume 64-bit integer]
    can be expressed as an m bit number in base p

    => next greatest prime number or something

    log E base p ~ m digit number

    Let this number be x.

// generate random number of m digits (in base p) -- Done

// (Dot product)  Hash function = <x,a> mod m -- Done

*/

// f(x) = (x^m) - E
double funct(int x, double m, double E)
{
    return (pow(x,m) - E);
}

// Input f(x), returns root X_0

// long newtons_method(*funtion pointer*)
{

}

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

int dotproduct(unsigned int* A, const unsigned int size_A, unsigned int* B, const unsigned int size_B)
{
    //We shall return the remainder, so the value returned will never be negative.

    if (size_A != size_B)   {return -1;} // => Error
    if (size_A == 0)        {return 0;} // Dot product of zero vectors is 0.

    unsigned int sum = 0;
    for (int i = 0; i < size_A; i++)
    {
        sum = sum + (A[i] * B[i]);
    }

    return (sum);
}

unsigned int hash(unsigned int* key, unsigned int* E, const unsigned int index_count)
{
    int index = dotproduct(key, index_count, E, index_count) % index_count;
    return index_count;
}