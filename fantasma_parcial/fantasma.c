#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "fantasma.h"
#include "utn.h"
static int fantasma_setId(Fantasma* this,int id);

Fantasma* fantasma_new()
{
    Fantasma* this = NULL;
    this = (Fantasma*) malloc(sizeof(Fantasma));
    return this;
}

void fantasma_delete(Fantasma* this)
{
    free(this);
}

Fantasma* fantasma_newParametros(int id,char* name,char* lastName,char* dni)
{
    Fantasma* this = fantasma_new();
    if(name!=NULL && lastName!=NULL && dni!=NULL)
    {
        fantasma_setId(this,id);
        fantasma_setName(this,name);
        fantasma_setLastName(this,lastName);
        fantasma_setDni(this,dni);
    }
    return this;
}

int fantasma_alta(ArrayList* pArrayList)
{
    Fantasma* auxFantasma;
    int auxReturn = -1;
    char name[50];
    char lastName[50];
    char dni[50];
    if(pArrayList!=NULL)
    {
        auxReturn = 0;
        fantasma_setParametros(name,lastName,dni);
        auxFantasma = fantasma_newParametros(-1,name,lastName,dni);
        al_add(pArrayList,auxFantasma);
    }
    return auxReturn;
}

int fantasma_modificar(ArrayList* pArrayList, int id)
{
    Fantasma* auxFantasma;
    int auxReturn = -1;
    //--------------
    char name[50];
    char lastName[50];
    char dni[50];
    int auxId;
    int i;
    if(pArrayList!=NULL)
    {
        for(i=0;i<al_len(pArrayList);i++)
        {
            auxFantasma = al_get(pArrayList,i);
            fantasma_getId(auxFantasma,&auxId);
            if(id == auxId)
            {
                auxReturn = 0;
                fantasma_setParametros(name,lastName,dni);
                auxFantasma = fantasma_newParametros(auxId,name,lastName,dni);
                al_set(pArrayList,i,auxFantasma);
                break;
            }
        }
    }

    return auxReturn;
}

int fantasma_baja(ArrayList* pArrayList,int id)
{
    Fantasma* auxFantasma;
    int auxReturn = -1;
    int i;
    int auxId;
    if(pArrayList!=NULL)
    {
        for(i=0;i<al_len(pArrayList);i++)
        {
            auxFantasma = al_get(pArrayList,i);
            fantasma_getId(auxFantasma,&auxId);
            if(id==auxId)
            {
                auxReturn = 0;
                al_remove(pArrayList,i);
            }
        }
    }
    return auxReturn;
}

int fantasma_ordenar(void* lastNameA,void* lastNameB)
{
    int auxReturn = -1;
    char auxlastNameA[50];
    char auxlastNameB[50];
    fantasma_getLastName(lastNameA,auxlastNameA);
    fantasma_getLastName(lastNameB,auxlastNameB);
    auxReturn = strcmp(auxlastNameA,auxlastNameB);

    return auxReturn;
}

int fantasma_listar(ArrayList* pArrayList)
{
    Fantasma* auxFantasma;
    int auxReturn = -1;
    int i;
    //-----------
    int id;
    char name[50];
    char lastName[50];
    char dni[14];
    //------------
    if(pArrayList!=NULL)
    {
        auxReturn = 0;
        for(i=0;i<al_len(pArrayList);i++)
        {
            auxFantasma = al_get(pArrayList,i);
            fantasma_getId(auxFantasma,&id);
            fantasma_getName(auxFantasma,name);
            fantasma_getLastName(auxFantasma,lastName);
            fantasma_getDni(auxFantasma,dni);
            printf("%d, %s, %s, %s\n",id,name,lastName,dni);
        }
    }
    return auxReturn;
}

int fantasma_setParametros(char* name,char* lastName,char* dni)
{
    int auxReturn = -1;
    if(name!=NULL && lastName!=NULL && dni!=NULL)
    {
        getValidString("Ingrese nombre:\n","INVALIDO\n","Se paso\n",name, 50,2);
        getValidString("Ingrese apellido:\n","INVALIDO\n","Se paso\n",lastName, 50,2);
        getValidDNI(dni,"Ingrese DNI:\n","INVALIDO\n",2);
    }
    return auxReturn;
}

int fantasma_setId(Fantasma* this,int id)
{
    static int lastId = -1;
    int auxReturn;
    if(this!=NULL)
    {
        auxReturn = 0;
        if(id>0)
        {
            this->idFantasma = id;
            if(id>lastId)
            lastId = id;
        }
        else
        {
            lastId++;
            this->idFantasma = lastId;
        }
    }
    return auxReturn;
}

int fantasma_getId(Fantasma* this,int* id)
{
    int auxReturn = -1;
    if(this!=NULL && id!=NULL)
    {
        auxReturn = 0;
        *id = this->idFantasma;
    }
    return auxReturn;
}

int fantasma_setName(Fantasma* this,char* name)
{
    int auxReturn = -1;
    if(this!=NULL && name!=NULL)
    {
        auxReturn = 0;
        strcpy(this->name,name);
    }
    return auxReturn;
}

int fantasma_getName(Fantasma* this,char* name)
{
    int auxReturn = -1;
    if(this!=NULL && name!=NULL)
    {
        auxReturn = 0;
        strcpy(name,this->name);
    }
    return auxReturn;
}

int fantasma_setLastName(Fantasma* this,char* lastName)
{
    int auxReturn = -1;
    if(this!=NULL && lastName!=NULL)
    {
        auxReturn = 0;
        strcpy(this->lastName,lastName);
    }
    return auxReturn;
}

int fantasma_getLastName(Fantasma* this,char* lastName)
{
    int auxReturn = -1;
    if(this!=NULL && lastName!=NULL)
    {
        auxReturn = 0;
        strcpy(lastName,this->lastName);
    }
    return auxReturn;
}

int fantasma_setDni(Fantasma* this,char* dni)
{
    int auxReturn = -1;
    if(this!=NULL && dni!=NULL)
    {
        auxReturn = 0;
        strcpy(this->dni,dni);
    }
    return auxReturn;
}

int fantasma_getDni(Fantasma* this,char* dni)
{
    int auxReturn = -1;
    if(this!=NULL && dni!=NULL)
    {
        auxReturn = 0;
        strcpy(dni,this->dni);
    }
    return auxReturn;
}

int fantasma_setHoras(Fantasma* this, int horas)
{
    int auxReturn;
    if(this!=NULL && horas >= 0)
    {
        auxReturn = 0;
        this->horasTrabajadas = horas;
    }
    return auxReturn;
}

int fantasma_getHoras(Fantasma* this, int* horas)
{
    int auxReturn;
    if(this!=NULL && horas!=NULL)
    {
         auxReturn = 0;
        *horas = this->horasTrabajadas;
    }
    return auxReturn;
}

int fantasma_setSueldo(Fantasma* this, int sueldo)
{
    int auxReturn;
    if(this!=NULL && sueldo>=0)
    {
        auxReturn = 0;
        this->sueldo = sueldo;
    }
    return auxReturn;
}

int fantasma_getSueldo(Fantasma* this, int* sueldo)
{
    int auxReturn;
    if(this!=NULL && sueldo!=NULL)
    {
        auxReturn = 0;
        *sueldo = this->sueldo;
    }
    return auxReturn;
}
