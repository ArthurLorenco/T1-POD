#include <stdio.h>
#include <stdlib.h>

#define TAM 10      // Tamanho do vetor
#define N_BUCKETS 5 // Número de baldes

// Função de ordenação usada dentro dos buckets (Insertion Sort)
void insertionSort(int *array, int n);
void bucketSort(int *array, int n);
void mostra(int *vetor, int n);