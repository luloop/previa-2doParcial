#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "formatos.h"

int main()
{
    FILE*pArchivo;
    Employee *listaPersonas;
    Employee *personas;

    int len=0;
    int i;
    int seguir=1;
    int opcion;
    char salir;
    int flagOrdenar=-1;
    int flagAgregar=-1;
    int* auxiliar;

    listaPersonas=al_newArrayList()//llamo al constructor
    if (validaArrayList(listaPersonas)==0)
        {
            return 0;
        }

    do
    {
     seguir= formato_ABM(listaPersonas, pArchivo)





    }while (seguir!=0)












}
