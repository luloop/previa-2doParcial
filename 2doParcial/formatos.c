
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "personas.h"
#include "archivos.h"
#include "lib.h"

int  formato_ABM_Archivo(ArrayList *this, FILE *parchivo, char textoABM[])
{
    int i;
    int opcion;
    int opcion2;
    int auxflag=0;
    int flagArchivo=0;
    int auxArchivo;
    char nombreArchivo [20];
    Employee aux;


    do
    {
        printf("\n\n\t 1- Alta\n\t 2- Baja \n\t 3- Modificacion \n\t 4- Listar\n\t 5- Leer de Archivo\n\t 6- Guardar en Archivo\n\t 0- Salir\tSeleccione la opcion: \t");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            ingresarTexto(aux.name, 20, "\nNombre:");
            ingresarTexto(aux.lastName, 20, "\nApellido:");
            ingresarTexto(aux.dni, 20, "\nDNI:");

           Employee*pAux= persona_newPersona(5000,aux.name, aux.lastName, 6000, 0);
           if (pAux!=NULL)
           {
               al_add(this, pAux);
           }
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
            parserCSV(parchivo, this, textoABM);
            cleanScreen();
            break;

        case 6:
           ingresarTexto(nombreArchivo, 19, "Ingrese el nombre de su Archivo a Guardar:");
            do
            {
                // el archivo lo genera, todavia no copia nada
            opcion2=menuTipoArchivoGuardar(this, parchivo,nombreArchivo, this->len(this));
            } while (opcion2 !=0);
            break;
        default:
            fflush(stdin);
            break;
        }

        }while (opcion !=0);
}




int menuTipoArchivoGuardar ( ArrayList*this, FILE* parchivo, char nombreArchivo[], int cantidad)
{
    int flagArchivo;
    int opcion2;

    if(this!=NULL && parchivo!=NULL)
    {
            printf( "\n\n\t 1- .csv\n"
                        "\t 2- .bin\n"
                        "\t 3- .data\n"
                        "\t 4- .doc\n"
                        "\t 5- .html\n"
                        "\t 0- Salir\tSeleccione la opcion: \t ");
                scanf("%d", &opcion2);

                switch(opcion2)
                {

                case 1:
                    strcat(nombreArchivo, ".csv");
                    flagArchivo=guardarEnArchivo(this,cantidad, parchivo,nombreArchivo);
                    if (flagArchivo!=0)
                    {
                        printf("\n COPIA EXITOSA %d Elementos\n", flagArchivo);
                    }
                    else
                    {
                        printf("\n no se pudo copiar el archivo\n");
                    }
                    cleanScreen();
                    break;

                 case 4:
                    strcat(nombreArchivo, ".doc");
                    flagArchivo=guardarEnArchivo(this,cantidad, parchivo,nombreArchivo);
                    if (flagArchivo!=0)
                    {
                        printf("\n COPIA EXITOSA %d Elementos\n", flagArchivo);
                    }
                    else
                    {
                        printf("\n no se pudo copiar el archivo\n");
                    }
                    cleanScreen();
                    break;

                case 0:
                    opcion2=0;
                    break;
                default:
                    fflush(stdin);
                    printf("no ha ingresado una opcion valida");
                    printf("\n");
                    system ("cls");
                    break;
                }
    }
    else
        {
        return 0;
        }

    }


int menuTipoArchivoAbrir( ArrayList*this, FILE* parchivo, char nombreArchivo[])
{
    int flagArchivo;
    int opcion2;
                printf( "\n\n\t 1- .csv\n"
                        "\t 2- .bin \n"
                        "\t 3- .data \n"
                        "\t 4- .doc\n"
                        "\t 0- Salir\tSeleccione la opcion: \t ");
                scanf("%d", &opcion2);

                switch(opcion2)
                {
                case 1:
                    //COPI DE ARCHIVO- paso el puntero a empleado y puntero arraylist
                    strcat(nombreArchivo, ".csv");
                    flagArchivo=parserCSV(parchivo, this, nombreArchivo);
                    if (flagArchivo==0)
                    {
                        printf("\n COPIA EXITOSA\n");
                    }
                    else
                    {
                        printf("\n no se pudo copiar el archivo\n");
                    }
                    cleanScreen();
                    break;

                case 6:

                    cleanScreen();
                    break;
                case 0:
                    opcion2=0;
                    break;
                default:
                    fflush(stdin);
                    printf("no ha ingresado una opcion valida");
                    printf("\n");
                    system ("cls");
                    break;
                }

    }
