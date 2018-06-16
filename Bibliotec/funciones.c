#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "informe.h"

#define LIBRE 1
#define OCUPADO 0

/** \brief Se pueden ingresar numeros enteros
 *
 * \param mensaje char* Es el mensaje que se muestra para pedir el ingreso de datos
 * \param mensajeError char* Es el mensaje que se muestra si los datos son invalidos
 * \param reIntentos int Cantidad de intentos de ingreso
 * \param minimo int cantidad de numeros minima
 * \param maximo int cantidad de numeros maxima
 * \param resultado int* la variavle que se pretende validar para la carga de datos
 * \return int retorno de los ingresado
 *
 */
int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 0)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}
/** \brief valida numeros enteros
 *
 * \param str char*
 * \return int Retorna un valor que valida el if
 *
 */
int esEntero(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] > '9' || str[i] < '0')
           return -1;
       i++;
   }
   return 0;

}
/** \brief Valida el ingreso de strings
 *
 * \param mensaje[] char se introduce un mensaje
 * \param imput[] char se introduce el dato
 * \return int retorna un valor que valida
 *
 */
int getString(char mensaje[], char imput[])
{
    printf("%s", mensaje);
    scanf("%s", imput);
    return 0;
}
/** \brief Valida la letras mayusculas y las minusculas
 *
 * \param str[] char
 * \return int retorna un valor que valida
 *
 */
int esLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 1;
        i++;
    }
    return 0;
}
/** \brief Se puede introducir cadenas de caracteres
 *
 * \param mensaje[] char mensaje para indicar  que colocar
 * \param cant int limite del array
 * \param imput[] char se coloca la array para guardar los datos cargador
 * \re/** \brief Se pueden ingresar numeros enteros
 *
 * \param mensaje char* Es el mensaje que se muestra para pedir el ingreso de datos
 * \param mensajeError char* Es el mensaje que se muestra si los datos son invalidos
 * \param reIntentos int Cantidad de intentos de ingreso
 * \param minimo int cantidad de numeros minima
 * \param maximo int cantidad de numeros maxima
 * \param resultado int* la variavle que se pretende validar para la carga de datos
 * \return int retorno de los ingresado
 *
 */
int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 0)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}
/** \brief valida numeros enteros
 *
 * \param str char*
 * \return int Retorna un valor que valida el if
 *
 */
int esEntero(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return -1;
       i++;
   }
   return 0;

}
/** \brief Valida el ingreso de strings
 *
 * \param mensaje[] char se introduce un mensaje
 * \param imput[] char se introduce el dato
 * \return int retorna un valor que valida
 *
 */
int getString(char mensaje[], char imput[])
{
    printf("%s", mensaje);
    scanf("%s", imput);
    return 0;
}
/** \brief Valida la letras mayusculas y las minusculas
 *
 * \param str[] char
 * \return int retorna un valor que valida
 *
 */
int esLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {turn int
 *
 */
int getStringLetras(char mensaje[], int cant,char imput[])
{
    int retorno = -1;
    char aux[50];
    getString(mensaje, aux);
    //do{
        if(esLetras(aux)==0)
        {
            strcpy(imput, aux);
            //return 0;
        }
        //printf("%s", mensajeError);
    //}while(retorno!=-1);
    return retorno;
}
/** \brief Realiza la apertura de espacios dentro del array
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int funciones_init(Funciones* arrayFunciones, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            arrayFunciones[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}
/** \brief Se obtiene el espacio libre dentro del array
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int funciones_buscarLibre(Funciones* arrayFunciones, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayFunciones[i].isEmpty == LIBRE)
            {
                 retorno = i;
            }
        }
    }
    return retorno;
}
/** \brief Asigna un ID a cada conbinacion de datos cargados
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant  limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int funciones_proximoId(Funciones* arrayFunciones, int cant)
{
    int retorno = 0;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayFunciones[i].isEmpty == OCUPADO)
            {
                if(arrayFunciones[i].id>retorno)
                {
                    retorno = arrayFunciones[i].id;
                }
            }
        }
    }
    return retorno+1;// Id a partir del 1. mayor a 0 'retorno+1 ... también si se quiere retorno+2'
}
/** \brief Busca el la array en busca de un espacio ocupado por el dni
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant int limite del array
 * \param dni int Identificador de la persona
 * \return int retorna el dni a buscar
 *
 */
int funciones_buscarPorId(Funciones* arrayFunciones, int cant, int id)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayFunciones[i].isEmpty == OCUPADO && arrayFunciones[i].id == id)
            {
                retorno = i;
            }
        }
    }
    return retorno;
}
/** \brief Carga los datos de una persona
 *
 * \param arrayFunciones Funciones* llama a la estructura
 * \param cant int limite del array
 * \return int retorna un valor negativo
 *
 */
int funciones_alta(Funciones* arrayFunciones, int cant)
{
    int retorno = -1;
    int i;
    int id;
    if(cant > 0 && arrayFunciones != NULL)
    {
        i = funciones_buscarLibre(arrayFunciones, cant);
        if(i > 0 && i <= cant)
        {
            id = funciones_proximoId(arrayFunciones, cant);
            if(arrayFunciones[i].isEmpty == LIBRE)
            {
                getStringLetras("\nIngrese A : \n",50,arrayFunciones[i].nombre);
                getStringLetras("\nIngrese B : \n",50,arrayFunciones[i].apellido);
                arrayFunciones[i].isEmpty = 0;
                arrayFunciones[i].id = id;
                return 0;
            }
        }else{
            printf("\nSIN ESPACIO \n");
        }
    }
    return retorno;
}
/** \brief Da de baja el dni de una persona, por lo tanto lo borra
 *
 * \param variable para cargar la llamada a la funcion de busqueda del dni
 * \param
 * \return retorno 0
 *
 */
int funciones_baja(Funciones* arrayFunciones, int cant, int id)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        printf("\nID a dar de baja \n");
        scanf("%d", &id);
            i = funciones_buscarPorId(arrayFunciones, cant, id);
            if(i>=0)
            {
                arrayFunciones[i].isEmpty = LIBRE;
                retorno = 0;
            }else{
            printf("\nID INEXISTENTE \n");
            }
    }
    return retorno;
}

int funciones_modificar(Funciones* arrayFunciones, int cant, int id)
{
    int retorno = -1;
    int opcion;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        printf("ID?\n");
        scanf("%d", &id);
        do{
            i = funciones_buscarPorId(arrayFunciones, cant, id);
            if(i >= 0)
            {
                printf("\nQue desea modificar?\n");
                getInt("\n1- Modificar nombre \n2- Modificar apellido \n8- salir \n", "\nInvalido \n", 2, 0, 3, &opcion);
                switch(opcion)
                {
                    case 1:
                        getStringLetras("\nIngrese nuevo nombre \n", 3, arrayFunciones[i].nombre);
                    break;
                    case 2:
                        getStringLetras("\nIngrese nuevo nombre \n", 50, arrayFunciones[i].apellido);
                    break;
                }
            }
        }while(opcion!=3);
    }
    return retorno;
}
/** \brief Ordena alfabeticamente los nombres
 *
 * \param arrayFunciones Funciones* llama a la estructura
 * \param cant int limite del array
 * \param orden int ordena
 * \return int retorna un valor negativo
 *
 */
int funciones_ordenar(Funciones* arrayFunciones, int cant, int orden)
{
    Funciones aux;
    int retorno = -1;
    int i;
    int flagSwap = 0;
    if(cant > 0 && arrayFunciones != NULL)
    {
        do{
            flagSwap = 0;
            for(i=0;i<cant-1;i++)
            {
                if(arrayFunciones[i].isEmpty == OCUPADO && arrayFunciones[i+1].isEmpty == OCUPADO)
                {
                    if((strcmp(arrayFunciones[i].nombre, arrayFunciones[i+1].nombre)>0  && !orden) ||(strcmp(arrayFunciones[i].nombre, arrayFunciones[i+1].nombre)<0  && orden))
                    {
                        aux = arrayFunciones[i];
                        arrayFunciones[i] = arrayFunciones[i+1];
                        arrayFunciones[i+1] = aux;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
