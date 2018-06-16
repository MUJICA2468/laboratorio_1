#include "destinatario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Destinatario* destinatario_new()
{
    Destinatario* this;
    this=malloc(sizeof(Destinatario));
    return this;
}

void destinatario_delete(Destinatario* this)
{
    free(this);
}

int destinatario_setNombre(Destinatario* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int destinatario_getNombre(Destinatario* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int destinatario_setMail(Destinatario* this,char* mail)
{
    int retorno=-1;
    if(this!=NULL && mail!=NULL)
    {
        strcpy(this->mail,mail);
        retorno=0;
    }
    return retorno;
}

int destinatario_getMail(Destinatario* this,char* mail)
{
    int retorno=-1;
    if(this!=NULL && mail!=NULL)
    {
        strcpy(mail,this->mail);
        retorno=0;
    }
    return retorno;
}

