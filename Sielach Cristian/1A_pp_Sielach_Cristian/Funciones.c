#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"


int buscarLibre(eCliente lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int buscarLibreAuto(eAuto lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int buscarClientePorId(int id,eCliente lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1 && lista[i].idDuenio==id)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

void variablesCero(eCliente lista[],int i)
{
    lista[i].idDuenio=0;
    strcpy(lista[i].nombre,"\0");
    strcpy(lista[i].apellido,"\0");
    lista[i].direccion=0;
    lista[i].numeroTarjeta=0;
    lista[i].estado=0;
    lista[i].numeroTarjeta=0;
}

void variablesCeroAuto(eAuto lista[],int i)
{
    lista[i].estado=0;
}

void inicializarVariables(eCliente lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCero(lista,i);
    }
}

void inicializarVariablesAutos(eAuto lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCeroAuto(lista,i);
    }
}

void alta(eCliente lista[],int tam)
{
    eCliente nuevoCliente;
    int lugar;

    lugar=buscarLibre(lista,tam);

    if(lugar==-1)
    {
        printf("No hay lugar!\n");
    }
    else
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nuevoCliente.nombre);
        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(nuevoCliente.apellido);
        printf("\nIngrese direccion: ");
        scanf("%d",&nuevoCliente.direccion);
        printf("\nIngrese Numero de Tarjeta: ");
        scanf("%ld",&nuevoCliente.numeroTarjeta);
        nuevoCliente.estado=1;
        nuevoCliente.idDuenio=lugar;

    }
    lista[lugar]=nuevoCliente;
}

void altaAuto(eAuto lista[],int tamA,eCliente cliente[],int tamC)
{
    eAuto nuevoAuto;
    int lugar;
    int id;
    int i;

    lugar=buscarLibreAuto(lista,tamA);

    if(lugar==-1)
    {
        printf("No hay lugar!\n");
    }
    else
    {
        printf("\nIngrese ID del Duenio: ");
        scanf("%d",&id);
        for(i=0; i<tamC; i++)
        {
            if(cliente[i].idDuenio==id)
            {
                mostrarCliente(cliente[i]);
                nuevoAuto.duenio=id;
                printf("\n\nIngrese Patente: ");
                fflush(stdin);
                gets(nuevoAuto.patente);
                printf("\nIngrese Marca del auto \n1-Alfa Romeo\n2-Ferrari\n3-Audi\n4-Otro\n");
                scanf("%d",&nuevoAuto.marca);
                printf("\nIngrese hora de entrada: ");
                scanf("%d",&nuevoAuto.horaEntrada);
                while(nuevoAuto.horaEntrada<0 || nuevoAuto.horaEntrada>24)
                {
                    printf("\nError! hora incorrecta.");
                    printf("\nReingrese: ");
                    scanf("%d",&nuevoAuto.horaEntrada);
                }
                nuevoAuto.estado=1;
            }
        }
    }
    lista[lugar]=nuevoAuto;
}

void harcCliente(eCliente lista[],int tam)
{
    int i;
    int idDuenio[]= {0,1,2,3};
    char nombre[][20]= {"Raul","Jorge","Manuel","Miguel"};
    char apellido[][20]= {"Gomez","Lopez","Campos","Rojas"};
    int direccion[]= {123,124,125,126};
    long int numeroTarjeta[]= {40080379,39621487,36987123,37693481};
    int estado[]= {1,1,1,1};

    for(i=0; i<tam; i++)
    {
        lista[i].idDuenio=idDuenio[i];
        lista[i].direccion=direccion[i];
        strcpy(lista[i].nombre,nombre[i]);
        strcpy(lista[i].apellido,apellido[i]);
        lista[i].numeroTarjeta=numeroTarjeta[i];
        lista[i].estado=estado[i];
    }
}

void mostrarCliente(eCliente lista)
{
    printf("\n%d   \t%s    \t%s    \t%ld    \t%d",lista.idDuenio,lista.nombre,lista.apellido,lista.numeroTarjeta,lista.direccion);
}

void mostrarAuto(eAuto lista)
{
    char mac[20];

    if(lista.marca==1)
    {
        strcpy(mac,"Alfa Romeo");
    }
    else if(lista.marca==2)
    {
        strcpy(mac,"Ferrari");
    }
    else if(lista.marca==3)
    {
        strcpy(mac,"Audi");
    }
    else
    {
        strcpy(mac,"Otro");
    }

    printf("\t%s    \t%s     \t%d",mac,lista.patente,lista.horaEntrada);
}

void mostrarClientes(eCliente lista[], int tam)
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarCliente(lista[i]);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}

void mostrarClientesAutos(eCliente lista[], int tamC,eAuto autos[],int tamA)
{
    int i,j;
    int flag=0;

    printf("ID   \tNombre    \tApellido    \tTarjeta    Direccion\tMarca   \tPatente  \tHora Entrada\n");
    printf("------------------------------------------------------------------------------------------------------------\t");
    for(i=0; i<tamC; i++)
    {
        for(j=0; j<tamA; j++)
        {
            if(autos[j].duenio==lista[i].idDuenio)
            {
                if(lista[i].estado==1 && autos[j].estado==1)
                {

                    mostrarCliente(lista[i]);
                    printf("    ");
                    mostrarAuto(autos[j]);
                    flag=1;
                }
            }

        }
    }
    printf("\n------------------------------------------------------------------------------------------------------------\t");

    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}

void ordenar(eCliente lista[], int tamC,eAuto autos[],int tamA)
{
    int i,j;
    eAuto auxA;

    for(i=0; i<tamA-1; i++)
    {
        for(j=1; j<tamA; j++)
        {
            if(autos[i].estado==1 && autos[j].estado==1)
            {
                if(autos[i].horaEntrada>autos[j].horaEntrada)
                {
                    auxA=autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxA;
                }
                if(autos[j].horaEntrada==autos[i].horaEntrada && strcmp(autos[i].patente,autos[j].patente)==1)
                {
                    auxA=autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxA;

                }
            }
        }
    }
    mostrarClientesAutos(lista,tamC,autos,tamA);
}

void harcAuto(eAuto autos[],int tam)
{
    char patente[][4]= {{"das"},{"des"},{"asd"},{"bod"}};
    int marca[]= {1,2,4,1};
    int duenio[]= {0,1,2,3};
    int horaEntrada[]= {12,21,12,15};
    int estado[]= {1,1,1,1};

    int i;

    for(i=0; i<tam; i++)
    {
        strcpy(autos[i].patente,patente[i]);
        autos[i].marca=marca[i];
        autos[i].duenio=duenio[i];
        autos[i].horaEntrada=horaEntrada[i];
        autos[i].estado=estado[i];
    }

}
