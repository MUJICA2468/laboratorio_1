#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "fantasma.h"
#include "utn.h"
static int fantasma_setId(Fantasma* this,int id);

/** \brief Genera un nuevo elemento en el array
 *
 * \return Fantasma* Puntero a estructura
 *
 */
Fantasma* fantasma_new()
{
    Fantasma* this = NULL;
    this = (Fantasma*) malloc(sizeof(Fantasma));
    return this;
}

/** \brief Libera espacio reservado previamente
 *
 * \param this Fantasma* Puntero a estructura
 * \return void Retorno a void(nada)
 *
 */
void fantasma_delete(Fantasma* this)
{
    free(this);
}

/** \brief Funcion con los seteos y parametros llamados
 *
 * \param id int parametro a id
 * \param name char* parametro a name
 * \param lastName char* parametro a lastname
 * \param dni char* parametro a dni
 * \return Fantasma* retorna un nuevos elementos para el llamado
 *
 */
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

/** \brief Lista la cantidad de elementos en el arrat
 *
 * \param pArrayList ArrayList* puntero a estructura
 * \return int retorna (-1)si no se logra entrar
 *                      (0)si logra la entrada
 */
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

/** \brief Se van a pedir los datos y se los consigue por parametro
 *
 * \param name char* parametro para name
 * \param lastName char* parametro para lastName
 * \param dni char* parametro para el dni
 * \return int retorna(-1)si no logra entrar
 *
 */
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

/** \brief Se OBTIENEN los datos por parametro
 *
 * \param auxCliente Fantasma* puntero a estructura
 * \param id int* puntero a int para que se obtenga el id
 * \param name char* puntero a char para que se obtenga el name
 * \param lastName char* puntero a char para que se obtenga el lastName
 * \param dni char* puntero a char para que se obtenga el DNI
 * \return int retorna (-1)si logra iterar
 *
 */
int fantasma_getParametros(Fantasma* auxCliente,int* id,char* name,char* lastName,char* dni)
{
    int auxReturn = -1;
    if(auxCliente!=NULL&&id!=NULL && name!=NULL && lastName!=NULL && dni!=NULL)
    {
        fantasma_getId(auxCliente,id);
        fantasma_getName(auxCliente,name);
        fantasma_getLastName(auxCliente,lastName);
        fantasma_getDni(auxCliente,dni);
    }
    return auxReturn;
}

/** \brief setea el ID
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para el ID
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief OBTIENE el ID
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para obtener el ID
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief setea el nombre
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para setear el nombre
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief OBTIENE el nombre
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para obtener el nombre
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief setea el apellido
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para setear el apellido
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief OBTIENE el apellido
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para obtener el apellido
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief setea el dni
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para setear el dni
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief OBTIENE el dni
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para obtener el dni
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief setea las horas
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para setear las horas
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief OBTIENE las horas
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para obtener las horas
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief setea el sueldo
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para setear el sueldo
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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

/** \brief OBTIENE el sueldo
 *
 * \param this Fantasma* puntero a la estructura
 * \param id int parametro para obtener el sueldo
 * \return int retorna (-1)Si no logra entrar
 *                     (0)si logra entrar
 */
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
