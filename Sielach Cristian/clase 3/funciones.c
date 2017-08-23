#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

int sumar(int a,int b)
{
    int r;

    printf("SUMA\t\n");
    printf("Ingrese un numero: ");
    scanf("%d",&a);
    printf("Ingrese otro numero: ");
    scanf("%d",&b);
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
    printf("Ingrese un numero: ");
    scanf("%d",&a);
    printf("Ingrese otro numero: ");
    scanf("%d",&b);
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
    printf("Ingrese un numero: ");
    scanf("%d",&a);
    printf("Ingrese otro numero: ");
    scanf("%d",&b);
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
    printf("Ingrese un numero: ");
    scanf("%d",&a);
    printf("Ingrese otro numero: ");
    scanf("%d",&b);
    r=(float)a/b;
    printf("La division es de: %.2f \n",r);
    system("pause");
    printf("\n");
    return 0;
}

int factorial(int a)
{
    long int r=1;
    int i;

    printf("FACTORIAL\t\n");
    printf("Ingrese un numero: ");
    scanf("%d",&a);
    if(a>=1)
    {
        for(i=1;i<=a;i++)
        {
            r*=i;
        }
        printf("El factorial es de: %li \n",r);
    }
    else
    {
        printf("ERROR!\n");
    }

    system("pause");
    printf("\n");
    return 0;
}

