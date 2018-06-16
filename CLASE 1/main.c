#include <stdio.h>
#include <stdlib.h>










int main(void)
{

    int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroMayor;


    printf("Ingrese primer numero \n");
    scanf("%d", &numeroUno);
    printf("Ingrese segundo  numero \n");
    scanf("%d", &numeroDos);
    printf("Ingrese tercer numero \n");
    scanf("%d",&numeroTres);

    //printf("%d %d %d \n ",numeroDos,numeroDos,numeroTres);



    if(numeroUno > numeroDos && numeroUno > numeroTres){

        numeroMayor = numeroUno;


    }
    else{
        if(numeroDos > numeroTres){


            numeroMayor = numeroDos;

        }
        else{

            numeroMayor = numeroTres;

        }
    }


    printf("El numero mayor es \n\%d", numeroMayor);



    return 0;



}

