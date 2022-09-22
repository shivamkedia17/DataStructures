#include <stdio.h>

//print yes if the computer thinks 0.1+0.1+0.1 = 0.3, else no
int main(void)
{
    int i = 0.1 + 0.1 + 0.1;
    if (i == 0.3)
        {printf("yes");}
    else
        {printf("no");}
    return 0;
}