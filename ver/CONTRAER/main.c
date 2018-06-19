#include <stdio.h>
#include <stdlib.h>
#define CANTVECTOR 20

    int main()
{
    int* vector;
    int* auxVector;
    int i;
    int contador;

vector=malloc(sizeof(int)*CANTVECTOR);
if(vector!=NULL)
  {
    for (i=0; i<CANTVECTOR; i++)
        {
        *(vector+i)=i+1;
        }

printf("\n\n MALLOC\n");
for (i=0; i<CANTVECTOR; i++)
    {
    printf("%d\n", *(vector+i));
    }



    contador= contraer(vector,10, CANTVECTOR);

    printf("\n\n REALLOC POR MENOS\n"); //NO NECESITA USAR AUXILIAR
    vector=realloc(vector, sizeof(int)*contador);

        for (i=0; i<contador; i++)
        {
        printf("%d\n", *(vector+i));
        }

    }



    return 0;
}


///////////////////////////

int contraer(int* vector, int index, int tamanio)
{
  int i;
  int contador=0;

  for (i=0; i<tamanio; i++)
    {
       if(i == (index-1))
        {
        contador++;
        while (i<tamanio)
        {
            *(vector+i)= *(vector+(i+1));
            i++;
        }

        }
    }

    contador=tamanio-contador;
    return contador;

}

/////////////////
