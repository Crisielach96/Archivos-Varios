#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"



int buscarLibre(eProg lista[],int tam)
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

int buscarProgramador(int id,eProg lista[],int tam)
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

void variablesCero(eProg lista[],int i)
{
    strcpy(lista[i].nombre,"\0");
    lista[i].categ='\0';
    lista[i].estado=0;
    lista[i].id=0;
}

void inicializarVariables(eProg lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCero(lista,i);
    }
}


void mostrarProgramador(eProg lista)
{
    printf("\n%d     %s",lista.id,lista.nombre);


}

void mostrarProgramadores(eProg lista[],int tamPro, eCat cate[], int tamCat)
{
    int i;
    int flag=0;

    for(i=0; i<tamPro; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarProgramador(lista[i]);
            buscarCat(lista,cate,3,3);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}


void alta(eProg lista[],int tam)
{
    eProg nuevoProgramador;

    int esta;
    int lugar;
    int id;

    lugar=buscarLibre(lista,tam);

    if(lugar==-1)
    {
        printf("No hay lugar!\n");
    }
    else
    {
        printf("\ningrese ID: ");
        scanf("%d",&id);
        esta=buscarProgramador(id,lista,tam);
    }
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
        printf("\nIngrese categoria (1-Senior  2-SemiSenior  3-Junior): ");
        fflush(stdin);
        nuevoProgramador.categ=getchar();
        nuevoProgramador.estado=1;

    }
    lista[lugar]=nuevoProgramador;
}


void baja(eProg lista[],int tam)
{
    int esta;
    int id;
    char respuesta='n';

    printf("\ningrese ID: ");
    scanf("%d",&id);
    esta=buscarProgramador(id,lista,tam);

    if(esta!=-1)
    {
        mostrarProgramador(lista[esta]);
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


void modificacion(eProg lista[],int tam)
{
    int esta;
    int id;
    char respuesta='n';

    printf("\ningrese ID: ");
    scanf("%d",&id);
    esta=buscarProgramador(id,lista,tam);

    if(esta!=-1)
    {
        mostrarProgramador(lista[esta]);
        printf("\nDesea modificar esta entrada: S/N\n");
        fflush(stdin);
        respuesta=getch();
        if(respuesta=='s')
        {
            printf("\nIngrese nueva categoria: ");
            fflush(stdin);
            lista[esta].categ=getchar();
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

void harcProg(eProg lista[],int tam)
{
    int i;
    int id[]={1,2,3};
    char nombre[][20]={"Raul","Jorge","Manuel"};
    char categoria[]={3,1,2};
    int estado[]={1,1,1};

    for(i=0;i<tam;i++)
    {
        lista[i].id=id[i];
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].categ=categoria[i];
        lista[i].estado=estado[i];
    }
}

void harcCat(eCat cat[],int tam)
{
    int i;
    int id[]={1,2,3};
    char desc[][12]={"Senior","SemiSenior","Junior"};
    int sueldo[]={100,75,50};

    for(i=0;i<tam;i++)
    {
        cat[i].idCat=id[i];
        strcpy(cat[i].nombCat,desc[i]);
        cat[i].sueldo=sueldo[i];
    }
}

void harcProy(eProy proyec[],int tam)
{
    int i;
    int id[]={1,2,3};
    char desc[][10]={"Linux","Android","IOS"};

    for(i=0;i<tam;i++)
    {
        proyec[i].idProy=id[i];
        strcpy(proyec[i].desc,desc[i]);
    }
}

void buscarCat(eProg lista[],eCat cat[],int tamProg,int tamCat)
{
    int i,j;

    for(i=0;i<tamProg;i++)
    {
        for(j=0;j<tamCat;j++)
        {
            if(lista[i].categ==cat[j].idCat)
            {

            }
        }
    }
}
