#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "ArrayList.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados);
int generarArchivoFiltrado(char* path,ArrayList* pArrayList);
#endif // PARSER_H_INCLUDED
