#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

void cleanScreen (void);

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{

    ArrayList* listaEmpleados;
    FILE *f_empleados;
    Employee *aux;
    int flagParser=0;

    Employee*filtro;

    int len=0;
    int i;
    int seguir=1;
    int opcion;
    char salir;
    int flagOrdenar=-1;
    int flagAgregar=-1;
    int* auxiliar;


    //CREO ARRAY LIST
    listaEmpleados=al_newArrayList(); // llamo al constructor;
    if (listaEmpleados==NULL)
    {
        printf("\n can't allocate memory \n");
        return 0;
    }
    while(seguir==1)
    {

        //calculo el tamaño-LO GENERO UNA SOLA VEZ
        printf("\n-------------------------------\n");
        printf("-- EMPLEADOS --\n");
        printf("-------------------------------\n");
        printf(" 1. Parse del archivo data.csv\n");
        printf(" 2. Listar Empleados\n");
        printf(" 3. Ordenar por nombre\n");
        printf(" 4. Agregar un elemento\n");
        printf(" 5. Elimina un elemento\n");
        printf(" 6. Listar Empleados (Desde/Hasta)\n");
        printf(" 7. Guardar\n");

        printf(" 0. Salir");
        printf("\n-----------------------------\n\t Ingrese la Opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
                        //COPI DE ARCHIVO- paso el puntero a empleado y puntero arraylist
            flagParser=parserEmployee(f_empleados, listaEmpleados);
            if (flagParser==0)
            {
                printf("\n COPIA EXITOSA\n");
            }
            else
            {
                printf("\n no se pudo copiar el archivo\n");
            }
            cleanScreen();
            break;
        case 2:
                    //muestro  elementos
            printf("elementos: %d", al_len(listaEmpleados));
            for (i=0; i<al_len(listaEmpleados); i++ )
            {
                //casteo a una estructura  COPIO LA DIRECCION DE MEMORIA DE LA INFO QUE QUIERO
                aux=(Employee*)al_get(listaEmpleados,i);
                printf("\n-%d-----%s, %s", aux->id, aux->lastName, aux->name);
                if (i%100==0)// CONVERTIR ESTO EN FUNCION
                {
                    printf("\n\n");
                    system("pause");
                }
            }
            cleanScreen();
            break;
        case 3:
            printf("-------------Ordenar por nombre\n");
            flagOrdenar=al_sort(listaEmpleados,employee_compare,1);
//COMPARA Y ORDENA //puntero a funcion (*PFUNC)
//**IMPORTANTE* VALOR DE RETORNO Y CANTIDAD DE TIPOS DE DATO
            printf("\n \n %d \n \n", flagOrdenar);
            // system("pause");
            if(flagOrdenar==0)
            {
                for (i=0; i<al_len; i++ )
                {
                    aux=(Employee*)al_get(listaEmpleados,i); //casteo a una estructura  COPIO LA DIRECCION DE MEMORIA DE LA INFO QUE QUIERO
                    printf("\n-%d-----%s, %s", aux->id, aux->lastName, aux->name);
                    if (i%100==0)// CONVERTIR ESTO EN FUNCION
                    {
                        printf("\n\n");
                        system("pause");
                    }
                }

                printf("\n");
                printf("\n");

            }

            cleanScreen();
            break;
        case 4:
            printf("\n AGREGAR UN EMPLEADO \n");

            printf("%d", al_len(listaEmpleados));

            Employee* unEmpleado;
            unEmpleado=(Employee*)employee_new( 100, "Lucila", "Rizzi");


            //HACER SETEEERS DONDE PIDES LOS DATOS ACA




            if(unEmpleado!=NULL)
            {
                flagAgregar=al_add(listaEmpleados, unEmpleado);
            }
            cleanScreen();
            break;
        case 5:

            auxiliar=al_subList(listaEmpleados, 100, 200);

            cleanScreen();
            break;
        case 6:

           filtro=al_newArrayList();
            filtro=al_filter(listaEmpleados,employee_filterId100);

            for (i=0; i<al_len(filtro); i++ )
            {
                //casteo a una estructura  COPIO LA DIRECCION DE MEMORIA DE LA INFO QUE QUIERO
                aux=(Employee*)al_get(filtro,i);
                printf("\n-%d-----%s, %s", aux->id, aux->lastName, aux->name);
                if (i%100==0)// CONVERTIR ESTO EN FUNCION
                {
                    printf("\n\n");
                    system("pause");
                }
            }




            cleanScreen();
            break;
        case 7:





            cleanScreen();
            break;
        case 0:
            printf("elementos: %d", len);
             guardarEnArchivo(listaEmpleados, len, f_empleados);
            seguir=0;
            cleanScreen();
            break;
        }
    }




    return 0;
}








/** \brief LIMPIAR PANATALLA
 *
 */
void cleanScreen (void)
{
    printf("\n");
    system ("pause");
    system ("cls");
}

