#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
  int idCliente;
  char nombre[21];
  char sexo;
  int isEmpty;

}eCliente;

#endif // CLIENTE_H_INCLUDED


/** \brief Incializa todas las posiciones como vacio, asignando el valor 1 en el campo isEmpty
*
* \param  puntero al array de tipo Cliente
* \param  tamanio del array
* \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
*
*/
int inicializarCliente (eCliente lista[], int tam);


/** \brief Muestra un cliente
 *
 * \param   puntero al array de tipo cliente
 * \param   puntero al array de tipo localidad
 * \param   tamanio del array
 *
 * \return no aplica
 *
 */
 void mostrarCliente(eCliente cliente);


/** \brief Muestra listado de clientes
 *
 * \param  puntero al array de tipo clientes
 * \param  tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int mostrarClientes(eCliente aClientes[], int tamC);


/** \brief Valida el id del cliente este comprendido en el array
 *
 * \param id del cual se requiere validar
 * \param  puntero al array de tipo cliente
 * \param tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int validarIdCliente(int id, eCliente cliente[], int tamC);



/** \brief Carga el nombre de un cliente
 *
 * \param  puntero al array de tipo cliente
 * \param  tamanio del array
 * \param  id del cual se requiere obtener la descripcion
 * \param  la direccion al array en donde cargar la cadena de caracteres
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int cargaNombreCliente(eCliente lClientes[], int tamCl, int idCliente, char nombreCliente[]);
