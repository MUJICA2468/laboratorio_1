#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "ArrayList.h"
#include "cliente.h"

int controller_leerArchivoCliente(char* path, ArrayList* pArrayClientes)
{
    char bNombre[4096];
    char bApellido[4096];
    char bEmail[4096];
    char bGenero[4096];
    char bProfesion[4096];
    char bNacionalidad[4096];
    char bUsuario[4096];
    char bId[4096];
    Cliente* pAuxiliarCliente;
    FILE* pFile;
    int retorno = -1;
    pFile = fopen(path,"r");
    if(pFile!=NULL)
    {
        retorno = 0;
        while(!feof(pFile))
            // \contrabarra para saltos de linea y para compactar
        {
            fscanf(pFile," %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n] \n ", bId, bNombre, bApellido, bEmail, bGenero, bProfesion,  bUsuario, bNacionalidad);
            printf("\n%s", bNombre);
            pAuxiliarCliente = cliente_newParametros(bNombre, bApellido, bEmail, bGenero,//Este es un cliente
                                        bProfesion, bNacionalidad, bUsuario, atoi(bId));

            al_add(pArrayClientes, pAuxiliarCliente);//se añade al array
        }

    }
    fclose(pFile);
    return retorno;
}

int controller_leerClientes(ArrayList* pArrayClientes)
{
    int retorno = -1;
    int i;
    Cliente* auxCliente;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[50];
    char profesion[256];
    char usuario[300];
    char nacionalidad[256];
    int id;

    for(i=0;i<al_len(pArrayClientes);i++)
    {
        auxCliente = al_get(pArrayClientes, i);
        cliente_getNombre(auxCliente, nombre);
        cliente_getApellido(auxCliente, apellido);
        printf("\n NOMBRE:%s -- APELLIDO:%s \n", nombre, apellido);
    }
    return retorno;
}

int controller_otrdenarNombreApellido(ArrayList* pArrayCliente)
{
    int retorno = -1;
    if(pArrayCliente != NULL)
    {
        retorno = 0;
        al_sort(pArrayCliente, cliente_ordenarNombreApellido,0);
    }
    return retorno;
}


int controller_guardarClientes(ArrayList* pArrayClientes, char* path)
{
    int retorno = -1;
    int i;
    Cliente* auxCliente;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero;
    char profesion[256];
    char usuario[300];
    char nacionalidad[256];
    int id;
    FILE* pFile;
    pFile = fopen(path, "w");
    if(pArrayClientes != NULL)
    {
        printf(pFile,"\nID,nombre,apellido,genero,profesion,usuario,nacionalidad\n", id,nombre, apellido, genero,
            profesion, usuario, nacionalidad);
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            auxCliente = al_get(pArrayClientes, i);
            cliente_getNombre(auxCliente, nombre);
            cliente_getApellido(auxCliente, apellido);
            cliente_getEmail(auxCliente, email);
            cliente_getGenero(auxCliente, &genero);
            cliente_getProfesion(auxCliente, profesion);
            cliente_getUsuario(auxCliente, usuario);
            cliente_getNacionalidad(auxCliente, nacionalidad);
            cliente_getId(auxCliente, &id);
            //stdout: PUNTERO A LA CONSOLA
            fprintf(stdout,"\n%d - %s - %s - %s - %c - %s - %s - %s\n", id,nombre, apellido, genero,
            profesion, usuario, nacionalidad);
        }
    }
    fclose(pFile);
    return retorno;
}
