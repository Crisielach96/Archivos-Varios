#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"


int main()
{
    int todoOk;
    char seguir = 'n';
    //ArrayList* subLista;
    eParcial* auxEmpleado;
    ArrayList* lista = al_newArrayList();

    if(lista == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }

    FILE* f = fopen("data.csv", "r");


    if(f == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

        do
    {
        switch(menu())
        {

        case 1:
            todoOk = parserParcial(f, lista);

            if(todoOk)
            {
                printf("\nError al parsear archivo\n\n");
            }
            else
            {
                printf("\nArchivo cargado con exito\n\n");
            }
            system("pause");

            break;

        case 2:
            printf("Lista de empleados\n\n");
            printf("id  Nombre   Apellido\n\n");
            for(int i=0; i < lista->len(lista); i++)
            {
                auxEmpleado = (eParcial*)lista->get(lista, i);
                employee_print(auxEmpleado);
            }
            system("pause");
            break;
}
}
while(seguir == 's');
}
