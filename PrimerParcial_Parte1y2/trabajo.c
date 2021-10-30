#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"inputs.h"
#include"trabajo.h"
#include"servicio.h"
#include"notebook.h"



int inicializarTrabajos (eTrabajo lista[], int tam)
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


int buscarLibreTrabajo (eTrabajo lista[], int tam)
{
    int retorno = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(lista[i].isEmpty) // if(lista[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;

}


void mostrarTrabajo(eTrabajo trabajo, eServicio lServicios[], int tamS, eNotebook lNotebooks[], int tamN)
{

    char descServicio[26];
    char descNote[21];

    cargaDescServicio(lServicios, tamS,trabajo.idServicio,descServicio);
    cargaDescNotebook(lNotebooks, tamN,trabajo.idNotebook,descNote);

    printf("  %-4d          %-4d           %-21s           %-26s      %02d/%02d/%d \n",
           trabajo.idTrabajo,
           trabajo.idNotebook,
           descNote,
           descServicio,
           trabajo.fechaTrabajo.dia,
           trabajo.fechaTrabajo.mes,
           trabajo.fechaTrabajo.anio

          );

}


int mostrarTrabajos(eTrabajo aTrabajos[], int tamT, eServicio aServicios[], int tamS, eNotebook aNotebooks[], int tamN)
{
    int retorno = 0;
    int flag = 1;


    if(aTrabajos != NULL && tamT > 0 && aServicios != NULL && tamS > 0 && aNotebooks != NULL && tamS > 0)
    {
        //system("cls");
        printf("\n    ****Lista de trabajos ****\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf(" Id Trabajo    Id Notebook     Descripcion notebook            Servicio                        Fecha de trabajo   \n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");

        for(int i= 0; i<tamT; i++)
        {
            if(aTrabajos[i].isEmpty==0)
            {

                mostrarTrabajo(aTrabajos[i], aServicios, tamS, aNotebooks, tamN);
                flag = 0;
            }
        }

        printf("\n\n");
        if(flag)
        {
            printf("No hay notebooks para mostrar\n");
        }
        retorno = 1;
    }

return retorno;
}



int altaTrabajo(eTrabajo aTrabajos[], int tamT,
                eServicio aServicios[], int tamS,
                eNotebook aNotebooks[], int tamN,
                eMarca aMarcas[], int tamMa,
                eTipo aTipos[], int tamTi,
                eCliente aClientes[], int tamC,
                int * pId)
{
    int retorno = -1;
    int indice;
    eTrabajo auxTrabajo;

    if(aTrabajos != NULL && tamT > 0 && aServicios != NULL && tamS > 0 &&
       aNotebooks != NULL && tamN  > 0 && aMarcas != NULL && tamMa  > 0 &&
       aTipos != NULL && tamTi  > 0 && aClientes != NULL && tamC  > 0 && pId != NULL)
    {

        system("cls");
        printf("    *** Alta trabajo*** \n");

        {
            indice = buscarLibreTrabajo(aTrabajos, tamT);

            if(indice == -1)
            {
                printf("No hay lugar");
            }
            else if (

                mostrarNotebooks(aNotebooks, tamN,aMarcas, tamMa,  aTipos,tamTi, aClientes, tamC) &&

                (!utn_getNumeroEntero(&auxTrabajo.idNotebook, "Ingrese el id de la notebook corespondiente al trabajo: ", "\nError.",2000, 4000, 3)) &&
                (validarIdNotebook(aNotebooks, tamN,auxTrabajo.idNotebook)== 1) &&

                 mostrarServicios(aServicios, tamS) &&
                (!utn_getNumeroEntero(&auxTrabajo.idServicio, "Ingrese el id del sevicio corespondiente al trabajo: ", "\nError.",20000, 20003, 3)) &&
                (validarIdServicio(auxTrabajo.idServicio, aServicios, tamS)== 1) &&

                !utn_getNumeroEntero(&auxTrabajo.fechaTrabajo.dia,"Ingrese el dia del trabajo : ", "Error, dia invalido\n",1,31,3)  &&
                !utn_getNumeroEntero(&auxTrabajo.fechaTrabajo.mes,"Ingrese el mes del trabajo : ", "Error, mes invalido\n",1,12,3)  &&
                !utn_getNumeroEntero(&auxTrabajo.fechaTrabajo.anio,"Ingrese el anio del trabajo : ", "Error, anio invalido\n",2000,3000,3))


                {
                    auxTrabajo.isEmpty = 0;
                    auxTrabajo.idTrabajo = *pId;
                    (*pId)++;
                    aTrabajos[indice] = auxTrabajo;
                    retorno = 1;
                }


            }
        }

    return retorno;

}


int validaTrabajoActivo(eTrabajo lista[], int tam)
{

    int retorno = 0;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
