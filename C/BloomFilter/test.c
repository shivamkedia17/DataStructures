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

    int test_size = 3;
    unsigned int set_sizes[]    = {10,100,500,10000,100000,1000000,10000000};
    unsigned int filter_sizes[] = {10,50,100,1000,10000,1000000};
    unsigned int counts[]       = {3,5,9,17,25};

    unsigned int false_positives[] = {0,0,0,0,0,0,0};
    unsigned int positives[] = {0,0,0,0,0,0,0};
    unsigned int totals[] = {0,0,0,0,0,0,0};

    for (int i = 0; i < test_size; i++)
    {
        Results rst = run_tests(set_sizes[i], filter_sizes[2], counts[1]);
        // false_positives[i] = rst->false_positives;
        // positives[i] = rst->positives;
        // totals[i] = rst->total;

        printf("\n");
        printf("Set Size: %d\n", set_sizes[i]);
        printf("Filter Size: %d\n", filter_sizes[2]);
        printf("No. of Hash functions: %d\n", counts[1]);
        printf("Totals: %d\n", rst->total);
        printf("Positives: %d\n", rst->positives);
        printf("False Positives: %d\n", rst->false_positives);

        float fp_ratio = rst->false_positives * 100.0 / (float) rst->total;
        float p_ratio = rst->positives * 100.0 / (float) rst->total;

        printf("Ratios: FP:%f, P:%f\n", fp_ratio, p_ratio);
        printf("\n");

        free(rst);
    }
    

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

    Results rst = (Results) malloc(sizeof(struct results));

    int random_asize = 5 * set_size;
    int* random_nums = genArray(random_asize);
    rst->positives = 0;
    rst->false_positives = 0;
    rst->total = random_asize;

    // search filter and tree to get false/true positive
    for (int i = 0; i < random_asize; i++)
    {
        bool in_set = false;
        if (search(Mainroot, random_nums[i]) != NULL) {in_set = true;}

        if      (search_filter(random_nums[i]) &&   in_set)  {rst->positives++;}
        else if (search_filter(random_nums[i]) && !(in_set)) {rst->false_positives++;}
    }

    free_everything();
    free(set);
    free(random_nums);
    freeTree(Mainroot);

    return rst;
}