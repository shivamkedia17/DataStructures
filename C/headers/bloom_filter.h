#pragma once
#include <stdbool.h>
#include "arrays.h"

bool* generateBitArray(unsigned int m);
unsigned int** create_hashvectors(unsigned int count, unsigned int m, unsigned int r);
void create_filter(unsigned int size, unsigned int count);
unsigned int* use_hash(int key);
void insert(int key);
void print_search_result(bool result, int key);
bool search(int key);
void print_filter(bool *b, unsigned int m);
void printArray(int* A, unsigned int l);
void free_everything();
