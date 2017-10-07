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
            modificacion(cliente,cantClientes);
            getch();

            break;
        case 3:
            system("cls");
            altaAuto(autos,cantAutos,cliente,cantClientes);
            getch();

            break;

        case 4:
            system("cls");
            bajaAuto(cliente,cantClientes,autos,cantAutos);
            getch();
            break;

        case 5:
            system("cls");
            ordenar(autos,cantAutos);
            mostrarClientesAutos(cliente,cantClientes,autos,cantAutos);
            getch();
            break;

        case 6:
            salir = 0;
            break;

        case 7:
            system("cls");
            mostrarClientes(cliente,cantClientes);
            getch();
            break;

        default:
            printf("Opcion Invalida!!\n");
            system("pause");

        }
    }
    while(salir);
    return 0;
}
