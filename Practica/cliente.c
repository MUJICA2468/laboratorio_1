#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"


Cliente* cliente_newCliente()
{
    Cliente* retorno = NULL;
    retorno = (Cliente*) malloc(sizeof(Cliente));
    return retorno;
    //return Cliente* retorno = (*Cliente) malloc(sizeof(Cliente));
}

Cliente* cliente_newParametros(char* nombre, char* apellido, char* mail, char* genero, char* profesion, char* nacionalidad, char* usuario, int id)
{
    Cliente* auxCliente;
    auxCliente= cliente_newCliente();
    int retorno = -1;
    if(nombre!=NULL && apellido!=NULL && mail!=NULL && genero!=NULL && profesion!=NULL && nacionalidad!=NULL)
    {
        cliente_setNombre(auxCliente, nombre);
        cliente_setApellido(auxCliente, apellido);
        cliente_setEmail(auxCliente, mail);
        cliente_setGenero(auxCliente, genero);
        cliente_setProfesion(auxCliente, profesion);
        cliente_setNacionalidad(auxCliente, nacionalidad);
        cliente_setUsuario(auxCliente, usuario);
    }
    return retorno;
}

void cliente_deleteCliente(Cliente* this)
{
    free(this);
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre!=NULL)
    {
        retorno = 0;
        strcpy(this->nombre, nombre);
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre!=NULL)
    {
        retorno = 0;
        strcpy(nombre, this->nombre);
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this!=NULL && apellido!=NULL)
    {
        retorno = 0;
        strcpy(this->apellido, apellido);
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this!=NULL && apellido!=NULL)
    {
        retorno = 0;
        strcpy(apellido, this->apellido);
    }
    return retorno;
}

int cliente_setEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this!=NULL && email!=NULL)
    {
        retorno = 0;
        strcpy(this->email, email);
    }
    return retorno;
}

int cliente_getEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this!=NULL && email!=NULL)
    {
        retorno = 0;
        strcpy(email, this->email);
    }
    return retorno;
}

int cliente_setGenero(Cliente* this, char* genero)
{
    int retorno = -1;
    if(this!=NULL && genero!=NULL)
    {
        retorno = 0;
        strcpy(this->genero, genero);
    }
    return retorno;
}

int cliente_getGenero(Cliente* this, char* genero)
{
    int retorno = -1;
    if(this!=NULL && genero!=NULL)
    {
        retorno = 0;
        strcpy(genero, this->genero);
    }
    return retorno;
}

int cliente_setProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this!=NULL && profesion!=NULL)
    {
        retorno = 0;
        strcpy(this->profesion, profesion);
    }
    return retorno;
}

int cliente_getProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this!=NULL && profesion!=NULL)
    {
        retorno = 0;
        strcpy(profesion,this->profesion);
    }
    return retorno;
}

int cliente_setUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this!=NULL && usuario!=NULL)
    {
        retorno = 0;
        strcpy(this->usuario, usuario);
    }
    return retorno;
}

int cliente_getUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this!=NULL && usuario!=NULL)
    {
        retorno = 0;
        strcpy(usuario,this->usuario);
    }
    return retorno;
}

int cliente_setNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this!=NULL && nacionalidad!=NULL)
    {
        retorno = 0;
        strcpy(this->nacionalidad, nacionalidad);
    }
    return retorno;
}

int cliente_getNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this!=NULL && nacionalidad!=NULL)
    {
        retorno = 0;
        strcpy(nacionalidad,this->nacionalidad);
    }
    return retorno;
}

int cliente_setId(Cliente* this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this!=NULL)
    {
        retorno = 0;
        id = this -> id;
    }
    return retorno;
}

int cliente_getId(Cliente* this, int* id)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        this -> id = *id;
    }
    return retorno;
}

int cliente_ordenarNombreApellido(Cliente* clienteA, Cliente* clienteB)
{
    char nombreA[64];
    char nombreB[64];
    char apellidoA[64];
    char apellidoB[64];
    cliente_getNombre(clienteA, nombreA);
    cliente_getNombre(clienteB, nombreB);
    if(!strcmp(nombreA, nombreB))
    {
        cliente_getApellido(clienteA, nombreA);
        cliente_getApellido(clienteB, nombreB);
        return strcmp(apellidoA, apellidoB);
    }
    return strcmp(nombreA, nombreB);
}
