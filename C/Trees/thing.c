#include <stdio.h>
#include <stdlib.h>

#define errorf(code, msg, ...) {fputs("\x1b[31m", stderr); fprintf(stderr, "CODE %d: ", code); fprintf(stderr, msg, __VA_ARGS__); fputs("\x1b[0m", stderr); exit(1);}

int main()
{
    int a = 10;
    
    while (a > 0)
    {
        if (a == 6) errorf(50, "program messed up at %d\n", a);
        printf("%d\n", a--);
    }

    return 0;
}