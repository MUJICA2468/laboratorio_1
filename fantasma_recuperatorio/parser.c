#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "producto.h"
int parser_nuevoParser(char* path,ArrayList* pArrayList)
{
    FILE* pFile;
    Producto* auxProducto = NULL;
    char bString[4096];
    char bNumero[4096];
    char bIdProducto[4096];
    //---------------------
    int auxNumero;
    int auxIdProducto;
    int auxReturn = -1;
    pFile = fopen(path,"r");
    if(pFile!=NULL && path!=NULL && pArrayList!=NULL)
    {
        auxReturn = 0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bIdProducto,bString,bNumero);
            auxNumero = atoi(bNumero);
            auxIdProducto = atoi(bIdProducto);
            auxProducto = producto_newParametros(bString,auxNumero,auxIdProducto);
            al_add(pArrayList,auxProducto);
            printf("%d-%s-%d\n",auxIdProducto,bString,auxNumero);
        }
        fclose(pFile);
    }
    return auxReturn;
}

int parser_generar(char* path,ArrayList* pArrayList)
{
    FILE* pFile;
    Producto* auxProducto;
    char string[50];
    int numeros;
    int idProducto;
    //----------
    int i;
    int auxreturn = -1;
    pFile = fopen(path,"w");
    if(pFile!=NULL && path!=NULL && pArrayList!=NULL)
    {
        auxreturn = 0;
        for(i=0;i<al_len(pArrayList);i++)
        {
            auxProducto = al_get(pArrayList,i);
            producto_getParametros(auxProducto,string,&numeros,&idProducto);
            fprintf(pFile,"%d,%s,%d\n",idProducto,string,numeros);
            printf("%d-%s-%d\n",auxIdProducto,bString,auxNumero);
        }
        fclose(pFile);
    }
    return auxreturn;
}
