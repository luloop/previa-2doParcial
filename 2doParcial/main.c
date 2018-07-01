#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "formatos.h"
#include "personas.h"


int main()
{
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

    listaPersonas=al_newArrayList();//llamo al constructor
    if (validaArrayList(listaPersonas)==0)
    {
        return 0;
    }
    do
    {
        seguir= formato_ABM_Archivo(listaPersonas);
    }
    while (seguir!=0);
    al_deleteArrayList(listaPersonas);
    return 0;

}
