#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct{
    char nombre[50];
    int edad;
    //---------------
    int idAlumno;
    int isEmpty;
}Alumno;
#endif // PERSONA_H_INCLUDED
int alumno_init(Alumno* arrayAlumno, int cant);
void mostrar(Alumno *arrayAlumno, int cant);
void func(Alumno *arrayAlumno, int cant);
Alumno*alumno_new( );
void alumno_delete(Alumno* this);
int alumno_setEdad(Alumno* this, int edad);
int alumno_getEdad(Alumno* this, int *edad);
void cargar(Alumno *arrayAlumno, int cant);
void mostrar2(Alumno *arrayAlumno, int cant);
