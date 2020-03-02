#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main() {
char linha[1024];
char * ultima;
int palavras=0;
char art[5]="Lorem ipsum";
char cont[10]="CAPÍTULO";
char non[3]="non";
int brasil=0;
FILE *txt;
FILE *saida;
    if((txt=fopen("ArquivoExemplo.txt","r")) == NULL){
        printf("Erro ao abrir arquivo principal");
    }
     if((saida=fopen("saida.html","w")) == NULL){
        printf("Erro ao abrir arquivo de saida");
    }
    else{
        fprintf(saida, "<html>\n <head><meta charset=\"utf-8\"/>\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n</head>\n<body>");
        fprintf(saida, "<header align=\"center\" style=\"border:2px groove gray; background-color:purple;\">\n <h1> Exemplo de página </h1>\n <p><b> Nome: </b> Larissa Moro \n ADS II Sem </p>\n</header>\n<div align=\"center\">\n");
        while(!feof(txt)) {
            fgets(linha, 1024, txt);
            ultima = strtok(linha, " ");
                while(ultima != NULL){
                    printf("%s ",ultima);

                  if(ultima != NULL)  {
                        if((strcmp(ultima,art))==0){
                            fprintf(saida, "<b>%s ", ultima);
                            ultima = strtok(NULL, " ");
                            printf("%s ", ultima);
                            fprintf(saida, "%s </b>", ultima);
                        }
                        else if((strcmp(ultima,non))==0){
                            fprintf(saida, "<b style='color:brown;'>%s ", ultima);
                            ultima = strtok(NULL, " ");
                            printf("%s ", ultima);
                            fprintf(saida, "%s </b>", ultima);
                        }
                         
                        else if((strcmp(ultima,cont))==0){
                                 fprintf(saida, "<h2 style='color:red'> %s ", ultima);
                                 ultima = strtok(NULL, " ");
                                 printf("%s ", ultima);
                                 fprintf(saida, "%s </h2>", ultima);
                        }
                        else
                        	fprintf(saida, "%s ", ultima);
                  }
                  ultima = strtok(NULL, " ");
               }
            fprintf(saida, "<br>");
        }

    }

        fprintf(saida, "</div><footer style=\"background-color:gray;border:2px groove black; padding:20px;\">Lari Moro <br> IFRS-Campus Osório <br> ADS II Sem - 2017 <br> Atividade IV </footer></body>\n</html>", ultima);
        fclose(txt);
        printf("\nConfira o arquivo!\n");
        fclose(saida);
        system("pause");
        return(0);
}
