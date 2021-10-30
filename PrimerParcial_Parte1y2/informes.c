#include"informes.h"

int listarInformes (eNotebook lNotebooks[], int tamN, eTrabajo lTrabajos[], int tamTr,
                    eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamTi,
                    eCliente lClientes[], int tamC, eServicio lServicios[], int tamS)
{

    int retorno = 0;
    int opcion;
    char seguir = 's';

    do
    {
        utn_getNumeroEntero(&opcion, "\n   *** Menu informes  *** \n\n"
                            " 1. Listar notebook de tipo seleccionado\n"
                            " 2. Listar notebook de marca seleccionada\n"
                            " 3. Listar la/s notebook/s mas baratas\n"
                            " 4. Listar notebooks separadas por Marca\n"
                            " 5. Listar cantidad de notebooks por tipo y marca seleccionada\n"
                            " 6. Listar la/s notebook/s mas elegidas\n"
                            " 7. Listar los trabajos por notebook\n"
                            //" 8. Listar la suma de los importes de los servicios por notebook\n"
                            " 9. Listar la/s notebooks por servicio\n"
                            "10. Listar los servicios por fecha\n"
                            "11. Salir\n\n"
                            "Seleccione una opcion: ",
                            "\nOpcion invalida. \n\n",1,30, 3);


        switch(opcion)
        {
        case 1: // Listar notebook de tipo seleccionado
            listarNoteTipo(lNotebooks,  tamN, lTipos, tamTi, lMarcas, tamMa,  lClientes, tamC);
            break;
        case 2: // Listar notebook de marca seleccionada
            listarNoteMarca(lNotebooks,tamN,lTipos,tamTi, lMarcas, tamMa, lClientes, tamC);
            break;
        case 3: // Listar la/s notebook/s mas baratas
            listarNoteBaratas(lNotebooks,tamN,lMarcas, tamMa, lTipos,tamTi, lClientes, tamC);
            break;
        case 4: // Listar notebooks separadas por Marca
            listarAllNotesMarca(lNotebooks,tamN,lMarcas, tamMa, lTipos,tamTi, lClientes, tamC);
            break;
        case 5: // Listar cantidad de notebooks por tipo y marca seleccionada
            listarCantNotexMarcayTipo(lNotebooks,tamN,lMarcas, tamMa, lTipos,tamTi);
            break;
        case 6: // Listar la/s notebook/s mas elegidas
            listarMarcasMasElegidas(lNotebooks,tamN,lMarcas, tamMa);
            break;
        case 7: // Listar los trabajos por notebook
            listarTrabajosDeNotebook(lNotebooks,tamN,lMarcas, tamMa, lTipos,tamTi,lClientes, tamC,
                                     lServicios, tamS, lTrabajos, tamTr);
            break;
        case 8:
            break;
        case 9:
            servicioPorNotebook(lNotebooks,tamN, lTrabajos, tamTr,lMarcas, tamMa,lTipos,tamTi,lClientes, tamC, lServicios, tamS);
            break;
        case 10:
            servicioPorFecha(lNotebooks,tamN,lTrabajos, tamTr,lServicios, tamS);
            break;
        case 11:
            printf("Ha seleccionado salir\n\n");
            seguir = 'n';
            break;

        }
    }
    while(seguir != 'n');

    return retorno;

}


int listarNoteTipo(eNotebook lista[], int tamN, eTipo lTipos[], int tamT, eMarca lMarcas[], int tamMa, eCliente lClientes[], int tamC)
{
    int retorno = 0;
    int idTipo;

    if(lista != NULL && tamN>0 && lTipos !=NULL && tamT>0 && lMarcas!= NULL && tamMa>0 && lClientes!= NULL && tamC>0)
    {
        system("cls");
        printf("    ****Lista notebooks por tipo****\n\n");

        mostrarTipos(lTipos, tamT);
        if ((!utn_getNumeroEntero(&idTipo, "Ingrese el id del tipo: ","Error\n",5000,5003,3)))
        {
            while(validarIdTipo(idTipo,lTipos, tamT)!=1)
            {

                utn_getNumeroEntero(&idTipo, "Ingrese el id del tipo: ","Error\n",5000,5003,3);
            }
        }


        mostrarNotebooksTipo(lista, tamN, lMarcas, tamMa, lTipos,tamT, lClientes, tamC, idTipo);
        retorno = 1;
    }
    return retorno;

}


int mostrarNotebooksTipo(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC, int id)
{
    int retorno = 0;
    int flag;
    char descNotebok[21];
    if(lNotebooks != NULL && tamN>0 && lMarcas !=NULL && tamMa>0 && lTipos != NULL && tamT>0 && lClientes !=NULL && tamC>0)
    {

        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf(" Id    Descripcion              Marca                  Tipo                       Precio      Cliente  \n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        for(int i= 0; i<tamN; i++)
        {
            if(!lNotebooks[i].isEmpty && lNotebooks[i].idTipo == id)
            {

                mostrarNotebook(lNotebooks[i],lMarcas, tamMa, lTipos,tamT, lClientes, tamC);
                flag = 0;
            }


        }
        if(flag)
        {
            cargaDescTipos(lTipos, tamT, id,descNotebok);
            printf("No hay notebooks para mostrar del tipo %s\n",descNotebok);
        }
        printf("\n\n");
        retorno = 1;
    }

    return retorno;
}


int listarNoteMarca(eNotebook lista[], int tamN, eTipo lTipos[], int tamT, eMarca lMarcas[], int tamMa, eCliente lClientes[], int tamC)
{
    int retorno = 0;
    int idMarca;

    if(lista != NULL && tamN>0 && lTipos !=NULL && tamT>0 && lMarcas!= NULL && tamMa>0 && lClientes!= NULL && tamC>0)
    {
        system("cls");
        printf("    ****Lista notebooks de marca****\n\n");

        mostrarMarcas(lMarcas, tamMa);
        if ((!utn_getNumeroEntero(&idMarca, "Ingrese el id de la marca: ","Error\n",1000,1003,3)))
        {
            while(validarIdMarca(idMarca,lMarcas, tamMa)!=1)
            {

                utn_getNumeroEntero(&idMarca, "Ingrese el id de la marca: ","Error\n",1000,1003,3);
            }
        }


        mostrarNotebooksMarca(lista, tamN, lMarcas, tamMa, lTipos,tamT, lClientes, tamC, idMarca);
        retorno = 1;
    }
    return retorno;

}

int mostrarNotebooksMarca(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC, int id)
{
    int retorno = 0;
    int flag;
    char descNotebok[21];
//
    if(lNotebooks != NULL && tamN>0 && lMarcas !=NULL && tamMa>0 && lTipos != NULL && tamT>0 && lClientes !=NULL && tamC>0)
    {

        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf(" Id    Descripcion              Marca                  Tipo                       Precio      Cliente  \n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        for(int i= 0; i<tamN; i++)
        {
            if(!lNotebooks[i].isEmpty && lNotebooks[i].idMarca == id)
            {

                mostrarNotebook(lNotebooks[i],lMarcas, tamMa, lTipos,tamT, lClientes, tamC);
                flag = 0;
            }


        }
        if(flag)
        {
            cargaDescMarca(lMarcas, tamMa, id,descNotebok);
            printf("No hay notebooks para mostrar de la marca %s\n",descNotebok);
        }
        printf("\n\n");
        retorno = 1;
    }

    return retorno;
}


int listarNoteBaratas(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC)
{
    int retorno = 0;
    int flag=1;
    float menorPrecio;

    if(lNotebooks != NULL && tamN>0 && lMarcas !=NULL && tamMa>0 && lTipos != NULL && tamT>0 && lClientes !=NULL && tamC>0)
    {
        for(int i= 0; i<tamN; i++)
        {
            if(!lNotebooks[i].isEmpty)
            {
                if(flag || lNotebooks[i].precioNotebook < menorPrecio)
                {
                    menorPrecio = lNotebooks[i].precioNotebook;
                    flag =0;
                }

            }

        }


        system("cls");
        printf("    **** Notebook mas barata ****\n");

        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf(" Id    Descripcion              Marca                  Tipo                       Precio      Cliente  \n");
        printf("---------------------------------------------------------------------------------------------------------\n");

        for(int i= 0; i<tamN; i++)
        {
            if(!lNotebooks[i].isEmpty && lNotebooks[i].precioNotebook== menorPrecio)
            {

                mostrarNotebook(lNotebooks[i],lMarcas, tamMa, lTipos,tamT, lClientes, tamC);
            }

        }
        printf("\n\n");
        retorno = 1;
    }

    return retorno;
}




int listarAllNotesMarca (eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT, eCliente lClientes[], int tamC)
{
    int retorno = 0;


    if(lNotebooks != NULL && tamN>0 && lMarcas !=NULL && tamMa>0 && lTipos != NULL && tamT>0 && lClientes !=NULL && tamC>0)
    {

        printf("\n    ****Lista notebooks por marca****\n\n");
        for(int i=0; i<tamMa; i++)
//
        {
            printf("\nMarca: %s\n",lMarcas[i].descMarca);
            mostrarNotebooksMarca(lNotebooks, tamN, lMarcas, tamMa, lTipos,tamT, lClientes, tamC, lMarcas[i].idMarca);
            printf("\n");
        }
        retorno = 1;
    }

    return retorno;
}



int listarCantNotexMarcayTipo(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamT)
{
    int retorno = 0;
    int cantidad = 0;
    int auxIdMarca;
    int auxIdTipo;
    char auxDescMarca[21];
    char auxDescTipo[21];

    if(lNotebooks != NULL && tamN>0 && lMarcas !=NULL && tamMa>0 && lTipos !=NULL && tamT>0)
    {
        system("cls");

        printf("\n    ****Cantidad de notebooks por marca y tipo****\n\n");

        if(
            (mostrarMarcas (lMarcas, tamMa) &&
             !utn_getNumeroEntero(&auxIdMarca,"Ingrese el id de la marca: ", "Error, id de la marca es invalido\n",1000,1003,3)  &&
             validarIdMarca(auxIdMarca, lMarcas, tamMa))&&

            mostrarTipos(lTipos, tamT)&&
            ( !utn_getNumeroEntero(&auxIdTipo,"Ingrese el id del tipo: ", "Error, id del tipo es invalido\n",5000,5003,3)
              && (validarIdTipo(auxIdTipo,lTipos, tamT)==1)) )
            {
                for(int i=0; i<tamN; i++)
                {

                    if(!lNotebooks[i].isEmpty && lNotebooks[i].idMarca==auxIdMarca && lNotebooks[i].idTipo==auxIdTipo)
                    {
                        cantidad++;
                    }
                }

                cargaDescMarca(lMarcas, tamMa, auxIdMarca, auxDescMarca);
                cargaDescTipos(lTipos, tamT,auxIdTipo, auxDescTipo);

                printf("\n\n Para la marca: %-21s y el tipo:  %-21s, la cantidad notebooks:%d\n", auxDescMarca, auxDescTipo, cantidad);
                retorno = 1;
            }

        printf("\n\n");
    }


return retorno;
}






int listarMarcasMasElegidas(eNotebook lNotebooks[], int tamN, eMarca lMarcas[], int tamMa)
{
    int retorno = 0;
    int contadores[]= {0,0,0,0};
    int mayor;

    if(lNotebooks != NULL && tamN>0 && lMarcas !=NULL && tamMa>0)
    {
        system("cls");
        printf("\n    ****Lista de la/s marca/s mas elegidas****\n\n");

        for(int i=0; i<tamMa; i++)
        {

            for(int j=0; j<tamN; j++)
            {
                if(!lNotebooks[j].isEmpty && lNotebooks[j].idMarca==lMarcas[i].idMarca)
                {
                    contadores[i]++;
                }
            }
        }

        for(int i=0; i<tamMa; i++)
        {
            if(i==0 || contadores[i] > mayor)
            {
                mayor = contadores[i];
            }
        }

        for(int i=0; i<tamMa; i++)
        {
            if(contadores[i] == mayor)
            {
                printf(" Marca: %s\n", lMarcas[i].descMarca);
            }
        }

        printf("\n");
    }


    return retorno;
}



int listarTrabajosDeNotebook(eNotebook lNotebooks[], int tamN,
                             eMarca lMarcas[], int tamMa,
                             eTipo lTipos[], int tamTi,
                             eCliente lClientes[], int tamC,
                             eServicio lServicios[], int tamS,
                             eTrabajo lTrabajos[], int tamTr)
{
    int retorno = 0;
    int auxIdNote;

    if(lNotebooks != NULL && tamN>0 && lTrabajos !=NULL && tamTr>0)
    {

        mostrarNotebooks(lNotebooks, tamN, lMarcas, tamMa,  lTipos,tamTi,lClientes, tamC);

        if(
            (  validaNotebookActiva(lNotebooks, tamN) &&
               !utn_getNumeroEntero(&auxIdNote, "Ingrese el id de la notebook corespondiente al trabajo: ", "\nError.",2000, 4000, 3)) &&
            (validarIdNotebook(lNotebooks, tamN,auxIdNote)== 1))
        {

            system("cls");
            printf("    **** Trabajo/s por notebook ****\n");

            printf("\n--------------------------------------------------------------------------------------------------------------\n");
            printf(" Id Trabajo    Id Notebook     Descripcion notebook            Servicio                        Fecha de trabajo \n");
            printf("----------------------------------------------------------------------------------------------------------------\n");

            for(int i= 0; i<tamTr; i++)
            {
                if(!lNotebooks[i].isEmpty && lTrabajos[i].idNotebook== auxIdNote)
                {

                    mostrarTrabajo(lTrabajos[i], lServicios, tamS, lNotebooks,tamN);
                }

            }
            printf("\n\n");
            retorno = 1;
        }




    }

    return retorno;
}




int servicioPorNotebook(eNotebook lNotebooks[], int tamN, eTrabajo lTrabajos[], int tamTr,
                        eMarca lMarcas[], int tamMa, eTipo lTipos[], int tamTi,
                        eCliente lClientes[], int tamC, eServicio lServicios[], int tamS)

{
    int retorno = 0;
    int auxServicio;
    char descServ[26];

    if(lNotebooks != NULL && tamN>0 && lTrabajos !=NULL && tamTr>0 &&
            lMarcas !=NULL && tamMa>0 && lTipos != NULL && tamTi>0 &&
            lClientes !=NULL && tamC>0 && lServicios !=NULL && tamS>0)
    {
        if(     mostrarServicios(lServicios, tamS) &&
                (!utn_getNumeroEntero(&auxServicio, "Ingrese el id del sevicio: ", "\nError.",20000, 20003, 3)) &&
                (validarIdServicio(auxServicio, lServicios, tamS)== 1))
        {
            //system("cls");
            cargaDescServicio(lServicios, tamS,auxServicio,descServ);

            printf("\n    **** Lista de notebooks por Servicio: %-26s ****\n\n", descServ);

            printf("---------------------------------------------------------------------------------------------------------\n");
            printf(" Id    Descripcion              Marca                  Tipo                       Precio      Cliente  \n");
            printf("---------------------------------------------------------------------------------------------------------\n");

            for(int j= 0; j<tamN; j++)
            {
                if(!lNotebooks[j].isEmpty && lTrabajos[j].idServicio== auxServicio)
                {
                    mostrarNotebook(lNotebooks[j], lMarcas, tamMa, lTipos,tamTi, lClientes, tamC);

                }
            }
            printf("\n\n");
            retorno = 1;
        }
    }


    return retorno;
}











int servicioPorFecha(eNotebook lNotebooks[], int tamN, eTrabajo lTrabajos[], int tamTr, eServicio lServicios[], int tamS)
{
    int retorno = 0;
    eFecha auxFecha;
    char descServ[26];
    int flag = 1;

    if(lNotebooks != NULL && tamN>0 && lTrabajos !=NULL && tamTr>0 && lServicios !=NULL && tamS>0)
    {
        if(
            !utn_getNumeroEntero(&auxFecha.dia,"Ingrese el dia : ", "Error, dia invalido\n",1,31,3)  &&
            !utn_getNumeroEntero(&auxFecha.mes,"Ingrese el mes : ", "Error, mes invalido\n",1,12,3)  &&
            !utn_getNumeroEntero(&auxFecha.anio,"Ingrese el anio : ", "Error, anio invalido\n",2000,3000,3))

        {
            //system("cls");
            //

            printf("\n    **** Lista de servicios por fecha: %02d/%02d/%d****\n\n", auxFecha.dia,
                   auxFecha.mes,
                   auxFecha.anio);

            for(int j= 0; j<tamTr; j++)
            {
                if(!lTrabajos[j].isEmpty && lTrabajos[j].fechaTrabajo.dia == auxFecha.dia &&
                        lTrabajos[j].fechaTrabajo.mes == auxFecha.mes && lTrabajos[j].fechaTrabajo.anio == auxFecha.anio)
                {
                    cargaDescServicio(lServicios, tamS,lTrabajos[j].idServicio,descServ);
                    printf("Idservicio: %5d, descripcion: %-26s \n",lTrabajos[j].idServicio, descServ);
                    flag = 0;
                }

            }
            if(flag)
            {
                printf("No hay servicios para la fecha seleccioanda\n");
            }
            printf("\n\n");
            retorno = 1;
        }
    }


    return retorno;
}
