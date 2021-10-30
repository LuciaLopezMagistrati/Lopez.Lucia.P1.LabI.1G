#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"tipo.h"


int mostrarTipos(eTipo tipos[], int tamT)
{
    int retorno = 0;

    if(tipos != NULL && tamT >0)

    {
        printf("\n     ****Lista de tipos ****\n");
        printf("-------------------------------------------------\n");
        printf(" ID               Descripcion                     \n");
        printf("--------------------------------------------------\n");

        for(int i=0; i<tamT; i++)
        {
            printf(" %4d              %-21s       \n", tipos[i].tipo, tipos[i].descTipo);
        }
        retorno = 1;
        printf("\n\n");
    }

    return retorno;
}



int cargaDescTipos(eTipo tipos[], int tamT, int id, char descTipo[])
{
    int retorno = 0;

    if(tipos != NULL && tamT >0 && descTipo != NULL)
    {

        for (int i=0; i< tamT; i++)
        {
            if(id == tipos[i].tipo)
            {
                strcpy(descTipo, tipos[i].descTipo);
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}



int validarIdTipo(int id, eTipo tipos[], int tamT)
{
    int retorno = 0;

    if(tipos != NULL && tamT >0)
    {
        for (int i=0; i< tamT; i++)
        {

            if(id== tipos[i].tipo)
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}
