#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Parser.h"
#include "Empleado.h"
int parser_parseEmpleados(char* path, ArrayList* pArrayList)
{
    FILE* pFile;
    Empleado* auxEmpleado;
    int auxReturn = -1;
    char bId[4096];
    char bNombre[128];
    char bHorasTrabajadas[4096];
    //------------------
    pFile = fopen(path,"r");
    if(pFile!=NULL)
    {
        auxReturn = 1;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bNombre,bHorasTrabajadas);//Si se colocara un fscanf fuera, arriba del while se saltea la cabeza para que sean 1000 empleados clavados
            auxEmpleado = empleado_newEmpleadoUp(bId,bNombre,bHorasTrabajadas);//Con esto se crean empleados en la memoria, con todos sus elementos
            al_add(pArrayList,auxEmpleado);
            //printf("%s - %s - %s - %s\n",bId,bNombre,bHorasTrabajadas,bSueldo);

        }
    }
    fclose(pFile);
    return auxReturn; // OK
}

int generarArchivoSueldos(char* path,ArrayList* pArrayList)
{
    Empleado* auxEmpelado;
    char nombre[50];
    int id;
    int sueldo;
    int horas;
    int i;
    int auxReturn = -1;
    //--------------
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile!=NULL)
    {
        auxReturn = 1;
        fprintf(pFile,"id,nombre,horas_trabajadas,sueldo\n");
        for(i=0;i<al_len(pArrayList);i++)
        {
            auxEmpelado = al_get(pArrayList,i);
            empleado_getId(auxEmpelado,&id);
            empleado_getNombre(auxEmpelado,nombre);
            empleado_getHoras(auxEmpelado,&horas);
            empleado_getSueldo(auxEmpelado,&sueldo);
            fprintf(pFile,"\n%d, %s, %d, %d",id,nombre,horas,sueldo);
        }
    }
    fclose(pFile);
    return auxReturn;
}
