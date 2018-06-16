#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char nombre[50];
    char apellido[50];
    //----------------
    int id;
    int isEmpty;
}Funciones;
/** \brief Se pueden ingresar numeros enteros
 *
 * \param mensaje char* Es el mensaje que se muestra para pedir el ingreso de datos
 * \param mensajeError char* Es el mensaje que se muestra si los datos son invalidos
 * \param reIntentos int Cantidad de intentos de ingreso
 * \param minimo int cantidad de numeros minima
 * \param maximo int cantidad de numeros maxima
 * \param resultado int* la variavle que se pretende validar para la carga de datos
 * \return int retorno de los ingresado
 *
 */
int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado);
/** \brief valida numeros enteros
 *
 * \param str char*
 * \return int Retorna un valor que valida el if
 *
 */
int esEntero(char *str);
/** \brief Valida el ingreso de strings
 *
 * \param mensaje[] char se introduce un mensaje
 * \param imput[] char se introduce el dato
 * \return int retorna un valor que valida
 *
 */
int getString(char mensaje[], char imput[]);
/** \brief Valida la letras mayusculas y las minusculas
 *
 * \param str[] char
 * \return int retorna un valor que valida
 *
 */
int esLetras(char str[]);
/** \brief Se puede introducir cadenas de caracteres
 *
 * \param mensaje[] char mensaje para indicar  que colocar
 * \param cant int limite del array
 * \param imput[] char se coloca la array para guardar los datos cargador
 * \return int
 *
 */
int getStringLetras(char mensaje[], int cant, char imput[]);
/** \brief Realiza la apertura de espacios dentro del array
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int funciones_init(Funciones* arrayFunciones, int cant);
/** \brief Se obtiene el espacio libre dentro del array
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant int limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int funciones_buscarLibre(Funciones* arrayFunciones, int cant);
/** \brief Asigna un ID a cada conbinacion de datos cargados
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant  limite del array
 * \return int retorna los espacios libre de la array
 *
 */
int funciones_proximoId(Funciones* arrayFunciones, int cant);
/** \brief Busca el la array en busca de un espacio ocupado por el dni
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant int limite del array
 * \param dni int Identificador de la persona
 * \return int retorna el dni a buscar
 *
 */
int funciones_buscarPorId(Funciones* arrayFunciones, int cant,int id);
//----------------------------------------------------------------
/** \brief Carga los datos de una persona
 *
 * \param arrayFunciones Funciones* llama a la estructura
 * \param cant int limite del array
 * \return int retorna un valor negativo
 *
 */
int funciones_alta(Funciones* arrayFunciones, int cant);
/** \brief Da de baja el dni de una persona, por lo tanto lo borra
 *
 * \param variable para cargar la llamada a la funcion de busqueda del dni
 * \param
 * \return retorno 0
 *
 */
int funciones_baja(Funciones* arrayFunciones, int cant, int id);
/** \brief Modifica los datos cargados
 *
 * \param arrayFunciones Funciones* se llama a la estructura
 * \param cant int limite del array
 * \param id int se ingresa el id de la publicacion para dar de baja estos datos
 * \return int retorna un valor negativo
 *
 */
int funciones_modificar(Funciones* arrayFunciones, int cant, int id);
/** \brief Ordena alfabeticamente los nombres
 *
 * \param arrayFunciones Funciones* llama a la estructura
 * \param cant int limite del array
 * \param orden int ordena
 * \return int retorna un valor negativo
 *
 */
int funciones_ordenar(Funciones* arrayFunciones,int cant, int orden);
#endif // FUNCIONES_H_INCLUDED
/*
int getInt(char* mensaje, char* mensajeError, int intentos, int minimo, int maximo, int* resultado);
int esEntero(char str[]);
int getString(char mensaje[], char imput[]);
int esLetras(char str[]);
int getStringLetras(char mensaje[], int cant,char imput[]);
int funciones_init(Funciones* arrayFunciones, int cant);
int funciones_buscarLibre(Funciones* arrayFunciones, int cant);
int funciones_proximoId(Funciones* arrayFunciones, int cant);
int funciones_buscarPorId(Funciones* arrayFunciones, int cant, int id);
//----------------------------------------------------------------------
int funciones_alta(Funciones* arrayFunciones, int cant);
int funciones_baja(Funciones* arrayFunciones, int cant, int id);
int funciones_modificar(Funciones* arrayFunciones, int cant, int id);
int funciones_ordenar(Funciones* arrayFunciones, int cant, int orden);
*/

