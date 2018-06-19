#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>


/** \brief Funcion de Indice
 * \param estructura de usuarios
 * \param tamanio de array de personas
 * \return VOID
 *
 */
void indiceUsuarios (ePersona usuarios[], int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
    usuarios[i].estado=0;
    usuarios[i].edad=0;
    }
}


/** \brief  carga inicial Usuarios para poder operar
 *
 * \param estructura de usuarios
 * \param tamanio de array de personas
 * \return flag
 *
 */
int cargarUsuarios (ePersona usuarios[], int tamanio)
{
 int flag =0;
 char auxNombre[30] [50] ={"XOzoz" , "Lucila"  , "MArco", "Caro", "ANA", "Marco", "Caro", "Ana", "Caro", "Ana", "Zozoz", "Lucila", "Marco", "Caro", "Ana","XOzoz" , "Lucila"  , "MArco", "Caro", "ANA", "Marco", "Caro", "Ana", "Caro", "Ana", "Zozoz", "Lucila", "Marco", "Caro", "Ana"};
 int auxEdad[30] = {16,17,21,28,45,14,56,36,56,34,15,18,22,39,12,16,17,21,28,45,14,56,36,56,34,15,18,22,39,12};
 int i;
    for (i=0 ; i<tamanio;i++)
    {
    strcpy(usuarios[i].nombre, auxNombre[i]);
    usuarios[i].edad=auxEdad[i];
    usuarios[i].dni=30887699+i;
    usuarios[i].estado=1;
    flag =1;
    }

    return flag;
}


/** \brief Alta de usuario
 *
 * \param Estructura de usuario
 * \param tamanio de array de usuarios
 * \return Nuevo Flag
 *
 */
int  altaUsuario (ePersona users[], int tamanio)
{
    int seguir='s';
    int index;
    int flag;
    while (seguir == 's')
        {
            index=searchIndexUsers(users, tamanio);
            if (index != -1)
                {
           //   printf("\n\n---PRUEBA DE INDEX %d \t STATUS %d\n\n",index, users[index].estado);
                printf("\n \n---- NUEVO INGRESO DE USUARIO -----\t");

                printf("\n \nIngrese su Nombre\t");
                fflush(stdin);
                gets(users[index].nombre);

                users[index].edad=pedirEdad();
                users[index].dni= pedirDNI();
                users[index].estado=1;

                flag=1;
                printf("\n");

                seguir = preguntarSiNo("Cargar otro usuario?");
                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE USUARIOS LLENO\n===========================\n");
                break;
                }
        }
return flag;
}

/** \brief Busqueda de espacio disponible via indice para iniciar la carga segun su esta
 * \param Estructura de personas
 * \param tamanio del array
 * \return primer ubicacion disponible en el array
 *
 */
int searchIndexUsers ( ePersona status[], int tamanio)
{
    int index=-1;
    int i;
    for (i=0 ; i<tamanio ; i++)
            {
                if (status[i].estado==0)
                {
                   index = i;
                   break;
                }
            }
    return index;
}

/** \brief Baja de usuario, pasa el status a Numero 2 para dejar disponible los usuarios borrados
 *
 * \param Estructura de Personas
 * \param tamaño del array
 * \param flag de carga de usuarios
 * \return void
 *
 */
void bajaUsuario (ePersona users[], int tamanio, int flag)
{
int flagDelete;
int i;
int idAux;
int confirm;

     if(flag==0)
            {
               printf("\n\n\n======================\n NO HAY USUARIOS CARGADOS\n======================\n");
            }
        else
            {
               listadoDeUsuarios(users, tamanio);
                printf("\n\n=========================================================\n");
                printf("\nIngrese el DNI del Usuarios que desea dar de BAJA: ");
                scanf("%d", &idAux);
                printf("\n==========================================================\n");
                    flagDelete=0;
                        for (i=0; i<tamanio;i++)
                            {
                                if (users[i].dni== idAux && users[i].estado ==1)
                                    {
                                    printf("\n");
                                    confirm =preguntarSiNo("Seguro que desea borrar al usuario:");
                                     if (confirm == 's')
                                        {
                                        users[i].estado=2;
                                        printf("\n\n==========================================================\n");
                                        printf("Usuario borrado: %s, con el DNI  Nro: %d", users[i].nombre, users[i].dni);
                                        printf("\n==========================================================\n");
                                        flagDelete=1;
                                        break;
                                        }
                                    else if (confirm == 'n')
                                        {
                                        printf("\n\n==========================================\n");
                                        printf("Operacion Cancelada");
                                        printf("\n==========================================\n");
                                        flagDelete=1;
                                        break;
                                        }
                                    }
                            }

                    if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("El users que desea borrar no existe");
                            printf("\n==========================================\n");
                    }


            }

}


/** \brief Listado de usuarios cargados, busca estado 1 y publica
 *
 * \param Estructura de personas
 * \param tamaño del array de personas
 * \return
 *
 */

void listadoDeUsuarios (ePersona users [], int tamanio)
 {
      int i;
      printf("\n\n\n=====================\n USUARIOS CARGADOS\n=====================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (users[i].estado==1)
                    {
                        showOneUser(users[i]);
                    }
                }
 }
/** \brief Muestra un solo usuario, complementaria al listado
 *
 * \param Estructura de personas
 * \return Void
 *
 */
  void showOneUser (ePersona usuarios)
{
 printf("\nNombre: %s \t Edad:%d \t Dni:%d \t Estado:%d"  , usuarios.nombre , usuarios.edad, usuarios.dni, usuarios.estado);
}


/** \brief Ordena por burbujeo alfabeticamente
 *
 * \param Vector Estructura de personas
 * \param tamanio del array de personas
 * \param Flag de estado de carga de usuaarios
 * \return
 *
 */
void mostrarOrdenadoPorNombre (ePersona usuarios [], int CantUsuario, int flag)
{
    int i;
    int j;
    ePersona aux;
    if (flag ==1)
    {
         printf(" \n \n---El orden de los usuarios por nombre---\n");
         printf("\n------------------------------------------------------\n");
       for (i=0; i<CantUsuario-1;i++)
        {
           for (j=i+1; j<CantUsuario;j++)
            {
                if (stricmp( usuarios[j].nombre , usuarios[i].nombre, 50)<0)
                {
                   aux=usuarios[i];
                   usuarios[i]=usuarios[j];
                   usuarios[j]=aux;
                }
            }
        }
        listadoDeUsuarios(usuarios, CantUsuario);
        printf("\n---------------------------------------------------------\n");

    }
    else
    {
         printf("\n\n\n======================\n NO HAY USUARIOS CARGADOS\n======================\n");
    }
}

/** \brief Grafico de que muestra la edad de los usuarios
 *
 * \param Vector Estructura de personas
 * \param tamanio del array de personas
 * \return void
 *
 */

void graficos (ePersona personas [], int CantUsuario)
{
    int i;
    int menor18=0;
    int de18a35=0;
    int mas35=0;
    char menor[CantUsuario][2];
    char joven[CantUsuario][2];
    char adulto[CantUsuario][2];
    int contador=0;

  for(i=0; i<CantUsuario; i++)
     {
        strcpy(menor[i] , " ");
        strcpy(joven[i] , " ");
        strcpy(adulto[i] , " ");
     }

    for(i=0; i<CantUsuario; i++)
    {
        if (personas [i].edad <=18 && personas [i].edad >0 &&personas [i].estado ==1 )
        {
            menor18++;
        }
        else if (personas [i].edad >18&&personas [i].edad <35 &&personas [i].estado ==1 )
                 {
            de18a35++;
        }
        else if (personas [i].edad >35 &&personas [i].estado ==1 )
        {
            mas35++;
        }

    }

    for(i=0; i<menor18; i++)
    {
        if (i==0)
        {
         strcpy(menor[i] , "*");
        }
        else{
         strcpy(menor[i], "*") ;
        }

    }
    for(i=0; i<de18a35; i++)
    {
        if (i==0)
        {
            strcpy(joven[i], "*");
        }
        else
        {
           strcpy(joven[i], "*") ;
        }
    }
    for(i=0; i<mas35; i++)
    {
        if (i==0)
        {
            strcpy(adulto[i], "*");
        }
        else{
           strcpy(adulto[i], "*") ;
        }
    }
   if (menor18 <= de18a35)
   {
     contador = de18a35;
   }
   else if (de18a35<=mas35)
   {
   contador = mas35;
   }
   else
    {
     contador=menor18;
    }
    for(i=contador; i>=0; i--)
    {
      printf(" \n\t%s \t  %s\t %s", menor[i] , joven[i] , adulto[i]);
    }
  printf("\n       <18      18y35 \t>35 \n \n" );
  printf("\n----------------------------------- \n");
  cleanScreen();

}


/** \LIMPIA LA PANTALLA
 */
void cleanScreen (void)
{
            printf("\n");
            system ("pause");
            system ("cls");
}





/** \brief Pregunta S o N
 * *
 * \param texto de la pregunta
 * \return respuesta
 *
 */
 char preguntarSiNo ( char texto [])
 {
     char respuesta;

     printf("\t %s S o N:", texto);
     fflush(stdin);
     respuesta= tolower(getche());

    while (respuesta != 's' && respuesta !='n')
        {
        printf("\n\t Respuesta Incorrecta-%s S o N:\t",texto);
        fflush(stdin);
        respuesta= tolower(getche());
        }

  return respuesta;
}


/** \brief PEDIR DNI
 *
 * \param DNI
 * \return DNI VALIDADO
 *
 */

 int pedirDNI (void)
 {
    int dni;
    printf("Ingrese un DNI\t\t");
   scanf("%d", &dni);

   while (dni<1000000||dni>100000000)
   {
   fflush(stdin);
   printf("Error! Ingrese una DNI valido entre 1.000.000 y 100.000.000:\t");
   scanf("%d", &dni);
   }
   return dni;
 }

  /** \brief PEDIR EDAD
 *
 * \return EDAD VALIDADO
 *
 */
 int pedirEdad (void)
 {
     int edad;
        printf("Ingrese una edad:\t");
        scanf("%d", &edad);
        while (edad<0 || edad>100)
            {
            fflush(stdin);
            printf("Error! Ingrese una edad valida entre 1 y 99:\t");
            scanf("%d", &edad);
            }
         return edad;
 }
