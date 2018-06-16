#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "controller.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/


int main()
{
    FILE* pFile;
    ArrayList* pArrayClientes;
    pArrayClientes = al_newArrayList();
    int opcion;
    do{

        getValidInt("\n**INGRESE UNA OPCION**\
                    1. Cargar datos desde data.csv \
                    2. Listar Clientes \
                    3. Ordenar por nombre y apellido \
                    4. Ordenar por mail \
                    5. Agregar un Cliente\
                    6. Elimina un Cliente\
                    7. Modificar Cliente (Nombre, Apellido y Mail)\
                    8. Listar Clientes\n9. Guardar datos en data.csv (modo texto)\
                    9. Guardar datos en data.csv (modo texto)\
                    10. Guardar datos en data.bin (modo binario)\
                    11. SALIR \n",
        "\nINVALIDO", &opcion, 0, 11, 2);
        switch(opcion)
        {
            case 1:
                controller_leerArchivoCliente("data.csv", pArrayClientes);
                break;
            case 2:
                controller_leerClientes(pArrayClientes);
                break;
            case 3:
                controller_otrdenarNombreApellido(pArrayClientes);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                controller_guardarClientes("data2.csv", pArrayClientes);
                break;
            case 10:
                break;
        }

    }while(opcion!=11);
    return 0;
}
