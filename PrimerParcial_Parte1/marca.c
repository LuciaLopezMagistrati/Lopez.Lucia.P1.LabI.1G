#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "marca.h"

int mostrarMarcas(eMarca marcas[], int tamM)
{
    int retorno = 0;

    if(marcas != NULL && tamM >0)

    {
        printf("\n    ****Lista de marcas ****\n");
        printf("-------------------------------------------------\n");
        printf(" ID                Descripcion                    \n");
        printf("--------------------------------------------------\n");

        for(int i=0; i<tamM; i++)
        {
            printf(" %4d              %-21s       \n", marcas[i].idMarca, marcas[i].descMarca);
        }
        retorno = 1;
        printf("\n\n");
    }

    return retorno;
}



int cargaDescMarca(eMarca marcas[], int tamM, int id, char descMarca[])
{
    int retorno = 0;

    if(marcas != NULL && tamM >0 && descMarca != NULL)
    {
        for (int i=0; i< tamM; i++)
        {
            if(id == marcas[i].idMarca)
            {
                strcpy(descMarca, marcas[i].descMarca);
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}



int validarIdMarca(int id, eMarca marcas[], int tamM)
{
    int retorno = 0;

    if(marcas != NULL && tamM >0)
    {
        for (int i=0; i< tamM; i++)
        {
            if(id== marcas[i].idMarca)
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}
