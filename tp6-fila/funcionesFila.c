#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int item;  // tipo de datos que contiene la Fila
const int indefinido = -9999;

struct nodo {
    item dato;
    struct nodo* sig;
} typedef Nodo;

struct Fila {
    struct nodo* frente;
    struct nodo* final;
} typedef Fila;

Fila FilaVacia() {
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    return F;
}

int EsFilaVacia(Fila F) {
    if (F.final == NULL && F.frente == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Fila EnFila(Fila F, item x) {
    /*
    PASOS:
    Crear dinámicamente un nuevo nodo
    Agregar el dato X al nodo
    Apuntar a NULL el puntero siguiente del nuevo nodo
    Enlazar el nuevo nodo a la Fila

        CASO A: Fila vacía
            Apuntar Fr al nuevo nodo
            Apuntar Fi al nuevo nodo

        CASO B: Fila con elementos
            Apuntar el puntero siguiente del ultimo nodo al nuevo nodo   F.Fi ->siguiente = nuevo
            Apuntar el final al nuevo nodo  F.Fi = nuevo
    */
    Nodo* NuevoNodo;                          // creo un nuevo nodo
    NuevoNodo = (Nodo*)malloc(sizeof(Nodo));  // reservo la memoria dinamica para el nuevo nodo
    NuevoNodo->sig = NULL;                    // Como sera el ultimo, deve apuntar a NULL
    NuevoNodo->dato = x;                      // Cargo el dato
    if (!EsFilaVacia(F)) {
        F.final->sig = NuevoNodo;  // Enlazo el sig del ultimo nodo al nuevo nodo
        F.final = NuevoNodo;       // pongo el nuevo nodo en el final
        return F;
    } else {
        F.final = NuevoNodo;  // ambos punteros apuntando al nuevo nodo.
        F.frente = NuevoNodo;
        return F;
    }
}

Fila DeFila(Fila F) {
    Nodo* NodoAux;
    NodoAux = F.frente;
    if (F.frente == F.final) {
        F.final = NULL;
        F.frente = NULL;
        free(NodoAux);
        return F;
    } else {
        F.frente = F.frente->sig;
        free(NodoAux);
        return F;
    }
}

item Frente(Fila F) {
    if (!EsFilaVacia(F)) {
        return F.frente->dato;
    } else {
        printf("%d \nLa Fila se encuentra Vacia\n", indefinido);
    }
}

item Final(Fila F) {
    if (!EsFilaVacia(F)) {
        return F.final->dato;
    } else {
        printf("%d \nLa Fila se encuentra Vacia\n", indefinido);
    }
}

Fila EnFilaN(Fila F, item x, int cant) {
    /*
    Especificacion Algebraica:
            Sintaxis:
                Enfilan: Fila x Item x Entero>= 0 → Fila

            Semantica: ∀ q ∈ Fila, ∀ i ∈ item, ∀ n ∈ Naturales ≥ 0

                Entero igual a cero -- Entero mayor que cero -- fila vacia -- fila no vacia

                Enfilan(q, i, n) ≡  Si n = 0 Entonces
                                        q
                                    Sino
                                        Enfilan(Enfila(q,i), i , n-1)
    */

    if (cant == 0) {
        return F;
    } else {
        cant--;
        F = EnFila(F, x);
        F = EnFilaN(F, x, cant);
    }
    return F;
}
void MostrarFila(Fila F) {
    if (EsFilaVacia(F)) {
        printf("La fila está vacía.\n");
        return;
    }

    Nodo* actual = F.frente;

    printf("Elementos de la fila:\n");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->sig;
    }

    printf("\n");
}

Fila InvertirFila(Fila F) {
    if (EsFilaVacia(F) || F.frente == F.final) {
        return F;  // Si la fila está vacía o solo tiene un elemento, no es necesario invertirla
    }

    Nodo* anterior = NULL;
    Nodo* actual = F.frente;
    Nodo* proximo = NULL;

    while (
        actual != NULL) {
        proximo = actual->sig;

        actual->sig = anterior;
        anterior = actual;
        actual = proximo;
    }

    F.final = F.frente;
    F.frente = anterior;

    return F;
}

Fila concat(Fila f1, Fila f2) {
    if (EsFilaVacia(f2)) {
        return f1;
    } else {
        int frent;
        frent = Frente(f2);
        return concat(EnFila(f1, frent), DeFila(f2));
    }
}

Fila DeFilaX(Fila F, item x) {
    // if (EsFilaVacia(F)) {
    //     return F;
    // }
    // Nodo* actual = F.frente;
    // Nodo* anterior = NULL;

    // while (actual != NULL) {
    //     if (actual->dato == x) {
    //         if (anterior == NULL) {
    //             F.frente = actual->sig;
    //         } else {
    //             anterior->sig = actual->sig;
    //         }

    //         if (actual == F.final) {
    //             F.final = anterior;
    //         }

    //         Nodo* temp = actual;
    //         actual = actual->sig;
    //         free(temp);
    //     } else {
    //         anterior = actual;
    //         actual = actual->sig;
    //     }
    // }
    if (EsFilaVacia(F) || F.frente == NULL) {
        return F;
    } else {
        if (F.frente->dato == x) {
            Nodo* aux;
            aux = F.frente;
            F.frente = F.frente->sig;
            if (F.frente == NULL) {
                F.final = NULL;
            }

            free(aux);
            F = DeFilaX(F, x);
            return F;

        } else {
            F.frente = F.frente->sig;
            F = DeFilaX(F, x);
            return F;
        }
    }
}