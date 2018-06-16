#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void mostrar(Alumno* array[],int cantidad);
void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual);

int main()
{

    Alumno* arrayPunteroAlumnos[4000];
    int qtyActualArrayAlumnos = 0;
    int qtyMaximaArrayAlumnos = 4000;

    arrayAlumno_loadFromfile(arrayPunteroAlumnos, &qtyActualArrayAlumnos, qtyMaximaArrayAlumnos, "archivo.loquesea.c");
    cargar(arrayPunteroAlumnos,qtyMaximaArrayAlumnos,&qtyActualArrayAlumnos);
    mostrar(arrayPunteroAlumnos,qtyActualArrayAlumnos);


    return 0;
}


void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual)
{

}

void mostrar(Alumno* array[],int cantidad)
{
    int i;
    char nombre[50];
    float altura;
    int id;
    for(i=0;i<cantidad,i++)
    {
        alumno_getNombre(array[i].nombre);
        alumno_getAltura(array[i].&altura);
        alumno_getId(array[i].id);
        printf("%s - %f - %d \n");

    }
}

void modificar(Alumno* array[],int cantidad)
{

}
