/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __PERSONAS
#define __PERSONAS
struct
{
    int id;
    char name[51];
    char lastName[51];
    char dni[51];
    float salary;
    int sector;
    int legajo;
    int edad;
    int status;
    int isEmpty;

}typedef Employee;
#endif // __EMPLOYEE

void persona_printPersona(Employee* p);
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector);
int persona_compareName(void* pEmployeeA,void* pEmployeeB);

