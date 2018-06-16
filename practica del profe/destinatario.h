#ifndef DESTINATARIO_H_INCLUDED
#define DESTINATARIO_H_INCLUDED
typedef struct
{
    char nombre[256];
    char mail[256];
}Destinatario;

Destinatario* destinatario_new();
void destinatario_delete();

int destinatario_setNombre(Destinatario* this,char* nombre);
int destinatario_getNombre(Destinatario* this,char* nombre);

int destinatario_setMail(Destinatario* this,char* mail);
int destinatario_getMail(Destinatario* this,char* mail);

#endif // DESTINATARIO_H_INCLUDED
