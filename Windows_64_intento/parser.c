#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxiliarEmpleado;
    //pFile = fopen("data.csv","r");
    char bId[4096];
    char bName[4096];
    char bLastName[4096];
    char bIsEmpty[4096];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            retorno = 0;
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n] \n", bId, bName, bLastName, bIsEmpty);
            employee_newParametrosString(bId, bName, bLastName, bIsEmpty);
            auxiliarEmpleado = printf("%s %s %s %s \n", bId, bName, bLastName, bIsEmpty);
            employee_print(auxiliarEmpleado);
            al_add(pArrayListEmployee ,auxiliarEmpleado);
        }
    }
    fclose(pFile);
    return retorno;
}
