#include "BucketSort.h"
#include "Sorts.h"
#include <time.h>
#include <math.h>


double difTempo(clock_t t0, clock_t t1) {
    return (double)(t1 - t0) / CLOCKS_PER_SEC;
}

int EscolheOrdenacao(void) {
    int qual;

    while (1) {
        printf("Qual tipo de ordenacao voce quer usar?\n\n");
        printf("1 - Select sort\n2 - Bubble sort\n3 - Heap sort\n4 - Quick sort\n5 - Inserction sort\n\n");

        if (scanf("%d", &qual) != 1) {
            printf("Entrada invalida");
            while (getchar() != '\n');
        } else if (qual > 5 || qual < 1) {
            printf("Opcao invalida\n");
        } else {
            break;
        }
    }

    return qual;
}

int *OrdenacaoDosBuckets(int *array, int N_BUCKETS, int **buckets, int bucketCount[]) {
    int qual = EscolheOrdenacao();
    int k = 0;
    int i, j;
    clock_t t0, t1;

    t0 = clock();

    switch (qual) {
    case 1:
        for (i = 0; i < N_BUCKETS; i++) {
            selectSort(buckets[i], bucketCount[i]);
            for (j = 0; j < bucketCount[i]; j++)
                array[k++] = buckets[i][j];
        }
        break;
    case 2:
        for (i = 0; i < N_BUCKETS; i++) {
            bubbleSort(buckets[i], bucketCount[i]);
            for (j = 0; j < bucketCount[i]; j++)
                array[k++] = buckets[i][j];
        }
        break;
    case 3:
        for (i = 0; i < N_BUCKETS; i++) {
            heapSort(buckets[i], bucketCount[i]);
            for (j = 0; j < bucketCount[i]; j++)
                array[k++] = buckets[i][j];
        }
        break;
    case 4:
        for (i = 0; i < N_BUCKETS; i++) {
            quickSort(buckets[i], 0, bucketCount[i] - 1);
            for (j = 0; j < bucketCount[i]; j++)
                array[k++] = buckets[i][j];
        }
        break;
    case 5:
        for (i = 0; i < N_BUCKETS; i++) {
            insertionSort(buckets[i], bucketCount[i]);
            for (j = 0; j < bucketCount[i]; j++)
                array[k++] = buckets[i][j];
        }
        break;
    }

    t1 = clock();
    printf("Tempo para ordenar: %f\n", (float)difTempo(t0, t1));

    return array;
}

void bucketSort(int *array, int n) {
    clock_t t0, t1;

    int N_BUCKETS = (int)sqrt(n);

    /* Encontra o valor máximo para normalizar */
    int max = array[0];
    int i, j;
    for (i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }

    /* Cria os buckets */
    int **buckets = malloc(N_BUCKETS * sizeof(int*));
    
    int *bucketCount =  malloc(N_BUCKETS * sizeof(int));
    int bucketSize = n; /* Tamanho máximo por bucket */

    for (i = 0; i < N_BUCKETS; i++){
        buckets[i] = malloc(bucketSize * sizeof(int));
        bucketCount[i] = 0;
        for(j = 0; j < bucketSize; j++) 
            buckets[i][j] = 0;
    }

    /* Distribui os elementos nos buckets */
    for (i = 0; i < n; i++) {
        int idx = (array[i] * N_BUCKETS) / (max + 1); /* Índice do bucket */
        buckets[idx][bucketCount[idx]++] = array[i];
    }

    /* Ordena cada bucket e junta os resultados */
    OrdenacaoDosBuckets(array, N_BUCKETS, buckets, bucketCount);


    /* Libera a memória */
    for (i = 0; i < N_BUCKETS; i++)
        free(buckets[i]);
    free(buckets);
}
