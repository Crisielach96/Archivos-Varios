#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "estacionamiento.h"

#define TAM 10000

int contador=0;
eAuto coche[TAM];

int main()
{
    char seguir= 's';
    int opcion=0;


    while(seguir == 's')
    {
        printf("1- Agregar Auto\n");
        printf("2- Borrar Auto\n");
        printf("3- Modificar Auto\n");
        printf("4- mostrar Autos\n");;
        printf("5- salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            cargarDatos(coche,contador);
            contador++;
            break;
        case 2:
            bajaDatos(coche,contador);
            break;
        case 3:
            modificarDatos(coche,contador);
            break;
        case 4:
            mostrarDatos(coche,contador);
            break;
        case 5:
            seguir= 'n';
            break;
        }
    }
    return 0;
}
