#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define MAX 100000

//Larissa Moro ADS Estrutura de Dados 2019
struct clientes{
	char nome[10];
	char endereco[300];
	char telefone[20];
	int cpf;
};

typedef clientes Clientes;

struct lista{
	Clientes* arr[MAX];
	int topo;
};
typedef lista Lista;

Lista* cria_lista(){
	Lista* lista = (Lista*)malloc(sizeof(Lista));
	lista->topo=0;
	lista->arr[lista->topo]=NULL;
	return lista;
}

void ordena(Lista * lista){
	Clientes* aux;
	int i,j;
    for (int i = 0; i < lista->topo; i++){
        for (int j = 0; j < lista->topo; j++){
            if (lista->arr[i]->cpf < lista->arr[j]->cpf){
                aux = lista->arr[i];
                lista->arr[i] = lista->arr[j];
                lista->arr[j] = aux;
            }
        }
    }
}

void insere_lista(Lista* lista, char* nome, char* endereco, char* telefone, int cpf){
	int pos=lista->topo;
	int cont;
	int i=0;
	int j=0;	
	Clientes* cli = (Clientes*)malloc(sizeof(Clientes));
	strcpy(cli->nome, nome);
	strcpy(cli->endereco, endereco);
	strcpy(cli->telefone, telefone);
	cli->cpf=cpf;
	lista->arr[pos]=cli;
	lista->topo++;
}



int busca(Lista* lista, int cpf){
   int direita, esquerda, meio, encontrado = 0;
   direita = lista->topo-1 ;
   esquerda = 0;
   while (esquerda <= direita && !encontrado) {
    meio = (direita + esquerda) / 2;
	    if (lista->arr[meio]->cpf == cpf){
	    	encontrado = 1;
		}
	    else if (cpf < lista->arr[meio]->cpf){
	    	direita = meio - 1;
		}
	    else if (cpf > lista->arr[meio]->cpf){
		    esquerda = meio + 1;
		}
   }
   if (encontrado){
   		return meio;
   }else{
       return -1;
	}
}


void remove(Lista* lista, int cpf){
	int i=0;
	
	int encontrou;
	int encontrado;
	encontrou=busca(lista, cpf);
	//encontrado=encontrou;
	if(encontrou>=0){
		free(lista->arr[encontrou]);
		int j=encontrou;
		while(encontrou < lista->topo){
			lista->arr[encontrou]=lista->arr[encontrou+1];
			encontrou++;
		}
		free(lista->arr[encontrou]);
		lista->topo=lista->topo-1;
	}
	else{
		printf("Não está na lista.");
	}
	
	
}




void imprime_lista(Lista* lista){
	int cont=0;
	for(cont; cont<lista->topo; cont++){
		printf("[%d] Cliente: %s | Tel: %s | Endereco: %s | CPF %d | \n", cont, lista->arr[cont]->nome, lista->arr[cont]->telefone, lista->arr[cont]->endereco, lista->arr[cont]->cpf);
	}
}

void print_menu(){
	printf("\n|----MENU----|");
	printf("\n| 1- Inserir |");
	printf("\n| 2- Procurar|");
	printf("\n| 3- Remover |");
	printf("\n| 0- Sair    |");
	printf("\n|------------|");
	printf("\n Sua escolha: ");
}


int main(){
	
	int pos=0;
	int opc=1;
	char nome[10];
	char endereco[300];
	char telefone[20];
	int cpf, enc;
	Lista* list = cria_lista();
	printf("\n------Larissa--Moro--|--ADS--Estrutura--de--dados--|------");
	printf("\n------Clientes--ordenados--pelo--CPF--e--com--busca--binaria------\n");
	printf("\n-----------------------------------------------------------------------------------------------------------\n");
	
	insere_lista(list, "Lari", "Rua Teste","(00)000-000",1234);
	insere_lista(list, "Vitoria", "Rua Teste2","(00)2222-222",5678);
	insere_lista(list, "Chelli", "Rua feliz","(00)2332-22112",1111);
	insere_lista(list, "Kevin", "Rua taltal","(00)24462-22882",91011);
	while(opc>0){
		ordena(list);
		printf("\n--------------CLIENTES--------------\n");
		imprime_lista(list);
		printf("\n------------------------------------\n");
		print_menu();
		scanf("%d", &opc);
				switch(opc){
					case 1:
					
						printf("Inserindo um cliente:\n");
						printf("\nNome:");
						scanf("%s", nome);
						printf("\nEndereco:");
						scanf(" %s", endereco);
						printf("\nTelefone:");
						scanf(" %s", telefone);
						printf("\nCPF:");
						scanf("%d", &cpf);
						insere_lista(list, nome, endereco,telefone,cpf);
						printf("\n Continuar? 1[sim] 0[nao]");
						scanf("%d", &opc);
						system("@cls||clear");	
					break;
					case 2:
						printf("Buscar cliente por cpf:\n");
						scanf("%d", &cpf);
						enc=busca(list, cpf);
						if(enc>=0){
							printf("Encontrado: %s",list->arr[enc]->nome);
						}else{
							printf("Nao encontrado");
						}
						printf("\n Continuar? 1[sim] 0[nao]");
						scanf("%d", &opc);
						system("@cls||clear");
					break;
					
					case 3:
						printf("Digite o cpf para remover:\n");
						scanf("%d", &cpf);
						remove(list, cpf);
						printf("\n Continuar? 1[sim] 0[nao]");
						scanf("%d", &opc);
						system("@cls||clear");
						break;
					
					
					default:
						opc=0;
						break;
					
					
				}
	}
	
	
	
	
	
	
	
	//return 0;
}
