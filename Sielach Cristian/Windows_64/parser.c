#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    FILE * parch;
    if((parch=fopen("data.csv","r+"))==NULL)
    {
        printf("El archivo no existe.");
        exit(1);
    }
    else
    {
        printf("El archivo se abrio correctamente\n");
    }

    return 0;
}
