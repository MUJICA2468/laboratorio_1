#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
typedef struct
{
    int cantidad;
    char nombre[50];
    char email[50];
    char descripcion[128];
    float precio;
    char categoria;
    int id;
    int prueba;
}Cliente;

Cliente* cliente_new();
void cliente_delete();

int cliente_setCantidad(Cliente* this,int cantidad);
int cliente_getCantidad(Cliente* this,int* cantidad);

int cliente_setNombre(Cliente* this,char* nombre);
int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setDescripcion(Cliente* this,char* descripcion);
int cliente_getDescripcion(Cliente* this,char* descripcion);

int cliente_setPrecio(Cliente* this,float precio);
int cliente_getPrecio(Cliente* this,float* precio);

int cliente_setCategoria(Cliente* this,char categoria);
int cliente_getCategoria(Cliente* this,char* categoria);

int cliente_setId(Cliente* this,int id);
int cliente_getId(Cliente* this,int* id);

int cliente_setPrueba(Cliente* this,int prueba);
int cliente_getPrueba(Cliente* this,int* prueba);

int cliente_setEmail(Cliente* this, char* email);
int cliente_getEmail(Cliente* this, char* email);

#endif // cliente_H_INCLUDED
