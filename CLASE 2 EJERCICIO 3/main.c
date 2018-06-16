#include <stdio.h>
#include <stdlib.h>
#define cantidad 10

int main()
{
    char caracteres;
    char validacion;
    int contador;
    int acumuladorLetraA;
    int acumuladorLetraE;
    int acumuladorLetraI;
    int acumuladorLetraO;
    int acumuladorLetraU;

    contador = 0;

    acumuladorLetraA = 0;
    acumuladorLetraE = 0;
    acumuladorLetraI = 0;
    acumuladorLetraO = 0;
    acumuladorLetraU = 0;



    while(contador < cantidad){

        contador++;

        printf("Ingrese caracter \n");
        fflush(stdin);
        scanf("%c", &caracteres);



        /*
        if(caracteres == 'a'){

            acumuladorLetraA++;

        }
        else{
            if(caracteres == 'e'){

               acumuladorLetraE++;

            }
            else{
                if(caracteres == 'i'){

                    acumuladorLetraI++;

                }
                else{
                    if(caracteres == 'o'){

                        acumuladorLetraO++;
                    }
                    else{
                        if(caracteres == 'u'){

                            acumuladorLetraU++;

                        }
                    }
                }
            }
        }
        */

        // o... sino

        switch(caracteres){

        case 'a':
        acumuladorLetraA++;
        break;
        case 'e':
        acumuladorLetraE++;
        break;
        case 'i':
        acumuladorLetraI++;
        break;
        case 'o':
        acumuladorLetraO++;
        break;
        case 'u':
        acumuladorLetraU++;
        }



    }

    printf("Letras a \n\ %d, Letras e \n\ %d, Letras i \n\ %d, Letras o \n\ %d, Letras u \n\ %d", acumuladorLetraA, acumuladorLetraE, acumuladorLetraI, acumuladorLetraO, acumuladorLetraU); //revisar la impresion

    return 0;
}
