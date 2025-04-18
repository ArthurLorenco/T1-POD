#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int selectSort(int *vet, int tam);
int *bubbleSort(int *vetor, int tam);
void heapSort(int a[], int n);
int partitionQuick(int *vet, int lo, int hi);
int *quickSort(int *vet, int lo, int hi);
int *ordenacaoParcial(int *vet, int tam);
void insertionSort(int *array, int n);
