#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"



Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

Cliente* cliente_new2(int edad, char* nombre, int id)
{
    Cliente* retorno =  cliente_new();
    cliente_setEdad(retorno, edad);
    cliente_setNombre(retorno, nombre);
    //cliente_setId(retorno);
    return retorno;
}

void cliente_delete(Cliente* this)
{
    return free(this);
}

int cliente_getNombre(Cliente* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && (nombre))
    {
        strcpy(nombre, this->nombre);

        retorno = 0;
    }
    return retorno;
}

int cliente_setNombre(Cliente* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && (nombre))
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int cliente_setEdad(Cliente* this,int edad)
{
    int retorno = -1;
    if(this != NULL && (edad))
    {
        this->edad = edad;
        retorno = 0;

    }
    return retorno;
}

int cliente_getEdad(Cliente* this,int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        retorno = 0;
    }
    return retorno;
}

static int cliente_setId(Cliente* this)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        ultimoId++;
        this->idCliente = ultimoId;
        retorno = 0;
    }
    return retorno;
}

static int cliente_getId(Cliente* this)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        ultimoId++;
        ultimoId = this-> idCliente;
        retorno = 0;
    }
    return retorno;
}

int cliente_alta(int* cantidad, Cliente* listado[])
{
    listado[*cantidad]= cliente_new2(18, "Fabian", 0);
    *cantidad=*cantidad+1;
}

int cliente_listar(int* cantidad, Cliente* listado[])
{
    int retorno = -1;
    int i;
    char nombre[50];
    for(i=0;i<cantidad;i++)
    {
        //*(listado+i)
        //*(listdo)+i
        //*(listado+i)
        //(*listado+i)
        //*listado+i
        //listado+i
            cliente_getNombre(*(listado+i), nombre);
            /*
            printf("\n Id de cliente: %d ", (*(listado+i))-> idCliente);
            printf("\t edad: %d ",  (*(listado+i))-> edad);
            */
            printf("\n nombre: %s ", (*(listado+i))-> nombre);
           // return 0;
    }
    return retorno;
}
/*
int cliente_alta(Cliente* this, int cantC, char nombre[])
{
    int retorno;
    if(this != NULL)
    {
        retorno = cliente_new2();
        //cliente_getNombre(this, "Fabian", cantC);
        cliente_setNombre(this, "Fabian", cantC);

        nombre[50] = this -> nombre[50];
        this -> idCliente = cliente_setId(this);
        printf("\n Nombre: %s ", nombre);
    }
    return retorno;
}
*/
