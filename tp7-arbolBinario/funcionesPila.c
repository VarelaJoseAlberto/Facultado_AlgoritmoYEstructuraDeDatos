#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const item PILA_INDEFINIDO = -9999;
typedef struct nodo {
    item dato;
    struct nodo* sig;
} nodo;

typedef struct {
    struct nodo* cabecera;
    int altura;
} Pila;

/*pilavacia*/
void crearPila(Pila* pila) {
    pila->cabecera = NULL;
    pila->altura = 0;
}

bool esPilaVacia(Pila pila) {
    if (pila.altura == 0) {
        return true;
    } else {
        return false;
    }
}

Pila push(Pila pila, item x) {
    nodo* nuevo;
    nuevo = (nodo*)malloc(sizeof(nodo*));
    nuevo->dato = x;
    nuevo->sig = pila.cabecera;
    pila.cabecera = nuevo;
    pila.altura++;
    return pila;
}

Pila pop(Pila pila) {
    if (!esPilaVacia(pila)) {
        struct nodo* aux = pila.cabecera;
        pila.cabecera = pila.cabecera->sig;
        pila.altura -= 1;
        free(aux);
        return pila;
    }
}

int top(Pila pila) {
    if (!esPilaVacia(pila)) {
        return pila.cabecera->dato;
    } else {
        puts("Pila vacia.");
        return PILA_INDEFINIDO;
    }
}

int altura(Pila pila) {
    if (!esPilaVacia(pila)) {
        return pila.altura;
    } else {
        return 0;
    }
}

void limpiarPila(Pila* pila) {
    while (!esPilaVacia(*pila)) {
        *pila = pop(*pila);
    }
}

void mostrarPila(Pila* pila) {
    nodo* nodoActual = pila->cabecera;
    while (nodoActual != NULL) {
        printf("%d ", nodoActual->dato);
        nodoActual = nodoActual->sig;
    }
    printf("\n");
}

item fondo(Pila pila) {
    if (!esPilaVacia(pila)) {
        Pila pilAux = pila;
        nodo* nodoAux = pilAux.cabecera;
        while (nodoAux->sig != NULL) {
            pilAux.cabecera = nodoAux->sig;
            nodoAux = nodoAux->sig;
        }
        return pilAux.cabecera->dato;
    } else {
        puts("Error, pila vacia");
    }
}

Pila* invertirLista(Pila* pila) {
    Pila* pAux = (Pila*)malloc(sizeof(Pila));
    crearPila(pAux);
    nodo* actual = pila->cabecera;
    while (actual != NULL) {
        push(*pAux, actual->dato);
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

Pila popFondo(Pila pila) {
    if (esPilaVacia(pila)) {
        printf("pila vacia");
        return pila;
    }
    item fond = fondo(pila);
    Pila pilAux;
    crearPila(&pilAux);

    while (!esPilaVacia(pila)) {
        item elemento = top(pila);
        if (elemento != fond) {
            pilAux = push(pilAux, elemento);
        }
        pila = pop(pila);
    }
    while (!esPilaVacia(pilAux)) {
        item elemento = top(pilAux);
        pilAux = push(pilAux, elemento);
        pilAux = pop(pilAux);
    }
    return pila;
}

bool esSimetrica(Pila pila) {
    if (esPilaVacia(pila)) {
        return true;
    } else {
        item cabeza, fond;
        cabeza = top(pila);
        fond = fondo(pila);
        if (cabeza == fond) {
            pila = pop(pila);
            pila = popFondo(pila);
            esSimetrica(pila);
        } else {
            return false;
        }
    }
}

bool incluida(Pila p1, Pila p2) {
    while (!esPilaVacia(p1)) {
        if (top(p1) == top(p2)) {
            p1 = pop(p1);
            p2 = pop(p2);
        } else {
            p2 = pop(p2);
        }
        if (esPilaVacia(p1)) {
            return true;
        }
        if (esPilaVacia(p2)) {
            return false;
        }
    }
    return true;
}