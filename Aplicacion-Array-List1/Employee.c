#include <stdio.h>
#include <stdlib.h>
#include"string.h"
#include "ArrayList.h"
#include "Employee.h"

/////////////////////////////
int employee_compare(void* empleadoA,void* empleadoB)
{
    int retorno=0;
    if (strcmp(((Employee*)empleadoA)->name,((Employee*)empleadoB)->name)==1)
    {
      retorno=1;
    }
        if (strcmp(((Employee*)empleadoA)->name,((Employee*)empleadoB)->name)==-1)
    {
      retorno=-1;
    }

    return retorno;
}
/////////////////////////
int employee_compare2(void* empleadoA,void* empleadoB)
{
    int retorno=0;
    Employee* aux1= empleadoA;
    Employee* aux2= empleadoB;


    if (strcmp(aux1->name,aux2->name))
    {
      retorno=1;
    }

    return retorno;
}

////////////////////////

void employee_print(Employee* this)
{

 printf("\n%d\t %s\t %s", this->id, this->name, this->lastName);

}

//////////////////////////////////*
/*
Employee* employee_new(  len)
{
    char nombre [100];
    char auxnombre [50];
    char apellido[100];
    char auxapellido[50];
    int i;

    Employee* returnAux = (Employee*)malloc(sizeof(Employee));

    if (returnAux!=NULL)
    {

    returnAux->id=len+1; // como le asigno el numero de

    printf("\n \nIngrese Nombre\t");
    fflush(stdin);
    gets (nombre);
        for (i=0; i<50; i++)
        {
            auxnombre[i]=nombre[i];
        }
    strcpy(returnAux->name, auxnombre);


    printf("\nIngrese Apellido\t");
    fflush(stdin);
    gets (apellido);
        for (i=0; i<50; i++)
        {
            auxapellido[i]=apellido[i];
        }
    strcpy(returnAux->lastName, auxapellido);
    returnAux->isEmpty=1;

    employee_print(returnAux);

    }

    return returnAux;


}*/

Employee* employee_new(int id, char name[],char lastName[])
{
    Employee* returnAux = NULL;
    Employee* empleado = malloc(sizeof(Employee));

    if(empleado != NULL)
    {
        empleado->id = id;
        strcpy(empleado->name,name);
        strcpy(empleado->lastName,lastName);
        empleado->isEmpty = 0;
        returnAux = empleado;
    }

    return returnAux;

}







///////////////////////////
void employee_delete(Employee* this)
{
    this->isEmpty=0;
}


//////////////////////////////
int employee_setId(Employee* this, int id)
{
    int aux = 0;
    if(this!=NULL)
    {
        this->id = id;
        aux = 1;
    }

    return aux;
}


/////////////////////////
int employee_getId(Employee* this)
{
    int aux=0;
    if (this!=NULL)
    {
     aux=this->id;
    }

    return aux;

}


