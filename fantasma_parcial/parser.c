#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "ArrayList.h"
#include "fantasma.h"
int parser_loadFiles(char* path,ArrayList* pArrayList)
{
    FILE* pFile;
    Fantasma* auxFantasma;
    int auxReurn = -1;
    char bName[4096];
    char bLastName[4096];
    char bDni[4096];
    char bId[4096];
    //---------------
    int auxId;
    pFile = fopen(path,"r");
    if(path!=NULL && pArrayList!=NULL)
    {
        auxReurn = 1;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,bName,bLastName,bDni);
            printf("%s - %s - %s - %s\n",bId,bName,bLastName,bDni);
            auxId = atoi(bId);
            auxFantasma = fantasma_newParametros(auxId,bName,bLastName,bDni);
            al_add(pArrayList,auxFantasma);
        }
    }
    fclose(pFile);
    return auxReurn;
}

int parser_generateFile(char* path,ArrayList* pArrayList)
{
    FILE* pFile;
    Fantasma* auxFantasma;
    int auxReturn = -1;
    int i;
    //-----------
    int id;
    char name[50];
    char lastName[50];
    char dni[14];
    //------------
    pFile = fopen(path,"w");
    if(pFile!=NULL && path!=NULL && pArrayList!=NULL)
    {
        auxReturn = 0;
        for(i=0;i<al_len(pArrayList);i++)
        {
            auxFantasma = al_get(pArrayList,i);
            fantasma_getId(auxFantasma,&id);
            fantasma_getName(auxFantasma,name);
            fantasma_getLastName(auxFantasma,lastName);
            fantasma_getDni(auxFantasma,dni);
            fprintf(pFile,"\n%d, %s, %s, %s",id,name,lastName,dni);
            printf("%d, %s, %s, %s\n",id,name,lastName,dni);
        }
    }
    fclose(pFile);
    return auxReturn;
}
