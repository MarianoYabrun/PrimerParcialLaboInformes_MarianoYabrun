
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menu()
{
    int opcion;


    printf("\n\n***MENU DE OPCIONES***\n\n");
    printf("1) ALTA \n");
    printf("2) MODIFICAR  \n");
    printf("3) BAJA  \n");
    printf("4) LISTADO DE ELECTRODOMESTICOS\n");
    printf("5) LISTADO MARCAS\n");
    printf("6) LISTADO SERVICIOS\n");
    printf("7) ALTA TRABAJO\n");
    printf("8) LISTADO TRABAJOS\n");
    printf("9) INFORMES\n");
    printf("10) SALIR\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int buscarLibre( eElectrodomestico vec[], int tam)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty ==1)
        {
            indice =i;
            break;
        }

    }
    return indice;
}


int buscarLibreTrabajo( eTrabajo vec[], int tam)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty ==1)
        {
            indice =i;
            break;
        }

    }
    return indice;
}


void inicializarElectrodomesticos(eElectrodomestico vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {

        vec[i].isEmpty = 1;


    }

}

void inicializarTrabajos(eTrabajo vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {

        vec[i].isEmpty = 1;

    }

}



int altaElectrodomestico( int id, eElectrodomestico vec[], int tam, eMarca marcas[], int tamM)
{
    system("cls");
    int indice = buscarLibre(vec, tam);
    eElectrodomestico aux;
    int todoOk;

    if(indice == -1)
    {
        printf("Sistema completo \n\n");
        todoOk =0;

    }
    else
    {
        aux.id = id;

        printf("\n**ALTA**\n");

        printf("\n Ingrese Modelo (anio de fabricacion): ");
        fflush(stdin);
        scanf("%d", &aux.modelo);

        system("cls");

        printf("\n Ingrese Numero de serie: ");
        fflush(stdin);
        scanf("%d", &aux.serie);


        mostrarMarcas(marcas, tamM);
        printf("\n Ingrese id de la marca : ");
        fflush(stdin);
        scanf("%d", &aux.idMarca);
        system("cls");


        while(aux.idMarca != 1000 && aux.idMarca != 1001 && aux.idMarca != 1002 && aux.idMarca != 1003 && aux.idMarca != 1004 )
        {
            mostrarMarcas(marcas, tamM);
            printf("\n El id que ingresaste no existe, Reingrese el id de la marca : ");
            fflush(stdin);
            scanf("%d", &aux.idMarca);
            system("cls");


        }


        aux.isEmpty =0;

        vec[indice] = aux;
        todoOk =1;
    }
    return todoOk;
}

int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tamM)
{
    int todoOk = 0;

    for(int i =0; i<tamM; i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion, marcas[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;
}

int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tamS)
{
    int todoOk = 0;

    for(int i =0; i<tamS; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;
}


void mostrarElectrodomestico(eElectrodomestico x, eMarca marcas[], int tamM)
{

    char descripcionMarca[20];

    cargarDescripcionMarca(descripcionMarca, x.idMarca, marcas, tamM );



    printf("%d ", x.id);
    printf(" %d  ", x.serie);
    printf("  %d  ", x.modelo);
    printf("  %s  ", descripcionMarca );



}


void mostrarElectrodomesticos(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM)
{

    printf("\n\n**** LISTADO DE ELECTRODOMESTICOS****\n\n");
    printf("ID   SERIE  MODELO   MARCA         \n\n");

    int flag =0;

    ordenarElectrodomesticos(vec, tam);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarElectrodomestico(vec[i], marcas, tamM);
            printf("\n");
            flag =1;
        }

        if( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\n No hay Electrodomesticos cargados\n");
            break;
        }

    }

}

void ordenarElectrodomesticos(eElectrodomestico vec[], int tam)
{
    eElectrodomestico aux;

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0 && vec[i].modelo > vec[j].modelo)
            {

                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;


            }
            else if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0 && vec[i].modelo == vec[j].modelo && vec[i].serie > vec[j].serie)
            {

                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;

            }
        }
    }
}

void bajaElectrodomestico(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM)
{
    system("cls");
    int id;
    int indice;
    char confirmar;

    printf("**BAJA**");

    mostrarElectrodomesticos(vec, tam, marcas, tamM);

    printf("\nIngrese id del electrodomestico que quiera eliminar del sistema: ");

    scanf("%d", &id);

    indice = buscarElectrodomestico(id, vec, tam);

    if(indice ==-1)
    {
        printf("\nNo hay Electrodomestico cuyo id sea %d", id);
    }
    else
    {
        printf("\n\n");
        mostrarElectrodomestico(vec[indice], marcas, tamM);

        printf("\nConfirma la baja de este Electrodomestico? presione 's' para confirmar o cualquier otra tecla para cancelar :  ");
        fflush(stdin);
        scanf("%c", &confirmar);

        if(confirmar == 's')
        {
            vec[indice].isEmpty = 1;
            printf("\n\nBAJA EXITOSA\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la operacion\n");
        }

    }
}

int buscarElectrodomestico(int id,eElectrodomestico vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)

    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice =i;
            break;
        }

    }
    return indice;
}

void modificarElectrodomestico (eElectrodomestico vec[], int tam, eMarca marcas[], int tamM )
{

    int id;
    int opcion;
    int indice;
    system("cls");

    printf("***MODIFICAR Electrodomestico***\n\n");

    mostrarElectrodomesticos(vec, tam, marcas, tamM);
    printf("Ingrese id del electrodomestico que desea modificar: ");
    scanf("%d", &id);

    indice = buscarElectrodomestico(id, vec, tam);

    if(indice == -1)
    {
        printf("\nNo existe un electrodomestico con ese ID\n");
    }
    else
    {
        printf("\n\n");

        mostrarElectrodomestico(vec[indice],marcas,tamM );


        printf("\n1- Modificar Serie\n");
        printf("2- Modificar Modelo\n");
        printf("3- Salir\n");
        printf("\nQue dato desea modificar? \n\n");
        scanf("%d", &opcion);



        switch(opcion)
        {

        case 1:


            printf("\nIngrese nuevo numero de serie: ");
            fflush(stdin);
            scanf("%d", &vec[indice].serie);


            break;


        case 2:

            printf("\nIngrese nuevo Modelo: ");
            fflush(stdin);
            scanf("%d", &vec[indice].modelo);

            break;


        case 3:
            break;

        default:
            printf("\nOPCION NO VALIDA\n\n");
            break;
        }
    }
}



void mostrarMarcas(eMarca marcas[], int tamM)
{
    printf("\nID  DESCRIPCION\n\n");

    for(int i=0; i<tamM; i++)
    {

        printf("%d  ", marcas[i].id);
        printf(" %s\n", marcas[i].descripcion);


    }
}

void mostrarServicios(eServicio servicios[], int tamS)
{
    printf("\nID  DESCRIPCION   PRECIO\n\n");

    for(int i=0; i<tamS; i++)
    {

        printf("%d  ", servicios[i].id);
        printf(" %s  ", servicios[i].descripcion);
        printf(" %.2f $ \n", servicios[i].precio);


    }
}

int altaTrabajo(int id, eTrabajo vec[], int tamTR, eElectrodomestico lista[], int tam, eServicio servicios[], int tamS, eMarca marcas[], int tamM)
{
    system("cls");
    eTrabajo aux;
    int idN;
    int idS;
    int indice;
    int todoOk =0;

    int ind = buscarLibreTrabajo(vec, tamTR);
    printf("\n\n***ALTA TRABAJO***\n\n");

    mostrarElectrodomesticos(lista, tam, marcas, tamM);
    printf("\nIngrese el ID del Electrodomestico que desea seleccionar para el trabajo: ");
    scanf("%d", &idN);
    indice = buscarElectrodomestico(idN, lista, tam);


    while( indice == -1)
    {
        printf("\nEste id no corresponde a ningun Electrodomestico, reingrese id: ");
        scanf("%d", &idN);
        indice = buscarElectrodomestico(idN, lista, tam);

    }


    system("cls");

    aux.id = id;

    mostrarServicios(servicios, tamS);
    printf("\nIngrese el id del servicio que desea contratar :  ");
    scanf("%d", &idS);

    while(idS != 20000 && idS != 20001 && idS != 20002 && idS != 20003 )
    {
        printf("\nEl id que ingreso no corresponde a ningun servicio. Reingrese : ");
        scanf("%d", &idS);

    }
    system("cls");


    aux.idServicio = idS;



    mostrarElectrodomesticos(lista, tam, marcas, tamM);

    printf(" \nIngrese el numero de serie del electrodomestico: ");
    fflush(stdin);
    scanf("%d", &aux.serie);


    printf("\nIngrese el dia asignado para el trabajo: ");
    scanf("%d", &aux.fecha.dia);
    while(aux.fecha.dia < 0 || aux.fecha.dia > 31)
    {
        printf("\n El dia ingresado no es valido, Reingrese: ");
        scanf("%d", &aux.fecha.dia);

    }
    printf("\nIngrese el mes asignado para el trabajo: ");
    scanf("%d", &aux.fecha.mes);
    while(aux.fecha.mes < 1 || aux.fecha.mes > 12 )
    {
        printf("\n El mes ingresado no es valido, Reingrese: ");
        scanf("%d", &aux.fecha.mes);


    }
    printf("\nIngrese el anio asignado para el trabajo: ");
    scanf("%d", &aux.fecha.anio);
    while(aux.fecha.anio < 2020)
    {
        printf("\n El anio ingresado debe ser el anio actual o posterior, Reingrese: ");
        scanf("%d", &aux.fecha.anio);

    }


    aux.isEmpty = 0;
    vec[ind] = aux;

    todoOk =1;

    return todoOk;

}

void mostrarTrabajos(eTrabajo vec[], int tam, eElectrodomestico lista[], int tamL, eMarca marcas[], int tamM, eServicio servicios[], int tamS)
{

    printf("\n\n**** LISTADO DE TRABAJOS****\n\n");
    printf(" ID   SERIE   SERVICIO   FECHA     \n\n");

    int flag =0;

    char descripcionServicio [20];

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            printf("%d ", vec[i].id);

            printf("  %d ", vec[i].serie);

            int idS = vec[i].idServicio;
            cargarDescripcionServicio(descripcionServicio,idS, servicios, tamS );
            printf("%s ", descripcionServicio);

            printf("  %d/", vec[i].fecha.dia);
            printf(" %d/", vec[i].fecha.mes);
            printf(" %d  \n\n", vec[i].fecha.anio);


            flag =1;
        }

        if ( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\nNo hay trabajos cargados\n\n");
            break;
        }

    }

}




void informar(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM, eTrabajo vect[], int tamT, eServicio vecs[], int tamS)
{

    char seguir ='s';
    system("cls");


    do
    {

        switch (menuInformes())
        {

        case 1:
            mostrarElectrodomesticos2020(vec,tam,marcas,tamM);

            break;
        case 2:
            mostrarElectrodomesticosxMarca(vec, tam, marcas, tamM);

            break;

        case 3:
            FacturacionMantenimientos(vect,tamT);


            break;

        case 4:
                contadorDeServicios(vect, tamT);


            break;

        case 5:


            break;



        case 7:
            seguir = 'n';
            break;

        default:
            printf("\n opcion no valida");

        }

    }
    while (seguir =='s');

}






int menuInformes()
{
    int opcion;

    system("cls");
    printf("\n\n***Gestion de informes***\n\n");
    printf("1) Mostrar electrodomesticos del 2020 \n");
    printf("2) Mostrar electrodomesticos de marca selecionada\n");
    printf("3) Facturacion mantenimientos \n");
    printf("4) Mostrar el servicio mas pedido \n");
    printf("7) Salir \n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);


    return opcion;
}

void mostrarElectrodomesticosxMarca(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM )
{
    int idM;
    int flag =0;
    printf("\n\n");
    mostrarMarcas(marcas, tamM);
    printf("\nIngrese el ID de la Marca por la cual desea filtrar: ");
    scanf("%d", &idM);

    while(idM != 1000 && idM != 1001 && idM != 1002 && idM != 1003 && idM != 1004 )
    {
        mostrarMarcas(marcas, tamM);
        printf("\n El id que ingresaste no existe, Reingrese id de la Marca : ");
        fflush(stdin);
        scanf("%d", &idM);
        system("cls");
    }



    printf("\n\n**** LISTADO DE ELECTRODOMESTICOS****\n\n");
    printf("ID   SERIE  MODELO   MARCA       \n\n");


    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idMarca == idM)
        {
            mostrarElectrodomestico(vec[i], marcas, tamM);
            printf("\n");
            flag =1;
        }

        if( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\n No hay Electrodomesticos de la marca que selecciono. \n");
            break;
        }

    }

    system("pause");

}

void mostrarElectrodomesticos2020(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM )
{
    int Anio = 2020;
    int flag =0;
    printf("\n\n");


    printf("\n\n**** LISTADO DE ELECTRODOMESTICOS DEL 2020****\n\n");
    printf("ID   SERIE  MODELO   MARCA       \n\n");


    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].modelo == Anio)
        {
            mostrarElectrodomestico(vec[i], marcas, tamM);
            printf("\n");
            flag =1;
        }

        if( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\n No hay Electrodomesticos del anio 2020\n");
            break;
        }

    }

    system("pause");

}

void FacturacionMantenimientos(eTrabajo vec[], int tamT)
{
    int acumulador = 0;

    for(int i=0; i<tamT; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idServicio == 20001)
        {
            acumulador = acumulador +500;

        }

    }


    printf("La facturacion por los mantenimientos fue de %d\n", acumulador );

    system("pause");
}

void contadorDeServicios(eTrabajo vec[], int tamT)
{
    int contadorM =0;
    int contadorG =0;
    int contadorR = 0;
    int contadorRe = 0;


    for(int i=0; i<tamT; i++)
    {
        if(vec[i].idServicio== 20000)
        {
            contadorG ++;
        }
        else if(vec[i].idServicio== 20001)
        {
            contadorM ++;

        }
        else if(vec[i].idServicio== 20002)
        {
            contadorR ++;

        }
        else if(vec[i].idServicio== 20003)
        {
            contadorRe ++;

        }

    }

    if(contadorG > contadorM && contadorG > contadorR && contadorG > contadorRe)
    {
        printf("El servicio mas pedido fue garantias \n\n");

    }
    else if (contadorM > contadorG && contadorM > contadorR && contadorM > contadorRe)
    {
        printf("El servicio mas pedido fue Mantenimientos \n\n");
    }
    else if (contadorR > contadorG && contadorR > contadorM && contadorR > contadorRe)
    {
        printf("El servicio mas pedido fue Repuestos\n\n");
    }
    else if (contadorRe > contadorG && contadorRe > contadorM && contadorRe > contadorR)
    {
        printf("El servicio mas pedido fue Refacciones\n\n");

    }
     system("pause");
}

void mostrarTrabajosPorId (eTrabajo vec[], int tamT, eElectrodomestico lista[], int tam, eMarca marcas[], int tamM,eServicio servicios[], int tamS)
{
    int id;

    mostrarElectrodomesticos(lista, tam, marcas, tamM);

    printf("Ingrese el id del electrodomestico que quiera ver sus reparaciones");
   fflush(stdin);
   scanf("%d", &id);

   for (int i=0;i<tamT;i++)
   {
       if(vec[i].id == id)
       {
           mostrarTrabajos(vec,tamT,lista,tam,marcas,tamM,servicios,tamS);
       }
   }


        system("pause");
}
