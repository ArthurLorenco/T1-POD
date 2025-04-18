#include <stdio.h>
#include "BucketSort.h"


void imprimeVetor(int *vetor, int tam){
   int cont;
   for(cont=0; cont<tam; cont++)
      printf("%d ", vetor[cont]);
   printf("\n");
   return;
}

void lerValores(int* N, int* numeroMaximo){

   while(1){
      printf("Digite quantos numeros o vetor deve ter\n");
      if(scanf("%d", N) == 1 && *N > 0) break;
      else{
         printf("Entrada invalida\n\n");
         while (getchar() != '\n');
      }

   }

   
   printf("E qual vai ser o limite superior?\n");
   while(1){
      if(scanf("%d", numeroMaximo) == 1 && *numeroMaximo > 0) break;
      else{
         printf("Entrada invalida\n\n");
         while (getchar() != '\n');
      }
   }
}

void preencheVetor(int vetor[], int tamanho, int numeroMaximo){

for(int i=0; i<tamanho; i++)
      vetor[i] = rand()%numeroMaximo;

}

int main(){

   int N, numeroMaximo;

   lerValores(&N, &numeroMaximo);

   int vetor[N];

   preencheVetor(vetor, N, numeroMaximo);

   imprimeVetor(vetor, N);

   bucketSort(vetor, N);

   imprimeVetor(vetor, N);

}
