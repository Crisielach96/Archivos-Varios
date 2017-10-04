#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

#define cantClientes 10
#define cantAutos 10
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

int menu();

int main()
{
    eCliente cliente[10];
    eAuto autos[10];
    inicializarVariablesAutos(autos,cantAutos);
    inicializarVariables(cliente,cantClientes);
    harcCliente(cliente,4);
    harcAuto(autos,4);

    int salir = 1;

    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            alta(cliente,cantClientes);
            getch();

            break;

        case 2:
            system("cls");
            ordenar(autos,cantAutos);
            mostrarClientesAutos(cliente,cantClientes,autos,cantAutos);
            getch();

            break;
        case 3:
            system("cls");
            altaAuto(autos,cantAutos,cliente,cantClientes);
            getch();

            break;

        case 4:
            printf("\n");
            mostrarClientes(cliente,cantClientes);
            getch();
            break;

        case 5:
            printf("\n");
            getch();
            break;

        case 6:
            printf("\n");
            getch();
            break;



        case 7:
            salir = 0;
            break;

        default:
            printf("Opcion Invalida!!\n");
            system("pause");

        }
    }
    while(salir);
    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("1- Alta Cliente\n");
    printf("2- Clientes y autos\n");
    printf("3- Agregar auto\n");
    printf("4- Mostrar Clientes\n");
    printf("5- \n");
    printf("6- \n");
    printf("7- Salir\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}
