#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{

    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
}Cliente;

Cliente* cliente_newArrayCliente();
Cliente* cliente_newClienteUp(char* id, char* nombre,char* horas);
int cliente_setNombre(Cliente* this, char* nombre);
int cliente_getNombre(Cliente* this, char* nombre);
int cliente_setSueldo(Cliente* this, int sueldo);
int cliente_getSueldo(Cliente* this, int* sueldo);
int cliente_setHoras(Cliente* this, int horas);
int cliente_getHoras(Cliente* this, int* horas);
int cliente_getId(Cliente* this, int* id);
int cliente_calcularSueldo(void* this);

#endif // CLIENTE_H_INCLUDED
