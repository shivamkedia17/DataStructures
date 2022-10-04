#include <stdio.h>

int main(int argc, char **argv)
{
    int * a;
    int n = 10;
    a = malloc(n * sizeof(int));
    
    for (int i = 0; i<n; i++)
    {
        a[i] = i;
    }
}