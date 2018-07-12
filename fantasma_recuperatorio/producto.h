#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
typedef struct{

    char string[50];
    int numero;
    int idProducto;
}Producto;

Producto* producto_new();
Producto* producto_newParametros(char* string,int numeros,int idProducto);
int producto_getParametros(Producto* this,char* string,int* numeros,int* idProducto);
int producto_setString(Producto* this,char* string);
int producto_getString(Producto* this,char* string);
int producto_setInt(Producto* this,int numero);
int producto_getInt(Producto* this,int* numero);
int producto_setId(Producto* this,int id);
int producto_getId(Producto* this,int* id);
#endif // PRODUCTO_H_INCLUDED
