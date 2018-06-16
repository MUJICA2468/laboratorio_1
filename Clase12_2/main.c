#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

#define QTY 10
#define LEN_CONT    1000

int main()
{
    Pantalla pantallas[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;

    pantalla_init(pantallas,QTY);
    cont_init(contrataciones,LEN_CONT);

    pantalla_altaForzada(pantallas,QTY,"Wilde","Las Flores 50",50,0);
    pantalla_altaForzada(pantallas,QTY,"Avellaneda","Belgrano 250",2000,0);
    pantalla_altaForzada(pantallas,QTY,"Bernal","Cerrito 300",3000,0);
    pantalla_altaForzada(pantallas,QTY,"Quilmes","Lavalle 450",1000,1);
    pantalla_altaForzada(pantallas,QTY,"Berazategui","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,pantallas,QTY,0,"video.avi","20911911915",100);
    cont_altaForzada(contrataciones,LEN_CONT,pantallas,QTY,0,"video1.avi","20911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,pantallas,QTY,0,"video2.avi","30911911915",300);
    cont_altaForzada(contrataciones,LEN_CONT,pantallas,QTY,2,"video3.avi","30911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,pantallas,QTY,2,"video4.avi","40911911915",500);
    cont_altaForzada(contrataciones,LEN_CONT,pantallas,QTY,2,"video5.avi","40911911915",600);

    //informar_ConsultaFacturacion(contrataciones,LEN_CONT,pantallas,QTY,"20911911915");
    informar_ListarContrataciones(contrataciones,LEN_CONT,pantallas,QTY);
    //informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,pantallas,QTY);


    do
    {
        getValidInt("\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n8.Listar pantalla 'nombre y precio'\n9.Listar pantallas cuyo precio es menor a 1000\n10.Listar pantallas con mayor publicaciones\n15.Salir\n","\nNo valida\n",&menu,1,10,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(pantallas,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(pantallas,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(pantallas,QTY,auxiliarId);
                break;
            case 4:
                pantalla_mostrar(pantallas,QTY);
                cont_mostrar(contrataciones,LEN_CONT);
                break;
            case 5:
                cont_ordenarCuit(contrataciones,LEN_CONT,0);
                pantalla_ordenar(pantallas,QTY,0);
                break;
            case 6:
                pantalla_mostrarDebug(pantallas,QTY);

                break;
            case 7:
                cont_alta(contrataciones,LEN_CONT,pantallas,QTY);
                break;
            case 8:
                informar_ListarPantallas(pantallas, QTY);
                break;
            case 9:
                informar_ListarPantallasValorMenorPrecio(pantallas, QTY);
                break;
            case 10:
                informar_ListarPantallasMayorPublicacion(pantallas, QTY, contrataciones);
                break;
        }

    }while(menu != 10);

    return 0;
}
