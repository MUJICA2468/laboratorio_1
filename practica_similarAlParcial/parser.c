#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "ArrayList.h"
#include "Cliente.h"
int parser_newParser(char* path,ArrayList* pArrayList)
{
    FILE* pFile;
    Cliente* pClienteList;
    int auxReturn=-1;
    char bId[4096];
    char bNombre[4096];
    char bHoras[4096];
    pFile = fopen(path,"r");
    if(path!=NULL && pArrayList!=NULL)
    {
        auxReturn = 0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bNombre,bHoras);
            pClienteList = cliente_newClienteUp(bId,bNombre,bHoras);
            al_add(pArrayList,pClienteList);
        }
        fclose(pFile);
    }
    return auxReturn;
}

int parser_generateFile(char* path,ArrayList* pArrayList)
{
    FILE* pFile;
    Cliente* pClienteList;
    int i;
    int auxReturn = -1;
    int id;
    char nombre[50];
    int horas;
    int sueldo;
    pFile = fopen(path,"w");
    if(path!=NULL && pArrayList!=NULL)
    {
        auxReturn = 0;
        fprintf(pFile,"id,nombre,horas_trabajadas,sueldo\n");
        for(i=0;i<al_len(pArrayList);i++)
        {
            pClienteList = al_get(pArrayList,i);
            cliente_getId(pClienteList,&id);
            cliente_getNombre(pClienteList,nombre);
            cliente_getHoras(pClienteList,&horas);
            cliente_getSueldo(pClienteList,&sueldo);
            fprintf(pFile,"\n%d, %s, %d, %d",id, nombre,horas,sueldo);
        }
        fclose(pFile);
    }
    return auxReturn;
}
