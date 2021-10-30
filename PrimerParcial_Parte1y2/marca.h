#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int idMarca;
    char descMarca[21];

}eMarca;


#endif // MARCA_H_INCLUDED





/** \brief Lista las marcas
 *
 * \param   puntero al array de tipo marcas
 * \param  tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */

int mostrarMarcas(eMarca marcas[], int tamM);


/** \brief Carga la descripcion de una marca
 *
 * \param  puntero al array de tipo marca
 * \param  tamanio del array
 * \param  id del cual se requiere obtener la descripcion
 * \param  la direccion al array en donde cargar la cadena de caracteres
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */

int cargaDescMarca(eMarca marcas[], int tamM, int id, char descMarca[]);



/** \brief Valida el id de la marca este comprendido en el array de marcas
 *
 * \param id del cual se requiere validar
 * \param  puntero al array de tipo marca
 * \param tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */

int validarIdMarca(int id, eMarca marcas[], int tamM);
