#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidNombre(char* nombre);
static int isValidAltura(int altura);


Alumno* alumno_new()
{
    return malloc(sizeof(Alumno));
}

Alumno* alumno_newP(char* nombre,float altura,int id)
{
    Alumno* auxiliarAlumno = alumno_new();
    if(!alumno_setNombre(auxiliarAlumno,nombre) && !alumno_setId(auxiliarAlumno,id) && !alumno_setAltura(auxiliarAlumno,altura))
    {

    }
    alumno_delete(auxiliarAlumno);
    return NULL;
}



void alumno_delete(Alumno* this)
{
    free(this);
}

int alumno_setNombre(Alumno* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre)
    {
        retorno = 0;
        strcpy(this-> nombre, nombre);
    }
    return retorno;
}

int alumno_getNombre(Alumno* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre, this-> nombre);
    }
    return retorno;
}

int alumno_setAltura(Alumno* this, float altura)
{
    int retorno = -1;
    if(this != NULL && isValidAltura(altura))
    {
        retorno = 0;
        this -> altura= altura;
    }
    return retorno;
}

int alumno_getAltura(Alumno* this, float* altura)
{
    int retorno = -1;
    if(this != NULL && altura != NULL)
    {
        retorno = 0;
        *altura = this -> altura;
    }
    return retorno;
}

int alumno_setId(Alumno* this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        if(id >= 0)
        {
            retorno = 0;
            if(id > maximoId)
            maximoId = id;
            this -> id = id;

        }else
        {
            maximoId++;
            this -> id = maximoId;
        }
    }
    return retorno;
}

int isValidnombre(char* nombre)
{

    return 1;
}

int isValidAltura(int altura)
{

    return 1;
}



int alumno_getId(Alumno* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this -> id;
    }
    return retorno;
}

//*************************************
/*
Alumno* arrayAlumno_getById (Alumno* array[],int cantidad,int id)
{

}

void arrayAlumno_add(Alumno* array[],int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit,float altura,int id)
{

}

void arrayAlumno_remove(Alumno* array[],int cantidadMaxima,int* cantidadActual, int id)
{

}
*/
//array de punteros alumnos el cual hay que rellenar de alumnos


int arrayAlumno_loadFromfile(Alumno* arrayPunterosAlumnos[], int* qytOcupada, int qytTotal, char* path)
{
    int retorno = -1;
    char bNombre[4096];
    char bAltura[4096];
    char bId[4096];
    char nombre[50];
    float altura;
    int id;
    FILE* pFile;
    pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,%],%[^,%],%[^\n%] \n",bNombre, bAltura, bId);
            printf("%s - %s - %s \n", bNombre, bAltura, bId);
            //Falta validar
            strcpy(nombre, bNombre);
            altura = atof(bAltura);
            id = atoi(bId);

            arrayPunterosAlumnos[*qytOcupada] = alumno_newP(nombre,altura, id);
            (*qytOcupada)++;

        }
    }
    fclose(pFile);//cierra la funcion, cierra el archivo
    return retorno;
}

int arrayAlumno_dumpFromfile(Alumno* arrayPunterosAlumnos[], int* qytOcupada, char* path)
{
    int retorno = -1;
    char nombre[4096];
    float altura;
    int id;
    int i;
    FILE* pFile;
    pFile = fopen(path, "w");
    if(pFile != NULL)
    {
        for(i=0;i<*qytOcupada;i++)
        {
            alumno_getNombre(arrayPunterosAlumnos,arrayPunterosAlumnos[i].nombre);
            alumno_getAltura(arrayPunterosAlumnos[i].&altura);
            alumno_getId(arrayPunterosAlumnos[i].id);
            fprintf("%s - %f - %d \n", nombre, altura, id);
        }
    }
    fclose(pFile);//cierra la funcion, cierra el archivo
    return retorno;
}
