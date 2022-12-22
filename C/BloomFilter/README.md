# BloomFilter - Data Structures

Final Project for CS-1203 (Monsoon 2022), Ashoka University.

## Codefile Descriptions

- *arrays.c*  - Basic array functions like generate
- *avlTree.c* - Uses my AVL tree code
- *hashing.c* - Functions used to implement a dot-product hash family
- *bloom_filter.c* - Implements the bloom filter using 'hashing.c'

--------------------------------------------------------------------------------

## What the Bloom Filter Does

Helps check for set membership.
Wikipedia: <https://en.wikipedia.org/wiki/Bloom_filter>

Uses the Dot-Product Hash family in the Bloom Filter.
MIT lecture on Dot-Product Hashing: <https://youtu.be/z0lJ2k0sl1g?t=1839>

**TLDR;** Given a set, a bloom filter tells you that an element you're trying to search for, is either **definitely** not in the set, or **probably** in the set. (That's why it's a probabilistic Data Structure)

--------------------------------------------------------------------------------

## What I've Done 

Coded up a bloom filter from scratch using only theory given on the links and Prof's guidance.

`test.c` - Contains a bunch of parameters to run the tests on the bloom filter, (e.g Set Size, Filter Size, No. of Hash functions used, etc.) and gives the number of false positives and true negatives obtained.

The sets used are randomly generated (for both initialising and testing the filter.)

----------------------------------------

### My testing

Please refer to `test.c`, it contains the `main()` running the tests and other functions to run those tests. If you notice, there are `set_sizes[]` and `filter_sizes[]`.

I've directed the output of my tests for the corresponding *set_size* in `set_sizes[]` to `BloomFilter/testoutputs/size_[set_size]_[n].txt` where for each *set_size*, *n* hash functions are used and the *filter_size* is varied (each filter_size in `filter_sizes[]` is used).

A randomly generated set of size = *test_factor* x *set_size* (test_factor = 5 here) was used to search the filter.

An AVL tree was simultaneously used to check whether an element had been inserted into a filter.

Using the search results from the Bloom filter and the AVL Tree, we can tell whether the filter returns a false-positve, a true-positive or a negative.

----------------------------------------

### Observations:

- The filter is quite effective when the *filter_size* is roughly 10 times a given *set_size*. The ratio of false-positives to negatives is quite low. Beyond a factor of 10, this ratio tends to 0-100. (Nice)

- When the *set_size* is roughly equal to the *filter_size*, the ratio of false positives to negatives is approximately 80-20. (Bad)

- When the *set_size* is less than the *filter_size*, the ratio of false positives to negatives is approximately 100-0. (Very Bad)

(For a given, constant no. of hash functions)

- For given *set* and *filter sizes*, increasing *n*, (the no. of hash functions) decreasing the efficacy of the filter, i.e, the ratio of false-positives to negatives goes up. (Bad)

----------------------------------------

### Custom Testing (If you want)

`test2.c` - Provides an interface for the user to provide parameters to run the tests on the bloom filter, (e.g Set Size, Filter Size, No. of Hash functions used, etc.) and gives the number of false positives and true negatives obtained.

The sets can be randomly generated (for both initialising and testing the filter) if the user wishes.

Please refer to the function signatures if you want to provide custom inputs and accordingly modify/create files.

------------
© Shivam Kedia.
