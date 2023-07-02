#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
typedef struct {
    int data[MAX];
    int length;
} Tfila;

Tfila filaVacia() {
    Tfila f;
    f.length = 0;
    return f;
}

int esFilaVacia(Tfila f) {
    return (f.length == 0);
}

Tfila enfila(Tfila f, int elemento) {
    f.data[f.length] = elemento;
    f.length++;
    return f;
}

Tfila defila(Tfila f) {
    if (!esFilaVacia(f)) {
        for (int i = 0; i < f.length - 1; i++) {
            f.data[i] = f.data[i + 1];
        }
        f.length--;
    }
    return f;
}

int frente(Tfila f) {
    return f.data[0];
}

void mostrar(Tfila f) {
    for (int i = 0; i < f.length; i++) {
        printf("%d ", f.data[i]);
    }
    printf("\n");
}

int kthDigit(int number, int k) {
    int divisor = 1;
    for (int i = 1; i < k; i++) {
        divisor *= 10;
    }
    return (number / divisor) % 10;
}

void radixMSD(int A[], int izq, int der, int k) {
    if (izq < der) {
        Tfila q[10];
        for (int j = 0; j < 10; j++) {
            q[j] = filaVacia();
        }
        for (int i = izq; i <= der; i++) {
            int b = A[i];
            int j = kthDigit(b, k);
            q[j] = enfila(q[j], b);
        }
        int i = izq;
        for (int j = 0; j < 10; j++) {
            while (!esFilaVacia(q[j])) {
                A[i] = frente(q[j]);
                q[j] = defila(q[j]);
                i++;
            }
        }
        for (int j = 0; j < 10; j++) {
            if (!esFilaVacia(q[j]) && k > 1) {
                radixMSD(A, izq, i - 1, k - 1);
            }
        }
    }
}

void radixSortMSD(int A[], int n, int M) {
    radixMSD(A, 0, n - 1, M);
}
