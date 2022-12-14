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

Results run_tests(unsigned int set_size, unsigned int filter_size, unsigned int count, unsigned int test_factor);
void print_Results(Results rst, unsigned int set_size, unsigned int filter_size, unsigned int n);

int main()
{
    srandom(time(NULL));

    int f_sizes = 6;
    int n_sizes = 2;
    int t_sizes = 3;
    
    unsigned int set_sizes[]    = {10,100,500,10000,100000,1000000,10000000};
    unsigned int filter_sizes[] = {10,50,100,1000,10000,1000000};
    unsigned int counts[]       = {3,5,9};
    unsigned int test_factors[] = {1,5,10};


    for (int i = 0; i < f_sizes; i++)
    {
        Results rst = run_tests(set_sizes[4], filter_sizes[i], counts[0], test_factors[1]);
        print_Results(rst, set_sizes[4], filter_sizes[i], counts[0]);
    }
}

Results run_tests(unsigned int set_size, unsigned int filter_size, unsigned int count, unsigned int test_factor)
{
    int* set = genArray(set_size);
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

    unsigned int random_asize = test_factor * set_size;
    int* random_nums = genArray(random_asize);

    // printArray(random_nums, test_factor);
    
    rst->positives = 0;
    rst->false_positives = 0;
    rst->total = random_asize;

    // search filter and tree to get false/true positive
    for (unsigned int i = 0; i < random_asize; i++)
    {
        bool in_set = false;
        bool in_filter = search_filter(random_nums[i]);
        if (search(Mainroot, random_nums[i]) != NULL) {in_set = true;}

        if      (in_filter &&   in_set)  {rst->positives++;}
        else if (in_filter && !(in_set)) {rst->false_positives++;}
    }

    free_everything();
    free(set);
    free(random_nums);
    freeTree(Mainroot);

    return rst;
}

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