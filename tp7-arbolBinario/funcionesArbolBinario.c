#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char itemAB;
const int indefinido = -9999;
struct nodoAB {
    itemAB raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
};
typedef struct nodoAB *AB;

AB ABVACIO() {
    return NULL;
}

int ESABVACIO(AB ArbolB) {
    if (ArbolB == NULL) {
        return true;
    } else {
        return false;
    }
}

AB ARMARAB(AB I, itemAB raiz, AB D) {
    /*
            PASOS:
                Crear dinámicamente un nuevo nodo //Funcion aparte CrearNodo
                Agregar el valor de la Raiz al nodo
                Apuntar el puntero izq del nuevo nodo al árbol I
                Apuntar el puntero der del nuevo nodo al árbol D
                Retornar el nuevo nodo
    */
    AB nuevoNodo;
    nuevoNodo = (AB)malloc(sizeof(AB));
    nuevoNodo->raiz = raiz;
    nuevoNodo->der = D;
    nuevoNodo->izq = I;
    return nuevoNodo;
}

AB IZQUIERDO(AB ArbolB) {
    if (!ESABVACIO(ArbolB)) {
        return ArbolB->izq;
    } else {
        return NULL;
    }
}

AB DERECHO(AB ArbolB) {
    if (!ESABVACIO(ArbolB)) {
        return ArbolB->der;
    } else {
        return NULL;
    }
}

itemAB RAIZ(AB ArbolB) {
    if (!ESABVACIO(ArbolB)) {
        return ArbolB->raiz;
    } else {
        return indefinido;
    }
}

int PERTENECE(AB ArbolB, itemAB x) {
    if (!ESABVACIO(ArbolB)) {
        if (RAIZ(ArbolB) == x || PERTENECE(IZQUIERDO(ArbolB), x) || PERTENECE(DERECHO(ArbolB), x)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void preOrden(AB ArbolB) {
    if (!ESABVACIO(ArbolB)) {
        printf("%c\n", RAIZ(ArbolB));
        preOrden(ArbolB->izq);
        preOrden(ArbolB->der);
    }
}

void posOrden(AB ArbolB) {
    if (!ESABVACIO(ArbolB)) {
        preOrden(ArbolB->izq);
        preOrden(ArbolB->der);
        printf("%c\n", RAIZ(ArbolB));
    }
}

void simetricoOrden(AB ArbolB) {
    if (!ESABVACIO(ArbolB)) {
        preOrden(ArbolB->izq);
        printf("%c\n", RAIZ(ArbolB));
        preOrden(ArbolB->der);
    }
}

int EsABHoja(AB ArbolB) {
    if (ArbolB) {
        return (ArbolB->izq == NULL && ArbolB->der == NULL);
    } else {
        return (0);
    }
}