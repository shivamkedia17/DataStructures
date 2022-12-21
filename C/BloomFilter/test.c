#include "bloom_filter.c"

int main()
{
    unsigned int size = 20;
    count = 3;
    create_filter(size, count);
    int set[] = {45,95,60,345,-6932,4231421, 5, 11, 3};
    int set_size = 9;
    for (int i = 0; i < set_size; i++)
    {
        insert(set[i]);
        printf("m: %d, r: %d, key:%d \n", m, r, set[i]);
        // printf("\n");
    }

    print_filter(filter, m);

    for (int i = 0; i < set_size; i++)
    {
        search(set[i]);
    }
    search(192);
    search(321);
    search(0);

    free_everything();
}