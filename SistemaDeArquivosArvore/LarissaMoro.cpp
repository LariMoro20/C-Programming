// Larissa Moro S. Santos ADS 2019
// Trabalho de estrutura de dados
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct no {
	char info[50];
	struct no *prim; /* ponteiro para eventual primeiro filho */
	struct no *proxirm; /* ponteiro para eventual irmão */
};
typedef struct no No;

struct tree{
	struct no* prim; // arvore tem apenas o ponteiro para o primeiro nó que terá para os demais
};
typedef struct tree Tree;

No* getPont(No* prim, char *val) { //Pega o nó pelo ponto
   if(prim==NULL)
   		return NULL;
   	No* filho=prim;
   	No* irm=NULL;
   	No* achou=NULL;
   	for(filho=prim; filho!=NULL; filho= filho->prim)
   		for(irm=filho; irm!=NULL; irm = irm->proxirm){
   			if(!strcmp(irm->info, val))
				return irm;
				if(prim!=irm)
					achou=getPont(irm, val);
				if(achou)
				return achou;   
			}
	return NULL;
}

No* auxRemove(No* sair){
	if(sair->proxirm != NULL)
		return sair->proxirm;
	if(sair->prim!=NULL)
		sair->prim= auxRemove(sair->prim);
	free(sair);
	return NULL;
}

No* remove(No* prim, char *val) { //Remove de forma recursiva
  if(prim==NULL){
  	return NULL;
  }
  else{
  	if(strcmp(prim->info, val)==0){
  		prim=auxRemove(prim);
	}
  	else{
  		if(prim->proxirm!=NULL){
  		 prim->proxirm=remove(prim->proxirm, val);	
		}
		if(prim->prim!=NULL){
		 prim->prim=remove(prim->prim, val);	
		}	
	}
  }
 return prim;
}

Tree* insereTree(Tree* t, char *pasta, char *val){
  No* novo= (No*)malloc(sizeof(No));
  strcpy(novo->info, val);
  novo->prim=NULL;
  novo->proxirm=NULL;
  if(t==NULL){
  	t = (Tree*)malloc(sizeof(Tree));
  	t->prim=novo;
  	return t;
  }
  No* pont=getPont(t->prim,pasta);
  if(pont!=NULL){
  	if(pont->prim==NULL){
  		pont->prim=novo;
  		return t;
	  }else{
	  	No* aux = pont->prim;
	  		while(aux->proxirm !=NULL)
	  			aux=aux->proxirm;
	  		aux->proxirm=novo;
	  		return t;
	  }
  }else{
  	printf("Não encontrado elemento pai!");
  	getchar();
  }
  return t;
}

void tree_print(No *arv){
	static int altura=0;
	int espaco;
	No* aux;
	if(arv==NULL)
		return;
	for(aux =arv; aux!=NULL; aux=aux->proxirm){
		for(espaco=0; espaco<altura; espaco++)
			printf(" ");
		printf("%s", aux->info);
		if (aux->prim != NULL)
			printf("/");
		printf("\n");
		altura++;
		tree_print(aux->prim);
		altura--;
	}	
}

void imprime(Tree *t){
	printf("   ------------ARVORE----------- \n");
	tree_print(t->prim);
	printf(" ----------------------------- \n");
}

void print_menu(){
	printf("\n|----MENU----|");
	printf("\n| 1- Inserir |");
	printf("\n| 2- Remover |");
	printf("\n| 3- Procurar|");
	printf("\n| 0- Sair    |");
	printf("\n|------------|");
	printf("\n Sua escolha: ");
}

void imprimeHeader(){
	printf("|------------------------------------------------------------------|\n");
	printf("|\t\tEstrutura de Dados	                           |\n");
	printf("|\tLarissa Moro S. Santos ADS 2019				   |\n");
	printf("|Trabalho usando arvores com numero indefinido de nos filhos/irmaos|\n");
	printf("|------------------------------------------------------------------|\n");
}

int main(){
	Tree* t = NULL;
	No* rem;
	char item[100];
	char word[100];
	char pai[100];
	int opc=0;
	int cont=1;
	
	t= insereTree(t, "System",  "Sistema");// "System" apenas por conta da necesidade do parâmetro, neste caso o parametro não é utilizado.
	t= insereTree(t, "Sistema", "Pasta1");//Cria Pasta1 filho pasta Sistema
	t= insereTree(t, "Sistema", "Pasta2");//Cria Pasta2 filho pasta Sistema irma da pasta1

	t= insereTree(t, "Pasta1", "arquivo1Pasta1");//Cria arquivo1P1 filho pasta Pasta1
	t= insereTree(t, "Pasta1", "arquivo2Pasta1");//Cria arquivo2Pasta1 filho pasta Pasta1 irmao do arquivo1Pasta1
	t= insereTree(t, "Pasta1", "arquivo3Pasta1");//Cria arquivo3Pasta1 filho pasta Pasta1 irmao do arquivo1Pasta1 e arquivo2Pasta1
	t= insereTree(t, "Pasta1", "arquivo4Pasta1");//Cria arquivo3Pasta1 filho pasta Pasta1 irmao do arquivo1Pasta1 e arquivo2Pasta1

	t= insereTree(t, "Pasta2", "arquivo1Pasta2");//Cria arquivo2P2 filho pasta Pasta2
	t= insereTree(t, "Pasta2", "arq");//Cria arquivo2P2 filho pasta Pasta2
	t= insereTree(t, "Pasta2", "arquivo2Pasta2");//Cria arquivo2P2 filho pasta Pasta2 irmao do arquivo1Pasta2

	t= insereTree(t, "Pasta1", "SubPasta1");//Cria SubPasta1 filho Pasta1
	t= insereTree(t, "SubPasta1", "arq1SubPasta1");//Cria arq1SubPasta1 filho SubPasta1
	t= insereTree(t, "SubPasta1", "arq2SubPasta1");//Cria arq2SubPasta1 filho SubPasta1 irmao do arq1SubPasta1
	t= insereTree(t, "SubPasta1", "arq3SubPasta1");//Cria arq3SubPasta1 filho SubPasta1 irmao do arq2SubPasta1 e arq1SubPasta1
	t= insereTree(t, "SubPasta1", "arq4SubPasta1");//Cria arq4SubPasta1 filho SubPasta1 irmao do arq1SubPasta1, arq2SubPasta1 e arq3SubPasta1

	// USER INTERAÇÃO
	imprimeHeader();
	imprime(t);
	printf("\n Deseja interagir? 1-sim | 0-Nao \n");
	scanf("%d", &cont);
	while(cont>=1){
		system("@cls||clear");
		imprime(t);
		print_menu();
		scanf("%d", &opc);
		switch (opc){
			case 1:
				system("@cls||clear");
				imprime(t);
				printf("\n Insira um item");	
				printf("\n Nome do item:");
				scanf("%s", word);
				printf("\n %s sera filho de quem? ", word);
				scanf("%s", pai);
				t= insereTree(t, pai, word);//Cria Pasta3 filho pasta Sistema irma da Pasta1
			break;
			
			case 2:
				system("@cls||clear");
				imprime(t);
				printf("\n Que item deseja remover? ");
				scanf("%s", item);
				rem=remove(t->prim, item);
			break;
			
			case 3:
				system("@cls||clear");
				imprime(t);
				printf("\n Que item deseja procurar? ");
				scanf("%s", item);
				printf(getPont(t->prim, item) ? " Item existe na arvore!" : " Item NAO existe na arvore!");
				printf("\n De novo? 1-sim | 0-Nao \n");
				scanf("%d", &cont);
			break;
			
			default:
				cont=0;
				imprimeHeader();
			break;
		}
	}
}




