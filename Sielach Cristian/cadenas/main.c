#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char vec[],int tam);

int main()
{
    char vec[20];
    char auxVec[100];

    printf("ingrese nombre: ");
    gets(auxVec);

    while(!validarCadena(auxVec,20))
    {
        printf("nombre muy largo. Reingrese: ");
        gets(auxVec);
    }

        strcpy(vec,auxVec);

        printf("%s",vec);
    return 0;
}


int validarCadena(char vec[],int tam)
{
    int validacion=0;

    if(strlen(vec)<tam)
    {
        validacion=1;
    }
    return validacion;
}
