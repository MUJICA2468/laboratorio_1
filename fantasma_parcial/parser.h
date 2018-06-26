#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"
int parser_loadFiles(char* path,ArrayList* pArrayList);
int parser_generateFile(char* path,ArrayList* pArrayList);
#endif // PARSER_H_INCLUDED
