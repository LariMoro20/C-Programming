#include <stdio.h>
#include <string.h>

int fribo(int a1, int a2, int val){
	int soma=a1+a2;
	
	if(a2>val)
    	return(0);	
	
    if(a2==0)
        printf("\n\t\t    %d",a2);
     
     else
	     printf("\n\t\t    %d ", soma);
	     fribo(a2,soma,val);
 	 
}
