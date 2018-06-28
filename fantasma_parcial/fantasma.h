#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED
typedef struct{
    char name[50];
    char lastName[50];
    char dni[50];
    //************
    int horasTrabajadas;
    int sueldo;
    int idFantasma;
}Fantasma;

Fantasma* fantasma_new();
Fantasma* fantasma_newParametros(int id,char* name,char* lastName,char* dni);
int fantasma_alta(ArrayList* pArrayList);
int fantasma_modificar(ArrayList* pArrayList, int id);
int fantasma_baja(ArrayList* pArrayList,int id);
int fantasma_ordenar(void* lastNameA,void* lastNameB);
int fantasma_listar(ArrayList* pArrayList);
int fantasma_setParametros(char* name,char* lastName,char* dni);
int fantasma_getParametros(Fantasma* auxCliente,int* id,char* name,char* lastName,char* dni);
int fantasma_getId(Fantasma* this,int* id);
int fantasma_setName(Fantasma* this,char* name);
int fantasma_getName(Fantasma* this,char* name);
int fantasma_setLastName(Fantasma* this,char* lastName);
int fantasma_getLastName(Fantasma* this,char* lastName);
int fantasma_setDni(Fantasma* this,char* dni);
int fantasma_getDni(Fantasma* this,char* dni);
int fantasma_setHoras(Fantasma* this, int horas);
int fantasma_getHoras(Fantasma* this, int* horas);
int fantasma_setSueldo(Fantasma* this, int sueldo);
int fantasma_getSueldo(Fantasma* this, int* sueldo);

#endif // FANTASMA_H_INCLUDED
