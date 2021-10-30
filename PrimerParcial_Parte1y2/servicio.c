#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"servicio.h"


int mostrarServicios(eServicio servicios[], int tamS)
{
    int retorno = 0;

    if(servicios != NULL && tamS >0)

    {
        printf("\n     ****Lista de servicios ****\n");
        printf("-----------------------------------------------------------------\n");
        printf(" ID                 Descripcion                        Precio   \n");
        printf("------------------------------------------------------------------\n");

        for(int i=0; i<tamS; i++)
        {
            printf(" %5d              %-26s         %.2f\n", servicios[i].idServicio, servicios[i].descServicio, servicios[i].precio);
        }
        retorno = 1;
        printf("\n\n");
    }

    return retorno;
}



int cargaDescServicio(eServicio servicios[], int tamS, int id, char descSErvicio[])
{
    int retorno = 0;

    if(servicios != NULL && tamS >0 && descSErvicio != NULL)
    {
        for (int i=0; i< tamS; i++)
        {
            if(id == servicios[i].idServicio)
            {
                strcpy(descSErvicio, servicios[i].descServicio);
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}



int validarIdServicio(int id, eServicio servicios[], int tamS)
{
    int retorno = 0;

    if(servicios != NULL && tamS >0)
    {
        for (int i=0; i< tamS; i++)
        {
            if(id== servicios[i].idServicio)
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}
