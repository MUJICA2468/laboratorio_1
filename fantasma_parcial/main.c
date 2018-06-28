#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "parser.h"
#include "fantasma.h"
#include "utn.h"
int main()
{
    ArrayList* pArrayList = al_newArrayList();
    int opcion;
    int auxId;
    if(parser_loadFiles("data.csv",pArrayList)==1)
    {
        do{
            getIntB("Ingrese una opcion\
            \n1- ALTA\
            \n2- MODIFICAR\
            \n3- BAJA\
            \n9- SALIR\n","INVALIDO\n",2,1,9,&opcion);
            switch(opcion)
            {
                case 1:
                printf("Realize el alta\n");
                fantasma_alta(pArrayList);
                break;
                case 2:
                getValidInt("Ingrese el ID a modificar\n","INVALIDO\n",&auxId,1,1000,2);
                fantasma_modificar(pArrayList, auxId);
                break;
                case 3:
                getValidInt("Ingrese el ID a dar de baja\n","INVALIDO\n",&auxId,1,1000,2);
                fantasma_baja(pArrayList,auxId);
                break;
            }

        }while(opcion!=9);
          parser_generateFile("data.csv",pArrayList);

    }else{
        printf("No se han leido los archivos");
    }
    return 0;
}
