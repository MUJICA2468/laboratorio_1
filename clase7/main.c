#include <stdio.h>
#include <string.h>
#include "funcs.h"

int main(void)
{
    int edades[6] = {30,20,10,5,44,66};

    mostrarArrayInt(edades,6);
    ordenarArrayIntInsertion(edades,6,1);
    mostrarArrayInt(edades,6);
    ordenarArrayIntInsertion(edades,6,0);
    mostrarArrayInt(edades,6);

    return 0;
}
