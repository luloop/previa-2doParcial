#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include  <cstdio.h>
#include "ArrayList.h"
#include "personas.h"
#include "formatos.h"
#include "lib.h"


int parserCSV(ArrayList* pArrayListEmployee, char nombre[])
{
    Employee *auxEmpleado;

    FILE* pFile;

    char auxName[50];
    char auxLast[50];
    char auxId[50];
    char isEmpty[50];
    char charCantidad[50];
    int cantidad=0;

    pFile=fopen(nombre,"r");
    if(pFile== NULL || pArrayListEmployee==NULL || strlen(nombre)==0)
    {
        return -1;
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
                if(strcmp(isEmpty,"true"))
                {
                   strcpy(auxEmpleado->dni, "0");
                }
                else
                {
                   strcpy(auxEmpleado->dni, "1");
                }

                strcpy(auxEmpleado->lastName, auxLast);
                strcpy(auxEmpleado->name,auxName);

                //agrego al array list AL FINAL

                al_add(pArrayListEmployee,auxEmpleado);
                cantidad++; // AGREGO EL EMPLEADO

            }
//muestro
// printf("\n%d--%s--%s---%d", auxEmpleado->id,auxEmpleado->name, auxEmpleado->lastName, auxEmpleado->isEmpty);
       }

    }

    fclose(pFile);





    return cantidad;
}







/** \brief Guardar en Archivo en Array que se esta Trabajando
 *
 * \param PUNTERO A ESTRUCTRUA
 * \param TAMANIO DEL ARRAY
 * \param PUNTERO A FILE
 * \return  respuesta si es 1 no se genero el arhcivo correctamentem, si es cero todo OK
 */
int  archivos_guardarTexto(ArrayList *this, char nombre[])
{
    FILE *archivo;
    int cantidad=-1;
    int i=0;
    Employee*aux;
    ///////////////////////////
    archivo=fopen(nombre,"w");
    if(archivo==NULL)
    {
        return 1;
    }
    else
    {
        cantidad=this->len(this);
        fprintf(archivo,"ID,NOMBRE,APELLIDO,DNI, %d\n",i);
    while(i!=cantidad)
       {
       aux=(Employee*) this->get(this,i);
       fprintf(archivo,"%d,%s,%s,%s\n",persona_getId(aux),persona_getNombre(aux),persona_getApellido(aux),persona_getDni(aux));
       i++;
       //this->maxId=persona_getId(aux);//////////////
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
 */
int archivos_guardarBinario(ArrayList* pArray, char nombreArchivo[])
{
   int i;
   int retorno=-1;
   FILE* fArchivo=fopen("datos22.bin","wb");
   void* pSocio=NULL;

   if(fArchivo!=NULL && pArray!=NULL)
   {

       for(i=0;i<al_len(pArray);i++)
       {
           pSocio=al_get(pArray,i);
           fwrite(pSocio,sizeof(Employee),1,fArchivo);
           retorno++;

       }

   }
   fclose(fArchivo);
   return (retorno+1);
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
   Employee *auxSocio;
   int maxId=0;
   int i=0;
   FILE* Socios=fopen("datos22.bin","rb");

   if(Socios!=NULL && pArray!=NULL )
   {
       retorno=0;
       do{
           auxSocio=persona_newUnaPersona();
           if(fread(auxSocio,sizeof(Employee),1,Socios))
           {

               al_add(pArray,auxSocio);
               retorno++;
               pArray->maxId=auxSocio->id;

           }
       }while(!feof(Socios));
       fclose(Socios);
   }
   return retorno;
}

/** \brief
*
* \param
* \param
* \return
*
*//*
int archivos_leerMaxIdDOC(ArrayList* this)
{
   int retorno=-1;
   int maximo;
   int maxId=0;
   int i=0;
   char maximoId[10];
   FILE* Socios=fopen("maxId.doc","r");

   if(Socios==NULL &&this!=NULL)
   {
      Socios =fopen("maxId.doc","w");
      maxId=this->len(this);
      fprintf(Socios,"%d\n",maxId);
   }


   if(Socios!=NULL && this!=NULL )
   {
       retorno=0;
       do{
           fscanf(Socios,"%[^,]\n",maximoId);
           this->maxId =atoi(maximoId);

       }while(!feof(Socios));
       fclose(Socios);
   }
   return retorno;
}

/** \brief
*
* \param
* \param
* \return
*
*//*
int archivos_guardarMaxIdDOC(ArrayList* pArray)
{
   int retorno=-1;
   int maximo;
   int maxId=0;
   int i=0;
   char maximoId[10];
   FILE* Socios;

   if(Socios!=NULL && pArray!=NULL )
   {
      Socios =fopen("maxId.doc","w");
      do{
           fprintf(Socios,"%[^,]\n",pArray->maxId);
        }while(!feof(Socios));
   }

       fclose(Socios);

   return retorno;
}
*/




