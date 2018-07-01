#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include  <cstdio.h>
#include "ArrayList.h"
#include "personas.h"
#include "formatos.h"
#include "lib.h"


int parserCSV(FILE* pFile, ArrayList* pArrayListEmployee, char nombre[])
{
    Employee *auxEmpleado;

    char auxName[50];
    char auxLast[50];
    char auxId[50];
    char isEmpty[50];
    char charCantidad[50];
    int cantidad;

    pFile=fopen("data.csv","r");
    if(pFile== NULL && pArrayListEmployee==NULL && strlen(nombre)==0)
    {
        return 1;
    }
    else
    {
// LEO y salteo el primero leyendolo pero sin hacer nada
// fscanf(pFile,"%[^,],", charCantidad);
// cantidad=atoi(charCantidad);//A ARRALYST ->SIZE??
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
                strcpy(auxEmpleado->lastName, auxLast);
                strcpy(auxEmpleado->name,auxName);

                //agrego al array list AL FINAL

                al_add(pArrayListEmployee,auxEmpleado); // AGREGO EL EMPLEADO

            }
//muestro
// printf("\n%d--%s--%s---%d", auxEmpleado->id,auxEmpleado->name, auxEmpleado->lastName, auxEmpleado->isEmpty);
       }

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
int guardarEnArchivo(ArrayList *this, int cantidad, FILE *archivo, char nombre[])
{
    int i=0;
    Employee*aux;
    archivo=fopen(nombre,"w");
    if(archivo==NULL)
    {
        return 1;
    }
    else
    {
        fprintf(archivo,"ID,NOMBRE,APELLIDO,VACIO, %d\n",i);
    while(i!=cantidad)
       {
       aux=(Employee*) this->get(this,i);
       fprintf(archivo,"%d,%s,%s\n",persona_getId(aux),persona_getNombre(aux),persona_getApellido(aux),2);
       i++;
       }
        printf("\n-------------------------------\n");
        printf("\nSe guardo la informacion con exito\n");
        printf("\n-------------------------------\n");
    }

    fclose(archivo);
    return i;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 *//*
int archivos_guardar(ArrayList* pArray)
{
   int i;
   int retorno=-1;
   FILE* fArchivo=fopen("datos.bin","wb");
   void* pSocio=NULL;
   if(fArchivo!=NULL && pSocio!=NULL)
   {
       for(i=0;i<al_len(pArray);i++)
       {
           pSocio=al_get(pArray,i);
           fwrite(pSocio,sizeof(Socio),1,Socios);
           retorno=0;
       }

   }
   fclose(fArchivo);
   return retorno;
}

/** \brief
*
* \param
* \param
* \return
*
*//*
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
}*/
