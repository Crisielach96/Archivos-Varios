#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 3

int agregarNumero(char mensaje[])
{
    int num;

    printf(mensaje);
    scanf("%d",&num);
    return num;
}

int sumar(int a,int b)
{
    int r;

    printf("SUMA\t\n");
    r=a+b;
    printf("La suma es de: %d \n",r);
    system("pause");
    printf("\n");
    return 0;
}

int restar(int a, int b)
{
    int r;

    printf("RESTA\t\n");
    r=a-b;
    printf("La resta es de: %d \n",r);
    system("pause");
    printf("\n");
    return 0;
}

int mult(int a, int b)
{
    int r;

    printf("MULTIPLICACION\t\n");
    r=a*b;
    printf("La multiplicacion es de: %d \n",r);
    system("pause");
    printf("\n");
    return 0;
}

float division(int a, int b)
{
    float r;

    printf("DIVISION\t\n");
    r=(float)a/b;
    printf("La division es de: %.2f \n",r);
    system("pause");
    printf("\n");
    return 0;
}

int factorial(int a)
{
    long long int r=1;
    int i;

    printf("FACTORIAL\t\n");
    if(a>=1)
    {
        for(i=1;i<=a;i++)
        {
            r*=i;
        }
        printf("El factorial es de: %I64d \n",r);
    }
    else
    {
        printf("ERROR!\n");
    }

    system("pause");
    printf("\n");
    return 0;
}

