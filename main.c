#include <stdio.h>
#include "BucketSort.h"

/* gcc main.c Sorts.c BucketSort.c -ansi -o main */


/* Função para imprimir os elementos do vetor */
void imprimeVetor(int *vetor, int tam) {
   int cont;
   for (cont = 0; cont < tam; cont++)
      printf("%d ", vetor[cont]);
   printf("\n");
   return;
}

/* Função para ler o tamanho do vetor e o número máximo permitido */
void lerValores(int* N, int* numeroMaximo) {

   while (1) {
      printf("Digite quantos numeros o vetor deve ter\n");
      if (scanf("%d", N) == 1 && *N > 0) break;
      else {
         printf("Entrada invalida\n\n");
         while (getchar() != '\n');
      }
   }

   printf("E qual vai ser o limite superior?\n");
   while (1) {
      if (scanf("%d", numeroMaximo) == 1 && *numeroMaximo > 0) break;
      else {
         printf("Entrada invalida\n\n");
         while (getchar() != '\n');
      }
   }
}

void EscolherOrdenarParcialmente(int vetor[], int tamanho){

   int escolha;

   while(1){
      printf("Deseja ordenar parcialmente o vetor antes?\n0 - nao\n1 - sim\n\n");

      if(scanf("%d", &escolha) == 1 && (escolha == 0 || escolha == 1)){
         if(escolha == 1) 
            ordenacaoParcial(vetor, tamanho);
         break;
      }
      else{
         printf("Entrada invalida\n\n");
         while(getchar() != '\n');
      }
   }
}

/* Função para preencher o vetor com valores aleatórios */
void preencheVetor(int vetor[], int tamanho, int numeroMaximo) {
   int i;
   for (i = 0; i < tamanho; i++)
      vetor[i] = rand() % numeroMaximo;
}

int main() {
   int numeroMaximo;
   size_t N;

   lerValores(&N, &numeroMaximo);

   int *vetor = malloc(N * sizeof(int));

   preencheVetor(vetor, N, numeroMaximo);

   EscolherOrdenarParcialmente(vetor, N);

   /*imprimeVetor(vetor, N);*/

   bucketSort(vetor, N);

   /*imprimeVetor(vetor, N);*/

   return 0;
}
