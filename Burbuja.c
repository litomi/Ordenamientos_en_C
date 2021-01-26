#include "Utilidades.h"
#define TAM_ARREGLO 20
#define MAX 200
#define MIN 1

void Burbuja(int *, int);
void Imprimir_Vector(int *, int);
void Carga_Aleatoria(int *, int, int, int);

int main(int argc, char const *argv[])
{

    int vector[TAM_ARREGLO];

    Carga_Aleatoria(vector, TAM_ARREGLO, MIN, MAX);

    printf("\n-------Lista desordenada----------\n");
    Imprimir_Vector(vector, TAM_ARREGLO);

    printf("\n--------Lista ordenada----------\n");
    Burbuja(vector, TAM_ARREGLO);
    Imprimir_Vector(vector, TAM_ARREGLO);

    return 0;
}

/**
 * Ordenamiento Burbuja
 * @param int* vector
 * @param tam, tamaño del vector
 */
void Burbuja(int *arreglo, int tam)
{
    int aux = 0;
    for (size_t i = 1; i < tam; i++)
    {
        for (size_t j = 0; j < tam - i; j++) 
        {
            if (*(arreglo + j) > *(arreglo + j + 1))
            {
                aux = *(arreglo + j);
                *(arreglo + j) = *(arreglo + j + 1);
                *(arreglo + j + 1) = aux;
            }
        }
    }
}