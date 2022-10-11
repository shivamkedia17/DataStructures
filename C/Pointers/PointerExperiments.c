#include<stdio.h> 
#include<stdlib.h> 

int main(){

    int a=50; 
    int* p= &a; 
    int* x = &p;
    char* q=&p; 
    

    printf("The address of a is: %p \n",p); 
    printf("The value at the address next to 'a' is %d \n",&a + 1); //address of a + 1

    printf("The value at the address next to 'a' is %d \n",*&a + 1); //(value of a) + 1

    printf("The address of this value is: %p \n",p + 1); //=> moves sizeof(int) ahead when incremented by 1
    //The above statement shows that the next address is at a distance of 4 bytes from 'a' 
    printf("Q: %p\n",q);
    printf("X: %p\n",x);
    printf("Padd: %p\n",&p);
    printf("Qadd: %p\n",&q);
    
    printf("//value of q + 1 => address of p + 1 bytes %d\n",q + 1);  //value of q + 1 => address of p + 1 bytes
    printf("//value of x + 1 => address of p + 4 bytes %d\n",x + 1);  //value of x + 1 => address of p + 4 bytes
    
    printf("//value 1 byte  next to p %d\n",*q + 1);  //value 1 byte  next to p
    printf("//value 4 bytes next to p %d\n",*x + 1);  //value 4 bytes next to p
     

    printf("%lu\n",sizeof(p));
    printf("%lu\n",sizeof(q));
    printf("value at ((address of p) + 1 byte)? %d\n",*(q+1)); //value at ((address of p) + 1 byte)
    printf("value at ((address of p) + 4 bytes) %d\n",*(x+1)); //value at ((address of p) + 4 bytes)
    
    return 0;

}