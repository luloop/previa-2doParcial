#include <stdio.h>
#include <stdlib.h>

#include "Dato.h"

typedef struct
{
    int id;
    char nombre [50];
    float sueldo;

} eDatoss;



eDatoss* newDato();
eDatoss* neweDatoParametros ( int, char*, float);


//int pedirEspacioMemoria (eDato*a );

int main()
{
    eDatoss* d;
    eDatoss* otroDato;
/*
   d=newDato();
    if (d!=NULL)
        {
        eDato_set_a(d,1800);
        eDato_set_b(d,"hola");
        printf("%d--%s", eDato_get_a(d),eDato_get_b(d));
        }
*/
     otroDato= neweDatoParametros(14,'pedro', 5000);
    if (otroDato!=NULL)
     {
         printf("%d----%s----%f", otroDato->id, otroDato->nombre, otroDato->sueldo);
     }

    return 0;
}

eDatoss* newDato ()
{
    eDatoss*miDato;
    miDato=(eDatoss*)malloc(sizeof(eDatoss));
    return miDato;
}

eDatoss* neweDatoParametros ( int id, char* nombre, float sueldo)
{
    eDatoss*miDato;
    miDato= newDato();
    if (miDato!= NULL)
    {
        miDato->id=id;
        strcpy (miDato->nombre,nombre);
        miDato->sueldo=sueldo;
    }

    return miDato;

}
/*
int pedirEspacioMemoria(eDato* this )
{
    this=(eDato*)malloc(sizeof(eDato));
}*/
