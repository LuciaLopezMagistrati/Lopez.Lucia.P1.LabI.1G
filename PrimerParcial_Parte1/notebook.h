#include"marca.h"
#include"tipo.h"

#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED


typedef struct
{
    int idNotebook;
    char descNotebook[21];
    int idMarca;
    int idTipo;
    float precioNotebook;
    int isEmpty;

}eNotebook;


#endif // NOTEBOOK_H_INCLUDED


/** \brief Incializa todas las posiciones como vacio, asignando el valor 1 en el campo isEmpty
*
* \param  puntero al array de tipo autos
* \param  tamanio del array
* \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
*
*/
int inicializarNotebooks (eNotebook lista[], int tam);


/** \brief Busca el primer indice disponible en el array
*
* \param puntero al array de tipo notebook
* \param tamanio del array
* \return int retorna (-1) si hubo error [tamanio invalido or puntero nulo] - (indice) exito.
*/
int buscarLibreNotebook (eNotebook lista[], int tam);


/** \brief Busca por ID verificando si existe y si esta activo
 *
 * \param puntero al array de tipo notebook
 * \param tamanio del array
 * \param  identificador (ID) a buscar
 *
 * \return (-1) si hubo un error o (valor del indice donde se ubica ese ID dentro de array) en caso de exito
 *
 */
int buscarNotebookId(eNotebook lNotebooks[], int tamN, int Id);


/** \brief Gestiona el proceso de alta desde la obtencion al grabado de datos
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero a la direccion de Id
 * \return int retorna (-1) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int altaNotebook(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT,int * pId);


/** \brief Muestra una notebook
 *
 * \param   puntero al array de tipo notebook
 * \param   puntero al array de tipo marcas
 * \param   tamanio del array
 * \param   puntero al array de tipo tipos
 * \param   tamanio del array
 *
 * \return no aplica
 *
 */
void mostrarNotebook(eNotebook notebook, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT);


/** \brief Muestra listado de notebooks
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param   puntero al array de tipo marcas
 * \param   tamanio del array
 * \param   puntero al array de tipo tipos
 * \param   tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int mostrarNotebooks(eNotebook lnotebook[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT);


/** \brief Gestiona el proceso de modificacion desde la obtencion al grabado de datos
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param   puntero al array de tipo marcas
 * \param   tamanio del array
 * \param   puntero al array de tipo tipos
 * \param   tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int modificarNotebook(eNotebook lnotebook[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT);


/** \brief Busca por ID verificando si existe y si esta activo
 *
 * \param puntero al array de tipo notebook
 * \param tamanio del array
 * \param  identificador (ID) a buscar
 *
 * \return (-1) si hubo un error o (1) en caso de exito
 *
 */
int validarIdNotebook(eNotebook lNotebooks[], int tamN, int Id);


/** \brief Lista las notebooks:  1) solicita al usuario seleccionar un criterio de orden (ascendente o descendente),
        2) ordena el listado llamando a la funcion 'ordenarNBMarcayPrecio' y  3) lo imprime de la funcion mostrarNotebooks
 *
 * \param   puntero al array de tipo notebook
 * \param   tamanio del array
 * \param   puntero al array de tipo marcas
 * \param   tamanio del array
 * \param   puntero al array de tipo tipos
 * \param   tamanio del array
 * \return  retorna (-1) si hubo error [tamanio invalido or puntero nulo] - (0) exito.
 *
 */
int listarNBCriterios(eNotebook aNotebooks[], int tamN, eMarca aMarcas[], int tamMa, eTipo aTipos[], int tamT);


/** \brief Ordena(ascendente o descente) las notebooks por marca y por nombre
 *
 * \param   puntero al array de tipo notebook
 * \param   tamanio del array
 * \param   puntero al array de tipo marcas
 * \param   tamanio del array
 * \param   criterio de ordenamiento (1) ascendente, (0) descendente
 * \return  retorna (-1) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int ordenarNBMarcayPrecio(eNotebook aList[], int tam, eMarca aMarcas[], int tamM,int criterio);


/** \brief Gestiona el proceso de baja desde la obtencion al grabado de datos
 *
 * \param   puntero al array de tipo notebook
 * \param   tamanio del array
 * \param   puntero al array de tipo marca
 * \param   tamanio del array
 * \param   puntero al array de tipo tipo
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int bajaNotebook(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT);


/** \brief Carga la descripcion de una notebook
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  id del cual se requiere obtener la descripcion
 * \param  la direccion al array en donde cargar la cadena de caracteres
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int cargaDescNotebook(eNotebook notebooks[], int tamN, int id, char descNotebook[]);



/** \brief Valida si hay al menos una notebook activa
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 *
 * \return int retorna (0) sino hay ninguna o hubo error [tamanio invalido or puntero nulo] -
 *          (1) existe al menos una notebook activa.
 *
 */
int validaNotebookActiva(eNotebook lista[], int tam);
