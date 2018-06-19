#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
//evaluar que reciba el char denombre y el pfile adentro
//y hace un switch para que tipo de archivo quiere y concatenar
{
    Employee *auxEmpleado;

    char auxName[50];
    char auxLast[50];
    char auxId[50];
    char isEmpty[50];
    int cont =0;

    pFile=fopen("data.csv","r");
    if(pFile== NULL)
    {
        return 1;
    }
    else
    {
        //salteo el primero leyendolo pero sin hacer nada
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName, auxLast, isEmpty);

        while(!(feof(pFile)))
        {
//genero espacio en memoria para 1 estrsutura y se lo asigno al auxiliar *
            auxEmpleado=(Employee*)malloc(sizeof(Employee));
            if(auxEmpleado!=NULL)
            {
// leo del csv a auxiliares sueltos
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName, auxLast, isEmpty);
// printf("%s--%s--%s---%s", auxId, auxName, auxLast, isEmpty);//muestro

//copio del auxiliar suelto al e estructura
                auxEmpleado->id=atoi(auxId);
                strcpy(auxEmpleado->lastName, auxLast);
                strcpy(auxEmpleado->name,auxName);
                //  strcpy(auxEmpleado->isEmpty,isEmpty);

                //agrego al array list AL FINAL
cont++;
                al_add(pArrayListEmployee,auxEmpleado); // AGREGO EL EMPLEADO
printf("%d-", cont);
            }

//muestro
// printf("\n%d--%s--%s---%d", auxEmpleado->id,auxEmpleado->name, auxEmpleado->lastName, auxEmpleado->isEmpty);printf("\n%d--%s--%s---%d", auxEmpleado->id,auxEmpleado->name, auxEmpleado->lastName, auxEmpleado->isEmpty);

//agrego al array list AL FINAL

        }
        /*
        printf("\n-------------------------------\n");
        printf("\nSe guardo la informacion con exito\n");
        printf("\n-------------------------------\n");
                */
    }

    fclose(pFile);





    return 0;
}



/** \brief Guardar en Archivo en Array que se esta Trabajando
 *
 * \param aRRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \return  respuesta si es NULL no se genero el arhcivo correctamente
 */
int guardarEnArchivo(Employee *empleados, int cantidad, FILE *archivo)
{

    int i=0;

    archivo=fopen("data2.csv","w");
    if(archivo== NULL)
    {
        return 1;
    }
    else
    {
        while(i!=cantidad)
        {
            fprintf(archivo,"%d,%s,%s,%d\n", (empleados+i)->id,(empleados+i)->name,(empleados+i)->lastName,(empleados+i)->isEmpty);
            i++;
        }
        printf("\n-------------------------------\n");
        printf("\nSe guardo la informacion con exito\n");
        printf("\n-------------------------------\n");

    }

    fclose(empleados);
    return 0;
}
