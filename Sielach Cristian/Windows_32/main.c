#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int todoOk;
    ArrayList* lista = al_newArrayList();
    Employee* auxEmpleado;
    if(lista == NULL){
    printf("No se pudo reservar memoria");
    exit(1);
    }

    FILE* f = fopen("data.csv", "r");
    if(f == NULL){
        printf("No se pudo abrir el archivo");
    exit(1);
    }
     todoOk = parserEmployee(f, lista);

     if(todoOk){
          printf("Error al parsear archivo\n\n");
     }
     else{
          printf("Archivo cargado con exito\n\n");
     }


     printf("Lista de empleados\n\n");
     printf("id  Nombre   Apellido\n\n");
     for(int i=0; i < lista->len(lista); i++){
        auxEmpleado = (Employee*)lista->get(lista, i);
        employee_print(auxEmpleado);
     }





    return 0;
}
