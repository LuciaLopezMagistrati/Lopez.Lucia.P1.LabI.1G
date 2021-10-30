#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include"inputs.h"
#include"fecha.h"
#include"marca.h"
#include"notebook.h"
#include"servicio.h"
#include"tipo.h"
#include"trabajo.h"
#include"dataWarehouse.h"
#include"cliente.h"
#include"informes.h"

#define TAM_NOTEBOOKS 2000
#define TAM_MARCAS 4
#define TAM_TIPOS 4
#define TAM_SERVICIOS 4
#define TAM_CLIENTES 1000
#define TAM_TRABAJOS 2000
#define CANT_INTENTOS 3

int main()
{

    int seguir = 's';
    int nextId = 2000;
    int nextIdTr = 6000;
    int nextIdCl = 8000;
    char opcion[2];
    char opcionChar;
    eNotebook listaNotebooks[TAM_NOTEBOOKS];
    eTrabajo listaTrabajos[TAM_TRABAJOS];
    eCliente listaClientes[TAM_CLIENTES];

    eMarca listaMarcas[TAM_MARCAS] =
    {
        {1000, "Compaq"},
        {1001, "Asus"},
        {1002, "Acer"},
        {1003, "HP"}
    };


    eTipo listaTipos[TAM_TIPOS] =
    {
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };

    eServicio listaServicios[TAM_SERVICIOS] =
    {
        {20000, "Bateria", 2250},
        {20001, "Display", 10300},
        {20002, "Mantenimiento", 4400},
        {20003, "Fuente", 5600}
    };





    if(!inicializarTrabajos(listaTrabajos,TAM_TRABAJOS))
    {
        printf("Problema al inicializar los trabajos\n");
    }

    // hardcodearTrabajos(listaTrabajos,TAM_TRABAJOS,10, &nextIdTr);


    if(!inicializarCliente(listaClientes,TAM_CLIENTES))
    {
        printf("Problema al inicializar los clientes\n");
    }

    // hardcodearClientes(listaClientes, TAM_CLIENTES, 10, &nextIdCl);


    if(!inicializarNotebooks(listaNotebooks,TAM_NOTEBOOKS))
    {
        printf("Problema al inicializar notebooks\n");
    }

    // hardcodearNotebooks(listaNotebooks,TAM_NOTEBOOKS,listaClientes,10, &nextId);

    do
    {

        {
            utn_getChar(opcion, 2, "   *** Menu ABM Notebook  *** \n\n"
                        " A. Alta notebook\n"
                        " B. Modificar notebook\n"
                        " C. Baja notebook\n"
                        " D. Listar notebook\n"
                        " E. Listar marcas\n"
                        " F. Listar tipos\n"
                        " G. Listar servicios\n"
                        " H. Alta trabajo\n"
                        " I. Listar trabajos\n"
                        " J. Listar clientes\n"
                        " K. Informes\n"
                        " Z. Salir\n\n"
                        "Seleccione una opcion: ",
                        "\nOpcion invalida. \n\n", CANT_INTENTOS);

            opcionChar = opcion[0];


            switch(toupper(opcionChar))
            {

            case 'A':

                if(altaNotebook(listaNotebooks,TAM_NOTEBOOKS,listaMarcas, TAM_MARCAS, listaTipos, TAM_TIPOS,listaClientes,TAM_CLIENTES,&nextId)==1)
                {
                    printf("Alta exitosa\n\n");
                }
                else
                {
                    printf("No se pudo realizar el alta\n\n");
                }
                break;


            case 'B':

                if(validaNotebookActiva(listaNotebooks, TAM_NOTEBOOKS))
                {
                    if(modificarNotebook(listaNotebooks,TAM_NOTEBOOKS,listaMarcas, TAM_MARCAS, listaTipos, TAM_TIPOS,listaClientes,TAM_CLIENTES)==1)
                    {
                        printf("Modificacion exitosa\n\n");
                    }
                    else
                    {
                        printf("No se pudo realizar la modificacion\n\n");
                    }
                }
                else
                {
                    printf("\nPara modificar es necesario que existan notebooks activas (ejecutar alta previamente).\n\n");
                }
                break;

            case 'C':
                if(validaNotebookActiva(listaNotebooks, TAM_NOTEBOOKS))
                {
                    if(bajaNotebook(listaNotebooks,TAM_NOTEBOOKS,listaMarcas, TAM_MARCAS, listaTipos, TAM_TIPOS,listaClientes,TAM_CLIENTES)==1)
                    {
                        printf("Baja exitosa\n\n");
                    }
                    else
                    {
                        printf("No se pudo realizar la baja\n\n");
                    }
                }
                else
                {
                    printf("\nPara dar de baja es necesario que existan notebooks activas (ejecutar alta previamente).\n\n");
                }
                break;

            case 'D':
                if(validaNotebookActiva(listaNotebooks, TAM_NOTEBOOKS))
                {
                    listarNBCriterios(listaNotebooks,TAM_NOTEBOOKS,listaMarcas, TAM_MARCAS, listaTipos, TAM_TIPOS,listaClientes,TAM_CLIENTES) ;
                }
                else
                {
                    printf("\nPara listar es necesario que existan notebooks activas (ejecutar alta previamente).\n\n");
                }
                break;

            case 'E':
                mostrarMarcas(listaMarcas, TAM_MARCAS);
                break;

            case 'F':
                mostrarTipos(listaTipos, TAM_TIPOS);
                break;

            case 'G':
                mostrarServicios(listaServicios,TAM_SERVICIOS);
                break;

            case 'H':
                if(validaNotebookActiva(listaNotebooks, TAM_NOTEBOOKS))
                {
                    if(altaTrabajo(listaTrabajos, TAM_TRABAJOS,listaServicios,TAM_SERVICIOS,
                                   listaNotebooks,TAM_NOTEBOOKS,listaMarcas, TAM_MARCAS,
                                   listaTipos, TAM_TIPOS,listaClientes,TAM_CLIENTES,
                                   &nextIdTr)==1)
                    {
                        printf("Alta exitosa\n");
                    }
                    else
                    {
                        printf("No se pudo realizar el alta\n");
                    }
                }
                else
                {
                    printf("\nPara dar de alta trabajos es necesario que existan notebooks activas (ejecutar alta previamente).\n\n");
                }
                break;

            case 'I':
                if(validaTrabajoActivo(listaTrabajos, TAM_TRABAJOS))
                {
                    mostrarTrabajos(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIOS, listaNotebooks, TAM_NOTEBOOKS);
                }
                else
                {
                    printf("\nPara listar es necesario que existan trabajos activos (ejecutar alta previamente).\n\n");
                }
                break;

            case 'J':
                if(validaTrabajoActivo(listaTrabajos, TAM_TRABAJOS))
                {
                    mostrarClientes(listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("\nPara listar es necesario que existan trabajos activos (ejecutar alta previamente).\n\n");
                }
                break;

            case 'K':
                if(validaTrabajoActivo(listaTrabajos, TAM_TRABAJOS))
                {
                    listarInformes(listaNotebooks,TAM_NOTEBOOKS,listaTrabajos, TAM_TRABAJOS,
                                   listaMarcas, TAM_MARCAS, listaTipos, TAM_TIPOS,
                                   listaClientes,TAM_CLIENTES,listaServicios,TAM_SERVICIOS);
                }
                else
                {
                    printf("\nPara listar es necesario que existan trabajos activos (ejecutar alta previamente).\n\n");
                }
                break;

            case 'Z':
                printf("Ha seleccionado salir\n");
                seguir = 'n';
                break;

            default:
                printf("Opcion invalida\n");
                break;
            }
        }

    }
    while(seguir == 's');


    return 0;
}
