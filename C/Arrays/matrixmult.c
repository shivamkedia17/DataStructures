#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define LEN(arr) ((int) (sizeof(arr) / sizeof(arr)[0]))

int main(void);
int** create(int m, int n);
int** gen(int m, int n);
bool check_order(int oa[], int ob[]);
int** matmult(int ca, int cb, int a[][], int b[][]);
int innerproduct(int u[], int v[]);

//Main function
int main(void)
{
    int ra, rb, ca, cb;
    if (check_order({ra,ca},{rb,cb})==false)
    {
        printf("A[%d][%d] x B[%d][%d] is not possible.\n",ra,ca,rb,cb);
    }
    else
    {
        int a[ra][ca];
        int b[rb][cb];

        //shady
        a = create(ra, ca);
        b = create(rb, cb);

        a = gen(ra, ca);
        b = gen(rb, cb);

        

    }

    return 0;
}

//Initialises m x n matrix with zeroes
int** create(int m, int n)
{
    int a[m][n];  
    for (int i = 0; i < m; i++)
    {   
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    return a;
}

//Randomly assigns values to matrix 
int** gen(int m, int n)
{
    const int MAX = 20;
    int a[m][n]; 
    for (int i = 0; i < m; i++)
    {   
        srandom(time(NULL));
        for (int j = 0; j < n; j++)
        {
            a[i][j] = random()/MAX;
        }
    }
    return a;
}

//check order of input matrices, return order of resultant
bool check_order(int oa[], int ob[])
{   
    if (oa[1] == ob[0])
    {
        return true;
    }
    return false;
}

//Input Two Matrices, Return the result
int** matmult(int ca, int cb, int a[][ca], int b[][cb])
{   
    //store no. of rows and columns of matrices A and B
    int ra = LEN(a);
    int r[ra][cb];

    //Multiplying every row of A with every column of B, column-first
    for (int i = 0; i < cb; i++)
    {
        for (int j = 0; j < ra; j++)
        {
            r[j][i] = innerproduct(a[j],b[i]);
        }
    }
    return r;
}

//returns innerproduct of two vectors
int innerproduct(int u[], int v[])
{
    int l = LEN(u);
    int result = 0;
    for (int i = 0; i<l; i++)
    {
        result += (u[i]*v[i]);
    }
    return result;
}

//prints matrix
void printMatrix(int ra, int ca, int rb, int cb, int a[ra][ca], int b[rb][cb])
