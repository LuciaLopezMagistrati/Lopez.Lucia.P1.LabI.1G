#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"fecha.h"
#include"servicio.h"
#include"notebook.h"


#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int idTrabajo;
    int idNotebook;
    int idServicio;
    eFecha fechaTrabajo;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED



/** \brief Incializa todas las posiciones como vacio, asignando el valor 1 en el campo isEmpty
*
* \param  puntero al array de tipo autos
* \param  tamanio del array
* \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
*
*/
int inicializarTrabajos (eTrabajo lista[], int tam);


/** \brief Busca el primer indice disponible en el array
*
* \param puntero al array de tipo notebook
* \param tamanio del array
* \return int retorna (-1) si hubo error [tamanio invalido or puntero nulo] - (indice) exito.
*/
int buscarLibreTrabajo (eTrabajo lista[], int tam);


/** \brief Muestra un trabajo
 *
 * \param   puntero al array de tipo trabajo
 * \param   puntero al array de tipo sercvicio
 * \param   tamanio del array
 * \param   puntero al array de tipo notebook
 * \param   tamanio del array
 *
 * \return no aplica
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eServicio lServicios[], int tamS, eNotebook lNotebooks[], int tamN);



/** \brief Muestra listado de trabajos
 *
 * \param  puntero al array de tipo trabajo
 * \param  tamanio del array
 * \param   puntero al array de tipo sevicio
 * \param   tamanio del array
 * \param   puntero al array de tipo notebook
 * \param   tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int mostrarTrabajos(eTrabajo aTrabajos[], int tamT, eServicio aServicios[], int tamS, eNotebook aNotebooks[], int tamN);


/** \brief Gestiona el proceso de alta desde la obtencion al grabado de datos
 * \param  puntero al array de tipo trabajo
 * \param  tamanio del array
 * \param  puntero al array de tipo sevicio
 * \param  tamanio del array
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
int altaTrabajo(eTrabajo aTrabajos[], int tamT, eServicio aServicios[], int tamS, eNotebook aNotebooks[], int tamN,
                eMarca aMarcas[], int tamMa, eTipo aTipos[], int tamTi, int * pId);



/** \brief Valida si hay al menos un trabajo activo
 *
 * \param  puntero al array de tipo trabajo
 * \param  tamanio del array
 *
 * \return int retorna (0) sino hay ninguna o hubo error [tamanio invalido or puntero nulo] -
 *          (1) existe al menos un trabajo activo.
 *
 */
int validaTrabajoActivo(eTrabajo lista[], int tam);
