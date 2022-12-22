#include "bloom_filter.c"
#include "arrays.c"
#include "avlTree.c"
#include <time.h>

struct results{
    int false_positives;
    int positives;
    int total;
};

typedef struct results* Results;

Results run_tests(int* set, unsigned int set_size, unsigned int filter_size, unsigned int count, int* t_set, unsigned int t_set_size);
void print_Results(Results rst, unsigned int set_size, unsigned int filter_size, unsigned int n);

int main()
{
    srandom(time(NULL));

    // CUSTOM INPUT BELOW
    unsigned int set_size = 1000; // Choose set Size
    
    // int set[] = {}; // User-Defined
    int* set = genArray(set_size); // Generate randomly

    unsigned int filter_size = 10000; // Choose filter Size
    unsigned int n = 3; // Choose no. of hash functions
    
    unsigned int tset_size = 10; // Choose no. of hash functions
    int* test_set = genArray(tset_size); // Randomly Generated
    // int test_set[] = {35, 12343214, 1235, -9005, 456, 222, 12, 33, 24, 1}; // UserDefined
    // printArray(test_set, tset_size); to print set if needed

    Results rst = run_tests(set, set_size, filter_size, n, test_set, tset_size);
    print_Results(rst, set_size, filter_size, n);

}

/// @brief Print the Results of a Test
/// @param set_size The size of the set the filter is initialised with
/// @param filter_size The size you would want the bloom filter to be.
/// @param count The no. of hash functions you want to use

/// @return A struct containing No. of Tests ran, False/True Positives, True Negatives
Results run_tests(int* set, unsigned int set_size, unsigned int filter_size, unsigned int count, int* t_set, unsigned int t_set_size)
{
    // printArray(set, set_size);
    avlTree Mainroot = NULL;

    create_filter(filter_size, count);

    // insert values into filter and Tree
    for (int i = 0; i < set_size; i++)
    {
        insert_filter(set[i]);
        if (i == 0) {Mainroot   = insert(Mainroot, set[i]);}
        else        
        {
            avlTree leaf = insert(Mainroot, set[i]);
            Mainroot = fixup(Mainroot, leaf);
        }
    }

    printf("Filter State (After Insertion): \n");
    if (m < 1500) {print_filter(filter, m);}
    else          {printf("Filter Hidden, Too large.\n");}

    Results rst = (Results) malloc(sizeof(struct results));
    
    rst->positives = 0;
    rst->false_positives = 0;
    rst->total = t_set_size;

    // search filter and tree to get false/true positive
    for (unsigned int i = 0; i < t_set_size; i++)
    {
        bool in_set = false;
        bool in_filter = search_filter(t_set[i]);
        if (search(Mainroot, t_set[i]) != NULL) {in_set = true;}

        if      (in_filter &&   in_set)  {rst->positives++;}
        else if (in_filter && !(in_set)) {rst->false_positives++;}
    }

    free_everything();
    freeTree(Mainroot);

    return rst;
}

/// @brief Print the Results of a Test
/// @param rst Struct Storing No. of Tests ran, False/True Positives, True Negatives
/// @param set_size The size of the set the filter is initialised with
/// @param filter_size The size you would want the bloom filter to be.
/// @param n The no. of hash functions you want to use
void print_Results(Results rst, unsigned int set_size, unsigned int filter_size, unsigned int n)
{
    printf("\n");
    printf("Set Size   : %d\n", set_size);
    printf("Filter Size: %d\n", filter_size);
    printf("n-Hash functions: %d\n", n);
    printf("Total Tests     : %d\n", rst->total);
    printf("True  Positives : %d\n", rst->positives);
    printf("False Positives : %d\n", rst->false_positives);
    printf("True  Negatives : %d\n", rst->total - rst->false_positives - rst->positives);

    float fp_ratio = rst->false_positives * 100.0 / (float) rst->total;
    float p_ratio = rst->positives * 100.0 / (float) rst->total;
    float n_ratio = 100.0 - fp_ratio - p_ratio;

    printf("\nRatios: \nFalse Positives:%f\nTrue  Positives:%f\nTrue  Negatives:%f\n", fp_ratio, p_ratio, n_ratio);
    printf("\n");

    free(rst);
}