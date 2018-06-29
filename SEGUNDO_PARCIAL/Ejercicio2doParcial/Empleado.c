#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#include "ArrayList.h"
#include "utn.h"

int em_trabajaMasDe120Horas(void* item)
{
   // Empleado* this;
    int auxReturn = -1;
    int horas;
    if(item!=NULL)
    {
        empleado_getHoras(item,&horas);
        if(horas>120)
        {
            auxReturn = 1;
        }
        //empleado_setHoras(item,horas);
    }
    return auxReturn;
}

static int empleado_setId(Empleado* this,int id);

/** \brief Genera un nuevo elemento en el array
 *
 * \return Empleado* Puntero a estructura
 *
 */
Empleado* empleado_new()
{
    Empleado* this = NULL;
    this = (Empleado*) malloc(sizeof(Empleado));
    return this;
}

/** \brief Libera espacio reservado previamente
 *
 * \param this Empleado* Puntero a estructura
 * \return void Retorno a void(nada)
 *
 */
void empleado_delete(Empleado* this)
{
    free(this);
}

/** \brief Funcion con los seteos y parametros llamados
 *
 * \param id int parametro a id
 * \param name char* parametro a name
 * \param lastName char* parametro a lastname
 * \param dni char* parametro a dni
 * \return Empleado* retorna un nuevos elementos para el llamado
 *
 */
Empleado* empleado_newParametros(int id,char* name,int horas)
{
    Empleado* this = empleado_new();
    if(name!=NULL)
    {
        empleado_setId(this,id);
        empleado_setName(this,name);
        empleado_setHoras(this,horas);
    }
    return this;
}

/** \brief Lista la cantidad de elementos en el arrat
 *
 * \param pArrayList ArrayList* puntero a estructura
 * \return int retorna (-1)si no se logra entrar
 *                      (0)si logra la entrada
 */
int empleado_listar(ArrayList* pArrayList)
{
    Empleado* auxEmpleado;
    int auxReturn = -1;
    int i;
    //-----------
    int id;
    char name[50];
    //------------
    if(pArrayList!=NULL)
    {
        auxReturn = 0;
        for(i=0;i<al_len(pArrayList);i++)
        {
            auxEmpleado = al_get(pArrayList,i);
            empleado_getId(auxEmpleado,&id);
            empleado_getName(auxEmpleado,name);

            printf("%d, %s,\n",id,name);
        }
    }
    return auxReturn;
}

/** \brief Se van a pedir los datos y se los consigue por parametro
 *
 * \param name char* parametro para name
 * \param lastName char* parametro para lastName
 * \param dni char* parametro para el dni
 * \return int retorna(-1)si no logra entrar
 *
 */
int empleado_setParametros(char* name)
{
    int auxReturn = -1;
    if(name!=NULL)
    {
        getValidString("Ingrese nombre:\n","INVALIDO\n","Se paso\n",name, 50,2);
    }
    return auxReturn;
}

/** \brief Se OBTIENEN los datos por parametro
 *
 * \param auxCliente Empleado* puntero a estructura
 * \param id int* puntero a int para que se obtenga el id
 * \param name char* puntero a char para que se obtenga el name
 * \param lastName char* puntero a char para que se obtenga el lastName
 * \param dni char* puntero a char para que se obtenga el DNI
 * \return int retorna (-1)si logra iterar
 *
 */
/*int empleado_getParametros(Empleado* auxCliente,int* id,char* name, int* horas)
{
    int auxReturn = -1;
    if(auxCliente!=NULL&&id!=NULL && name!=NULL)
    {
        empleado_getId(auxCliente,id);
        empleado_getName(auxCliente,name);
        empleado_getHoras(auxCliente,horas);
    }
    return auxReturn;
}*/

/** \brief setea el ID
 *
 * \param this Empleado* puntero a la estructura
 * \param id int parametro para el ID
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
int empleado_setId(Empleado* this,int id)
{
    static int lastId = -1;
    int auxReturn;
    if(this!=NULL)
    {
        auxReturn = 0;
        if(id>0)
        {
            this->id = id;
            if(id>lastId)
            lastId = id;
        }
        else
        {
            lastId++;
            this->id = lastId;
        }
    }
    return auxReturn;
}

/** \brief OBTIENE el ID
 *
 * \param this Empleado* puntero a la estructura
 * \param id int parametro para obtener el ID
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
int empleado_getId(Empleado* this,int* id)
{
    int auxReturn = -1;
    if(this!=NULL && id!=NULL)
    {
        auxReturn = 0;
        *id = this->id;
    }
    return auxReturn;
}

/** \brief setea el nombre
 *
 * \param this Empleado* puntero a la estructura
 * \param id int parametro para setear el nombre
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
int empleado_setName(Empleado* this,char* name)
{
    int auxReturn = -1;
    if(this!=NULL && name!=NULL)
    {
        auxReturn = 0;
        strcpy(this->nombre,name);
    }
    return auxReturn;
}

/** \brief OBTIENE el nombre
 *
 * \param this Empleado* puntero a la estructura
 * \param id int parametro para obtener el nombre
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
int empleado_getName(Empleado* this,char* name)
{
    int auxReturn = -1;
    if(this!=NULL && name!=NULL)
    {
        auxReturn = 0;
        strcpy(name,this->nombre);
    }
    return auxReturn;
}

/** \brief setea las horas
 *
 * \param this Empleado* puntero a la estructura
 * \param id int parametro para setear las horas
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief OBTIENE las horas
 *
 * \param this Empleado* puntero a la estructura
 * \param id int parametro para obtener las horas
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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
