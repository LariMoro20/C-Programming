#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <pthread.h>
#include <locale.h>
#define N 1
//Larissa Moro ADS V semestre POD 2019
pthread_mutex_t minha_trava;
int totalzao=0;
struct resposta{
    char lista[10000][200];
    int tamanho;
};
typedef struct resposta Resposta;


struct palavras{
	char palavra[200];
	int oco;
	struct palavras* prox;
};
typedef struct palavras Palavras;

struct pilha{
    Palavras* topo;
    int total;
};
typedef struct pilha Pilha;

struct st_aux{
    Resposta* resp;
    Pilha* pilha;
    FILE * arq;
};
typedef struct st_aux Str_aux;

Pilha* cria_pilha(){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->topo=NULL;
	p->total=0;
	return p;
}

int carrega_arquivo(Pilha* p){
FILE *file;
char linha[8196];
int total=0;
char *palavra=NULL;
int tam_palavra;
int i, existe=0;

if((file=fopen("livro.txt","r"))==NULL){
		printf("O arquivo \"livro.txt\" nao existe!");
	}else{
	    while(!feof(file)){
			fgets(linha,8196,file);
			palavra=strtok(linha," ;:,.?!-\n    /t");
			while(palavra!=NULL){
				if(palavra!=NULL){
					tam_palavra=strlen(palavra);
					//Tudo minusculo
					if(palavra!=""){
						for(i=0;i<tam_palavra;i++){
							palavra[i]=tolower(palavra[i]);
						}
						cria_palavra(palavra, p);
	                  	total++;
					}
				}
				palavra=strtok(NULL," 	/t;:,.?!-\n");
			}
		}
	}
	fclose(file);
	return total;
}

int avalia(char*palavra, int tam){
    char contrario[80];
    strcpy(contrario, palavra);
    strrev(contrario);
    if(strcmp(contrario,palavra)==0){
        return(1);
    }else{
        return(0);
    }
}

int existe_palavra(char*palavra, Resposta* resp){
	int tam=resp->tamanho;
	int i;
	for(i=0; i<tam;i++){
		if(strcmp(palavra,resp->lista[i])==0){
			return(1);
		}
	}
	 return(0);
}

int cria_palavra(char*palavra, Pilha* pi){
    Palavras* p=(Palavras*)malloc(sizeof(Palavras));
	strcpy(p->palavra,palavra);
	p->oco=1;
	p->prox=pi->topo;
	pi->topo=p;
	pi->total++;
}




void* threadFunc( void *arg ){

	Str_aux *aux = (Str_aux*) arg;
   	Pilha* pi=aux->pilha;
   	Resposta* resp=aux->resp;
	FILE* arq=aux->arq;
	Palavras* p;
	int existe;
	pthread_mutex_lock( &minha_trava );
    while( pi->topo != NULL ){
		p = pi->topo;
		pi->topo = p->prox;
		int tam_palavra=strlen(p->palavra);
		pthread_mutex_unlock( &minha_trava );
		if(avalia(p->palavra,tam_palavra)){
		    pthread_mutex_lock( &minha_trava );
            totalzao++;
            pthread_mutex_unlock( &minha_trava );
            existe=existe_palavra(p->palavra, resp);

			if(existe!=1){
                 strcpy(resp->lista[resp->tamanho],p->palavra);
                 resp->tamanho++;
            }
		}
		pthread_mutex_lock( &minha_trava );

	}
        pthread_mutex_unlock( &minha_trava );
}


void imprime_tudo(Resposta* res){
	FILE* ret;

	if((ret=fopen("retorno2.txt","w"))==NULL){
		printf("O arquivo \"retorno2.txt\" nao existe!");
	}else{
        int c;
        while(c<res->tamanho){
            if((res->lista[c]!=" ")&& (res->lista[c]!="		")){
                fprintf(ret,"Palavra: %s\n",res->lista[c]);
            }
            c++;
        }
        fprintf(ret,"\n----------------------\n Total de palindromas(unicas): %d \n----------------------\n",res->tamanho);
        fprintf(ret,"\n----------------------\n Total de palindromas(repetidas): %d \n----------------------\n",totalzao);
        fclose(ret);
    }
}


int main(){

pthread_mutex_init(&minha_trava, NULL );
Pilha* pilha=cria_pilha();
int total = carrega_arquivo(pilha);

int nThreads=N;
int i, execute;
pthread_t  threades[nThreads];
	Resposta* r=(Resposta*)malloc(sizeof(Resposta));
	r->tamanho=0;
	FILE* ret;

    for(i=0; i<nThreads; i++){
        Str_aux* st=(Str_aux*) malloc(sizeof(Str_aux));
        st->pilha=pilha;
        st->resp=r;
        st->arq=ret;
        execute = pthread_create(&threades[i],NULL,threadFunc,(void*)st);
    }
	int j=0;
	for(j=0; j<nThreads; j++){
        pthread_join(threades[j], NULL);
	}
pthread_mutex_destroy;
imprime_tudo(r);
    printf("\nFim do programa, verificar arquivo gerado\n");

getchar();
return (0);
}
