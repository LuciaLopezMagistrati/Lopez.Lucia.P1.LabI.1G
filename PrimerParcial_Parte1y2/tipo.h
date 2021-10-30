#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int tipo;
    char descTipo[21];

}eTipo;


#endif // TIPO_H_INCLUDED


/** \brief Lista los tipos
 *
 * \param   puntero al array de tipos
 * \param  tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int mostrarTipos(eTipo tipos[], int tamT);


/** \brief Carga la descripcion de un tipo
 *
 * \param  puntero al array de tipo
 * \param  tamanio del array
 * \param  id del cual se requiere obtener la descripcion
 * \param  la direccion al array en donde cargar la cadena de caracteres
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int cargaDescTipos(eTipo tipos[], int tamT, int id, char descTipo[]);


/** \brief Valida el id del tipo este comprendido en el array
 *
 * \param id del cual se requiere validar
 * \param  puntero al array de tipo
 * \param tamanio del array
 *
 * \return int retorna (0) si hubo error [tamanio invalido or puntero nulo] - (1) exito.
 *
 */
int validarIdTipo(int id, eTipo tipos[], int tamT);
