#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Definicion de la estructara para lista enlazada
typedef int item;
typedef struct nodo {
    item dato;
    struct nodo* sig;
} Nodo;

// Definicion para la pila

typedef struct Pila {
    Nodo* tope;
} Pila;

int esPilaVacia(Pila* pila) {
    return pila == NULL;
}

void pilaVacia(Pila* pila) {
    pila->tope = NULL;
}

int top(Pila* pila) {
    if (pila->tope == NULL) {
        printf("pila vacia");
        exit(1);
    } else {
        return pila->tope->dato;
    }
}

int pop(Pila* pila) {
    int elemento;
    if (pila->tope == NULL) {
        printf("pila vacia");
        exit(1);
    } else {
        Nodo* nodo = pila->tope;
        elemento = nodo->dato;
        pila->tope = nodo->sig;
        free(nodo);
        return elemento;
    }
}

void push(Pila* pila, int elemento) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = elemento;
    nodo->sig = pila->tope;
    pila->tope = nodo;
}

int fondo(Pila* pila) {
    if (pila->tope == NULL) {
        printf("pila vacia");
        exit(1);
    } else {
        Nodo* nodo = pila->tope;
        while (nodo->sig != NULL) {
            nodo = nodo->sig;
        }
        return nodo->dato;
    }
}

void popFondo(Pila* pila) {
    if (pila->tope == NULL) {
        printf("pila vacia");
        exit(1);
    } else {
        Nodo* nodoAn = NULL;
        Nodo* nodo = pila->tope;
        while (nodo->sig != NULL) {
            nodoAn = nodo;
            nodo = nodo->sig;
        }
        if (nodoAn == NULL) {
            pila->tope = NULL;
        } else {
            nodoAn->sig = NULL;
        }
        free(nodo);
    }
}

void mostrarPila(Pila* pila) {
    Nodo* nodoActual = pila->tope;
    while (nodoActual != NULL) {
        printf("%d ", nodoActual->dato);
        nodoActual = nodoActual->sig;
    }
    printf("\n");
}

// void invertirLista(Pila* pila) {
//     Pila* pAux = (Pila*)malloc(sizeof(Pila));
//     pilaVacia(pAux);
//     Nodo* actual = pila->tope;
//     while (actual != NULL) {
//         pAux->tope = actual->dato;
//         pop(pila);
//         actual->dato = top(pila);
//     }
//     Pila* nuevo = (Pila*)malloc(sizeof(Pila));
//     pilaVacia(nuevo);
//     while (!esPilaVacia(pAux)) {
//         nuevo->tope = top(pAux);
//         pop(pAux);
//         nuevo->tope = top(pila);
//     }
//     return nuevo;
// }

Pila* invertirLista(Pila* pila) {
    Pila* pAux = (Pila*)malloc(sizeof(Pila));
    pilaVacia(pAux);
    Nodo* actual = pila->tope;
    while (actual != NULL) {
        push(pAux, actual->dato);
        actual = actual->sig;
    }
    mostrarPila(pAux);
    mostrarPila(pila);
    // Pila* nuevo = (Pila*)malloc(sizeof(Pila));
    // pilaVacia(nuevo);
    // while (!esPilaVacia(pAux)) {
    //     push(nuevo, top(pAux));
    //     pop(pAux);
    // }
    // mostrarPila(nuevo);
    free(pAux);
    // free(nuevo);
}
