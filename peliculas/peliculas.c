
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "peliculas.h"
#include "lib.h"


/** \brief Funcion de Indice
 * \param estructura de peliculas
 * \param tamanio de array de personas
 * \return VOID
 *
 */
void indiceUsuarios (EMovie peliculas[], int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
       peliculas[i].idPelicula=0;
       peliculas[i].puntaje=0;
      peliculas[i].estado=0;
      peliculas[i].htmlCreado=0;
      strcpy(peliculas[i].titulo, " ");
      strcpy(peliculas[i].descripcion, " ");
    }
}

/** \brief Alta de Pelicula
 *
 * \param Estructura de peliculas
 * \param tamanio de array de pelicula
 * \return Nuevo Flag
 *
 */
int agregarPelicula(EMovie pelicula[], int tamanio)
{
    char seguir ='s';
    int cargado=0;
    int i;

    do{
       i=buscarLibre(pelicula, tamanio);
       if (i!=-1)
        {
    pelicula[i].idPelicula = i+10;
    printf("\n \n---- NUEVO INGRESO DE PELICULA %d----\t", i+1);

    pedirTitulo(pelicula, i, TEXTOSCORTOS); //TITULO
    pedirGenero(pelicula, i);//GENERO
    asignarNombrehtml(pelicula, i, TEXTOSLINK);//HTML
    printf("\nIngrese Duracion en min: \t"); //DURACION
    scanf("%d",&pelicula[i].duracion);
            while(! (pelicula[i].duracion<300 && pelicula[i].duracion>0))
            {
                fflush(stdin);
                printf("\nError - Ingrese Duracion Valida: \t");
                scanf("%d",&pelicula[i].duracion);
            }
     pedirDescripcion(pelicula, i, TEXTOSDESCRIPCION);//DESCRIPCION
     pedirLink(pelicula, i, TEXTOSLINK); // LINK
     pelicula[i].puntaje=devolverPuntaje(); //PUNTAJE RANDOM
     pelicula[i].estado=1; //ESTADO
     cargado=1; //FLAG
     mostrarPeliculaIndividual(pelicula[i]); //MOSTRAR DATOS INGRESADOS
     printf("\n");

     seguir = preguntarSiNo("Cargar otra Pelicula?"); // CONFIRMACION PARA CARGAR
        if (seguir=='n')
        {
        break;
        }

        } //if !=-1
        else
        {
        printf("\nNO HAY ESPACIO DISPONIBLE CARGADA DE PELICULAS\t");
        seguir='n';
        cargado=2;
        }
    } while (seguir == 's');

return cargado;
}

/** \brief DAR DE BAJA UNA PELICULA PASANDO 2 ESTADOS
 *
 * \param aRRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param FLAG DE CONTADOR DE FILE
 * \param FLAG DE ACCIONES DEL PROGRAMA
 * \return
 *
 */
int bajaPelicula (EMovie peliculaa[], int tamanio, int contador, int flag2)
{
int flagDelete=0;
int i;
int idAux;
char confirm;

               if (contadorArray(peliculaa, tamanio)||flag2!=0)
               {
                listarPeliculas(peliculaa, tamanio, 1);

                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id de la peliculaa que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (peliculaa[i].idPelicula== idAux )
                                {

                                    mostrarPeliculaIndividual(peliculaa[i]);
                                    confirm = preguntarSiNo(" \nSeguro que desea borrar la Pelicula?\t");
                                    flagDelete=1;
                                    if (confirm == 's')
                                        {
                                       peliculaa[i].estado=2;
                                       printf("\n\n======================================================\n");
                                       printf("Pelicula borrada: %s, con el Id  Nro: %d",peliculaa[i].titulo,peliculaa[i].idPelicula);
                                       printf("\n======================================================\n");

                                       return 1;
                                       break;
                                        }
                                    else
                                      {
                                    printf("\n\n==========================================\n");
                                    printf("Operacion Cancelada");
                                    printf("\n==========================================\n\n\n\n");
                                    break;
                                      }

                                }//fin if id =aux


                            }//fin for
                    }
                else
                    {
                            printf("\n\n==========================================\n");
                            printf("NO HAY PELICULAS CARGADAS");
                            printf("\n==========================================\n");
                            ;
                    }

                if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("La peliculaa que desea borrar no existe");
                            printf("\n==========================================\n");
                            ;
                    }
    }



/** \brief mostar una pelicula individual en una sola linea con titulo
 *
 * \param ESTRUCTURA DE 1 PELICULA
 * \return VOID
 *
 */
void mostrarPeliculaIndividual(EMovie peli)
{
 printf("\n------------------------------------------\n");
 printf("\nId:\t\t%d \nTitulo:\t\t%08s \nGenero:\t\t%05s \n"
        "Duracion:\t%d \nDescripcion\t%20s\nPuntaje:\t%0.2f\nUrl Imagen:\t%s "
        "\n eEstaDo: %d" , peli.idPelicula,peli.titulo,peli.genero, peli.duracion,peli.descripcion, peli.puntaje, peli.linkImagen,peli.estado);
         printf("\n------------------------------------------\n");
}


/** \brief mostar una pelicula individual en una sola linea  sin titulos
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarUnaPeliculaParaListado(EMovie peli)
{
 printf("\n%d\t%10s\t%s\t%d\t\t%0.2f\t\t %d" , peli.idPelicula,peli.titulo,peli.genero, peli.duracion, peli.puntaje,peli.estado);
}


/** \brief armar listado de peliculas con encabezado
 *
 * \param array estructura emovie
 * \param tamanio array
 * \param estado
 * \return
 *
 */
void listarPeliculas(EMovie peliculass[], int tamanio, int estado)
{
    int i;

      printf("\n-----------------------\n LISTADO DE PELICULAS\n-----------------------\n ");

            printf("\nId     Titulo\t      Genero\tDuracion\tPuntaje\t     Estado");


                for (i=0; i<tamanio; i++)
                {

                    if(peliculass[i].estado==estado)
                    {
                    mostrarUnaPeliculaParaListado(peliculass[i]);
                        if ((i+1)%25==0 && i!=0) //CADA 25 PELICULAS HAGA UNA PAUSA
                        {  {
                            printf("\n");
                            system ("pause");
                            }
                        } //FIN IF PAUSA
                    }

                }
                printf("\n========================================================================\n");
            }


/** \brief Armado de archivos html - pagina individuales con descripcion genero etc
 *
 * \param array estructura emovie
 * \param tamanio array
 * \param
 * \return
 *
 */
int htmlArmado(EMovie peliculass[],int tamanio)
{
    FILE* archivo;
    char buffer[5000]= {};
    int i;
    char puntaje[10];
    char auxDuracion[10];
    char fileNam [TEXTOSLINK];

        for (i=0; i<tamanio;i++)
        {

        if (peliculass[i].estado==1 )
            {
        strcpy(buffer,"<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'>"
       " <meta name='viewport' content='width=device-width, initial-scale=1'>"
        "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
        "<title>Lista peliculas</title>"
        "<!-- Bootstrap Core CSS -->"
        "<link href='css/bootstrap.min.css' rel='stylesheet'>"
        "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
        "<link href='css/custom.css' rel='stylesheet'>"
        "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
        "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
        "<!--[if lt IE 9]>"
        "    <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
         " <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
        "<![endif]-->"
        "</head>"
        "<body><div class='container'><div class='row'>");
        strcat(buffer, "<article class='col-md-4 article-intro'> <a href='#'>"
        " <img class='img-responsive img-rounded' src='");//http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg
        strcat(buffer,peliculass[i].linkImagen);
        strcat(buffer,"'alt=''>"
        "</a><h3> <a href='#'>");
        strcat(buffer,peliculass[i].titulo);
        strcat(buffer,"</a>  </h3>  <ul>   <li>");
        strcat(buffer,"G&eacute;nero: ");
        strcat(buffer,peliculass[i].genero);
        strcat(buffer,"</li> <li>Puntaje: ");
        sprintf(puntaje, "%g", peliculass[i].puntaje);
        strcat(buffer,puntaje);
        strcat(buffer,"</li><li>Duraci&oacute;n:");
        sprintf(auxDuracion, "%g", peliculass[i].duracion);
        strcat(buffer,"</li></ul><p>");
        strcat(buffer,peliculass[i].descripcion);
        strcat(buffer,"</p>"
            "</article>"
            "<!-- Repetir esto para cada pelicula -->"
            "</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script>"
            "<!-- IE10 viewport bug workaround -->"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>"
            "<!-- Placeholder Images -->"
            "<script src='js/holder.min.js'></script>"
            "</body>"
            "</html>");


    sprintf(fileNam, peliculass[i].nombreArchivo);
    archivo = fopen(fileNam,"w");
    //////////////////
   if(archivo== NULL)

		{
        printf("\n-----------------------------\n");
        printf(" NULLLLL\t");
        printf("\n-----------------------------\n");
        return 0;
		}

    fprintf(archivo,buffer);
        printf("\n-----------------------------\n");
        printf(" pelicula %s en html\t", peliculass[i].nombreArchivo);
        printf("\n-----------------------------\n");

    fclose(archivo);
        }
     }
    return 1;



}


/** \brief constrae los textos borra los espacio vacios
 *
 * \param source char*
 * \return void
 *
 */
void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
    {
        i++;
    }

  }
  *i = 0;
}



/** \brief modifica DUNA PELICULA PASANDO ESTADO
 *
 * \param aRRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param FLAG DE ACCIONES CON PELICULAS DEL PROGRAMA
 * \return
 *
 */
int modificarPelicula(EMovie peliculas[], int tamanio, int flag)
 {
     int i;
     int idAux;
     int confirm;
     int flagchange=0;
     int opcion;
     EMovie auxmodi[2];
     char seguro='n';

              if(flag!=0)
               {
               listarPeliculas(peliculas, tamanio, 1);
               printf("\n============================================================================\n");
               printf("\n\n Ingrese el Id de la Pelicula que desea Modificar:\t");
               scanf("%d", &idAux);
               for (i=0; i<tamanio;i++)
                            {
                                if (peliculas[i].idPelicula== idAux && peliculas[i].estado==1)
                                    {
                                        flagchange=1;
                                    printf("\n----------------------------");
                                    printf("\nLa pelicula a modificar es\n");
                                    mostrarPeliculaIndividual(peliculas[i]);
                                    printf("\n-------------------------------------------------------------------------\n");
                                    confirm =preguntarSiNo("\nSeguro que desea modificar la pelicula:\t");
                                    if( confirm == 's')
                                    {
                                    auxmodi[0]=peliculas[i]; //copiamos en el auxiliar el original
                                    do {
                                    printf("\n\n\n  == OPCIONES DE DATOS A MODIFICAR == \n\n 1- Titulo \n 2- Genero\n 3- Duracion \n 4- Descripcion\n 5- Link \n 6- Terminar de Modificar \n \t \t Que dato desea modificar?\t");
                                    scanf ("%d", &opcion);

                                    switch(opcion)
                                        {
                                        case 1:
                                            pedirTitulo(auxmodi, 0, TEXTOSCORTOS);
                                            flagchange=2;
                                            break;
                                        case 2:
                                          pedirGenero(auxmodi, 0);
                                          flagchange=2;
                                            break;
                                        case 3:
                                            printf("\nIngrese Duracion: \t"); //DURACION
                                            scanf("%d",&auxmodi[0].duracion);
                                            while(! (auxmodi[0].duracion<300 && auxmodi[0].duracion>0))
                                            {
                                            fflush(stdin);
                                            printf("\nError - Ingrese Duracion Valida: \t");
                                            scanf("%d",&auxmodi[0].duracion);
                                            }
                                            flagchange=2;
                                            break;
                                        case 4:
                                        pedirDescripcion(auxmodi, 0, TEXTOSDESCRIPCION);
                                        flagchange=2;
                                            break;
                                        case 5:
                                           pedirLink(auxmodi, 0, TEXTOSLINK);
                                           flagchange=2;
                                            break;
                                        case 6:
                                               opcion=0;
                                               if (flagchange==2)
                                               {
                                                printf("\nPelicula Original\n");
                                                mostrarPeliculaIndividual(peliculas[i]);
                                                printf("\nPOR\n");
                                                mostrarPeliculaIndividual(auxmodi[0]);
                                                seguro=preguntarSiNo("\nSeguro desea modificar el registo\t");

                                                if (seguro=='s')
                                                {
                                                    peliculas[i]=auxmodi[0];
                                                    asignarNombrehtml(peliculas,i,TEXTOSLINK);

                                                    printf("\n\n\n======================\n Pelicula modificada\n======================\n");
                                                    return 1;
                                                 }
                                                else
                                                {
                                                    printf("\n\n=====================================\n");
                                                    printf("OPERACION CANCELADA");
                                                    printf("\n=====================================\n");
                                                }

                                               }
                                                                                               else
                                                {
                                                    printf("\n\n=====================================\n");
                                                    printf("NO SE MODIFICO NINGUN DATO");
                                                    printf("\n=====================================\n");
                                                }

                                            break;
                                        default:
                                            fflush(stdin);
                                            printf("\n -------- No ingreso una opcion valida -----------");
                                            break;
                                           }
                                        }while (opcion!=0);
                                    }// fin IF PREGUNTA S N
                                    else
                                    {
                                    printf("\n\n=====================================\n");
                                    printf("OPERACION CANCELADA");
                                    printf("\n=====================================\n");
                                    }
                                    break;
                                    } //FIN IF SI
                                } //FIN FOR

               if (flagchange==0)
                         {

                            printf("\n\n=====================================\n");
                            printf(" PELICULA NO EXISTE");
                            printf("\n=====================================\n");

                         }
               }// FIN FLAG !=0

                else
                {
                printf("\n\n=====================================\n");
                printf("NO HAY PELICULAS CARGADOS");
                printf("\n=====================================\n");
                }

 return 0;
 }

/** \brief lista todo
 *
 * \param aRRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 *
 */
  void listarTodo ( EMovie peliculas [], int cant)
 {
            printf("\n");
            printf("ESTADO 1 - PELICULAS ACTIVAS");
            listarPeliculas(peliculas, cant, 1);
            printf("\n");
            printf("ESTADO 2 - BORRADAS DEL LISTAR PERO NO DE SISTEMA");
            listarPeliculas(peliculas, cant,2);
            printf("\n");
            printf("ESTADO 0 - DISPONIBLE\n");
            listarPeliculas(peliculas, cant, 0);
 }




/** \brief genera listado de pelicula en html sin descripcion
 *
 * \param array de estructura de peliculas
 * \param tamanio
 * \return estado
 *
 */
int htmlLISTADO(EMovie peliculass[],int tamanio)
{
    FILE* archivo;
    char buffer[5000]= {};
    //int idAux;
    int i;
/*
    char puntaje[10];
    char auxDuracion[10];
    char fileNam [TEXTOSLINK];*/


        strcat(buffer,"<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'>"
       " <meta name='viewport' content='width=device-width, initial-scale=1'>"
        "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
        "<title>Lista peliculas</title>"
        "<!-- Bootstrap Core CSS -->"
        "<link href='css/bootstrap.min.css' rel='stylesheet'>"
        "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
        "<link href='css/custom.css' rel='stylesheet'>"
        "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
        "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
        "<!--[if lt IE 9]>"
        "    <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
         " <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
        "<![endif]-->"
        "</head>"
        "<body><div class='container'><div class='row'>");
        for (i=0; i<tamanio;i++)
        {
        if (peliculass[i].estado==1 )
            {
        strcat(buffer, "<article class='col-md-4 article-intro'> <a href='");
        //strcat(buffer, "");
        strcat(buffer, peliculass[i].nombreArchivo);
        strcat(buffer, "'>"
        " <img class='img-responsive img-rounded' src='");//http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg
        strcat(buffer,peliculass[i].linkImagen);
        strcat(buffer,"'alt=''>"
        "</a><h3> <a href='#'>");
        strcat(buffer,peliculass[i].titulo);
        /* strcat(buffer,"</a>  </h3>  <ul>   <li>");
        strcat(buffer,"Género: ");
        strcat(buffer,peliculass[i].genero);
        strcat(buffer,"</li> <li>Puntaje: ");
        sprintf(puntaje, "%g", peliculass[i].puntaje);
        strcat(buffer,puntaje);
        strcat(buffer,"</li><li>Duración:");
        sprintf(auxDuracion, "%g", peliculass[i].duracion);
        strcat(buffer,"</li></ul><p>");
        strcat(buffer,peliculass[i].descripcion);*/
        strcat(buffer,"</p>"
            "</article>"
            "<!-- Repetir esto para cada pelicula -->");
            }
            }
            strcat(buffer, "</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script>"
            "<!-- IE10 viewport bug workaround -->"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>"
            "<!-- Placeholder Images -->"
            "<script src='js/holder.min.js'></script>"
            "</body>"
            "</html>");

    archivo = fopen("Pelicula.html","w");
    //////////////////
   if(archivo== NULL)

		{
        printf("\n-----------------------------\n");
        printf(" NULLLLL\t");
        printf("\n-----------------------------\n");
        return 0;
		}

    fprintf(archivo,buffer);
        printf("\n-----------------------------\n");
       // printf(" pelicula %s en html\t", peliculass[i].nombreArchivo);
        printf("\n-----------------------------\n");

    fclose(archivo);

    return 1;



}
