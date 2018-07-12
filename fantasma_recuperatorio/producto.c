#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "producto.h"
Producto* producto_new()
{
    Producto* this = NULL;
    this = (Producto*) malloc(sizeof(Producto));
    return this;
}

void producto_delete(Producto* this)
{
    free(this);
}

Producto* producto_newParametros(char* string,int numeros,int idProducto)
{
    Producto* auxParametros = producto_new();
    if(string!=NULL)
    {
        producto_setString(auxParametros,string);
        producto_setInt(auxParametros,numeros);
        producto_setId(auxParametros,idProducto);
    }
    return auxParametros;
}

int producto_getParametros(Producto* this,char* string,int* numeros,int* idProducto)
{
    int auxReturn = -1;
    if(this!=NULL && string!=NULL)
    {
        auxReturn = 0;
        producto_getString(this,string);
        producto_getInt(this,numeros);
        producto_getId(this,idProducto);
    }
    return auxReturn;
}

int producto_setString(Producto* this,char* string)
{
    int auxReturn = -1;
    if(this!=NULL && string!=NULL)
    {
        auxReturn = 0;
        strcpy(this->string,string);
    }
    return auxReturn;
}

int producto_getString(Producto* this,char* string)
{
    int auxReturn = -1;
    if(this!=NULL && string!=NULL)
    {
        auxReturn = 0;
        strcpy(string,this->string);
    }
    return auxReturn;
}

int producto_setInt(Producto* this,int numero)
{
    int auxReturn = -1;
    if(this!=NULL && numero>0)
    {
        auxReturn = 0;
        this->numero = numero;
    }
    return auxReturn;
}

int producto_getInt(Producto* this,int* numero)
{
    int auxReturn = -1;
    if(this!=NULL && numero>0)
    {
        auxReturn = 0;
        *numero = this->numero;
    }
    return auxReturn;
}

int producto_setId(Producto* this,int id)
{
    static int lastId = -1;
    int auxReturn = -1;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->idProducto = id;
            if(id > lastId)
            lastId = id;

        }else
        {
            lastId++;
            this->idProducto = lastId;
        }
    }
    return auxReturn;
}

int producto_getId(Producto* this,int* id)
{
    int auxReturn = -1;
    if(this!=NULL && id>0)
    {
        auxReturn = 0;
        *id = this->idProducto;
    }
    return auxReturn;
}
