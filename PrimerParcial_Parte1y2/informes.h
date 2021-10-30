#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "notebook.h"
#include "tipo.h"
#include "marca.h"
#include "cliente.h"
#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Muestra el menu del listado de informes y lo muestra
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo trabajo
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \param  puntero al array de tipo sevicio
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */

int listarInformes (eNotebook lNotebooks[], int tamN, eTrabajo lTrabajos[], int tamTr,
                    eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamTi,
                    eCliente lClientes[], int tamC, eServicio lServicios[], int tamS);



/** \brief Obtiene el tipo de notebook a mostrar y llama a la funcion que las imprime (mostrarNotebooksTipo)Muestra las notebooks del tipo seleccionado por el usuario.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int listarNoteTipo(eNotebook lista[], int tamN, eTipo lTipos[], int tamT, eMarca lMarcas[], int tamMa, eCliente lClientes[], int tamC);


/** \brief Muestra las notebooks del tipo seleccionado por el usuario.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \param  id del tipo de notebook
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int mostrarNotebooksTipo(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC, int id);


/** \brief Obtiene la marca de notebook a mostrar y llama a la funcion que las imprime (mostrarNotebooksMarca)Muestra las notebooks del tipo seleccionado por el usuario.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int listarNoteMarca(eNotebook lista[], int tamN, eTipo lTipos[], int tamT, eMarca lMarcas[], int tamMa, eCliente lClientes[], int tamC);


/** \brief Muestra las notebooks de la marca seleccionada por el usuario.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \param  id del tipo de notebook
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int mostrarNotebooksMarca(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC, int id);


/** \brief Muestra la o las notebooks más baratas.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \param  id del tipo de notebook
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int listarNoteBaratas(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC);


/** \brief Muestra todas las notebooks separadas por Marca
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int listarAllNotesMarca (eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC);




/** \brief Muestra la cantidad de notebooks por tipo y marca seleccionada por usuario.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo tipo
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int listarCantNotexMarcayTipo(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT);


/** \brief Muestra la o las marcas más elegidas por los clientes.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int listarMarcasMasElegidas(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa);


/** \brief Muestra los trabajas segun la notebook seleccionada por el usuario.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  puntero al array de tipo tipos
 * \param  tamanio del array
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \param  puntero al array de tipo servicio
 * \param  tamanio del array
 * \param  puntero al array de tipo trabajo
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int listarTrabajosDeNotebook(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa,
                             eTipo lTipos[], int tamTi,eCliente lClientes[], int tamC,
                             eServicio lServicios[], int tamS,eTrabajo lTrabajos[], int tamTr);



/** \brief Muestra los servicios realizados para la fecha ingresada por el usuario.
 *
 * \param  puntero al array de tipo notebook
 * \param  tamanio del array
 * \param  puntero al array de tipo trabajo
 * \param  tamanio del array
 * \param  puntero al array de tipo servicio
 * \param  tamanio del array
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int servicioPorFecha(eNotebook lNotebooks[], int tamN, eTrabajo lTrabajos[], int tamTr, eServicio lServicios[], int tamS);




int servicioPorNotebook(eNotebook lNotebooks[], int tamN, eTrabajo lTrabajos[], int tamTr,
                        eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamTi,
                        eCliente lClientes[], int tamC, eServicio lServicios[], int tamS);
