#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "parser.h"
#include "Cliente.h"
#include "utn.h"
int main()
{
    ArrayList* pArrayList = al_newArrayList();
    char opcion='s';

    do{
        getValidString("Desea generar archivo: s/n\n","INVALIDO\n","SE PASO\n",&opcion,5,2);
        switch(opcion)
        {
            case's':
            if(parser_newParser("file.csv",pArrayList)==0)
            {
                al_map(pArrayList,cliente_calcularSueldo);
                if(parser_generateFile("archivoGenerado.csv",pArrayList)==0)
                {
                    printf("GENERARNDO ARCHIVO CON NUEVOS DATOS");
                }
                else
                {
                    printf("No se ha podido generar el nuevo archivo");
                }
            }
            else
            {
                printf("No se han podido cargar correctamente");
            }
            return 0;
            break;
        }
    }while(opcion!='n');
    return 0;
}
