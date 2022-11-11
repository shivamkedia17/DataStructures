#include <stdio.h>

int main(void)
{
    int i = 1;
    for (double x = 0; x < 0.0000000000000000000001; x=x+0.00000000000000000000001)
    {
        printf("%d\n",i);
        i++;
    }
    printf("\n");
    i = 1;
    for (float x = 0; x < 10; x=x+1)
    {
        printf("%d\n",i);
        i++;
    }
    return(0);
}