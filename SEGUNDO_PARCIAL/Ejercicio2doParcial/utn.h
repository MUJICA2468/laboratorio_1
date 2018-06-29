#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

//GETS
int getIntA(char* mensaje, char* mensajeError, int contadorIntentos, int numeroMax, int numeroMin, int* resultado);
int getIntB(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado);
int getFloatA(char* mensaje,char* mensajeError,float reIntentos,float minimo,float maximo,float* resultado);
int getInt(char* mensaje);
float getFloatB(char* mensaje);
char getChar(char* mensaje);
char getNumeroAleatorio(int desde , int hasta, int iniciar);
int getString(char* mensaje,char* input);
int getStringLetras(char* mensaje,char* input);
int getStringNumeros(char* mensaje,char* input);
int getStringNumerosFlotantes(char* mensaje,char* input);
int getValidString(char* requestMessage,char* errorMessage, char* errorMessageLenght,char* input, int maxLenght,int attemps);
int getValidInt(char* requestMessage,char* errorMessage, int* input,int lowLimit, int hiLimit,int attemps);
int getValidFloat(char* requestMessage,char* errorMessage, float* input,float lowLimit, float hiLimit,int attemps);
int getValidCuit(char* requestMessage,char* errorMessage, char* errorMessageLenght,char* input,int minLength, int maxLenght,int attemps);
int getValidUrl(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);
int getValidDNI(char *str, char *mensaje, char *error, int intentos);
//***************************************************
//CALCULO
int suma(int numeroUno, int numeroDos);
int resta(int numeroUno, int numeroDos);
int dividir(int numeroUno, int numeroDos);
int multiplicacion(int numeroUno, int numeroDos);
float calculo(int numeroUno, int numeroDos, char operacion);
//***************************************************
//VALIDS
int isValidEntero(char *str);
float isValidFlotante(char* mensaje);
int isValidNumerico(char *str) ;
int isValidTelefono(char *str);
int isValidAlfaNumerico(char *str);
int isValidSoloLetras(char *str);
int isValidNumericoFlotante(char* str);
int isValidDNI(char *str);
int isValidUrl(char *url);
//***************************************************
//Privates funtions
void clearStdin(void);
void pause(void);
void clearScreen(void);

#endif // UTN_H_INCLUDED

