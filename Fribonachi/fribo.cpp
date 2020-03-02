#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"
int i=1;
int b=0;
int val;
char opc[0];


main(){
	do{
    system("@cls||clear");
	printf("\t---SEQUENCIA-FRIBONACCI---\n");
	printf("\t\tQual o numero limite?\n\t\t Limite:");
	scanf("%d", &val);
 	fribo(i,b, val);
 	printf("\nDe novo?");
 	scanf("%s", &opc[0]);

}while((opc[0]=='s' || opc[0]=='S') && opc!=0);

}
