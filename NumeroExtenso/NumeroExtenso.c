#include<stdio.h>
#include<string.h>
int cont=0,b;//b tambem define 01unidade 02dezena 03centena 04milhar 05milhao nessa ordem crescente
char valor[20],imprimir[200];
	char continua[0];
void umd(){
     switch(valor[b]){
              case '1':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," um ");break;//verifica caso dgito seja um
              case '2':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," dois ");break;
              case '3':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," tres ");break;
              case '4':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," quatro ");break;
              case '5':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," cinco ");break;
              case '6':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," seis ");break;
              case '7':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," sete ");break;
              case '8':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," oito ");break;
              case '9':if(cont>=2)strcat(imprimir,"e");strcat(imprimir," nove ");break;
    }
}
void doisd(){
     if(valor[b]=='1'){
            switch(valor[b-1]){
                  case '0':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," dez ");break;
                  case '1':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," onze ");break;//verifica caso dgito seja um
                  case '2':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," doze ");break;
                  case '3':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," treze ");break;
                  case '4':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," quatorze ");break;
                  case '5':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," quinze ");break;
                  case '6':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," dezesseis ");break;
                  case '7':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," dezessete ");break;
                  case '8':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," dezoito ");break;
                  case '9':b--;if(cont>=3)strcat(imprimir,"e");strcat(imprimir," dezenove ");break;
            }
     }
     else{
         switch(valor[b]){//se for zero nao faz nada
              case '2':if(cont>=3)strcat(imprimir,"e");strcat(imprimir," vinte ");break;//verifica caso dgito seja um
              case '3':if(cont>=3)strcat(imprimir,"e");strcat(imprimir," trinta ");break;
              case '4':if(cont>=3)strcat(imprimir,"e");strcat(imprimir," quarenta ");break;
              case '5':if(cont>=3)strcat(imprimir,"e");strcat(imprimir," cinquenta ");break;
              case '6':if(cont>=3)strcat(imprimir,"e");strcat(imprimir," sessenta ");break;
              case '7':if(cont>=3)strcat(imprimir,"e");strcat(imprimir," setenta ");break;
              case '8':if(cont>=3)strcat(imprimir,"e");strcat(imprimir," oitenta ");break;
              case '9':if(cont>=3)strcat(imprimir,"e");strcat(imprimir," noventa ");break;
                }
         }
}

void tresd(){
    switch(valor[b]){//se for zero nao faz nada
          case '1':if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir," cem "); else strcat(imprimir," cento ");break;//verifica caso dgito seja um
          case '2':strcat(imprimir," duzentos ");break;
          case '3':strcat(imprimir," trezentos ");break;
          case '4':strcat(imprimir," quatrocentos ");break;
          case '5':strcat(imprimir," quinhentos ");break;
          case '6':strcat(imprimir," seiscentos ");break;
          case '7':strcat(imprimir," setecentos ");break;
          case '8':strcat(imprimir," oitocentos ");break;
          case '9':strcat(imprimir," novecentos ");break;
    }
}
void quatrod(){
       switch(valor[b]){//se for zero nao faz nada
              case '1':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," um mil ");break;//verifica caso dgito seja um
              case '2':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," dois mil");break;
              case '3':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," tres mil ");break;
              case '4':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," quatro mil ");break;
              case '5':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," cinco mil ");break;
              case '6':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," seis mil ");break;
              case '7':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," sete mil ");break;
              case '8':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," oito mil ");break;
              case '9':if(cont>=5)strcat(imprimir,"e");strcat(imprimir," nove mil ");break;
        }

}
void cincod(){
     if(valor[b-1]=='0'&&valor[b]=='1'){
         switch(valor[b]){
            case '1':strcat(imprimir," dez mil ");break;//verifica caso dgito seja um

        }
     }
    else if(valor[b]=='1'){
        switch(valor[b-1]){//se for zero nao faz nada
                  case '1':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," onze mil ");break;//verifica caso dgito seja um
                  case '2':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," doze mil ");break;
                  case '3':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," treze mil ");break;
                  case '4':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," quatorze mil ");break;
                  case '5':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," quinze mil ");break;
                  case '6':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," dezesseis mil ");break;
                  case '7':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," dezessete mil ");break;
                  case '8':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," dezoito mil ");break;
                  case '9':b--;if(cont>=6)strcat(imprimir,"e");strcat(imprimir," dezenove mil ");break;
        }
    }
         else{
	          switch(valor[b]){//se for zero nao faz nada
                  case '2':if(cont>=7)strcat(imprimir,"e");strcat(imprimir," vinte ");if((valor[b-1])=='0')strcat(imprimir,"mil ");break;//verifica caso dgito seja um
                  case '3':if(cont>=7)strcat(imprimir,"e");strcat(imprimir," trinta ");if((valor[b-1])=='0')strcat(imprimir,"mil ");break;
                  case '4':if(cont>=7)strcat(imprimir,"e");strcat(imprimir," quarenta ");if((valor[b-1])=='0')strcat(imprimir,"mil ");break;
                  case '5':if(cont>=7)strcat(imprimir,"e");strcat(imprimir," cinquenta ");if((valor[b-1])=='0')strcat(imprimir,"mil ");break;
                  case '6':if(cont>=7)strcat(imprimir,"e");strcat(imprimir," sessenta ");if((valor[b-1])=='0')strcat(imprimir,"mil ");break;
                  case '7':if(cont>=7)strcat(imprimir,"e");strcat(imprimir," setenta ");if((valor[b-1])=='0')strcat(imprimir,"mil ");break;
                  case '8':if(cont>=7)strcat(imprimir,"e");strcat(imprimir," oitenta ");if((valor[b-1])=='0')strcat(imprimir,"mil ");break;
                  case '9':if(cont>=7)strcat(imprimir,"e");strcat(imprimir," noventa ");if((valor[b-1])=='0')strcat(imprimir,"mil ");break;
	          }
         }
}

void seisd(){
         switch(valor[b]){//se for zero nao faz nada
	          case '1':if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir," cem mil");else strcat(imprimir," cento ");break;//verifica caso dgito seja um
	          case '2':strcat(imprimir," duzentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"mil ");break;
	          case '3':strcat(imprimir," trezentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"mil ");break;
	          case '4':strcat(imprimir," quatrocentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"mil ");break;
	          case '5':strcat(imprimir," quinhentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"mil ");break;
	          case '6':strcat(imprimir," seiscentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"mil ");break;
	          case '7':strcat(imprimir," setecentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"mil ");break;
	          case '8':strcat(imprimir," oitocentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"mil ");break;
	          case '9':strcat(imprimir," novecentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"mil ");break;
         }
}
void seted(){
     if(cont>=7)
         switch(valor[b]){//se for zero nao faz nada
              case '1':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," um milhao ");break;//verifica caso dgito seja um
              case '2':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," dois milhoes ");break;
              case '3':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," tres milhoes ");break;
              case '4':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," quatro milhoes ");break;
              case '5':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," cinco milhoes ");break;
              case '6':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," seis milhoes ");break;
              case '7':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," sete milhoes ");break;
              case '8':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," oito milhoes ");break;
              case '9':if(cont>=8)strcat(imprimir,"e");strcat(imprimir," nove milhoes ");break;
         }

}
void oitod(){
     if(valor[b-1]=='0'&&valor[b]=='1'){
         switch(valor[b]){
                case '1':strcat(imprimir," dez milhoes ");break;//verifica caso dgito seja um

                }
     }
     else if(valor[b]=='1'){
         switch(valor[b-1]){//se for zero nao faz nada
              case '1':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," onze milhoes ");break;//verifica caso dgito seja um
              case '2':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," doze milhoes ");break;
              case '3':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," treze milhoes ");break;
              case '4':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," quatorze milhoes ");break;
              case '5':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," quinze milhoes ");break;
              case '6':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," dezesseis milhoes ");break;
              case '7':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," dezessete milhoes ");break;
              case '8':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," dezoito milhoes ");break;
              case '9':b--;if(cont>=9)strcat(imprimir,"e");strcat(imprimir," dezenove milhoes ");break;
        }
    }
	else{
      switch(valor[b]){//se for zero nao faz nada
              case '2':if(cont>8)strcat(imprimir,"e");strcat(imprimir," vinte ");if((valor[b-1])=='0')strcat(imprimir,"milhoes ");break;//verifica caso dgito seja um
              case '3':if(cont>8)strcat(imprimir,"e");strcat(imprimir," trinta ");if((valor[b-1])=='0')strcat(imprimir,"milhoes ");break;
              case '4':if(cont>8)strcat(imprimir,"e");strcat(imprimir," quarenta ");if((valor[b-1])=='0')strcat(imprimir,"milhoes ");break;
              case '5':if(cont>8)strcat(imprimir,"e");strcat(imprimir," cinquenta ");if((valor[b-1])=='0')strcat(imprimir,"milhoes ");break;
              case '6':if(cont>8)strcat(imprimir,"e");strcat(imprimir," sessenta ");if((valor[b-1])=='0')strcat(imprimir,"milhoes ");break;
              case '7':if(cont>8)strcat(imprimir,"e");strcat(imprimir," setenta ");if((valor[b-1])=='0')strcat(imprimir,"milhoes ");break;
              case '8':if(cont>8)strcat(imprimir,"e");strcat(imprimir," oitenta ");if((valor[b-1])=='0')strcat(imprimir,"milhoes ");break;
              case '9':if(cont>8)strcat(imprimir,"e");strcat(imprimir," noventa ");if((valor[b-1])=='0')strcat(imprimir,"milhoes ");break;
      }
	 }
}
void noved(){
         switch(valor[b]){//se for zero nao faz nada
              case '1':if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir," cem milhoes");else strcat(imprimir," cento ");break;//verifica caso dgito seja um
              case '2':strcat(imprimir," duzentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"milhoes ");break;
              case '3':strcat(imprimir," trezentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"milhoes ");break;
              case '4':strcat(imprimir," quatrocentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"milhoes ");break;
              case '5':strcat(imprimir," quinhentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"milhoes ");break;
              case '6':strcat(imprimir," seiscentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"milhoes ");break;
              case '7':strcat(imprimir," setecentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"milhoes ");break;
              case '8':strcat(imprimir," oitocentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"milhoes ");break;
              case '9':strcat(imprimir," novecentos ");if(valor[b-1]=='0'&&valor[b-2]=='0')strcat(imprimir,"milhoes ");break;
         }
}

void inverter(char dados[20]){//funcao inverter string
  char auxc;
  int ac,bc,contc;
  contc=strlen(dados);
  bc=contc;
  for (ac=0;ac<contc/2;ac++){
        bc--;
      auxc=valor[ac];
      valor[ac]=valor[bc];
      valor[bc]=auxc;
 }
}


void tamanhochar(){
    printf("Digite valor:");
    scanf("%s", &valor);
    cont=strlen(valor);
    inverter(valor);
    if(valor[0]=='0'&&cont<=1){
    	strcat(imprimir,"Zero");
    }
}
int main(){
	 do{
	 	system("@cls||clear");
	 	printf("\n----------------------------\n");
	 	printf("\n----NUMERO--POR--EXTENSO----\n");
	 	printf("\n----------------------------\n");
	    tamanhochar();
	    int a;
	    for(b=cont;b>=0;b--){
	      switch (b){
              case 0:umd();break;//verifica qual casa decimal esta a correr //;
              case 1:doisd();break;
              case 2:tresd();break;
              case 3:quatrod();break;
              case 4:cincod();break;
              case 5:seisd();break;
              case 6:seted();break;
              case 7:oitod();break;
              case 8:noved();break;
	       }
	    }
        printf("\n\n\%s\n\n", imprimir);
    	printf ("\n Continuar (s) ou Ternimar (n)? ");
		scanf("%s", &continua[0]);
	}while((continua[0]=='s' || continua[0]=='S'));
    printf("Fim do programa");
    getchar();
}
