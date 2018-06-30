
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "personas.h"
#include "archivos.h"
#include "lib.h"

int  formato_ABM(ArrayList this, FILE *parchivo)
{
    int i;
    int opcion;
    int auxflag=0;
    Employee*personas;

do{

    printf( "\n\n\t 1- Alta\n"
            "\t 2- Baja \n"
            "\t 3- Modificacion \n"
            "\t 4- Listar\n"
            "\t 5- Leer de Archivo\n"
            "\t 6- Guardar en Archivo\n"
            "\t 0- Salir\tSeleccione la opcion: \t ");

    scanf("%d", &opcion);
    switch (opcion)
                {
                    case 1:


                        cleanScreen();
                        break;
                   case 2:


                        cleanScreen();
                        break;
                    case 3:


                        cleanScreen();
                        break;
                   case 4:

                        cleanScreen();
                        break;
                    case 5:


                        cleanScreen();
                        break;
                    case 6:

                        cleanScreen();
                        break;
                     case 0:
                        return 0;
                        break;
                    default:
                        printf("no ha ingresado una opcion valida");
                        printf("\n");
                        system ("cls");
                        break;
                }
 }while (opcion !=0);



}
