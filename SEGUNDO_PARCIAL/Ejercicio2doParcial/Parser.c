#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#include "Parser.h"
#include "ArrayList.h"

/** \brief Lee un archivo especifico que contenga elementos
 *
 * \param path char* Parametro donde se escribira el archivo a leer en su llamado
 * \param pArrayList ArrayList* Puntero a ArrayList
 * \return int retorna (-1)un valor negativo si no se logra entrar
 *                     (1)Si logra entrar
 */
int parser_parseEmpleados(char* path,ArrayList* pArrayList)
{
    FILE* pFile;
    Empleado* auxFantasma;
    int auxReurn = -1;
    char bName[4096];
    char bHoras[4096];
    char bId[4096];
    //---------------
    int auxId;
    int auxHoras;
    pFile = fopen(path,"r");
    if(path!=NULL && pArrayList!=NULL)
    {
        auxReurn = 1;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bName,bHoras);
            printf("%s - %s - %s\n",bId,bName,bHoras);
            auxId = atoi(bId);
            auxHoras = atoi(bHoras);
            auxFantasma = empleado_newParametros(auxId,bName,auxHoras);
            al_add(pArrayList,auxFantasma);
        }
    }
    fclose(pFile);
    return auxReurn;
}

/** \brief Genera un archivo con los elementos de otro archivo
 *
 * \param path char* Parametro donde se escribira el archivo a leer en su llamado
 * \param pArrayList ArrayList* Puntero a ArrayList
 * \return intretorna (-1)un valor negativo si no se logra entrar
 *                     (0)Si logra entrar
 *
 */
int generarArchivoFiltrado(char* path,ArrayList* pArrayList)
{
    Empleado* auxFantasma;
    FILE* pFile;
    int auxReturn = -1;
    int i;
    //-----------
    int id;
    char name[50];
    int horas;
    //------------
    pFile = fopen(path,"w");
    if(pFile!=NULL && path!=NULL && pArrayList!=NULL)
    {
        for(i=0;i<al_len(pArrayList);i++)
        {
            auxReturn = 1;
            auxFantasma = al_get(pArrayList,i);
            //empleado_getParametros(auxFantasma,&id,name,&horas);
            empleado_getId(auxFantasma,&id);
            empleado_getName(auxFantasma,name);
            empleado_getHoras(auxFantasma,&horas);
            if(em_trabajaMasDe120Horas(&horas))
            {
                if(contract(pArrayList,id)==0)
                {
                    fprintf(pFile,"\n%d, %s, %d",id,name,horas);
                    printf("%d, %s, %d\n",id,name,horas);
                }
            }
        }
    }
    fclose(pFile);
    return auxReturn;
}
