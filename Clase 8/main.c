#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
#include "empleado.h"
#define CANT 5

int main()
{
    char seguir = 's';
    int opcion;
    char nombre[CANT][20];
    char apellido[CANT];
    int aux;
    empleado arrayEmpleados[CANT];

    if(emp_init(arrayEmpleados, CANT)==-1)
        printf("ERROR");
    else if(emp_init(arrayEmpleados, CANT)==0)
        printf("started");

    do{
        printf("\n 1 - alta  \n 2 - baja \n 3 - mostrar \n 4 - salir");


        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                    aux = emp_nombre(nombre, CANT);
                    printf("%d", &aux);
            break;
            /*
            case 'b':
                    emp_init(apellido, CANT);
            break;
            */
        }

    }while(seguir == 'n');

    return 0;
}
