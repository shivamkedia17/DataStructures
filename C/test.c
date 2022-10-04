#include <stdio.h>

int main(void)
{
    int a[2][3] = {{0,3,4},{2,5,6}};
    printf("%lu", sizeof(a)/sizeof(a[0]));
    printf("%d", -3%-2);
}