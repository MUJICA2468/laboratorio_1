typedef struct
{
    //char dni[50];
    char nombre[50];
    //char apellido[50];
    //char cuit[50];
    float altura;
    int id;
}Alumno;


Alumno* alumno_new();
void alumno_delete(Alumno* this);

int alumno_setNombre(Alumno* this, char* nombre);
int alumno_getNombre(Alumno* this, char* nombre);
int  alumno_setAltura(Alumno* this, float altura);
int alumno_getAltura(Alumno* this, float* altura);
int alumno_setId(Alumno* this, int id);
int alumno_getId(Alumno* this,int* id);
Alumno* alumno_newP(char* nombre,float altura,int id);
void arrayAlumno_add(Alumno* array[],int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit,float altura,int id);
Alumno* arrayAlumno_getById (Alumno* array[],int cantidad,int id);
int arrayAlumno_loadFromfile(Alumno* arrayPunterosAlumnos[], int* qytOcupada, int qytTotal, char* path);
int arrayAlumno_dumpFromfile(Alumno* arrayPunterosAlumnos[], int* qytOcupada, char* path);
