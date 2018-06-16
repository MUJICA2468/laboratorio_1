#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "informe.h"

#define CANT 3
int main()
{
    Funciones arrayFunciones[CANT];
    int opcion;
    int auxId = 0;
    funciones_init(arrayFunciones, CANT);
    do{
        getInt("\n1- alta \n2- baja \n3- listar \n4- modificar \n5- ordenar segun orden alfabetico\n9- SALIR \n", "\nINVALIDO \n", 2,0, 9, &opcion);
        switch(opcion){

            case 1:
            funciones_alta(arrayFunciones, CANT);
            break;
            case 2:
            funciones_baja(arrayFunciones, CANT, auxId);
            break;
            case 3:
            informe_listar(arrayFunciones, CANT);
            break;
            case 4:
            funciones_modificar(arrayFunciones, CANT, auxId);
            break;
            case 5:
            funciones_ordenar(arrayFunciones, CANT, 0);
            break;
        }
    }while(opcion!=9);
    return 0;
}
