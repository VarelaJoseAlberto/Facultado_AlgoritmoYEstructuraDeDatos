#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcionesPila.c"
// Definicion de las funciones
// Funcion para crear una pila vacia
// int esPilaVacia(Pila* pila);
// void pilaVacia(Pila* pila);
// void push(Pila* Pila, int elemento);
// int pop(Pila* pila);
// int top(Pila* pila);
// int fondo(Pila* pila);
// void popFondo(Pila* pila);
// void mostrarPila(Pila* pila);
// Pila* invertirLista(Pila* pila);

int main(int argc, char const* argv[]) {
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pilaVacia(pila);
    printf("Elementos de la pila: ");
    mostrarPila(pila);

    push(pila, 1);
    push(pila, 2);
    push(pila, 3);
    mostrarPila(pila);

    int fo = fondo(pila);
    printf("El elemento en el fondo de la pila es: %d\n", fo);

    popFondo(pila);
    printf("Elementos de la pila despues de eliminar el fondo:\n");
    mostrarPila(pila);

    printf("Lista invertida: ");
    invertirLista(pila);

    return 0;
}
