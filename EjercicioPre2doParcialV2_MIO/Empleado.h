#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

int em_calcularSueldo(void* this);
Empleado* empleado_newArrayEmpleado();
Empleado* empleado_newEmpleadoUp(char* id, char* nombre,char* horas);
//----------------------------------------------
int empleado_setNombre(Empleado* this, char* nombre);
int empleado_getNombre(Empleado* this, char* nombre);
int empleado_setSueldo(Empleado* this, int sueldo);
int empleado_getSueldo(Empleado* this, int* sueldo);
int empleado_setHoras(Empleado* this, int horas);
int empleado_getHoras(Empleado* this, int* horas);
int empleado_getId(Empleado* this, int* id);

#endif // EMPLEADO_H_INCLUDED
