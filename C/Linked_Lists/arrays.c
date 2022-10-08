#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

/*
int* getArray_File(char **filename)
{
    FILE* fp = fopen(filename, "r");
    //Check for NULL pointer
    if (fp == NULL)
    {
        printf("Error reading file.\n");
        return 1;
    }
    else
    {
        printf("File read successfully.\n");
    }

    fscanf
    int l = //readfrom file
    char** vals = //readfrom file

    int *A = malloc(l * sizeof(int));
    for (int i = 0; i < l; i++)
    {
        A[i] = //read from vals
    }
    return A;
}
*/

int* genArray(int l)
{
    const int MAX = l<50?50:(50* l/50);
    srandom(time(NULL));
    int *A = malloc(l * sizeof(int));

    for (int i = 0; i < l; i++)
    {   
        A[i] = random() % MAX; //generate a random num less in range(0,MAX)
    }
    //printf("l%d\n",l);
    return A; 
}

void printArray(int l, int* A)
{
    //printf("l%d\n",l);
    for (int i=0; i<l; i++)
    {   
        printf(i? ", %d":"%d", A[i]);
    }
    printf(".\n");
}   