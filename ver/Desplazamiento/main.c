#include <stdio.h>
#include <stdlib.h>
#define VEC 10

 int main()
{
    int numero=33;
    int *punteroEntero;
    int numeros [VEC]= {100,300,500,444,98,752};

    punteroEntero = numeros;

   // printf("%d \n", punteroEntero);
    int i;
    printf("for -----------------------\n");
    for (i=0 ; i<VEC ; i++)
    {
    printf("\n%d +%d \n", punteroEntero+i, i);
    printf("\t%d +%d \n", *(punteroEntero+i), i);
    // printf("\t%d +%d \n", *punteroEntero+i, i);
    }

    printf("-----------------------\n");
    printf("%d +0 \n", punteroEntero+0);
    printf("%d +1 \n", punteroEntero+1);
    printf("%d +2 \n", punteroEntero+2);
    printf("%d +3 \n", punteroEntero+3);
    printf("%d +4 \n", punteroEntero+4);
    printf("-----------------------\n");
    printf("%d \n", *punteroEntero);
    printf("%d +0 \n", *(punteroEntero+0));
    printf("%d +1 \n", *(punteroEntero+1));
    printf("%d +2 \n", *(punteroEntero+2));
    printf("%d +3 \n", *(punteroEntero+3));
    printf("%d +4 \n", *(punteroEntero+4));
    printf("-----------------------\n");
    printf("%p \n", punteroEntero);
    printf("%p +1 \n", punteroEntero+1);


    printf("\nNumero -----------------------\n\n");

    printf("dato: %d \n", numero);
    printf("direccion de memoria: %p \n", numero);

    printf("\nPuntero &  --   *   -----------------------\n\n");

    printf("%p \n", &punteroEntero);
    printf("%p \n", *punteroEntero);




















    /*
    int numero=10;
    int *punteroEntero =NULL; //INICIALIZAR A NULL




   if (punteroEntero!= NULL) //SIEMPRE VERIFICAR QUE NO SEA NULL PARA MOSTRAR, SINO PINCHA
   {
    printf("porcentual != null P: %p \n", *punteroEntero);
   }


   punteroEntero=&numero;
   if (punteroEntero!= NULL)
        {
        printf("porcentual P no null: %p \n", *punteroEntero);
        printf("porcentual D no null : %d \n", *punteroEntero);
        }

    printf("-----------------------------------------------\n");

    printf("porcentual P: %p \n", *punteroEntero);

    printf("-----------------------------------------------\n");
    printf("porcentual &: %p \n", &punteroEntero);
    printf("porcentual po nombre solo: %p \n", punteroEntero);


    printf("Nombre solo %p", punteroEntero);
    printf("\ndireccion de memoria %p", &punteroEntero);



    printf("\n");*/
    return 0;
}
