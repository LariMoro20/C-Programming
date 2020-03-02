#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct pessoas {
	char nome[10];
	int idade;
}typedef CPessoa;

void imprime_pessoa(CPessoa *pessoa, int tam){

int b = 0;
for(; b < tam; b++){
            printf(" %s: %d \n", (pessoa+b)->nome, (pessoa+b)->idade);
        }
}

void cadastra_pessoa(CPessoa **cad, int tam){
    *cad = (CPessoa *) malloc(2);
    char opc='s';
     while((opc == 's') || (opc == 'S')){
     	fflush(stdin);
        printf("\nQuantidade de pessoas: %d ",tam);
        printf("\nDigite o nome: ");
        gets((*cad+tam)->nome);
        printf("\nDigite a idade do(a) %s: ", (*cad+tam)->nome);
        scanf("%d", &(*cad+tam)->idade);
        printf("\nMais um? ");
        scanf(" %c", &opc);
        tam++;

         switch(opc){
                case 's':
                    *cad = (CPessoa *) realloc(*cad, tam+1);
                 break;
                default:
                    printf("\n\t---- OK ----- \n");
                break;
         }
    }
}

int main(){
	int tam = 0;
    CPessoa *pessoa;
   // tamanho(pessoa);
    cadastra_pessoa(&pessoa, tam);
    imprime_pessoa(&pessoa, tam);
    return 0;
}

