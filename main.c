#include <stdio.h>
#include "BucketSort.h"
/* gcc main.c Sorts.c BucketSort.c -ansi -o main */

/* Função para imprimir os elementos do vetor */
void imprimeVetor(int *vetor, int tam)
{
   int cont;
   for (cont = 0; cont < tam; cont++)
      printf("%d ", vetor[cont]);
   printf("\n");
   return;
}

/* Função para ler o tamanho do vetor e o número máximo permitido */
void lerValores(int *N, int *numeroMaximo)
{

   while (1)
   {
      printf("Digite quantos numeros o vetor deve ter\n");
      if (scanf("%d", N) == 1 && *N > 0)
         break;
      else
      {
         printf("Entrada invalida\n\n");
         while (getchar() != '\n')
            ;
      }
   }

   printf("E qual vai ser o limite superior?\n");
   while (1)
   {
      if (scanf("%d", numeroMaximo) == 1 && *numeroMaximo > 0)
         break;
      else
      {
         printf("Entrada invalida\n\n");
         while (getchar() != '\n')
            ;
      }
   }
}

void escolherOrdenar(int vetor[], int tamanho){
   int escolha;
   float porcento;

   while (1){
      printf("Escolha a forma de ordenar o vetor?\n");
      printf("1 - Ordenar Parcialmente\n");
      printf("2 - Ordenar Parcial Inversamente\n");
      printf("3 - Ordenar de forma padrao(valores aleatorios)\n");
      if (scanf("%d", &escolha) != 1){
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }

      switch (escolha){
      case 1:
         printf("Ordenando parcialmente...\n");
         ordenacaoParcial(vetor, tamanho);
         break;
      case 2:
         printf("Digite a porcentagem que quer ordenar (ex: 50 para 50%%, 75 == 75%%):");
         scanf("%f", &porcento); 
         printf("Ordenando parcialmente de forma inversa...\n");
         ordenacaoParcialInversa(vetor, tamanho, porcento);
         break;
      case 3:
         printf("Mantendo a ordem padrao.\n");
         break;
      }
         break;
   }
}

/* Função para preencher o vetor com valores aleatórios */
void preencheVetor(int vetor[], int tamanho, int numeroMaximo)
{
   int i;
   for (i = 0; i < tamanho; i++)
      vetor[i] = rand() % numeroMaximo;
}

int main()
{
   int numeroMaximo;
   size_t N;

   lerValores(&N, &numeroMaximo);

   int *vetor = malloc(N * sizeof(int));

   preencheVetor(vetor, N, numeroMaximo);

   escolherOrdenar(vetor, N);
   /*imprimeVetor(vetor, N);*/

   bucketSort(vetor, N);

   /*imprimeVetor(vetor, N);*/

   return 0;
}
