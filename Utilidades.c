#include "Utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @param *vector a imprimir
 * @param int tam, tamaño
 */
void Imprimir_Vector(int *arreglo, int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        printf("[%d] => %d\n", i, *(arreglo + i));
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