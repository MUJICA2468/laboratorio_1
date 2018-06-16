#include <stdio.h>
#include <stdlib.h>

int main()
{

    char apellido;
    float sueldo;
    float aumento;
    int sueldoAumento;

    printf("Ingrese apellido \n ");// No es necesario escribir la variable acá
    fflush(stdin);
    scanf("%c", &apellido);

    printf("Ingrese sueldo \n ", sueldo);
    scanf("%f", &sueldo);

    printf("Ingrese aumento \n", aumento);
    scanf("%d", &aumento);


    aumento = sueldo * 20/100;

    sueldoAumento = sueldo + aumento;


    printf("%d", sueldoAumento);




    return 0;
}
