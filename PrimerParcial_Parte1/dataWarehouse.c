#include "dataWarehouse.h"



int idNote [10] = {2002, 2005, 2006, 2009, 2000, 2003, 2007, 2004,2001, 2008};

char descNote [10][21] = {"Qwerty", "Asddff", "zxcvv", "asddff", "Slajhr", "Mnnbvvch","JHhggy", "ASddff","Z", "gfyusd"};

int idMarcaNote [10] = {1003, 1003, 1002, 1002, 1000, 1001, 1002, 1002, 1000, 1000};

int idTipoNote [10] = {5003, 5000, 5000, 5002, 5001, 5003, 5003, 5002, 5001, 5000};

float precioNote [20] = {50030, 254000, 130987, 256734, 98765, 203456, 300000, 54009, 254763, 300000};

int idServicio [10] = {20000, 20003, 20003, 20001, 20002, 20001, 20002, 20000, 20003, 20000};

int idDia [10] = {1,10,28,5,8,10,19,2,9,10};

int idMes [10] = {1,12,2,5,8,10,7,2,9,4};

int idAnio [10] = {2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021,2021, 2021};







int hardcodearNotebooks(eNotebook lista[], int tam, int cant, int* pId)
{
    int contador = -1;

    if(lista != NULL && tam >0 && cant >=0 && cant <=tam && pId != NULL)
    {
        contador =0;

        for (int i = 0; i<cant; i++)
        {
            lista[i].idNotebook = *pId;
            (*pId)++;
            strcpy(lista[i].descNotebook, descNote[i]);
            lista[i].idMarca = idMarcaNote[i];
            lista[i].idTipo= idTipoNote[i];
            lista[i].precioNotebook = precioNote[i];
            lista[i].isEmpty = 0;
            contador++;

        }

    }

    return contador;
}




int hardcodearTrabajos(eTrabajo lista[], int tam, int cant, int* pId)
{
    int contador = -1;




    if(lista != NULL && tam >0 && cant >=0 && cant <=tam && pId != NULL)
    {
        contador =0;

        for (int i = 0; i<cant; i++)
        {
            lista[i].idTrabajo = *pId;
            (*pId)++;
            lista[i].idNotebook = idNote[i];
            lista[i].idServicio = idServicio[i];
            lista[i].fechaTrabajo.dia = idDia[i];
            lista[i].fechaTrabajo.mes = idMes[i];
            lista[i].fechaTrabajo.anio = idAnio[i];
            lista[i].isEmpty = 0;
            contador++;
        }

    }

    return contador;
}

