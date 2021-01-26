#include "Utilidades.h"
#define TAM_VECTOR 20
#define MAX 20
#define MIN 1

void Seleccion(int*, int);

int main(int argc, char const *argv[])
{
    int vector[TAM_VECTOR];
    Carga_Aleatoria(vector, TAM_VECTOR, MIN, MAX);
    printf("---------Lista desordenada----------\n");
    Imprimir_Vector(vector, TAM_VECTOR);
    printf("----------Lista ordenada------------\n");
    Seleccion(vector, TAM_VECTOR);
    Imprimir_Vector(vector, TAM_VECTOR);
    return 0;
}

void Seleccion(int * vector, int tam){

    for (size_t i = 0; i < tam; i++) //[5][2][1] Ej. Comentado primer ciclo.
    {
        for (size_t j = i + 1; j <= tam; j++) // i = 0 -> j = 1 -> v[j] = v[1] = 2
        {
            if(*(vector + i) > *(vector + j)){ //v[0] > v[1]
                //intercambio 
                int aux = *(vector + i);
                *(vector + i) = *(vector + j);
                *(vector + j) = aux;
            }
        }
        
    }
    
}