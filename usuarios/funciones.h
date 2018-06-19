#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
void indiceUsuarios (ePersona[],int);

/** \brief Alta de usuario
 *
 * \param Estructura de usuario
 * \param tamanio de array de usuarios
 * \return Nuevo Flag
 *
 */
int  altaUsuario (ePersona[],int);


/** \brief Busqueda de espacio disponible via indice para iniciar la carga segun su esta
 * \param Estructura de personas
 * \param tamanio del array
 * \return primer ubicacion disponible en el array
 *
 */
int searchIndexUsers (ePersona[],int );


/** \brief Listado de usuarios cargados, busca estado 1 y publica
 *
 * \param Estructura de personas
 * \param tamaño del array de personas
 * \return
 *
 */
void listadoDeUsuarios (ePersona [],int );

/** \brief Muestra un solo usuario, complementaria al listado
 *
 * \param Estructura de personas
 * \return Void
 *
 */
void showOneUser (ePersona);

  /** \brief Baja de usuario, pasa el status a Numero 2 para dejar disponible los usuarios borrados
 *
 * \param Estructura de Personas
 * \param tamaño del array
 * \param flag de carga de usuarios
 * \return void
 *
 */
void bajaUsuario (ePersona[],int ,int );

/** \brief Ordena por burbujeo alfabeticamente
 *
 * \param Vector Estructura de personas
 * \param tamanio del array de personas
 * \param Flag de estado de carga de usuaarios
 * \return
 *
 */
void mostrarOrdenadoPorNombre (ePersona[],int ,int );

/** \brief Grafico de que muestra la edad de los usuarios
 *
 * \param Vector Estructura de personas
 * \param tamanio del array de personas
 * \return void
 *
 */
void graficos (ePersona[] ,int);


/** \LIMPIA LA PANTALLA
 */
void cleanScreen (void);

/** \brief PEDIR DNI
 *
 * \param DNI
 * \return DNI VALIDADO
 *
 */
 int pedirDNI (void);

   /** \brief PEDIR EDAD
 *
 * \return EDAD VALIDADO
 *
 */
 int pedirEdad (void);

 /** \brief Pregunta S o N
 * *
 * \param texto de la pregunta
 * \return respuesta
 *
 */
 char preguntarSiNo ( char texto []);



#endif // FUNCIONES_H_INCLUDED

