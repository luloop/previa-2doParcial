#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "personas.h"
#include "formatos.h"
#include "lib.h"



int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
//evaluar que reciba el char denombre y el pfile adentro
//y hace un switch para que tipo de archivo quiere y concatenar
{
    Employee *auxEmpleado;

	char auxName[50];
	char auxLast[50];
	char auxId[50];
	char isEmpty[50];

		pFile=fopen("data.csv","r");
                if(pFile== NULL)
                {
               return 1;
                }
        else
        {
            //salteo el primero leyendolo pero sin hacer nada
            fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxName, auxLast, isEmpty);

        while(!(feof(pFile)))
        {
                //genero espacio en memoria para 1 estrsutura y se lo asigno al auxiliar *
            auxEmpleado=(Employee*)malloc(sizeof(Employee));
             if(auxEmpleado!=NULL)
            {
                // leo del csv a auxiliares sueltos
            fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxName, auxLast, isEmpty);
                // printf("%s--%s--%s---%s", auxId, auxName, auxLast, isEmpty);//muestro

                //copio del auxiliar suelto al e estructura
            auxEmpleado->id=atoi(auxId);
                // auxEmpleado->isEmpty=1;
            strcpy(auxEmpleado->lastName, auxLast);
            strcpy(auxEmpleado->name,auxName);

            //agrego al array list AL FINAL

               al_add(pArrayListEmployee,auxEmpleado); // AGREGO EL EMPLEADO

            }

//muestro
// printf("\n%d--%s--%s---%d", auxEmpleado->id,auxEmpleado->name, auxEmpleado->lastName, auxEmpleado->isEmpty);

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
 * \param PUNTERO A ESTRUCTRUA
 * \param TAMANIO DEL ARRAY
 * \param PUNTERO A FILE
 * \return  respuesta si es 1 no se genero el arhcivo correctamentem, si es cero todo OK
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
        fprintf(archivo,"ID,NOMBRE,APELLIDO,VACIO\n");
        while(i!=cantidad)
        {

           //GETS
            printf(archivo,"%d,%s,%s,%d\n", (empleados+i)->id,(empleados+i)->name,(empleados+i)->lastName,(empleados+i)->isEmpty);
            i++;
        }
						printf("\n-------------------------------\n");
						printf("\nSe guardo la informacion con exito\n");
						printf("\n-------------------------------\n");

        }

      fclose(empleados);
       return 0;
 }


 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */
int archivos_guardar(ArrayList* pArray)
{
    int i;
    int retorno=-1;
    FILE* Socios=fopen("datos.bin","wb");
    void* pSocio=NULL;
    if(Socios!=NULL && Socios!=NULL)
    {
        for(i=0;i<al_len(pArray);i++)
        {
            pSocio=al_get(pArray,i);
            fwrite(pSocio,sizeof(Socio),1,Socios);
            retorno=0;
        }

    }
    fclose(Socios);
    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int archivos_leer(ArrayList* pArray)
{
    int retorno=-1;
    Socio auxSocio;
    int maxId=0;
    Socio* pSocio=NULL;
    FILE* Socios=fopen("datos.bin","rb");

    if(Socios!=NULL && Socios!=NULL))
    {
        do{
            if(fread(&auxSocio,sizeof(Socio),1,Socios)==1)
            {
                pSocio=soc_new(auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.id,auxSocio.estado); //VEEER no va a funcionar
                al_add(pArray,pSocio);

                /////////////////
                if(auxSocio.id>maxId)
                {
                    maxId=auxSocio.id;
                }
                retorno=maxId;
                //////////////////
            }
        }while(!feof(Socios));
        fclose(Socios);
    }
    return retorno;
}
