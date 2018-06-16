#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente* cliente_new()
{
    Cliente* this;
    this=malloc(sizeof(Cliente));
    return this;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int cliente_setCantidad(Cliente* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int cliente_getCantidad(Cliente* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int cliente_setNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int cliente_setDescripcion(Cliente* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int cliente_getDescripcion(Cliente* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int cliente_setPrecio(Cliente* this,float precio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

int cliente_getPrecio(Cliente* this,float* precio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precio=this->precio;
        retorno=0;
    }
    return retorno;
}

int cliente_setCategoria(Cliente* this,char categoria)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->categoria=categoria;
        retorno=0;
    }
    return retorno;
}

int cliente_getCategoria(Cliente* this,char* categoria)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *categoria=this->categoria;
        retorno=0;
    }
    return retorno;
}

int cliente_setId(Cliente* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int cliente_getId(Cliente* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int cliente_setPrueba(Cliente* this,int prueba)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->prueba=prueba;
        retorno=0;
    }
    return retorno;
}

int cliente_getPrueba(Cliente* this,int* prueba)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *prueba=this->prueba;
        retorno=0;
    }
    return retorno;
}

int cliente_setEmail(Cliente* this, char* email)
{
    int auxRetorno = -1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(this->email,email);
        auxRetorno = 0;
    }
    return auxRetorno;
}

int cliente_getEmail(Cliente* this, char* email)
{
    int auxRetorno = -1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(email,this->email);
        auxRetorno = 0;
    }
    return auxRetorno;
}
