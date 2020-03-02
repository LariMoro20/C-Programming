#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct palavras{
char word[80];
int frequencia;
}typedef Palavras;

int tam_vetor;
int tamTotal=0;

Palavras * cria_palavra(char*ultima, Palavras *p){
  p=(Palavras*)realloc(p, sizeof(Palavras)*(tamTotal+1));
   strcpy((p[tamTotal]).word,ultima);
   p[tamTotal].frequencia=1;
   tamTotal++;
   return(p);
}

Palavras le_arquivo(FILE *txt, Palavras *palavra){
   int existe;
   char *ultima;
   int tam=0;
   int i=0;
   char linha[1024];
   if((txt=fopen("arquivo.txt", "r"))==NULL){
      printf("ERRO");
   }
   else{
      while(!feof(txt)){
      fgets(linha, 1024, txt);
            ultima = strtok(linha, " ;:,.?!-\n");
            while(ultima!=NULL){
                  if(ultima!=NULL){
                     tam=strlen(ultima);
                     i=0;
                     for(;i<tam;i++){//tudo minuscula padrão
                        ultima[i]=tolower(ultima[i]);
                     }
                     existe=existe_palavra(ultima, palavra);
                     if(existe==1){
                       palavra = cria_palavra(ultima, palavra);
                     }
                  }
                
               ultima=strtok(NULL,"  ;:,.?!-\n");
           }
      }
      int v=0;
	  FILE *resp;
      resp= fopen("registros.txt", "w");
      while(v<tamTotal){
      	fprintf(resp, "Palavra: %-22s\t|\tFrequencia:%d vez(es)\n", palavra[v].word,  palavra[v].frequencia);
      	v++;
	  }
	  fclose(resp);
   }
}


int existe_palavra(char*ultima, Palavras *p){
	int i;
	int existep;
	for(i=0;i<tamTotal+1;i++){
		existep=strcmp(ultima,(p+i)->word);
		if(existep==0){
			(p+i)->frequencia++;
			return(0);
		}
	}
	return(1);
}



int main(){
   FILE *txt;
   char titulo[100];
   printf("\nColoque o arquivo na mesma pasta do executavel com o nome de arquivo.txt, digite ok e aperte Enter: ");
   scanf("%s", titulo);
	printf("\nContando palavras.. aguarde ");

   Palavras *palavras= (Palavras *) malloc(sizeof(Palavras)+1);
   le_arquivo(txt, palavras);
   printf("\nTotal de palavras: %d", tamTotal);
   	printf("\nConcluido! Digite ok e confira o arquivo 'registros.txt' nesta mesma pasta para mais detalhes: ");

   scanf("%s", titulo);
   return(0);
}


