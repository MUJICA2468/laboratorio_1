#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"
//10.contratacion mas costosa
//archivo = cuit
//paso un cuit y me devuelve la cantidad de contrataciones
//for con llamada a dos funciones
//funcion que devuelve el importe de la contratacion
//7. precio por dias
int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("\n\nCuit: %s - Unitario: %.2f - Total: %.2f - Dias: %d\n",
                                    arrayC[i].cuit,
                                    pantallas[indexPantalla].precio,
                                    (arrayC[i].dias * pantallas[indexPantalla].precio),
                                    arrayC[i].dias );
            }
        }

        retorno = 0;
    }
    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(arrayC[i].isEmpty == 0)
                {
                    indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    //printf();
                    printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",arrayC[i].cuit,pantallas[indexPantalla].nombre,arrayC[i].archivo,arrayC[i].dias );
                }
        }

        retorno = 0;
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    char ultimoCuit[50];

    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }


                    //indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    /*printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );*/

                }


        }

        retorno = 0;
    }
    return retorno;
}

int informar_ListarPantallas(Pantalla* pantallas, int cantP)
{
    int retorno = -1;
    int i;
    if(cantP > 0 && pantallas != NULL)
    {
        for(i=0; i<cantP;i++)
        {
            if(!pantallas[i].isEmpty)
            {
                //indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("\nNombre: %s \nPrecio: %f",pantallas[i].nombre,pantallas[i].precio);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_ListarPantallasValorMenorPrecio(Pantalla* pantallas, int cantP)
{
    int retorno = -1;
    int i;
    if(cantP > 0 && pantallas != NULL)
    {
        for(i=0; i<cantP;i++)
        {
            if(!pantallas[i].isEmpty)
            {
                if(pantallas[i].precio < 1000)
                {
                    //indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    printf("\nNombre: %s \nPrecio: %f",pantallas[i].nombre,pantallas[i].precio);
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_ListarPantallasMayorPublicacion(Pantalla* pantallas, int cantP,Contratacion* contratacion)
{
    int retorno = -1;
    int i;
    if(cantP > 0 && pantallas != NULL)
    {
        for(i=0; i<cantP;i++)
        {
            if(!pantallas[i].isEmpty)
            {
                if(contratacion[i].dias > 1)
                {

                    printf("\nNombre: %s",pantallas[i].nombre);
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

/*
int informe_contratacionesCuitDias(Contratacion* contratacion, int cantC, char cuit[])
{
    int retorno = 1;
    int i;
    if(cantC > 0  && contratacion != NULL)
    {
        for(i=0;i<cantC;i++)
        {
            if(strcmp(contratacion[i].cuit, cuit)==0)
            {
                printf("\nCUIT: %s \ncontrataciones: %s \n", contratacion[i].cuit, cuit);
            }
        }
    }
    return retorno;
}
*/

int informar_BuscarPorCuit(Contratacion* contrataciones, int cantC, char cuit[])
{
    int retorno = -1;
    int i;
    if(cantC > 0 && contrataciones != NULL)
    {
        for(i=0;i<cantC;i++)
        {
            if(contrataciones[i].isEmpty == 0 && contrataciones[i].cuit == cuit)
            {
                retorno = i;
            }
        }
    }
    return retorno;
}
/*
int informe_pantallasContratacionCostosa(Pantalla* pantallas, int cantP, Contratacion* contrataciones, int cantC)
{
    contrataciones cuit[cantC];
    int retorno = -1;
    int i;

    if((cantP > 0 && pantallas != NULL) || (cantC > 0 && contrataciones != NULL))
    {
        i = informar_BuscarPorCuit(contrataciones, cantC, cuit);
        if(contrataciones[i].isEmpty == 0 && pantallas[i].isEmpty == 0)
        {
            if(contrataciones[i])
            {

            }
        }
    }
    return retorno;
}
*/
/*
int informe_pantallasContratacionCostosa(Pantalla* pantallas, int cantP, Contratacion* contrataciones, int cantC)
{
    int retonro = -1;
    int contadorMin = 0;
    int contadorMax = 0;
    int i;
    int j;
    if((cantP > 0 && pantallas != NULL) || (cantC > 0 && contrataciones != NULL))
    {
            if(contrataciones[i].isEmpty == 0 && pantallas[i].isEmpty == 0)
            {
                for(i=0;i<cantC;i++){
                    for(j=0;j<cantP;i++){
                        while(contadorMin)
                        {
                            contadorMin++;
                            if(contadorMin == 0)
                            {
                                contrataciones[contadorMin].dias;
                            }else if(){

                            }
                        }
                    }
                }
            }
    }
    return retonro;
}
*/
