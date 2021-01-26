#include "Utilidades.h"
#define TAM_ARREGLO 100
#define MIN 1
#define MAX 20

int particion(int *, int, int);
void Rapido(int *, int, int);

int main(int argc, char const *argv[])
{
    int vector[TAM_ARREGLO];

    printf("Longitud: %d\n", sizeof(vector)/sizeof(int));
    Carga_Aleatoria(vector, TAM_ARREGLO, MIN, MAX);
    printf("------Lista desordenada------\n");
    Imprimir_Vector(vector, TAM_ARREGLO);
    Rapido(vector, 0, TAM_ARREGLO - 1);
    printf("------Lista ordenada------\n");
    Imprimir_Vector(vector, TAM_ARREGLO);   

    return 0;
}

void Rapido(int *vector, int izquierda, int derecha)
{
    if (izquierda < derecha)
    {
        int indice = particion(vector, izquierda, derecha);
        Rapido(vector, izquierda, indice);
        Rapido(vector, indice + 1, derecha);
    }
}

int particion(int *vector, int izquierda, int derecha)
{
    //Selección del pivote, primer elemento
    int pivote = *(vector + izquierda);

    while (1)
    {
        //Mientras cada elemento sea menor que el pivote,
        //avanza el índice.
        while (*(vector + izquierda) < pivote)
        {
            izquierda++;
        }

        // Mientras que cada elemento sea mayor que el pivote,
        // retrocede el índice -se mueve de derecha a izquierda-
        while (*(vector + derecha) > pivote)
        {
            derecha--;
        }

        /**
         * Si el extremo izquierdo es mayor o igual que el derecho,
         * no se necesita intercambiar variables. Ya están ordenados.
         */
        if (izquierda >= derecha)
        {
            //Se devuelve la posición en la que se queda.
            return derecha;
        }
        else
        {
            //Si las variables, extremos, no se superan entonces se detuvieron.
            //Hay un valor que no está ordenado, se intercambia.
            int aux = *(vector + izquierda);
            *(vector + izquierda) = *(vector + derecha);
            *(vector + derecha) = aux;

            izquierda++;
            derecha--;
        }
    }
}