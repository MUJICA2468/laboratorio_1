#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include "parser.h"

ArrayList* generarListaBlanca(Cliente* pArrayDestinatario, Cliente* pArrayBlackList);

int main()
{
    ArrayList* lDestinatarios = al_newArrayList();
    ArrayList* lNegra = al_newArrayList();
    ArrayList* lBlacnca;
    parser_newParserBlackList("destinatarios.csv",lDestinatarios);
    parser_newParserBlackList("black_list.csv",lNegra);

    generarListaBlanca(lDestinatarios, lNegra);
    return 0;
}

int esDestinatario(Cliente* destinatarioA, Cliente* destinatarioB)
{
    char mailA[150];
    char mailB[150];
    cliente_getEmail(destinatarioA, mailA);
    cliente_getEmail(destinatarioB, mailB);

    if(!strcmp(mailA, mailB))
    {
        return 1;
    }else
    {
        return 0;
    }
}

ArrayList* generarListaBlanca(Cliente* pArrayDestinatario, Cliente* pArrayBlackList)
{
    //lo que hago es clonar pero a la vez filtro determinados usuarios.

    int i;
    ArrayList* pArrayWhiteList = al_newArrayList();
    Cliente* auxClienteBlack;
    auxClienteBlack = al_get(pArrayBlackList,0);
    for(i=0;i<al_len(pArrayDestinatario);i++)
    {
        int rta = al_contains_entidad(pArrayDestinatario, auxClienteBlack, esDestinatario);
        if(rta)
            al_add(pArrayWhiteList, al_get(pArrayDestinatario, i));

    }

    return pArrayWhiteList;
}
