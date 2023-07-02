#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "funcionesFila.c"

int main(void) {
    Fila F;
    Fila d;
    item x;

    F = FilaVacia();
    if (EsFilaVacia(F)) {
        printf("La fila esta Vacia\n");
    } else {
        printf("La fila no se encuentra vacia\n");
    }

    printf("Funcion Enfilar:\n");

    F = EnFila(F, 1);
    F = EnFila(F, 2);
    F = EnFila(F, 3);

    if (EsFilaVacia(F)) {
        printf("La fila esta Vacia\n");
    } else {
        printf("La fila no se encuentra vacia\n");
    }

    x = Frente(F);
    printf("Frente de la fila: %d\n", x);

    x = Final(F);
    printf("Final de la fila: %d\n", x);

    F = EnFilaN(F, 5, 2);
    printf("Enfilados exitosos\n");

    x = Final(F);
    printf("Final de la fila: %d\n", x);

    // mostrar todos los elementos de la fila
    MostrarFila(F);
    d = DeFilaX(F, 1);
    MostrarFila(d);
    /*
        Fila filaInvertida = InvertirFila(F);
        MostrarFila(filaInvertida);

        Fila f1, f2, de;
        f1 = FilaVacia();
        f2 = FilaVacia();

        f1 = EnFila(f1, 'a');
        f1 = EnFila(f1, 'b');
        f1 = EnFila(f1, 'c');
        printf("f1 ");
        MostrarFila(f1);
        f2 = EnFila(f2, 1);
        f2 = EnFila(f2, 2);
        f2 = EnFila(f2, 3);
        printf("f2 ");
        MostrarFila(f2);
    */
    return 0;
}
