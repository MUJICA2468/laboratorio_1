#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

#define OCUPADO 0
int informe_listar(Funciones* arrayFunciones, int cant)
{
    int retorno = -1;
    int i;
    for(i=0;i<cant;i++)
    {
        if(arrayFunciones[i].isEmpty == OCUPADO)
        {
            printf("\nNombre : %s \nApellido : %s \nID : %d \n", arrayFunciones[i].nombre, arrayFunciones[i].apellido, arrayFunciones[i].id);
            retorno = 0;
        }
    }
    return retorno;
}

