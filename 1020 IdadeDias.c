#include <stdio.h>

 
 int main(){
   int ano;
   int mes;
   int dia;
   int variavel;

   scanf("%d", &variavel);

   ano = variavel / 365;
   mes = ((variavel - (ano * 365)) / 30);
   dia = (variavel - (ano * 365) - (mes * 30));

   printf("%d ano(s)\n", ano);
   printf("%d mes(es)\n", mes);
   printf("%d dia(s)\n", dia);


      return 0;
   }