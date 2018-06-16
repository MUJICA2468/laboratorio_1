#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "destinatario.h"
#include "parser.h"
ArrayList* generarListaBlanca(ArrayList* pArrayDestinatario,ArrayList* pArrayListaNegra);
int main()
{
    ArrayList* pArrayDestinatarios = al_newArrayList();
    ArrayList* pArrayListaNegra = al_newArrayList();
    ArrayList* pArrayListaBlanca;

    parserDestinatarios("destinatarios.csv",pArrayDestinatarios);
    parserDestinatarios("black_list.csv",pArrayListaNegra);


    pArrayListaBlanca = generarListaBlanca(pArrayDestinatarios,pArrayListaNegra);
    imprimir_lista(pArrayListaBlanca);

    return 0;
}


int esDestinatarioMail(Destinatario* destinatarioA,Destinatario* destinatarioB)
{
    char mailA[256];
    char mailB[256];
    destinatario_getMail(destinatarioA,mailA);
    destinatario_getMail(destinatarioB,mailB);
    if(!strcmp(mailA,mailB))
        return 1;
    else
        return 0;

}

ArrayList* generarListaBlanca(ArrayList* pArrayDestinatario,ArrayList* pArrayListaNegra)
{
    ArrayList* pArrayListaBlanca = al_newArrayList();
    Destinatario* auxDestinatarioBlack;
    auxDestinatarioBlack = al_get(pArrayListaNegra,0);
    int i,rta;
    for(i=0;i<al_len(pArrayDestinatario);i++)
    {
        rta = al_contains_entidad(pArrayListaNegra ,al_get(pArrayDestinatario,i), esDestinatarioMail);
        if(!rta)
            al_add(pArrayListaBlanca , al_get(pArrayDestinatario,i));
    }
    return pArrayListaBlanca ;

}


void imprimir_lista(ArrayList* pArray)
{
    int i;
    char nombre[256];
    char mail[256];

    Destinatario* auxDestinatario=NULL;
    for(i=0;i<al_len(pArray);i++)
    {
        auxDestinatario = al_get(pArray,i);
        destinatario_getNombre(auxDestinatario,nombre);
        destinatario_getMail(auxDestinatario,mail);
        printf("%s,%s\n",nombre,mail);
    }
}

