#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define TAMH 4
#define TAMM 5
#include "funciones.h"
 //gjhcd,ljhdcvjl.,dhvdj,hvd
int main()
{
    int id = 8000;
    int idT = 3000;
    char seguir = 's';
    int flag =0;

    eElectrodomestico lista[TAM];

    eMarca marcas[TAMM] = {{1000, "Wirpool"},{1001, "Sony"},{1002, "Liliana"},{1003, "Gafa"},{1004, "Philips"}};

    eServicio servicios[TAMH] = {{20000, "Garantia", 250},{20001, "Mantenimiento", 500},{20002, "Repuestos", 400},{20003, "Refaccion",600}};

    eTrabajo trabajos[TAM];


    inicializarElectrodomesticos(lista, TAM);

    inicializarTrabajos(trabajos, TAM);

    do
    {

        switch (menu())
        {

        case 1:
            if(altaElectrodomestico( id, lista, TAM, marcas, TAMM ) == 1)
            {
                id++;
                flag =1;

            }
            break;

        case 2:
            if(flag == 0)
            {
                printf("\n\nNo dio de alta ningun Electrodomestico\n\n ");
                system("pause");
                system("cls");
            }
            else
            {
                modificarElectrodomestico (lista, TAM, marcas, TAMM );
                system("cls");
            }


            break;

        case 3:

            if(flag == 0)
            {
                printf("\n\nNo dio de alta ningun electrodomestico \n\n");
                system("pause");
                system("cls");

            }
            else
            {
                bajaElectrodomestico(lista, TAM, marcas, TAMM);
                system("pause");
                 system("cls");
            }

            break;

        case 4:

            if(flag == 0)
            {
                printf("\n\nNo dio de alta ningun electrodomestico \n\n");
                system("pause");
                system("cls");
            }
            else
            {

                mostrarElectrodomesticos(lista, TAM, marcas, TAMM);
                system("pause");
                system("cls");
            }


            break;

        case 5:
            mostrarMarcas(marcas, TAMM);
            system("pause");
            system("cls");

            break;

        case 6:

            mostrarServicios(servicios, TAMH);
            system("pause");
            system("cls");
            break;


        case 7:

            if(flag == 0)
            {
                printf("\n\nNo dio de alta ningun Electrodomestico\n\n");
                system("pause");
                system("cls");


            }
            else
            {



                if(altaTrabajo( idT, trabajos, TAM,lista, TAM, servicios, TAMH, marcas, TAMM)== 1)
                {

                    idT ++;

                }

            }

             break;

        case 8:
            mostrarTrabajos(trabajos, TAM, lista, TAM, marcas, TAMM, servicios, TAMH);
            system("pause");
            system("cls");


            break;

        case 9:
                    informar(lista, TAM, marcas, TAMM, trabajos, TAM, servicios, TAMH);


            break;


        case 10:

           seguir = 'n';

            break;

        default:

            printf("OPCION NO VALIDA\n\n");
        }

    }
    while (seguir =='s');


    return 0;
}
