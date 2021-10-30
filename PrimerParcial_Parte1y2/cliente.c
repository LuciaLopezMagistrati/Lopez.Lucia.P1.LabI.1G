#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"cliente.h"




int inicializarCliente (eCliente lista[], int tam)
{
    int retorno = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        retorno = 1;
    }

    return retorno;
}


void mostrarCliente(eCliente cliente)
{

    printf(" %-4d          %-21s                     %c           \n",
           cliente.idCliente,
           cliente.nombre,
           cliente.sexo

          );

}




int mostrarClientes(eCliente aClientes[], int tamC)
{
    int retorno = 0;
    int flag = 1;


    if(aClientes != NULL && tamC > 0)
    {
        //system("cls");
        printf("\n    ****Lista de clientes ****\n");
        printf("---------------------------------------------------------------------------------------\n");
        printf(" Id             Nombre                                  Sexo                  \n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i= 0; i<tamC; i++)
        {
            if(aClientes[i].isEmpty==0)
            {

                mostrarCliente(aClientes[i]);
                flag = 0;
            }
        }

        printf("\n\n");
        if(flag)
        {
            printf("No hay clientes para mostrar\n");
        }
        retorno = 1;
    }

return retorno;
}


int validarIdCliente(int id, eCliente cliente[], int tamC)
{
    int retorno = 0;

    if(cliente != NULL && tamC >0)
    {
        for (int i=0; i< tamC; i++)
        {
            if(id== cliente[i].idCliente && !cliente[i].isEmpty)
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}



int cargaNombreCliente(eCliente lClientes[], int tamCl, int idCliente, char nombreCliente[])

{
    int retorno = 0;

    if(lClientes != NULL && tamCl >0 && nombreCliente != NULL)
    {
        for (int i=0; i< tamCl; i++)
        {
            if(idCliente == lClientes[i].idCliente && !lClientes[i].isEmpty)
            {
                strcpy(nombreCliente, lClientes[i].nombre);
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}
