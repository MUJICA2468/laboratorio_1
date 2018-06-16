#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct{

    char nombre[20];
    char apellido[20];
    int idEmpleado;
    int isEmpy;
    //int dni[1234];
}empleado;
#endif // EMPLEADO_H_INCLUDED
/*
int newGetInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado);
int esEntero(char *str);
*/
int emp_mostrar(empleado* arrayEmpleados, int sizeArray);
int emp_init(empleado* arrayEmpleados, int sizeArray);
int emp_nombre(empleado* arrayEmpleados, int sizeArray);
