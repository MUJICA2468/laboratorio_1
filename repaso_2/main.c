#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

#define CANTC 5


//REVISAR
int main()
{
    Cliente arrayClientes[CANTC];

    Cliente* pArrayClientes;

    pArrayClientes = (Cliente*) malloc(sizeof(Cliente));

    int qtyArrayCliente = 0;


    cliente_alta(&arrayClientes, pArrayClientes);
    cliente_alta(&arrayClientes, pArrayClientes);
    cliente_alta(&arrayClientes, pArrayClientes);


    cliente_listar(arrayClientes, pArrayClientes);
    return 0;
}
