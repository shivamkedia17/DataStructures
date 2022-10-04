#include <stdio.h>
//working with input ouutput in C


int main(void)
{
	int num;
	char* s;
	// Reading input from STDIN
	scanf("Enter no. %d\n", &num);              	                  
	scanf("Enter string: %s\n", s);
	printf("%d\n", num*2); 
	printf("%s\n", s); 
	// Writing output to STDOUT
    return 0;
}