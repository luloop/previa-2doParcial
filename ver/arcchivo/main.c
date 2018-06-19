#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *parchivo;
    /*parchivo=fopen("C:\\TEST\\RIZZI\\laboratorio1-2daparte-cursada\\arcchivo\\archivo.txt", "w");

    if ( parchivo!=NULL)
    {
            fprintf(parchivo, "Holaaaaaaaaaa");
            fclose(parchivo);
            printf("Guardado");


    }
    else
    {
         printf("No Existe");
    }*/


    ////////////////////// COMO LEER
  char cadena [50];
    parchivo=fopen("C:\\TEST\\RIZZI\\laboratorio1-2daparte-cursada\\arcchivo\\archivo.txt", "r");

        if ( parchivo!=NULL)
        {
            while(!(feof(parchivo)))
              {
               fgets(cadena, 50, parchivo);
               puts(cadena);
              }
            fclose(parchivo);
        }
    else
    {
         printf("No Existe");
    }


}
