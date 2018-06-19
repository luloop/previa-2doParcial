
#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#define TEXTOSCORTOS 20
#define TEXTOSDESCRIPCION 200
#define TEXTOSLINK 150

typedef struct{
    char titulo[TEXTOSCORTOS];
    char genero[TEXTOSCORTOS];
    int duracion;
    char descripcion[TEXTOSDESCRIPCION];
    float puntaje;
    char linkImagen[TEXTOSLINK];
    int estado;
    int idPelicula;
    char nombreArchivo[TEXTOSLINK];
    int htmlCreado;

}EMovie;


/** \brief Funcion de Indice
 * \param estructura de peliculas
 * \param tamanio de array de personas
 * \return VOID
 *
 */
void indiceUsuarios (EMovie peliculas[], int tamanio);

/** \brief Alta de Pelicula
 *
 * \param Estructura de peliculas
 * \param tamanio de array de pelicula
 * \return Nuevo Flag
 *
 */
int agregarPelicula(EMovie[], int);


/** \brief DAR DE BAJA UNA PELICULA PASANDO 2 ESTADOS
 *
 * \param aRRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param FLAG DE CONTADOR DEL ARCHIVO
 * \param  FLAG DE ACCIONES CON PELICULAS DEL PROGRAMA
 * \return
 *
 */
int bajaPelicula(EMovie [], int, int, int );


/** \brief mostar una pelicula individual en una sola linea con titulo
 *
 * \param ESTRUCTURA DE 1 PELICULA
 * \return VOID
 *
 */
void mostrarPeliculaIndividual(EMovie peli);



/** \brief mostar una pelicula individual en una sola linea  sin titulos
 * \param dato estructura emovie
 * \return
 *
 */
void mostrarUnaPeliculaParaListado(EMovie peli);



/** \brief armar listado de peliculas con encabezado
 *
 * \param array estructura emovie
 * \param tamanio array
 * \param estado
 * \return
 *
 */
void listarPeliculas(EMovie peliculass[], int tamanio, int estado);


/** \brief Armado de archivos html - pagina individuales con descripcion genero etc
 *
 * \param array estructura emovie
 * \param tamanio array
 * \return
 *
 */
int htmlArmado(EMovie peliculass[],int tamanio);


/** \brief constrae los textos borra los espacio vacios
 *
 * \param source char*
 * \return void
 *
 */
void RemoveSpaces(char* source);



/** \brief modifica DUNA PELICULA PASANDO ESTADO
 *
 * \param aRRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param FLAG DE ACCIONES CON PELICULAS DEL PROGRAMA
 * \return
 *
 */
int modificarPelicula(EMovie peliculas[], int tamanio, int flag);

/** \brief lista todo
 *
 * \param aRRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 *
 */
  void listarTodo ( EMovie peliculas [], int cant);

  /** \brief genera listado de pelicula en html sin descripcion
 *
 * \param array de estructura de peliculas
 * \param tamanio
 * \return estado
 *
 */
int htmlLISTADO(EMovie peliculass[],int tamanio);

#endif // peliculas_H_INCLUDED
