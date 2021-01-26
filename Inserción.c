#include "Utilidades.h"

#define TAM_VECTOR 5

void Insercion(int *, int);

int main(int argc, char const *argv[])
{
    int vector[TAM_VECTOR];
    printf("----------Lista deordenada---------------\n");
    Carga_Aleatoria(vector, TAM_VECTOR, 1, 20);
    Imprimir_Vector(vector, TAM_VECTOR);

    printf("-----------Lista ordenada--------------\n");
    Insercion(vector, TAM_VECTOR);
    Imprimir_Vector(vector, TAM_VECTOR);

    

    return 0;
}

void Insercion(int *vector, int tam)
{
    int clave = 0, j, aux = 0;

    for (size_t i = 1; i < tam; i++) // [3][2][5] Ej. Comentado el primer ciclo.
    {
        clave = *(vector + i);  //Referencia  v[1] = 2

        j = i - 1; //Índice en el primero elemento del vector, j = 0  v[0] = 3

        while(j >= 0 && *(vector + j) > clave){ // j && v[0] > [1] =  0 && 3 > 2

            //Insertar el elemento en la posición contigua
            *(vector + j + 1) = *(vector + j); //v[j + 1] <- v[j] = v[1] <- v[0] = 2 <- 3 => [3][3][5]

            j--; //Decrementar el índice
        }
        *(vector + j + 1) = clave;  //   v[j+1] <- v[1]  = v[1] <- v[1] = 3 <- 2 => [2][3][5]
    }
    
}
