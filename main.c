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

   printf("Digite quantos numeros o vetor deve ter\n");
   scanf("%d", N);

   printf("E qual vai ser o limite superior?\n");
   scanf("%d", numeroMaximo);

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
