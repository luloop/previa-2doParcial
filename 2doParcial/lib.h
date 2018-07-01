
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
int preguntarSiNo ( char texto []);

 /** \brief devolver numero random float //////////arreglar!!!!!!!
 * \param
 * \param
 * \return
 *
 */
float devolverPuntaje();



/** \brief CUENTA CUANTOS ELEMENTOS HAY CARGADOS
 *
 * \param ARRAY ESTRUCTURA Employee
 * \param TAMANIO DEL ARRAY
 * \return
 *
 */
int contadorArray (Employee*, int tamanio);

/** \brief VALIDACION DE LA CARGA DE TITULO
 *
 * \param ARRAY ESTRUCTURA Employee
 * \param TAMANIO DEL ARRAY
 * \param CANTIDAD DE LETRAS QUE TENDRA EL TEXTO
 * \return
 *
 */
void pedirTitulo (Employee*, int posicion, int cantTexto);


/** \brief FUCNION PARA ELEGIR EL GENERO
 *
 * \param ARRAY ESTRUCTURA Employee
 * \param POSICION EN EL ARRAY
 * \return
 *
 */
void pedirGenero (Employee*, int i);

/** \brief FUCNION PARA ELEGIR EL GENERO
 *
 * \param ARRAY ESTRUCTURA Employee
 * \param POSICION EN EL ARRAY
 * \param TAMAÑO DEL NOMBRE DEL ARCHIVO
 * \return
 *
 */
  void asignarNombrehtml (Employee*, int j, int lenLink);

  /** \brief VALIDACION DE LA CARGA DE DESCRIPCION
 *
 * \param ARRAY ESTRUCTURA Employee
 * \param TAMANIO DEL ARRAY
 * \param CANTIDAD DE LETRAS QUE TENDRA EL TEXTO
 * \return
 *
 */
void pedirDescripcion(Employee*, int j, int lenDescrip);

/** \brief VALIDACION DE LA CARGA DE LINK
 *
 * \param ARRAY ESTRUCTURA Employee
 * \param TAMANIO DEL ARRAY
 * \param CANTIDAD DE LETRAS QUE TENDRA EL LINK
 * \return
 *
 */
void pedirLink(Employee*, int j, int lenLink);





























#endif // LIB_H_INCLUDED
