#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "producto.h"
#include "parser.h"
int main()
{
    ArrayList* pArrayList = al_newArrayList();

    parser_nuevoParser("id_nombre_horas.csv",pArrayList);
    parser_generar("generado.csv",pArrayList);

    return 0;
}
