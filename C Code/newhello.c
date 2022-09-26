//tutorial from class on 26/09/2022, Monday Lecture 7
#include <stdio.h>

int main(int argc, char **argv)
{
    int x;
    int y;

    x = 1;
    y = 1;
    x = (y=2)*3;
    printf("x = %d, y = %d\n", x, y);

    x = 0;
    y = x++;
    printf("x = %d, y = %d\n", x, y);

    x = 0;
    y = ++x;
    printf("x = %d, y = %d\n", x, y);

    char *s = "abcd";
    printf("the character *(s+1) is \"%c\".\n", *(s+1));
    printf("the string s is \"%s\".\n",s);
    //s[0] = 'A';
    //printf("the character *(s+1) is \"%s\".\n", *(s+1)); Doesn't work

    const int k = 5;
    int *p = &k;
    *p = 6;
    printf("k = %d\n", k);
    printf("*p = %d\n", *p);

    const char * str = "can't touch this.";
    str = "can't touch this either.";
    printf("%s\n", str);

    return 0;
}