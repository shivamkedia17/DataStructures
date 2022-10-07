#include <stdio.h>

//seeing how pointers work
int main(void)
{
    float i = 0.1 + 0.1 + 0.1;
    float *y = &i;
    printf("%f\n",*y); //prints value at address y
    printf("%p\n",y); //prints an address (y)
    printf("%p\n",y+1); //prints the address next to y
    printf("%p\n",y+4); //prints the address next to y
    *y = *y + 1;
    printf("%f",*y); //prints the value at address y after adding 1 to the value
    return 0;
}