#include "BucketSort.h"

// Função de ordenação usada dentro dos buckets (Insertion Sort)
void insertionSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
        int chave = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave;
    }
}

void bucketSort(int *array, int n) {
    // Encontra o valor máximo para normalizar
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];

    // Cria os buckets
    int **buckets = malloc(N_BUCKETS * sizeof(int *));
    int bucketCount[N_BUCKETS] = {0};
    int bucketSize = n; // Tamanho máximo por bucket

    for (int i = 0; i < N_BUCKETS; i++)
        buckets[i] = malloc(bucketSize * sizeof(int));

    // Distribui os elementos nos buckets
    for (int i = 0; i < n; i++) {
        int idx = (array[i] * N_BUCKETS) / (max + 1); // Índice do bucket
        buckets[idx][bucketCount[idx]++] = array[i];
    }

    // Ordena cada bucket e junta os resultados
    int k = 0;
    for (int i = 0; i < N_BUCKETS; i++) {
        insertionSort(buckets[i], bucketCount[i]);
        for (int j = 0; j < bucketCount[i]; j++)
            array[k++] = buckets[i][j];
    }

    // Libera a memória
    for (int i = 0; i < N_BUCKETS; i++)
        free(buckets[i]);
    free(buckets);
}

void mostra(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

