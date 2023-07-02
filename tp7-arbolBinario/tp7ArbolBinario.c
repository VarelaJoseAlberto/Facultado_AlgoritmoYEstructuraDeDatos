#include <stdio.h>
#include <stdlib.h>
#include "funcionesArbolBinario.c"
#include "funcionesPila.c"
#include "funcionesFila.c"

int main(void) {
    itemAB c;
    AB ArbolBinario, I, D, i, d, ArbolB;
    I = ABVACIO();
    D = ABVACIO();
    i = ABVACIO();
    d = ABVACIO();
    ArbolBinario = ABVACIO();
    ArbolB = ABVACIO();

    if (ESABVACIO(ArbolBinario)) {
        printf("El Arbol esta Vacio\n");
    } else {
        printf("El Arbol no esta Vacio\n");
    }

    I = ARMARAB(I, 'i', D);
    D = ARMARAB(I, 'd', D);
    ArbolBinario = ARMARAB(I, 'a', D);

    if (ESABVACIO(ArbolBinario)) {
        printf("El Arbol esta Vacio\n");
    } else {
        printf("El Arbol no esta Vacio\n");
    }

    c = RAIZ(ArbolBinario);
    printf("La raiz del arbol es: %c\n", c);

    printf("Arbol Impreso en Posfija\n");
    posOrden(ArbolBinario);

    printf("Arbol Impreso en Prefija\n");
    preOrden(ArbolBinario);

    printf("Arbol Impreso en Orden Simetrico\n");
    simetricoOrden(ArbolBinario);

    ArbolB = ARMARAB(i, 'R', d);

    if (EsABHoja(ArbolB)) {
        printf("El arbol es Arbol Hoja\n");
    } else {
        printf("El arbol no es Arbol Hoja\n");
    }
    if (PERTENECE(ArbolBinario, 'w')) {
        printf("El item si pertence al Arbol\n");
    } else {
        printf("El item ingreado no pertenece al arbol\n");
    }

    printf("\n --------------- PILA --------------- \n");
    Pila pila1, pila2;
    crearPila(&pila1);
    crearPila(&pila2);

    pila1 = push(pila1, 1);
    pila1 = push(pila1, 2);
    pila1 = push(pila1, 3);
    pila1 = push(pila1, 4);

    printf("Pila 1: ");
    mostrarPila(&pila1);

    printf("Altura de la Pila 1: %d\n", altura(pila1));

    printf("Top de la Pila 1: %d\n", top(pila1));

    printf("Fondo de la Pila 1: %d\n", fondo(pila1));

    pila1 = pop(pila1);

    printf("Pila 1 despues de hacer pop: ");
    mostrarPila(&pila1);

    printf("La Pila 1 esta vacia? %s\n", esPilaVacia(pila1) ? "Si" : "No");

    pila2 = push(pila2, 1);
    pila2 = push(pila2, 2);
    pila2 = push(pila2, 3);
    pila2 = push(pila2, 4);
    pila2 = push(pila2, 5);

    printf("Pila 2: ");
    mostrarPila(&pila2);

    printf("Pila 1 esta incluida en Pila 2? %s\n", incluida(pila1, pila2) ? "Si" : "No");

    printf("Pila 2 invertida: ");
    invertirLista(&pila2);

    printf("\n --------------- FILA --------------- \n");
    Fila fila = filaVacia();  // Crear una fila vacia para realizar las pruebas

    // Prueba de la función esFilaVacia
    printf("¿La fila esta vacia? %s\n", esFilaVacia(fila) ? "Si" : "No");

    // Prueba de la función enFila
    fila = enFila(fila, 1);
    fila = enFila(fila, 2);
    fila = enFila(fila, 3);

    // Prueba de la función frente y final
    printf("El frente de la fila es: %d\n", frente(fila));
    printf("El final de la fila es: %d\n", final(fila));

    // Prueba de la función deFila
    fila = deFila(fila);

    // Prueba de la función longitud
    printf("La longitud de la fila es: %d\n", longitud(fila));

    // Prueba de la función concat
    Fila fila2 = filaVacia();
    fila2 = enFila(fila2, 4);
    fila2 = enFila(fila2, 5);

    Fila filaConcat = concat(fila, fila2);
    printf("Fila concatenada: ");
    while (!esFilaVacia(filaConcat)) {
        printf("%d ", frente(filaConcat));
        filaConcat = deFila(filaConcat);
    }
    printf("\n");
    printf("\n fila 2---------------");
    Fila fila4 = filaVacia();
    printf("La fila esta vacia: %s\n", esFilaVacia(fila4) ? "Si" : "No");

    fila4 = enFila(fila4, 1);
    fila4 = enFila(fila4, 2);
    fila4 = enFila(fila4, 3);

    printf("La fila esta vacia: %s\n", esFilaVacia(fila4) ? "Si" : "No");
    printf("Longitud de la fila: %d\n", longitud(fila4));
    printf("Frente de la fila: %d\n", frente(fila4));
    printf("Final de la fila: %d\n", final(fila4));

    fila4 = deFila(fila4);

    printf("Longitud de la fila: %d\n", longitud(fila4));
    printf("Frente de la fila: %d\n", frente(fila4));
    printf("Final de la fila: %d\n", final(fila4));

    Fila fila3 = filaVacia();
    fila3 = enFila(fila3, 4);
    fila3 = enFila(fila3, 5);

    Fila filaConcatenada = concat(fila, fila3);

    printf("Longitud de la fila concatenada: %d\n", longitud(filaConcatenada));
    printf("Frente de la fila concatenada: %d\n", frente(filaConcatenada));
    printf("Final de la fila concatenada: %d\n", final(filaConcatenada));

    return 0;
}