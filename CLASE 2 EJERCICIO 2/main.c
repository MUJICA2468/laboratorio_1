#include <stdio.h>
#include <stdlib.h>
#define cantidad 5
int main()
{

    int numero;
    int contador;
    int acumulador;
    float promedio;
    //int contadorMax;
    //int contadorMin;
    int numeroMax;
    int numeroMin;
    int flag;

    contador = 0;

    flag = 0;//en vez de el contador se usa la bandera...Y ya esta

    //contadorMax = 0;
    //contadorMin = 0;

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



        //Mejor gg
        if(flag == 0){flag = 1;


           flag = 1;
           numeroMax = numero;
           numeroMin = numero;

        }
        else{
            if(numero > numeroMax){

                numeroMax = numero;
            }
            else{
               if(numero < numeroMin){

                numeroMin = numero;

                }
            }

        }


        //Demasiado codigo
        /*
        if(contadorMax == 0){

            contadorMax++;
            numeroMax = numero;


        }
        else{
            if(numero > numeroMax){

                numeroMax = numero;

            }
        }
        */

        /*
        if(contadorMin == 1){

            contadorMin++;
            numeroMin = numero;


        }
        else{
            if(numero < numeroMin){

                numeroMin = numero;

            }
        }
        */



    }

    promedio = (float)acumulador / contador;

    printf("El numero maximo es \n\ %d, \n\ El numero minimo es \n\2 %d, \n\ El promedio es \n\ %f", numeroMax, numeroMin, promedio );

    //printf("El promedio es \n %d", promedio);

    return 0;
}
