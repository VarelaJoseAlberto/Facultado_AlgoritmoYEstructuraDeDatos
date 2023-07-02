#include <stdio.h>
#include <stdlib.h>
#include "funcionesOrdenamineto.c"

int main() {
    int A[] = {200, 2, 31, 40, 220, 130, 100};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Arreglo desordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    radixSortMSD(A, n, 3);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}