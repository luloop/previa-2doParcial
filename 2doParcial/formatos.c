
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "personas.h"
#include "archivos.h"
#include "lib.h"

int  formato_ABM_Archivo(ArrayList *this, char textoABM[])
{
    int i;
    int opcion;
    int opcion2;
    int auxflag=0;
    int flagArchivo=0;
    int auxArchivo;
    char nombreArchivo [20];
    Employee aux;
    int auxiliaNumero;
    int*auxNum;
    Employee*pAux;
    int aux15;
    int aux_Baja;


    do
    {
        printf("\r\n\r\n********************************************************************\r\n");
        printf("******    MENU ABM GENERICO CON ARCHIVO TEXTO Y BINARIO  ************\r\n");
        printf("********************************************************************\r");
        printf("\n\t 1- Alta\n\t 2- Baja \n\t 3- Ordenar \n\t 4- Listar\n\t 5- Leer de Archivo\n\t "
               "6- Guardar en Archivo\n\t 0- Salir\tSeleccione la opcion: \t");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:///////////////////ALTA
            do
            {
                printf("\n--------------Ingreso de nuevo-----------------------\n");
                ingresarTexto(aux.name, 20, "Nombre:");
                ingresarTexto(aux.lastName, 20, "Apellido:");
                ingresarTexto(aux.dni, 20, "DNI:");
                aux.id=ingresarInt("ID", 0, 1500);
                aux.legajo=ingresarInt("Legajo", 0, 5000);
                printf("\n-------------------------------------\n");
                pAux= persona_newPersona(aux.id,aux.name, aux.lastName,aux.legajo,aux.legajo, aux.dni);
                if (pAux!=NULL)
                {
                    al_add(this, pAux);
                    persona_printPersona(pAux);
                }
            }
            while(preguntarSiNo("\nDesea cargar otra persona?\n"));
            cleanScreen();
            break;
        case 2:///////////////BAJA
            formato_baja (this);
            cleanScreen();
            break;
        case 3: ////////////ORDENAR
           formato_OrdenarDNI(this);
           cleanScreen();
            break;
        case 4:
            formato_listadoPersonas(this);
            cleanScreen();
            break;
        case 5:
            formato_leerArchivo(this);
            cleanScreen();
            break;

        case 6:
            do
            {
                opcion2=menuTipoArchivoGuardar(this);
            }
            while (opcion2 !=0);
            cleanScreen();
            break;
    case 0:
        printf("\r\n\r\n*********************************************\r\n");
        printf("******        CHAU       ************\r\n");
        printf("************************************************\r");
        cleanScreen();
        break;

        default:
            fflush(stdin);
            printf("\nNO INGRESO UNA OPCION VALIDA\n");
            cleanScreen();
            break;
        }

    }
    while (opcion !=0);
}



/** \brief MENU DE GUARDADO TEXTO Y BINARIO,
texto pide nombre, binario pone data.bin
 *
 * \param Array list
 * \return
 *
 */

int menuTipoArchivoGuardar ( ArrayList*this)
{
    int flagArchivo;
    int opcion2;
    char nombreArchivo[25];

    if(this!=NULL)
    {
        printf( "\n\n\t 1- .csv\n"
                "\t 2- .bin\n"
                "\t 3- .doc\n"
                "\t 0- Salir\tSeleccione la opcion: \t ");
        scanf("%d", &opcion2);

        switch(opcion2)
        {
        case 1:
            ingresarTexto(nombreArchivo, 19, "\n-------------------------------------\n Ingrese el nombre de su Archivo a Guardar:");
            strcat(nombreArchivo, ".csv");
            flagArchivo=archivos_guardarTexto(this,nombreArchivo);
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;
        case 2:
            flagArchivo=archivos_guardarBinario(this);
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;
        case 3:
            ingresarTexto(nombreArchivo, 19, "Ingrese el nombre de su Archivo a Guardar:");
            strcat(nombreArchivo, ".doc");
            flagArchivo=archivos_guardarTexto(this,nombreArchivo);
            formato_respuestaFlagArchivo(flagArchivo);
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
         //archivos_guardarMaxIdDOC(this);
    }
    else
    {
        return 0;
    }

}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int menuTipoArchivoAbrir ( ArrayList*this)
{
    int flagArchivo;
    int opcion2;

    if(this!=NULL)
    {
        printf( "\n\n\t 1- .texto\n"
                "\t 2- binario\n"
                "\t 0- Salir\t   Seleccione la opcion: \t ");
        scanf("%d", &opcion2);

        switch(opcion2)
        {
        case 1:
            flagArchivo=parserCSV(this, "l");
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;
        case 2:
            flagArchivo=archivos_leer(this);
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;

        case 4:
            flagArchivo=archivos_leer(this);
            formato_respuestaFlagArchivo(flagArchivo);
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


void formato_respuestaFlagArchivo(int flagArchivo)
{
    if (flagArchivo>0)
    {
        printf("\n-------------------------------\n");
        printf("\nCOPIA EXITOSA DE %d DATOS\n", flagArchivo);
        printf("\n-------------------------------\n");
    }
    else
    {
        printf("\n-------------------------------\n");
        printf("\nNO SE PUDO COPIAR EL ARCHIVO\n");
        printf("\n-------------------------------\n");
    }

}


void formato_listadoPersonas (ArrayList *this)
{
    int i;
    Employee*pAux;
     if(this->len(this)>0)
            {
                printf("\r\n\r\n********************************************************************\r\n");
                printf("***********    Elementos: %d   ************\r\n",al_len(this));
                printf("********************************************************************\r\n");
                printf("**|  ID  |       Nombre       |      Apellido      |       DNI        |**\r\n");

                for (i=0; i<al_len(this); i++ )
                {
                    //casteo a una estructura  COPIO LA DIRECCION DE MEMORIA DE LA INFO QUE QUIERO
                    pAux=(Employee*)al_get(this,i);
                    printf("**|  %3d |      %8s      |      %8s      |     %10s   |**\r\n", persona_getId(pAux),persona_getNombre(pAux),persona_getApellido(pAux),persona_getDni(pAux));

                    if (i%100==0 &&i!=0)// CONVERTIR ESTO EN FUNCION
                    {
                        printf("\n\n");
                        system("pause");
                    }
                }
            }
            else
            {
                printf("\r\n\r\n********************************************************************\r\n");
                printf("***********    NO HAY ELEMENTOS CARGADOS - Elementos: %d   ************\r\n",al_len(this));
                printf("********************************************************************\r\n");
            }

}


void formato_OrdenarNombre(ArrayList *this)
{
    if(this->len(this)>1)
            {
                printf("\n-------------------------------------\n");
                al_sort(this, persona_compareName, (ingresarInt("Que orden prefiere?\n 1- A-Z\n 0- Z-A       :", 0, 1)));
                printf("\r\n\r\n********************************************************************\r\n");
                printf("***********    ORDEN REALIZADO - Elementos: %d   ************\r\n",al_len(this));
                printf("********************************************************************\r\n");
            }
            else
            {
                printf("\r\n\r\n********************************************************************\r\n");
                printf("***********    NO HAY ELEMENTOS SUFICIENTES - Elementos: %d   ************\r\n",al_len(this));
                printf("********************************************************************\r\n");
            }
}



void formato_OrdenarDNI(ArrayList *this)
{
    if(this->len(this)>1)
            {
                printf("\n-------------------------------------\n");
                al_sort(this, persona_compareDNI, (ingresarInt("Que orden prefiere?\n 1- 0-9\n 0- 9-0       :", 0, 1)));
                printf("\r\n\r\n********************************************************************\r\n");
                printf("***********    ORDEN REALIZADO - Elementos: %d   ************\r\n",al_len(this));
                printf("********************************************************************\r\n");
            }
            else
            {
                printf("\r\n\r\n********************************************************************\r\n");
                printf("***********    NO HAY ELEMENTOS SUFICIENTES - Elementos: %d   ************\r\n",al_len(this));
                printf("********************************************************************\r\n");
            }
}


void formato_baja (ArrayList*this)
{
    int aux_Baja;

            if(this->len(this)>0)
            {
                printf("\n-------------------------------------\n");
                aux_Baja=ingresarInt("Que numero de indice desea dar de baja?", 0, al_len(this));
                al_remove(this, (aux_Baja-1));
            }
            else
            {
                printf("\r\n\r\n********************************************************************\r\n");
                printf("***********    NO HAY ELEMENTOS CARGADOS - Elementos: %d   ************\r\n",al_len(this));
                printf("********************************************************************\r\n");
            }
}


void formato_leerArchivo(ArrayList*this)
{
    int aux15;
    int flagArchivo=0;

        printf("\n\t 1- CSV\n\t 2- BInario \n\t\tSeleccione la opcion: \t");
        scanf("%d", &aux15);
        switch (aux15)
        {
        case 1:
            flagArchivo=parserCSV(this, "data.csv");
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;
        case 2:
            flagArchivo=archivos_leer(this);
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;
        default:
            printf("\nNO INGRESO UNA OPCION VALIDA\n");
            fflush(stdin);
            cleanScreen();
            break;

        }
}
