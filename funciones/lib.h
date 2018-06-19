
#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

/** \brief LIMPIAR PANATALLA
 *
 */
void cleanScreen (void);

 /** \brief Pregunta S o N
 * *
 * \param texto de la pregunta
 * \return respuesta
 *
 */
 char preguntarSiNo ( char texto []);

 /** \brief devolver numero random float //////////arreglar!!!!!!!
 * \param
 * \param
 * \return
 *
 */
float devolverPuntaje();


/** \brief Guardar en Archivo en Array que se esta Trabajando
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \return  respuesta si es NULL no se genero el arhcivo correctamente
 */
int guardarEnArchivo(EMovie peliculas [], int cantidad);


/** \brief PREGUNTGA SI DESEA Guardar en Archivo en Array que se esta Trabajando
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \return  respuesta si es NULL no se genero el arhcivo correctamente
 */
int guardarArchivoABM (EMovie peliculas [], int cantidad);

/** \brief CARGA DESDE EL  Archivo AL Array que se esta Trabajando
 * SI NO EXISTE EL ARCHIVO LO GENERA
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \return  respuesta si es NULL no se genero el arhcivo correctamente
 */
int cargarDesdeArchivo(EMovie peliculas[], int cantidad);


/** \brief BUSCA EL PRIMER INDICE ( ESTADO CERO) DISPONIBLE
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \return
 *
 */
int buscarLibre(EMovie peliculas[], int cantidad);



/** \brief CUENTA CUANTOS ELEMENTOS HAY CARGADOS
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \return
 *
 */
int contadorArray (EMovie peliculas [], int tamanio);

/** \brief VALIDACION DE LA CARGA DE TITULO
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param CANTIDAD DE LETRAS QUE TENDRA EL TEXTO
 * \return
 *
 */
void pedirTitulo (EMovie peliculas[], int posicion, int cantTexto);


/** \brief FUCNION PARA ELEGIR EL GENERO
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param POSICION EN EL ARRAY
 * \return
 *
 */
void pedirGenero (EMovie pelicula[], int i);

/** \brief FUCNION PARA ELEGIR EL GENERO
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param POSICION EN EL ARRAY
 * \param TAMAÑO DEL NOMBRE DEL ARCHIVO
 * \return
 *
 */
  void asignarNombrehtml (EMovie pelicula [], int j, int lenLink);

  /** \brief VALIDACION DE LA CARGA DE DESCRIPCION
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param CANTIDAD DE LETRAS QUE TENDRA EL TEXTO
 * \return
 *
 */
void pedirDescripcion(EMovie pelicula [], int j, int lenDescrip);

/** \brief VALIDACION DE LA CARGA DE LINK
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param CANTIDAD DE LETRAS QUE TENDRA EL LINK
 * \return
 *
 */
void pedirLink(EMovie pelicula [], int j, int lenLink);





























#endif // LIB_H_INCLUDED
