#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"



int menu()
{
    int opcion;
    system("cls");
    printf("\n***Programadores***\n\n\n");
    printf("1- Alta Programador\n");
    printf("2- Modificacion Programador\n");
    printf("3- Baja Programador\n");
    printf("4- Listado Programadores\n");
    printf("5- Salir\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}
int buscarLibre(eProgramador lista[],int tam)
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

int buscarProgramador(int id,eProgramador lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1 && lista[i].id==id)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

void variablesCero(eProgramador lista[],int i)
{
    strcpy(lista[i].nombre,"\0");
    lista[i].estado=0;
    lista[i].id=0;
    lista[i].proyecto=0;
}

void inicializarVariables(eProgramador lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCero(lista,i);
    }
}

void mostrarProgramador(eProgramador lista,eCategoria cate)
{
    char cat[11];

    if(cate.id==1)
    {
        strcpy(cat,"Senior");
    }
    else if(cate.id==2)
    {
        strcpy(cat,"SemiSenior");
    }
    else if(cate.id==3)
    {
        strcpy(cat,"junior");
    }


    printf("\n%d     %s     %s     %d",lista.id,lista.nombre,cat,lista.proyecto);
}

void mostrarProgramadores(eProgramador lista[],eCategoria cat[],int tam)
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1 && cat[i].id==lista[i].idCategoria)
        {
            mostrarProgramador(lista[i],cat[i]);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}

void alta(eProgramador lista[],eCategoria cat[],int tam)
{
    eProgramador nuevoProgramador;
    eCategoria nuevaCategoria;

    int esta;
    int lugar;
    int id;

    lugar=buscarLibre(lista,tam);

    if(lugar==-1)
    {
        printf("No hay lugar!\n");
        getch();
    }
    else
    {
        printf("\ningrese ID: ");
        scanf("%d",&id);
        esta=buscarProgramador(id,lista,tam);

        if(esta!=-1)
        {
            printf("El id ya existe");
        }
        else
        {
            nuevoProgramador.id=id;
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevoProgramador.nombre);
            printf("\nIngrese proyecto: ");
            scanf("%d",&nuevoProgramador.proyecto);
            printf("\nIngrese categoria (1-Senior  2-SemiSenior  3-Junior): ");
            scanf("%d",&nuevaCategoria.id);
            nuevoProgramador.estado=1;
            lista[lugar]=nuevoProgramador;

        }
    }
}

void baja(eProgramador lista[],eCategoria cat[],int tam)
{
    int esta;
    int id;
    char respuesta='n';

    printf("\ningrese ID: ");
    scanf("%d",&id);
    esta=buscarProgramador(id,lista,tam);

    if(esta!=-1)
    {
        mostrarProgramador(lista[esta],cat[esta]);
        printf("\nDesea eliminar esta entrada: S/N");
        fflush(stdin);
        respuesta=getch();
        if(respuesta=='s')
        {
            variablesCero(lista,esta);
            printf("\nEliminado con exito\n");
        }
        if(respuesta=='n')
        {
            printf("accion cancelada.\n");
        }
    }
    else
    {
        printf("\nNo se ha encontrado el ID.");

    }
}

void modificacion(eProgramador lista[],eCategoria cat[],int tam)
{
    int esta;
    int id;
    char respuesta='n';

    printf("\ningrese ID: ");
    scanf("%d",&id);
    esta=buscarProgramador(id,lista,tam);

    if(esta!=-1)
    {
        mostrarProgramador(lista[esta],cat[esta]);
        printf("\nDesea modificar esta entrada: S/N\n");
        fflush(stdin);
        respuesta=getch();
        if(respuesta=='s')
        {
            printf("\nIngrese nueva categoria: ");
            fflush(stdin);
            cat[esta].id=getchar();
            printf("\nModificacion con exito");
        }
        if(respuesta=='n')
        {
            printf("accion cancelada.\n");
        }
    }
    else
    {
        printf("\nNo se ha encontrado el ID.");

    }
}
