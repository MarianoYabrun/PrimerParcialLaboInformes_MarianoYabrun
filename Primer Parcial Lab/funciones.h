#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct
{

    int id;
    char descripcion[20];

}eMarca;

typedef struct
{

    int id;
    int serie;
    int idMarca;
    int modelo;
    int isEmpty;



}eElectrodomestico;




typedef struct
{

    int id;
    char descripcion[25];
    float precio;


}eServicio;


typedef struct
{
    int id;
    int serie;
    int idServicio;
    eFecha fecha;
    int isEmpty;


}eTrabajo;


#endif // FUNCIONES_H_INCLUDED

int menu();

int buscarLibre( eElectrodomestico vec[], int tam);

int altaElectrodomestico( int id, eElectrodomestico vec[], int tam, eMarca marcas[], int tamM);

void inicializarElectrodomesticos(eElectrodomestico vec[], int tam);

int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tamH);

void mostrarNotebook(eElectrodomestico x, eMarca marcas[], int tamM);

void mostrarElectrodomesticos(eElectrodomestico  vec[], int tam, eMarca marcas[], int tamM);

void ordenarElectrodomesticos(eElectrodomestico vec[], int tam);

int buscarElectrodomestico(int id ,eElectrodomestico vec[], int tam);

void bajaElectrodomestico(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM);

void modificarElectrodomestico (eElectrodomestico vec[], int tam, eMarca marcas[], int tamM );

void mostrarMarcas(eMarca marcas[], int tamM);

void mostrarServicios(eServicio servicios[], int tamS);

int altaTrabajo( int idT, eTrabajo vec[], int tamTR, eElectrodomestico lista[], int tam, eServicio servicios[], int tamS, eMarca marcas[], int tamM);

int buscarLibreTrabajo( eTrabajo vec[], int tam);

void inicializarTrabajos(eTrabajo vec[], int tam);

 void mostrarTrabajos(eTrabajo vec[], int tam, eElectrodomestico lista[], int tamL, eMarca marcas[], int tamM, eServicio servicios[], int tamS );

int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tamS);

int menuInformes();

void mostrarElectrodomesticosxMarca(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM );

void mostrarElectrodomesticos2020(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM );

void informar(eElectrodomestico vec[], int tam, eMarca marcas[], int tamM, eTrabajo vect[], int tamT, eServicio servicios[], int tamS);

void FacturacionMantenimientos(eTrabajo vec[], int tamT);

void contadorDeServicios(eTrabajo vec[], int tamT);

void mostrarTrabajosPorId (eTrabajo vec[], int tamT, eElectrodomestico lista[], int tam, eMarca marcas[], int tamM,eServicio servicios[], int tamS);
