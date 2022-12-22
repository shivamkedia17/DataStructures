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

Results run_tests(unsigned int set_size, unsigned int filter_size, unsigned int count);

int main()
{
    srandom(time(NULL));
    unsigned int set_size = 1000;
    unsigned int filter_size = 10000;
    unsigned int n = 3;
   
    Results rst = run_tests(set_size, filter_size, n);
    // false_positives[i] = rst->false_positives;
    // positives[i] = rst->positives;
    // totals[i] = rst->total;

    printf("\n");
    printf("Set Size: %d\n", set_size);
    printf("Filter Size: %d\n", filter_size);
    printf("No. of Hash functions: %d\n", n);
    printf("Totals: %d\n", rst->total);
    printf("Positives: %d\n", rst->positives);
    printf("False Positives: %d\n", rst->false_positives);

    float fp_ratio = rst->false_positives * 100.0 / (float) rst->total;
    float p_ratio = rst->positives * 100.0 / (float) rst->total;
    float n_ratio = 100.0 - fp_ratio - p_ratio;

    printf("Ratios: \nFalse Positives:%f\nTrue  Positives:%f\nTrue  Negatives:%f\n", fp_ratio, p_ratio, n_ratio);
    printf("\n");

    free(rst);
}

Results run_tests(unsigned int set_size, unsigned int filter_size, unsigned int count)
{
    int* set = genArray(set_size);
    printArray(set, set_size);
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

    print_filter(filter, m);

    Results rst = (Results) malloc(sizeof(struct results));

    int random_asize = 3 * set_size;
    int* random_nums = genArray(random_asize);
    printArray(random_nums, 3*set_size);
    rst->positives = 0;
    rst->false_positives = 0;
    rst->total = random_asize;

    // search filter and tree to get false/true positive
    for (int i = 0; i < random_asize; i++)
    {
        bool in_set = false;
        bool in_filter = search_filter(random_nums[i]);
        if (search(Mainroot, random_nums[i]) != NULL) {in_set = true;}

        if      (in_filter &&   in_set)  {rst->positives++;}
        else if (in_filter && !(in_set)) {rst->false_positives++;}
    }

    // insert values into filter and Tree
    for (int i = 0; i < set_size; i++)
    {
        search_filter(set[i]);
    }

    free_everything();
    free(set);
    free(random_nums);
    freeTree(Mainroot);

    return rst;
}

