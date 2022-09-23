#include <stdio.h>
#define LEN(arr) ((int) (sizeof(arr) / sizeof(arr)[0]))

int main(void);
int[][] gen(int m, int n);
int[] check_order(int oa[], int ob[]);
int[][] matmult(int a[][], int b[][]);
int innerproduct(int u[], int v[]);

//Main function
int main(void)
{
    return 0;
}

//Randomly generates matrix of order 
int[][] gen(int m, int n)
{
    int a[][];
    return a;
}

//check order of input matrices, return order of resultant
int[] check_order(int oa[], int ob[])
{   
    if (oa[1] == ob[0])
    {
        return [oa[0],ob[1]];
    }
    else
    {
        return [0,0];
    }
}

//Input Two Matrices, Return the result
int[][] matmult(int a[][], int b[][])
{   
    //store no. of rows and columns of matrices A and B
    int ra, cb;
    ra = LEN(a);
    cb = LEN(b[0]);
    
    int r[ra][cb];

    //Multiplying every row of A with every coloumn of B, column-first
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

