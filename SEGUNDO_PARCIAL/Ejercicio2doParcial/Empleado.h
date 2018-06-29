#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
};
typedef struct S_Empleado Empleado;
#include "ArrayList.h"
int em_trabajaMasDe120Horas(void* item);
Empleado* empleado_new();
Empleado* empleado_newParametros(int id,char* name,int horas);
int empleado_alta(ArrayList* pArrayList);
int empleado_modificar(ArrayList* pArrayList, int id);
int empleado_baja(ArrayList* pArrayList,int id);
int empleado_ordenar(void* lastNameA,void* lastNameB);
int empleado_listar(ArrayList* pArrayList);
int empleado_setParametros(char* name);
int empleado_getParametros(Empleado* auxCliente,int* id,char* name, int* horas);

int empleado_getId(Empleado* this,int* id);
int empleado_setName(Empleado* this,char* name);
int empleado_getName(Empleado* this,char* name);
int empleado_setLastName(Empleado* this,char* lastName);
int empleado_getLastName(Empleado* this,char* lastName);
int empleado_setDni(Empleado* this,char* dni);
int empleado_getDni(Empleado* this,char* dni);
int empleado_setHoras(Empleado* this, int horas);
int empleado_getHoras(Empleado* this, int* horas);
int empleado_setSueldo(Empleado* this, int sueldo);
int empleado_getSueldo(Empleado* this, int* sueldo);

#endif // EMPLEADO_H_INCLUDED
