#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char vec[],int tam);
void mostrarNombres(char[][20],int);
void ordenarNombre(char[][20],int);

int main()
{
    char vec[5][20];
    char auxVec[100];
    int i;


    for(i=0; i<5; i++)
    {
        printf("ingrese nombre: ");
        fflush(stdin);
        gets(auxVec);

        while(!validarCadena(auxVec,20))
        {
            printf("nombre muy largo. Reingrese: ");
            gets(auxVec);
        }
        strcpy(vec[i],auxVec);
    }

    mostrarNombres(vec,5);
    printf("\n");
    ordenarNombre(vec,5);
    mostrarNombres(vec,5);
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


void mostrarNombres(char vec[][20],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%s\n",vec[i]);
    }
}

void ordenarNombre(char vec[][20],int tam)
{
    int i,j;
    char auxVec[20];
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(vec[i],vec[j])>0)
            {
               strcpy(auxVec,vec[j]);
               strcpy(vec[j],vec[i]);
               strcpy(vec[i],auxVec);
            }

        }
    }
}
