#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "utn.h"
static int cliente_setId(Cliente* this, int id);

Cliente* cliente_newArrayCliente()
{
    Cliente* this;
    this = (Cliente*) malloc(sizeof(Cliente));
    return this;
}

void cliente_delete(Cliente* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

Cliente* cliente_newClienteUp(char* id, char* nombre,char* horas)
{
    int bId;
    int bHoras;
    Cliente* this = cliente_newArrayCliente();
    if(this!=NULL && horas>0 && nombre!=NULL && id>0)
    {
        bId = atoi(id);
        bHoras = atoi(horas);
        //-----------------
        cliente_setId(this,bId);
        cliente_setNombre(this,nombre);
        cliente_setHoras(this,bHoras);
    }
    return this;
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int auxReturn;
    if(this!=NULL && nombre!=NULL)
    {
        auxReturn = 0;
        strcpy(this->nombre,nombre);
    }
    return auxReturn;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int auxReturn =-1;
    if(this!=NULL && nombre!=NULL)
    {
        auxReturn = 0;
        strcpy(nombre,this->nombre);
    }
    return auxReturn;
}

int cliente_setSueldo(Cliente* this, int sueldo)
{
    int auxReturn;
    if(this!=NULL && sueldo>=0)
    {
        auxReturn = 0;
        this->sueldo = sueldo;
    }
    return auxReturn;
}

int cliente_getSueldo(Cliente* this, int* sueldo)
{
    int auxReturn;
    if(this!=NULL && sueldo!=NULL)
    {
        auxReturn = 0;
        *sueldo = this->sueldo;
    }
    return auxReturn;
}

int cliente_setHoras(Cliente* this, int horas)
{
    int auxReturn;
    if(this!=NULL && horas >= 0)
    {
        auxReturn = 0;
        this->horasTrabajadas = horas;
    }
    return auxReturn;
}

int cliente_getHoras(Cliente* this, int* horas)
{
    int auxReturn;
    if(this!=NULL && horas!=NULL)
    {
         auxReturn = 0;
        *horas = this->horasTrabajadas;
    }
    return auxReturn;
}

int cliente_setId(Cliente* this, int id)
{
    static int ultimoId = -1;
    int auxReturn = -1;;
    if(this!=NULL)
    {
        auxReturn = 0;
        if(id > 0)
        {
            this->id = id;
            if(id > ultimoId)
                ultimoId = id;
        }
        else
        {
            ultimoId++;
            this->id =  ultimoId;
        }
    }
    return auxReturn;
}

int cliente_getId(Cliente* this, int* id)
{

    int auxReturn;
    if(this!=NULL && id!=NULL)
    {
        auxReturn = 0;
        *id = this->id;
    }
    return auxReturn;
}

int cliente_calcularSueldo(void* this)
{
    int auxReturn = -1;
    int hora;
    int sueldo=0;
    if(this!=NULL)
    {
        auxReturn = 0;
        cliente_getHoras(this,&hora);
        if(hora < 120)
        {
            sueldo = hora*180;
        }
        else if(hora < 160)
        {
            sueldo = hora*240;
        }
        else
        {
            sueldo = hora*350;
        }
        cliente_setSueldo(this,sueldo);
    }
    return auxReturn;
}
