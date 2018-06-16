#include <stdio.h>
#include <stdlib.h>
#define  cantidad 3

int main(void)
{
    int numero;
    int contador;
    int acumulador;
    float promedio;

    contador = 0;

    acumulador = 0;

    while(contador < cantidad){

        //printf("Ingrese numero \n"); // para no coloca dos primntf en otra linea mejor un do while
        //scanf("%d", &numero);

        contador++;

        do
        {

            printf("Ingrese numero VALIDO \n");
            scanf("%d", &numero);


        }while(numero <= 0);


        acumulador += numero;


    }


    promedio = (float)acumulador / contador;


    printf("El promedio es \n %f", promedio);



    return 0;
}
