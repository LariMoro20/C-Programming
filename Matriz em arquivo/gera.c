#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#define num 7



int main(){

		int i=0, j=0, opcao,cont=0, g;
		char continua[0];
		char ladoa = 186; // 65 == 0x41
		char cima = 205; // 65 == 0x41
		char cantoa = 201; // 65 == 0x41
		char cantob = 187; // 65 == 0x41
		char cantoc = 200; // 65 == 0x41
		char cantod = 188; // 65 == 0x41
		int tam=7;
		FILE *txt;

		if((txt= fopen("Arquivo.txt", "w+")) == NULL){
			printf("Erro ao abrir arquivo");
		}
	    	do{
                int matriz[tam][tam];
				system("@cls||clear");


				printf ("%c", cantoa);
					while (i<=40){
						printf ("%c", cima);
						i++;
					}
				i=0;
				printf ("%c", cantob);
				printf ("\n%c \t\tMenu de opcoes", ladoa);
				printf ("\n");
				printf ("%c", cantoa);
					while (i<=40){
						printf ("%c", cima);
						i++;
					}
				i=0;
		        //imprime menu
				printf ("%c", cantob);

				printf ("\n%c Menu de opcoes: \t\t\t  %c", ladoa,ladoa);
				printf ("\n%c \tImprimindo matrizes de tamanho: %d %c", ladoa,tam,ladoa);
				printf ("\n%c \t[ 1 ] Matriz em X  \t\t  %c", ladoa,ladoa);
				printf ("\n%c \t[ 2 ] Matriz horizontal \t  %c", ladoa, ladoa);
				printf ("\n%c \t[ 3 ] Matriz diagonal \t\t  %c", ladoa,ladoa);
				printf ("\n%c \t[ 4 ] Matriz quadro \t\t  %c", ladoa,ladoa);
				printf ("\n%c \t[ 5 ] Muda tamanho da matriz \t  %c", ladoa,ladoa);
				printf ("\n%c \t[ 0 ] Sai do Sistema \t\t  %c", ladoa,ladoa);
				printf ("\n%c \tDigite uma opcao: ", ladoa);
				scanf("%i", &opcao);
				//dá opcoes
					switch(opcao){
							//--------------------------------------------------------------------------
						case 1:

						    for(i=0; i<tam; i++){
						         for (j=0; j<tam; j++){
						                if(j==i){
						                  matriz[i][j] = 'x';
						                }
						                else{
						                    matriz[i][j] = '-';
						                }
						         }
					   		}

							for (i=0; i<tam; i++){
						         	j=tam-(i+1);
						         	matriz[i][j]='x';
							 }

					        for(i=0; i<tam; i++){
					            for (j=0; j<tam; j++){
					             fprintf(txt,"%c", matriz[i][j]);
					            }
					        	fprintf(txt,"\n");
					        }
							printf ("%c\n Impresso no arquivo!\n ", ladoa);
							printf ("%c\n Continuar (s) ou Ternimar (n)? ", ladoa);
							scanf(" %s", &continua[0]);
						break;
							//--------------------------------------------------------------------------
					   case 2:
						    for(i=0; i<tam; i++){
						         for (j=0; j<tam; j++){
						                if((i<tam) && (i>=j+1)){
						                  matriz[i][j] = '-';
						                }
						                else{
						                    matriz[i][j] = 'x';
						                }
						        }
						   }
					        for(i=0; i<tam; i++){
					            for (j=0; j<tam; j++){
					              fprintf(txt, "%c", matriz[i][j]);
					            }
					           fprintf(txt, "\n");
					        }
								printf ("%c\n Impresso no arquivo!\n ", ladoa);
							printf ("%c\n Continuar (s) ou Ternimar (n)? ", ladoa);
							scanf(" %s", &continua[0]);
						break;
							//--------------------------------------------------------------------------
						case 3:
							for(i=0; i<tam; i++){
						         for (j=0; j<tam; j++){
						                if(j==i){
						                  matriz[i][j] = 'x';
						                }
						                else{
						                    matriz[i][j] = '-';
						                }
						        }
						    }
					        for(i=0; i<tam; i++){
					            for (j=0; j<tam; j++){
					              fprintf(txt, "%c", matriz[i][j]);
					            }
					            fprintf(txt, "\n");
					        }
					        	printf ("%c\n Impresso no arquivo!\n ", ladoa);
							printf ("%c\n Continuar (s) ou Ternimar (n)? ", ladoa);
							scanf("%s", &continua[0]);

							break;
								//--------------------------------------------------------------------------
						case 4:
							for(i=0; i<tam; i++){
						         for (j=0; j<tam; j++){
						                if ((i>(tam/2) && j<(tam/2)) || (j>(tam/2) && i<(tam/2))){
						                  matriz[i][j] = 'x';
						                }

						                else{
						                    matriz[i][j] = '-';
						                }
						        }
						   }
					        for(i=0; i<tam; i++){
					            for (j=0; j<tam; j++){
					             fprintf(txt, " %c", matriz[i][j]);
					            }
					            fprintf(txt, "\n");
					        }
								printf ("%c\n Impresso no arquivo!\n ", ladoa);
							printf ("%c\n Continuar (s) ou Ternimar (n)? ", ladoa);
							scanf("%s", &continua[0]);
							break;
								//--------------------------------------------------------------------------
						case 5:
							printf("%c\n Informe o novo valor: (Atualmente: %d) ", ladoa, tam);
							scanf(" %i", &tam);
							continua[0]='s';
							break;
								//--------------------------------------------------------------------------
								
								//--------------------------------------------------------------------------
						case 0:
							continua[0]='n';
							break;
								//--------------------------------------------------------------------------
						default:
								printf ("%c\n Opcao nao disponivel, tentar novamente? \n ", ladoa);
							printf ("%c\n Continuar (s) ou Ternimar (n)? ", ladoa);
			
							scanf("%s", &continua[0]);
						break;
							//--------------------------------------------------------------------------
					}
		        		//termina de imprimir a borda
						printf ("\n%c", cantoc);
						while (i<=40){
							printf ("%c", cima);
							i++;
						}
						i=0;
						printf ("%c", cantod);

			}while((continua[0]=='s' || continua[0]=='S') && opcao!=0);
			fclose(txt);
			return(0);
}
