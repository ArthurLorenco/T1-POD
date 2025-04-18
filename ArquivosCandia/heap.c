#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>

#define TAM_VET		10

void heapsort(int a[], int n) {

   // by P.
   int i = n / 2, pai, filho, t;

   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }

      pai = i;

      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i * 2 + 1;

      while (filho < n) {

         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

void mostra(int *vetor, int tam){
  int cont;
  for(cont=0; cont<tam; cont++)
	printf("%d ", vetor[cont]);
  printf("\n");
  return;
}

double difTempo(clock_t t0, clock_t t1) {
    return (double)(t1 - t0) / CLOCKS_PER_SEC;
}

int main(){
  int vet[TAM_VET]={9,3,5,2,1,7,8,6,4,0}, i;
  struct timespec t0, t1;

  mostra(vet,TAM_VET);
  clock_gettime(CLOCK_MONOTONIC_RAW, &t0);
  for(i=0; i<1000000; i++)
    heapsort(vet, TAM_VET);
  clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
  printf("%f\n", (float)difTempo(t0, t1)/1000000);
  mostra(vet,TAM_VET);
  exit(0);
}
