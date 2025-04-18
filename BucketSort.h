#include <stdio.h>
#include <stdlib.h>
#include "Sorts.h"

#define TAM 10      /* Tamanho do vetor*/
#define N_BUCKETS 5 /* Número de baldes */

int EscolheOrdenacao(void);
void bucketSort(int *array, int n);
