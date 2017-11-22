
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

eParcial* employee_new(void)
{
    eParcial* returnAux;
    returnAux = (eParcial*)malloc(sizeof(eParcial));
    if(returnAux !=NULL)
    {
        returnAux->prioridad = 0;
        strcpy(returnAux->descripcion,"");
        returnAux->tiempo = 0;
        returnAux->Empty = 1;
    }
    return returnAux;
}

int parserParcial(FILE* pFile, ArrayList* pArrayListEmployee)
{
    char auxInt[10];
    char auxDescripcion[100];
    char auxTiempo[10];
    char auxEmpty[10];
    eParcial* nuevoEmpleado;

    if(pFile == NULL || pArrayListEmployee == NULL)
    {
        return -1;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxDescripcion, auxTiempo, auxEmpty);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxDescripcion, auxTiempo, auxEmpty);

        nuevoEmpleado = employee_new();

        if(nuevoEmpleado !=NULL)
        {
            nuevoEmpleado->prioridad = atoi(auxInt);
            strcpy(nuevoEmpleado->descripcion, auxDescripcion);
            nuevoEmpleado->tiempo = atoi(auxTiempo);

            if(auxEmpty==0)
            {
                nuevoEmpleado->Empty = 0;
            }
            else
            {
                nuevoEmpleado->Empty = 1;
            }

            pArrayListEmployee->add(pArrayListEmployee, nuevoEmpleado);
            // al_add(pArrayListEmployee, nuevoEmpleado);

        }

    }

    return 0;
}

void employee_print(eParcial* lista)
{
    if(lista != NULL)
    {
        printf("%s %d %d \n", lista->descripcion, lista->prioridad, lista->tiempo);
    }


}

int menu()
{
    int opcion;
    system("cls");
    printf("**Menu de Opciones**\n\n");

    printf("1. Parse del archivo data.csv\n");
    printf("2. Listar Empleados\n");
    printf("3. Ordenar por nombre\n");
    printf("4. Agregar un elemento\n");
    printf("5. Elimina un elemento\n");
    printf("6. Listar Empleados (Desde/Hasta)\n");
    printf("7. Salir\n");
    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
