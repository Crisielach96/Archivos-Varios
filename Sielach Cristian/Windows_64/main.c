#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/

FILE* pFile;
ArrayList* list;

int main()
{

    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
        printf("1. Parse del archivo data.csv\n");
        printf("2. Listar Empleados\n");
        printf("3. Ordenar por nombre\n");
        printf("4. Agregar un elemento\n");
        printf("5. Elimina un elemento\n");
        printf("6. Listar Empleados (Desde/Hasta)\n");
        printf("7. Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1 :
            parserEmployee(pFile,list);
            break;

        case 2:

            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            seguir='n';
            fclose(pFile);
            break;
        }
    }
    return 0;
}
