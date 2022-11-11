#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

typedef struct arrayData
{
    int l;
    int *A;
}*array;


array getArray_File(char *filename)
{
    FILE* fp = fopen(filename, "r");
    //Check for NULL pointer
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open %s\n", filename);
        perror("Error: ");
        return NULL; 
    }
    else
    {
        printf("File read successfully.\n");
    }

    char* line = NULL;
    size_t len = 0;
    
    //First line should contain length of array to be read
    int l;
    getline(&line, &len, fp);
    sscanf(line, "%u", &l);
    
    //second line onwards contains the array to be read
    int *A = malloc(l * sizeof(int));
    for (int i = 0; i < l; i++)
    {
        if(getline(&line, &len, fp) != -1)
        {
            // printf("%s",line);
            sscanf(line, "%d", &A[i]);
        }
        else
        {
            printf("End of input file.\n");
        }
    }
    
    fclose(fp);
    free(line);
    array X = malloc(sizeof(array));
    X->l = l;
    X->A = A;
    return X;
}


int* genArray(int l)
{
    const int MAX = l<50?50:(50* l/50);
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