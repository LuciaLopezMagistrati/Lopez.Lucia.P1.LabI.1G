#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int idServicio;
    char descServicio[26];
    float precio;

}eServicio;


#endif // SERVICIO_H_INCLUDED


/** \brief Lista los servicios
 *
 * \param   puntero al array de tipo servicios
 * \param  tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int mostrarServicios(eServicio servicios[], int tamS);


/** \brief Carga la descripcion de un servicio
 *
 * \param  puntero al array de tipo servicio
 * \param  tamanio del array
 * \param  id del cual se requiere obtener la descripcion
 * \param  la direccion al array en donde cargar la cadena de caracteres
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int cargaDescServicio(eServicio servicios[], int tamS, int id, char descServicio[]);



/** \brief Valida el id del servicio este comprendido en el array
 *
 * \param id del cual se requiere validar
 * \param  puntero al array de tipo servicio
 * \param tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int validarIdServicio(int id, eServicio servicios[], int tamS);


