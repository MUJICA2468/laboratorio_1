#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
static int empleado_setId(Empleado* this, int id);

Empleado* empleado_newArrayEmpleado()
{
    Empleado* this;
    this = (Empleado*) malloc(sizeof(Empleado));
    return this;
}

void empleado_delete(Empleado* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

Empleado* empleado_newEmpleadoUp(char* id, char* nombre,char* horas)
{
    int bId;
    int bHoras;
    Empleado* this = empleado_newArrayEmpleado();
    //if(this!=NULL && horas>0 && nombre!=NULL && id>0)
    //{
        bId = atoi(id);
        bHoras = atoi(horas);
        //-----------------
        empleado_setId(this,bId);
        empleado_setNombre(this,nombre);
        empleado_setHoras(this,bHoras);
    //}
    return this;
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int auxReturn;
    if(this!=NULL && nombre!=NULL)
    {
        auxReturn = 0;
        strcpy(this->nombre,nombre);
    }
    return auxReturn;
}

int empleado_getNombre(Empleado* this, char* nombre)
{
    int auxReturn =-1;
    if(this!=NULL && nombre!=NULL)
    {
        auxReturn = 0;
        strcpy(nombre,this->nombre);
    }
    return auxReturn;
}

int empleado_setSueldo(Empleado* this, int sueldo)
{
    int auxReturn;
    if(this!=NULL && sueldo>=0)
    {
        auxReturn = 0;
        this->sueldo = sueldo;
    }
    return auxReturn;
}

int empleado_getSueldo(Empleado* this, int* sueldo)
{
    int auxReturn;
    if(this!=NULL && sueldo!=NULL)
    {
        auxReturn = 0;
        *sueldo = this->sueldo;
    }
    return auxReturn;
}

int empleado_setHoras(Empleado* this, int horas)
{
    int auxReturn;
    if(this!=NULL && horas >= 0)
    {
        auxReturn = 0;
        this->horasTrabajadas = horas;
    }
    return auxReturn;
}

int empleado_getHoras(Empleado* this, int* horas)
{
    int auxReturn;
    if(this!=NULL && horas!=NULL)
    {
         auxReturn = 0;
        *horas = this->horasTrabajadas;
    }
    return auxReturn;
}

int empleado_setId(Empleado* this, int id)
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

int empleado_getId(Empleado* this, int* id)
{

    int auxReturn;
    if(this!=NULL && id!=NULL)
    {
        auxReturn = 0;
        *id = this->id;
    }
    return auxReturn;
}

int em_calcularSueldo(void* this)
{
    int auxReturn = -1;
    int hora;
    int sueldo=0;
    if(this!=NULL)
    {
        auxReturn = 0;
        empleado_getHoras(this,&hora);

        if(hora < 120)
        {
            sueldo = hora*180;
        }
        else if(hora < 160)
        {
            sueldo = hora*220;
        }
        else
        {
            sueldo = hora*350;
        }
        empleado_setSueldo(this,sueldo);
    }
    return auxReturn;
}
