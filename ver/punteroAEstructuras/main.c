#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int datoInt;
    char datoChar;
}eDato;



int main()
{
    //////////////////estructura simple

    /*
    eDato miDato = {1 , 'c'};
    eDato *pDato=NULL;

    pDato=&miDato;


     printf(" \n Tamanio del puntero %d", sizeof(pDato));
     printf(" \n Tamanio del eDato %d", sizeof(eDato));
     printf(" \n %d -- %c", pDato->datoInt  , pDato->datoChar);//muy complicada

    */










//////////////////Array de estuctura



    eDato miDato = {1 , 'c'};
    eDato miDato2 = {2 , 'A'};
    eDato* pDato= NULL;
    eDato lista [2];

    int i;
    lista [0]=miDato;
    lista [1]=miDato2;

    pDato=lista;
     for (i=0; i<2; i++)

     {
       // printf(" \n %d -- %c", lista[i].datoInt, lista [i].datoChar);
        printf(" \n %d -- %c", (pDato+i)->datoInt  , (pDato+i)->datoChar);//muy complicada
        printf(" \n %d -- %c", pDato[i].datoInt  , pDato[i].datoChar);
     }






    return 0;
}
