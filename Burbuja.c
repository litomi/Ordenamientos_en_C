#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

/**
 * @param *vector a imprimir
 * @param int tam, tamaño
 */
void Imprimir_Vector(int *arreglo, int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        printf("%d <- %d\n", i, *(arreglo + i));
    }
}

/**
 * Sólo si el rango de enteros es menor al tamaño del vector, se
 * cargaran todos números sin repetir. 
 * 
 * @param int* vector
 * @param int tam, tamaño del vector
 * @param int min_rango
 * @param int max_rango
 */
void Carga_Aleatoria(int *arreglo, int tam, int min_rango, int max_rango)
{
    srand(time(NULL)); //Semilla para la generación de aleatorios.

    for (size_t i = 0; i < tam; i++)
    {
        *(arreglo + i) = (rand() % max_rango) + min_rango;

        if ((max_rango - min_rango + 1) >= tam)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (*(arreglo + j) == *(arreglo + i))
                {
                    i--;
                    break;
                }
            }
        }
    }
}