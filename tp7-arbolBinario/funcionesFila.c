#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const item FILA_INDEFINIDO = -9999;

typedef struct fila_nodo {
    item dato;
    struct fila_nodo* sig;
} fila_nodo;

typedef struct {
    struct nodo* frente;
    struct nodo* final;
    int longitud;
} Fila;

Fila filaVacia() {
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    F.longitud = 0;
    return F;
}

bool esFilaVacia(Fila fila) {
    if (fila.frente == NULL && fila.final == NULL) {
        return true;
    } else {
        return false;
    }
}

Fila enFila(Fila fila, item x) {
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = x;
    nuevo->sig = NULL;
    if (!esFilaVacia(fila)) {
        fila.final->sig = nuevo;
        fila.final = nuevo;
        return fila;
    } else {
        fila.final = nuevo;
        fila.frente = nuevo;
        return fila;
    }
}

item frente(Fila fila) {
    if (!esFilaVacia(fila)) {
        return fila.frente->dato;
    } else {
        printf("%d \nLa fila esta vacia", FILA_INDEFINIDO);
    }
}

item final(Fila fila) {
    if (!esFilaVacia(fila)) {
        return fila.final->dato;
    } else {
        printf("%d \nLa fila esta vacia", FILA_INDEFINIDO);
    }
}

Fila deFila(Fila fila) {
    nodo* aux;
    aux = fila.frente;
    if (fila.frente == fila.final) {
        fila.final = NULL;
        fila.frente = NULL;
        free(aux);
        fila.longitud -= 1;
        return fila;
    } else {
        fila.frente = fila.frente->sig;
        free(aux);
        fila.longitud -= 1;
        return fila;
    }
}

Fila enFilaN(Fila fila, item x, int cant) {
    if (cant == 0) {
        return fila;
    } else {
        cant--;
        fila = enFila(fila, x);
        fila.longitud += 1;
        fila = enFilaN(fila, x, cant);
    }
}

int longitud(Fila fila) {
    if (!esFilaVacia(fila)) {
        return fila.longitud;
    } else {
        return 0;
    }
}

Fila concat(Fila f1, Fila f2) {
    if (esFilaVacia(f2)) {
        return f1;
    } else {
        int frent;
        frent = frente(f2);
        f1 = enFila(f1, frent);
        f1.longitud += 1;
        f2 = deFila(f2);
        f2.longitud -= 1;
        // return concat(EnFila(f1, frent), DeFila(f2));
        return concat(f1, f2);
    }
}