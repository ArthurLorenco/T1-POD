#include "BucketSort.h"
#include "Sorts.h"

int EscolheOrdenacao(void){
    int qual;

    while(1){
        printf("Qual tipo de ordenacao voce quer usar?");
        printf("1 - Select sortr\n 2 - Bubble sort\n 3 - Heap sort\n 4 - Quick sort\n5 - Inserction sort\n\n");
        
        if(scanf("%d", &qual) != 1)
            printf("Entrada invalida");
        
        else
        if(qual > 5 || qual < 1)
            printf("Opcao invalida\n");

        else
            break;
    }

    return qual;

}

int *OrdenacaoDosBuckets(int *array, int **buckets, int bucketCount[]){

    int qual = EscolheOrdenacao();
    int k = 0;

    switch (qual){
    case 1:
        for(int i = 0; i < N_BUCKETS; i++){
            selectSort(buckets[i], bucketCount[i]);
            for (int j = 0; j < bucketCount[i]; j++)
            array[k++] = buckets[i][j];
        }
        break;
    case 2:
        for(int i = 0; i < N_BUCKETS; i++){
            bubbleSort(buckets[i], bucketCount[i]);
            for (int j = 0; j < bucketCount[i]; j++)
            array[k++] = buckets[i][j];
        }
        break;
    case 3:
        for(int i = 0; i < N_BUCKETS; i++){
            heapSort(buckets[i], bucketCount[i]);
            for (int j = 0; j < bucketCount[i]; j++)
            array[k++] = buckets[i][j];
        }
        break;
    case 4:
        for(int i = 0; i < N_BUCKETS; i++){
            quickSort(buckets[i], 0, bucketCount[i]);
            for (int j = 0; j < bucketCount[i]; j++)
            array[k++] = buckets[i][j];
        }
        break;
    case 5:
        for(int i = 0; i < N_BUCKETS; i++){
            insertionSort(buckets[i], bucketCount[i]);
            for (int j = 0; j < bucketCount[i]; j++)
            array[k++] = buckets[i][j];
        }
        break;

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
    OrdenacaoDosBuckets(array, buckets, bucketCount);

    // Libera a memória
    for (int i = 0; i < N_BUCKETS; i++)
        free(buckets[i]);
    free(buckets);
}



