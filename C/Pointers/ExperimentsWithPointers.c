#include<stdio.h> 
#include<stdlib.h> 

// int experiment(){

//     int a = 50; 
//     int* p = &a; 
//     int** ptop1=&p; 
//     char** ptop2=&ptop1;    

//     ptop2='o';    
    
//     printf("The value at a is %d \n",a);   
//     printf("The value at ptop1 is %d \n",**ptop1);  
//     printf("The value at ptop2 is %d \n",**ptop2); 
    
//     //The first two statements print out 50 while the last statement returns a segmentation fault 
//     //This is because it got dereferenced to a character 

// }

int main(){

    int a=50; 
    int* p= &a; 
    int* x = &p;
    char* q=&p; 
    

    printf("The address of a is: %p \n",p); 
    printf("The value at the address next to 'a' is %d \n",&a+1); 

    printf("The value at the address next to 'a' is %d \n",*&a+1); 

    printf("The address of this value is: %p \n",p+1); //=> moves sizeof(int) ahead when incremented by 1
    //The above statement shows that the next address is at a distance of 4 bytes from 'a' 
    printf("Q: %p\n",q);
    printf("X: %p\n",x);
    printf("Padd: %p\n",&p);
    printf("Qadd: %p\n",&q);

    
    printf("Another address near p? %p\n",q+1);  
    printf("Another address near p? %p\n",x+1);  

  
    
    printf("Value of address near p? %d\n",*q+1);  
    printf("Value of address near p? %d\n",*x+1); 
     

    printf("%lu\n",sizeof(p));
    printf("%lu\n",sizeof(q));
    printf("Value of address near p? %p\n",*(q+1));  
    printf("Value of address near p? %p\n",*(x+1)); 
    


    

    //This statement returns different values everytime it is run, clearly we are accessing 
    //memory that we are not supposed to (Hehehehe)

    return 0;

}