#include <stdio.h>

int main(void)
{
    int i = 0;
    for (float x = 0; x < 0.00000001; x=x+0.000000001)
    {
        printf("%d\n",i);
        i++;
    }
    return(0);
}