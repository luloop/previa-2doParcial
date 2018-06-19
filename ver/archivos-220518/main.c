#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
}eDato;

void funcion1();
void funcion2();
void funcion3();

int main()
{
    //funcion1();
    //funcion2();
    funcion3();

    return 0;
}

void funcion1()
{
    FILE* miArchivo;
    int numero =6002;

    //////////ESCRITURA

    miArchivo=fopen("prueba1.txt", "w");
    fwrite(&numero, sizeof(int), 1, miArchivo);
    fclose(miArchivo);

    //////////LECTURA
    miArchivo=fopen("prueba1.txt", "r");
    fread(&numero, sizeof(int), 1, miArchivo);
    printf("NUMERO: %d \n \n", numero);
    fclose(miArchivo);

}

void funcion2()
{
    FILE* miArchivo;
    int i;
    int numero;
    int list [5]={1,2,5,5,5};
 //////////ESCRITURA

    miArchivo=fopen("prueba2.txt", "w");
    fwrite(list, sizeof(int), 5, miArchivo); // NO SIRVE PARA FILTROS
    fclose(miArchivo);

                                            //SIRVE PARA FILTROS
   /* miArchivo=fopen("prueba2.txt", "w");
    for (i=0; i<5; i++)
    {
        printf("ingrese el numero:\n");
        scanf("%d", &numero);
        fwrite(&numero, sizeof(int), 1, miArchivo);
    }
    fclose(miArchivo);*/


    //////////LECTURA
    miArchivo=fopen("prueba2.txt", "r");

                                        //SIRVE PARA FILTROS
/*
    while(!feof(miArchivo))
    {
    fread(&list[i],sizeof(int), 1, miArchivo);
    i++;
    }
*/

    fread(list,sizeof(int), 5, miArchivo); // NO SIRVE PARA FILTROS- copia todo

    for (i=0; i<5; i++)
    {
    printf("NUMERO: %d \n", list[i]);
    }
    fclose(miArchivo);

}


void funcion3()
{
    eDato d [2]={{3, 'a'}, {4, 'c'}};
    FILE* miArchivo;
    int i;
    int numero =128;
    int otroNumero;
    eDato d2[2];

 //////////ESCRITURA
    miArchivo=fopen("prueba3.dat", "wb"); // .bin
    fwrite(d, sizeof(eDato), 2, miArchivo);
    fclose(miArchivo);

//////////LECTURA
    miArchivo=fopen("prueba3.dat", "rb");
    fread(d2,sizeof(eDato), 2, miArchivo);
    fclose(miArchivo);

    for( i=0; i<2; i++)
    {
        printf("%d --%c\n", d2[i].a, d2[i].b);

    }




}
