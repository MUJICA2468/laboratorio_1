#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

#define QTY 10 //pantalla
#define LEN_CONT    1000 //contratacio

int main()
{
    Pantalla array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;
    //char cuit[QTY][LEN_CONT];

    pantalla_init(array,QTY);
    cont_init(contrataciones,LEN_CONT);

    pantalla_altaForzada(array,QTY,"Wilde","Las Flores 50",50,0);
    pantalla_altaForzada(array,QTY,"Avellaneda","Belgrano 250",2000,0);
    pantalla_altaForzada(array,QTY,"Bernal","Cerrito 300",3000,0);
    pantalla_altaForzada(array,QTY,"Quilmes","Lavalle 450",1000,1);
    pantalla_altaForzada(array,QTY,"Berazategui","Mitre 150",5000,1);


    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video.avi","20911911915",100);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video1.avi","20911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video2.avi","30911911915",300);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video3.avi","30911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video4.avi","40911911915",500);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video5.avi","40911911915",600);



    informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");
    //informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);
    //informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);


    do
    {
        getValidInt("\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n8.Informar CONTRATACION\n9.Listar importe a pagar por contratacion\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                pantalla_mostrar(array,QTY);
                cont_mostrar(contrataciones,LEN_CONT);
                break;
            case 5:
                cont_ordenarCuit(contrataciones,LEN_CONT,0);
                pantalla_ordenar(array,QTY,0);
                break;
            case 6:
                pantalla_mostrarDebug(array,QTY);

                break;
            case 7:
                cont_alta(contrataciones,LEN_CONT,array,QTY);
                break;
            case 8:
                informar_ListarContrataciones(contrataciones, QTY, array, 0);
                break;
            case 9:
                informar_ConsultaFacturacion(contrataciones, QTY, array, LEN_CONT, "3243432");
                break;
        }

    }while(menu != 11);

    return 0;
}
