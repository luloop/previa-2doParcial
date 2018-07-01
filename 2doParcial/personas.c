#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personas.h"

int personas_compareSalario(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;


}

void printPersona(Employee* p)
{
    printf("Nombre:%s Salario:%.2f\r\n",p->name,p->salary);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* persona_newPersona(int id, char name[],char lastName[],float salary,int sector)
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


int persona_setNombre(Employee* this,char* nombre)
{
    strcpy(this->name,nombre);
    return 0;
}


char* persona_getNombre(Employee* this)
{
    return this->name;
}


int persona_setApellido(Employee* this,char* apellido)
{
    strcpy(this->lastName,apellido);
    return 0;
}


char* persona_getApellido(Employee* this)
{
    return this->lastName;
}


int persona_setDni(Employee* this,char* dni)
{
    strcpy(this->dni,dni);
    return 0;
}


char* persona_getDni(Employee* this)
{
    return this->dni;
}


int persona_setId(Employee* this,int id)
{
    this->id = id;
    return 0;
}

int persona_getId(Employee* this)
{
    return this->id;
}

int persona_setEstado(Employee* this,int estado)
{
    this->status = estado;
    return 0;
}

int persona_getEstado(Employee* this)
{
    return this->status;
}



