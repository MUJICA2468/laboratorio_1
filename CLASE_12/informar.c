#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limiteC,Pantalla* arrayP, int limiteP, char* cuit)
{
    int retorno = -1;
    int i;
    int indicePantalla;
    if(limiteC > 0 && arrayC != NULL && limiteP > 0 && arrayP != NULL)
    {
        for(i=0;i<limiteC;i++)
        {
            if(arrayC[i].isEmpty == 0 && !strcmp(arrayC[i].cuit, cuit))// Si son iguales devuelve 0 entonces lo niego
            {
                indicePantalla = pantalla_buscarPorId(arrayP, limiteP, arrayC[i].idPantalla);
                //printf("\nCUIT: %s \nID : %d \n Dias %d \nPrecio %2.f \n", arrayC[i].cuit, arrayC[i].id, arrayC[i].dias, arrayP[indicePantalla].precio);
                printf("\nCUIT: %s \nID : %d \nValor %2.f \n", arrayC[i].cuit, arrayC[i].id, arrayC[i].dias*arrayP[indicePantalla].precio);
            }
        }

    }

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limiteC,Pantalla* arrayP, int limiteP)
{
    int retorno = -1;
    int i;
    if(limiteC > 0 && arrayC != NULL && arrayP != NULL)
    {
        for(i=0;i<limiteC;i++)
        {
            if(arrayC[i].isEmpty == 0 && arrayP[i].isEmpty == 0)
            {
                    printf("\nNombre pantalla: %s \nNombre de video: %s \nDIAS: %d \nCUIT: %s \nID contrataciones: %d\n",arrayP[i].nombre, arrayC[i].archivo,arrayC[i].dias,arrayC[i].cuit,arrayC[i].id);
            }
        }

    }
    return retorno;
}

/*
int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limiteC,Pantalla* arrayP, int limiteP)
{
    int retorno = -1;
    int i;
    //int indicePantalla;
    int acumulador = 0;
    int contador = 0;
    char ultimoCuit[50]= "_";// Cuit invalido
    if(limiteC > 0 && arrayC != NULL && arrayP != NULL)
    {
        for(i=0;i<limiteC;i++)
        {
            cont_ordenarCuit(arrayC, limiteC, 0);
            if(arrayC[i].isEmpty == 0 && !strcmp(arrayC[i].cuit, ultimoCuit) != 0)// Si son iguales devuelve 0 entonces lo niego
            {
                strcpy(ultimoCuit, arrayC[i].cuit);

                printf("\n - %s - ", ultimoCuit);
                informar_ConsultaFacturacion(arrayC, limiteC, arrayP, limiteP, ultimoCuit);

            contador++;
            acumulador += arrayC[i].dias*arrayP[indicePantalla].precio;
            }
        }

    }

    return retorno;
}
*/
