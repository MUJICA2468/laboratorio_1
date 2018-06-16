#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"

#define OCUPADO 0
#define LIBRE 1

/** \brief Realiza la apertura de espacios dentro del array
 *
 * \param arraycliente Alumno* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int alumno_init(Alumno* arrayAlumno, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayAlumno != NULL)
    {
        for(i=0;i<cant;i++)
        {
            arrayAlumno[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}
/** \brief Se obtiene el espacio libre dentro del array
 *
 * \param arrayAlumno Alumno* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int alumno_buscarLibre(Alumno* arrayAlumno, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayAlumno != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayAlumno[i].isEmpty == LIBRE)
            {
                 retorno = i;
            }
        }
    }
    return retorno;
}
//Esta manera de hacerlo es la mas indicada
void mostrar(Alumno *arrayAlumno, int cant)
{
    Alumno* limite = arrayAlumno + cant;
    for(;arrayAlumno<limite;arrayAlumno++)
    {
        //Es inecesario el i+(arrayAlumno+i); -> edad = 10 + i//Para que incremente, si tengo el puntero uso el operador flecha
        printf("\n%d \n",arrayAlumno->edad);
    }
}

void func(Alumno *arrayAlumno, int cant)
{
    int i;

    for(i=0;i<cant;i++)
    {
        (arrayAlumno+i)->edad = 10 + i;//Para que incremente, si tengo el puntero uso el operador flecha
    }
}

//Funcion que crea un alumno GG | CONSTRUCTOR
Alumno*alumno_new( )
{
    return malloc(sizeof(Alumno));
}
//Destruye el alumno GG | DESTRUCTOR
void alumno_delete(Alumno* this)//this: el alumno que destruyo es 'èste' : this
{
    free(this);
}

int alumno_setEdad(Alumno* this, int edad)
{
    int retorno = -1;
    if(edad >= 0 && this != NULL)
    {
        retorno = 0;
        this -> edad = edad;
    }
    return retorno;
}

int alumno_getEdad(Alumno* this, int *edad)
{
    int retorno = -1;
    if(edad != NULL && this != NULL)
    {
        retorno = 0;
        *edad = this -> edad;
    }
    return retorno;
}

void cargar(Alumno *arrayAlumno, int cant)
{
    int i;
    Alumno* auxiliarAlumno;
    for(i=0;i<cant;i++)
    {
        auxiliarAlumno = alumno_new();
        *(arrayAlumno+i) = auxiliarAlumno;
        alumno_setEdad(arrayAlumno, i+10);

        auxiliarAlumno = malloc(sizeof(Alumno));
        /*
        if(auxiliarAlumno != NULL)
        {
            auxiliarAlumno->edad = 44;
            *(array+i) = auxiliarAlumno;

        }
        */
    }

}

void mostrar2(Alumno *arrayAlumno, int cant)
{
    //Alumno* limite = arrayAlumno + cant;
    int auxiliarEdad;
    for(;arrayAlumno>0;arrayAlumno++,arrayAlumno--)
    {
        alumno_getEdad(*arrayAlumno,&auxiliarEdad);
        printf("\n%d \n",arrayAlumno);
    }
}

void cargar2(Alumno *arrayAlumno[], int cant)
{
    int i;
    Alumno *auxiliarAlumno;
    for(i=0;i<cant;i++)
    {
        auxiliarAlumno = alumno_new();
        *(arrayAlumno+i) = auxiliarAlumno;
        alumno_setEdad(auxiliarAlumno, i+10);
    }
}
