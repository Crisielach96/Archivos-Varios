#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

#define cantProg 4

int menu();

int main()
{
    eProg equipo[50];
    eProy proy[3];
    eCat cat[3];
    ProgProy progsproys[]={{0,3},{1,2},{2,3},{2,1},{3,2},{1,3}};
    inicializarVariables(equipo,50);
    harcProg(equipo,cantProg);
    harcProy(proy,3);
    harcCat(cat,3);
    harcProy(proy,3);


    int salir = 1;


    do{
        switch(menu()){

    case 1:
        system("cls");
        mostrarTodo(equipo,cantProg,proy,3,progsproys,6,cat,3);
        getch();

        break;

    case 2:
        system("cls");

        getch();

        break;
    case 3:
        system("cls");

        getch();

        break;

    case 4:
        system("cls");
        mostrarTodo(equipo,cantProg,proy,3,progsproys,6,cat,3);
        printf("\n");

        getch();
        break;



    case 5:
      salir = 0;



        break;

        }

    }while(salir);
    return 0;
}


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
