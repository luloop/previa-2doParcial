#include <stdio.h>
#include <stdlib.h>
#include"string.h"
#include "ArrayList.h"
#include "Employee.h"

/////////////////////////////
int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=0;
    if (strcmp(((Employee*)pEmployeeA)->name,((Employee*)pEmployeeB)->name)==1)
    {
      retorno=1;
    }
        if (strcmp(((Employee*)pEmployeeA)->name,((Employee*)pEmployeeB)->name)==-1)
    {
      retorno=-1;
    }

    return retorno;
}
/////////////////////////
int employee_compare2(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=0;
    Employee* aux1= pEmployeeA;
    Employee* aux2= pEmployeeB;


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

Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
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
        this->id = 0;
        aux = 1;
    }

    return aux;
}


/////////////////////////
int employee_getId(Employee* this)
{

    return 0;

}


