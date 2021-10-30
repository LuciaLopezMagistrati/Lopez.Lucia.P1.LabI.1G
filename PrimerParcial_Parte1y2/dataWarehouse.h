#include "notebook.h"
#include "trabajo.h"
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED


#endif // DATAWAREHOUSE_H_INCLUDED


/** \brief Harcodea datos de pruebas para la estructura notebook
 * \param lista   puntero al array de tipo notebook
 * \param tam     tamanio del array
 * \param lista   puntero al array de tipo cliente
 * \param cant    cantidad de datos a hardcodear
 * \param pId     direccion del Id de notebooks
 * \return contador  retorna en de: error (-1), parametros validados sin
 *  datos harcodeados (0)  o la cantidad de datos hardcodeados (>0).
 *
 */
int hardcodearNotebooks(eNotebook lista[], int tam, eCliente listaC[],int cant, int* pId);


/** \brief Harcodea datos de pruebas para la estructura trabajos
 * \param lista   puntero al array de tipo trabajo
 * \param tam     tamanio del array
 * \param cant    cantidad de datos a hardcodear
 * \param pId     direccion del Id de trabajo
 * \return contador  retorna en de: error (-1), parametros validados sin
 *  datos harcodeados (0)  o la cantidad de datos hardcodeados (>0).
 *
 */
int hardcodearTrabajos(eTrabajo lista[], int tam, int cant, int* pId);

/** \brief Harcodea datos de pruebas para la estructura clientes
 * \param lista   puntero al array de tipo clientes
 * \param tam     tamanio del array
 * \param cant    cantidad de datos a hardcodear
 * \param pId     direccion del Id de trabajo
 * \return contador  retorna en de: error (-1), parametros validados sin
 *  datos harcodeados (0)  o la cantidad de datos hardcodeados (>0).
 *
 */
int hardcodearClientes(eCliente lista[], int tam, int cant, int* pId);
