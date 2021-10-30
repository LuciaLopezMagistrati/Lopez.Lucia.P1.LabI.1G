#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"notebook.h"
#include"inputs.h"




int inicializarNotebooks (eNotebook lista[], int tam)
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




int buscarLibreNotebook (eNotebook lista[], int tam)
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



int altaNotebook(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC, int * pId)
{
    int retorno = -1;
    int indice;
    eNotebook auxNotebook;

    if(lNotebooks != NULL && tamN > 0 && lMarcas != NULL && tamMa > 0 && lTipos != NULL && tamT > 0 && pId != NULL)
    {

        system("cls");
        printf("    *** Alta notebook*** \n");

        {
            indice = buscarLibreNotebook(lNotebooks, tamN);

            if(indice == -1)
            {
                printf("No hay lugar");
            }
            else if (

                !utn_getDescripcion(auxNotebook.descNotebook, 21, "Ingrese el modelo: ", "Error. Reintente.\n",3) &&


                (mostrarMarcas (lMarcas, tamMa) &&
                 !utn_getNumeroEntero(&auxNotebook.idMarca,"Ingrese el id de la marca: ", "Error, id de la marca es invalido\n",1000,1003,3)  &&
                 validarIdMarca(auxNotebook.idMarca, lMarcas, tamMa))&&

                mostrarTipos(lTipos, tamT)&&
                ( !utn_getNumeroEntero(&auxNotebook.idTipo,"Ingrese el id del tipo: ", "Error, id del tipo es invalido\n",5000,5003,3)
                  && (validarIdTipo(auxNotebook.idTipo,lTipos, tamT)==1))&&

                !utn_getNumeroFlotante(&auxNotebook.precioNotebook, "Ingrese el precio: ", "Error.", 50000.00, 500000.00, 3) &&

                mostrarClientes(lClientes, tamC) &&
                ( !utn_getNumeroEntero(&auxNotebook.idCliente,"Ingrese el id del cliente: ", "Error, id del tipo es invalido\n",8000,9003,3)
                  && (validarIdCliente(auxNotebook.idCliente,lClientes, tamC)==1))

                )

                {
                    auxNotebook.isEmpty = 0;
                    auxNotebook.idNotebook = *pId;
                    (*pId)++;
                    lNotebooks[indice] = auxNotebook;
                    retorno = 1;
                }


        }
    }

    return retorno;

}



void mostrarNotebook(eNotebook notebook, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC)
{

    char descMarca[21];
    char descTipo[21];
    char nombreCliente[21];

    cargaDescMarca(lMarcas, tamMa,notebook.idMarca,descMarca);
    cargaDescTipos(lTipos, tamT,notebook.idTipo,descTipo);
    cargaNombreCliente(lClientes, tamC, notebook.idCliente, nombreCliente);

    printf(" %-4d  %-21s    %-21s  %-21s      %-9.02f   %-21s \n",
           notebook.idNotebook,
           notebook.descNotebook,
           descMarca,
           descTipo,
           notebook.precioNotebook,
           nombreCliente
          );

}



int mostrarNotebooks(eNotebook lnotebook[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC)
{
    int retorno = 0;
    int flag = 1;
    if(lnotebook != NULL && tamN > 0 && lMarcas != NULL && tamMa > 0 &&  lTipos != NULL && tamT > 0 &&  lClientes != NULL && tamC > 0)
    {
        //system("cls");
        printf("\n    ****Lista de notebooks ****\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        printf(" Id    Descripcion              Marca                  Tipo                       Precio      Cliente                 \n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");

        for(int i= 0; i<tamN; i++)
        {
            if(!lnotebook[i].isEmpty)
            {

                mostrarNotebook(lnotebook[i], lMarcas, tamMa, lTipos,tamT, lClientes, tamC);
                flag = 0;
            }
        }

        printf("\n\n");
        if(flag)
        {
            printf("No hay notebooks para mostrar\n\n");
        }
        retorno = 1;
    }

    return retorno;
}




int modificarNotebook(eNotebook lnotebook[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT,eCliente lClientes[], int tamC)
{
    char confirmacionString[2];
    char confirmacionChar;
    int retorno =0;
    int indice;
    int id;
    eNotebook auxNote;
    int opcion;

    if(lnotebook != NULL && tamN > 0 && lMarcas != NULL && tamMa > 0 && lTipos != NULL && tamT > 0 && lClientes != NULL && tamC > 0)
    {
        system("cls");
        printf("        *** Modificar notebook ***\n\n");


        mostrarNotebooks(lnotebook, tamN,lMarcas, tamMa,  lTipos,tamT,lClientes, tamC);

        if(!utn_getNumeroEntero(&id, "Ingrese el id de la notebook a modificar: ", "\nError.",2000, 4000, 3))
        {

            indice = buscarNotebookId (lnotebook, tamN, id);
            if(indice == -1)
            {
                printf("El id: %d no esta registrado en el sistema\n", id);

            }
            else
            {
                printf("--------------------------------------------------------------------------------------------------------------\n");
                printf("Id    Descripcion              Marca                  Tipo                       Precio      Cliente           \n");
                printf("---------------------------------------------------------------------------------------------------------------\n");

                mostrarNotebook(lnotebook[indice], lMarcas, tamMa, lTipos,tamT, lClientes, tamC);

                utn_getChar(confirmacionString,2,"\nConfirma [S-N]: ", "\nError, ingrese S para confirmar, N para cancelar.", 3);

                confirmacionChar = confirmacionString[0];
                confirmacionChar = toupper(confirmacionChar);

                if(confirmacionChar == 'S')
                {

                    utn_getNumeroEntero(&opcion, "\n   *** Menu modificacion Notebook  *** \n\n"
                                        " 1. Modificar precio\n"
                                        " 2. Modificar tipo\n"
                                        " 3. Salir\n\n"
                                        "Seleccione una opcion: ",
                                        "\nOpcion invalida. \n\n",1,3, 3);


                    switch(opcion)
                    {

                    case 1: // precio
                        if(!utn_getNumeroFlotante(&auxNote.precioNotebook,
                                                  "\nIngrese el nuevo precio: ",
                                                  "\nError.\n",
                                                  50000.00, 500000.00,3))
                        {
                            lnotebook[indice].precioNotebook = auxNote.precioNotebook;
                            printf("Precio modificado correctamente\n\n");
                            retorno = 1;
                        }
                        break;
                    case 2: // tipo
                        mostrarTipos(lTipos, tamT);
                        if ((!utn_getNumeroEntero(&auxNote.idTipo, "Ingrese el id del nuevo tipo: ","Error\n",5000,5003,3))
                                && (validarIdTipo(auxNote.idTipo,lTipos, tamT)==1))
                        {
                            lnotebook[indice].idTipo = auxNote.idTipo;
                            printf("Tipo modificado correctamente\n\n");
                            retorno = 1;
                        }
                        break;
                    case 3:
                        printf("Ha seleccionado salir\n");
                        break;
                    default:
                        printf("Opcion invalida\n");

                    }
                }
                else if (confirmacionChar == 'N')
                {
                    printf("Modificacion cancelada por usuario.\n");
                }

            }
        }

    }

    return retorno;
}



int buscarNotebookId(eNotebook lNotebooks[], int tamN, int Id)
{
    int retorno = -1;


    if(lNotebooks != NULL && tamN > 0 )
    {
        for(int i=0; i < tamN; i++)
        {
            if(lNotebooks[i].idNotebook ==  Id && !lNotebooks[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;



}





int bajaNotebook(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT,eCliente lClientes[], int tamC)
{
    char confirmacionString[2];
    char confirmacionChar;
    int retorno =0;
    int indice;
    int id;

    if(lNotebooks != NULL && tamN > 0 && lMarcas != NULL && tamMa > 0 && lTipos != NULL && tamT > 0 && lClientes != NULL && tamC > 0)
    {
        system("cls");
        printf("        *** Baja notebook ***\n\n");


        mostrarNotebooks(lNotebooks, tamN,lMarcas, tamMa,  lTipos,tamT,lClientes, tamC);

        if(!utn_getNumeroEntero(&id, "Ingrese el id de la notebook a dar de baja: ", "\nError.",2000, 4000, 3))
        {

            indice = buscarNotebookId (lNotebooks, tamN, id);

            if(indice == -1)
            {
                printf("El id: %d no esta registrado en el sistema\n", id);

            }
            else
            {
                printf("---------------------------------------------------------------------------------------------------\n");
                printf("Id    Descripcion              Marca                  Tipo                       Precio     Cliente\n");
                printf("---------------------------------------------------------------------------------------------------\n");

                mostrarNotebook(lNotebooks[indice], lMarcas, tamMa, lTipos,tamT,lClientes, tamC);

                utn_getChar(confirmacionString,2,"\nConfirma [S-N]: ", "\nError, ingrese S para confirmar, N para cancelar.", 3);

                confirmacionChar = confirmacionString[0];
                confirmacionChar = toupper(confirmacionChar);

                if(confirmacionChar == 'S')

                {
                    lNotebooks[indice].isEmpty = 1;
                    retorno = 1;
                }
                else if (confirmacionChar == 'N')
                {
                    printf("Baja cancelada por usuario.\n");
                }

            }
        }

    }

    return retorno;
}




int validarIdNotebook(eNotebook lNotebooks[], int tamN, int Id)
{
    int retorno = 0;

    if(lNotebooks != NULL && tamN >0)
    {
        for (int i=0; i< tamN; i++)
        {
            if(lNotebooks[i].idNotebook== Id && !lNotebooks[i].isEmpty)
            {
                lNotebooks[i].idNotebook = Id;
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}





int listarNBCriterios(eNotebook aNotebooks[], int tamN, eMarca aMarcas[], int tamMa, eTipo aTipos[], int tamT, eCliente lClientes[], int tamC)
{
    int result = -1;
    int opcion;

    if(aNotebooks != NULL && tamN >0 && aMarcas != NULL && tamMa >0 && aTipos != NULL && tamT >0 && lClientes != NULL && tamC >0)
    {
        if(!utn_getNumeroEntero(&opcion, "\nIndicar criterio de orden del listado por marca y precio:\n\n"
                                "0. Descendente\n"
                                "1. Ascendente\n\n"
                                "Seleccione una opcion: ",
                                "\nError opcion invalida. Seleccione una opcion del ",0,2,1))

        ordenarNBMarcayPrecio(aNotebooks, tamN, aMarcas, tamMa, opcion);

        mostrarNotebooks(aNotebooks, tamN, aMarcas, tamMa, aTipos, tamT, lClientes, tamC);

        result = 0;
    }

    return result;
}


int ordenarNBMarcayPrecio(eNotebook aList[], int tam, eMarca aMarcas[], int tamM,int criterio)
{
    int retorno = -1;
    eNotebook auxNote;
    char descMarcaPT[21];
    char descMarcaST[21];
    int resultado;


    if(aList!= NULL && tam > 0 && (criterio == 0 || criterio ==1))

    {

        for (int i = 0; i < tam-1; i++)
        {
            for (int j = i+1; j<tam; j++)
            {
                cargaDescMarca(aMarcas,tamM, aList[i].idMarca,descMarcaPT);
                cargaDescMarca(aMarcas,tamM, aList[j].idMarca,descMarcaST);
                resultado= strcmp(descMarcaPT, descMarcaST);

                if(
                    (resultado > 0 && criterio ==1) ||
                    (resultado < 0 && criterio ==0) ||
                    ((resultado == 0) &&
                     (((aList[i].precioNotebook > aList[j].precioNotebook)  && criterio ==1) ||
                     ((aList[i].precioNotebook < aList[j].precioNotebook)  && criterio ==0))))
                {
                    auxNote = aList[i];
                    aList[i] = aList[j];
                    aList[j] = auxNote;
                }
            }


        }
        retorno = 1;
    }

    return retorno;
}


int cargaDescNotebook(eNotebook notebooks[], int tamN, int id, char descNotebook[])
{
    int retorno = 0;

    if(notebooks != NULL && tamN >0 && descNotebook != NULL)
    {
        for (int i=0; i< tamN; i++)
        {
            if(id == notebooks[i].idNotebook && !notebooks[i].isEmpty)
            {
                strcpy(descNotebook, notebooks[i].descNotebook);
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}


int validaNotebookActiva(eNotebook lista[], int tam)
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
