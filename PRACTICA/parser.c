#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "cliente.h"

int parser_newParserBlackList(char*path, Cliente* pArrayList)
{
    FILE* pFile = NULL;
    int auxReturn = -1;
    char nombre[150];
    char eMail[150];
    Cliente* auxCliente;
    char auxInt;
    pFile = fopen(path,"r");
    if(pFile!=NULL && pArrayList!=NULL && path!=NULL)
    {
        auxReturn = 0;
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^\n]\n",nombre, eMail);
            //printf("\n%s-%s", nombre, eMail);
            auxCliente = cliente_new();
            cliente_setNombre(auxCliente, nombre);
            cliente_setEmail(auxCliente, eMail);
            al_add(pArrayList, auxCliente);

        }
        fclose(pFile);
    }
    return auxReturn;
}

int parser_newParserDestinatarios(Cliente** pFile,Cliente* this,int qty, char* path)
{
    pFile = fopen("destinatarios.csv","r");
    int auxReturn = -1;
    char nombre[50];
    char eMail[50];
    if(pFile!=NULL && this!=NULL && qty>=0 && path!=NULL)
    {
        auxReturn = 0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%s[^,],%s[^\n]\n", nombre, eMail);
            cliente_getNombre(this, nombre);
            cliente_getEmail(this, eMail);
        }
    }
    fclose(pFile);
    return auxReturn;
}
