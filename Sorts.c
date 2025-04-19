#include "Sorts.h"

int selectSort(int *vet, int tam) {
    int i, j, menor, aux;
    for (i = 0; i < tam - 1; i++) {
        for (j = i + 1, menor = i; j < tam; j++) {
            if (vet[j] < vet[menor])
                menor = j;
        }
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
    return 0;
}

int *bubbleSort(int *vetor, int tam) {
    int cont, troca, aux;
    do {
        troca = 0;
        for (cont = 0; cont < (tam - 1); cont++) {
            if (vetor[cont] > vetor[cont + 1]) {
                aux = vetor[cont];
                vetor[cont] = vetor[cont + 1];
                vetor[cont + 1] = aux;
                troca = 1;
            }
        }
    } while (troca);
    return vetor;
}

void heapSort(int a[], int n) {
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
        filho = i * 2 + 1;

        while (filho < n) {
            if ((filho + 1 < n) && (a[filho + 1] > a[filho]))
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

int partitionQuick(int *vet, int lo, int hi) {
    int pivo, i, j, aux;
    pivo = vet[lo];
    i = lo - 1;
    j = hi + 1;

    while (1) {
        do {
            j--;
        } while (vet[j] > pivo);

        do {
            i++;
        } while (vet[i] < pivo);

        if (i < j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        } else {
            return j;
        }
    }
}

int *quickSort(int *vet, int lo, int hi) {
    int p;
    if (lo < hi) {
        p = partitionQuick(vet, lo, hi);
        quickSort(vet, lo, p);
        quickSort(vet, p + 1, hi);
    }
    return vet;
}

void ordenacaoParcialInversa(int *vet, int tam, float porcentagemDesordenado){
    int elementos_inverter = (int)(tam * porcentagemDesordenado / 100.0f);
    quickSort(vet, 0, elementos_inverter - 1);
    
    int i;
    for (i = 0; i < elementos_inverter / 2; i++) {
        int temp = vet[i];
        vet[i] = vet[elementos_inverter - 1 - i];
        vet[elementos_inverter - 1 - i] = temp;
    }
}

int *ordenacaoParcial(int *vet, int tam) {
    int i, j, k = 0, temp;
    int gaps[8]={701,301,132,57,23,10,4};

    while (gaps[k] > ((tam / 2) - 1))
        k++;

    while (gaps[k] >= 1) {
        i = gaps[k];
        while (i < tam) {
            temp = vet[i];
            j = i - gaps[k];
            while (j >= 0 && temp < vet[j]) {
                vet[j + gaps[k]] = vet[j];
                j -= gaps[k];
            }
            vet[j + gaps[k]] = temp;
            i++;
        }
        k++;
    }
    return vet;
}

void insertionSort(int *array, int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave;
    }
}
