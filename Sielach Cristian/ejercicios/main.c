#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int a=0;
    int b=0;

    while(seguir=='s')
    {
        printf("1-Ingrese un numero\n");
        printf("2-Ingrese un segundo numero\n");
        printf("3-Sumar\n");
        printf("4-resta\n");
        printf("5-Multiplicacion\n");
        printf("6-Division\n");
        printf("7-Factorial del primer numero\n");
        printf("8-Factorial del segundo numero\n");
        printf("9-Todas las operaciones\n");
        printf("10-Salir\n");

        printf("Primer numero: %d\n",a);
        printf("Segundo numero: %d\n",b);

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            a=agregarNumero("Ingrese un numero: ");
            break;
        case 2:
            b=agregarNumero("\nIngrese un numero: ");
            break;
        case 3:
            sumar(a,b);
            break;
        case 4:
            restar(a,b);
            break;
        case 5:
            mult(a,b);
            break;
        case 6:
            division(a,b);
            break;
        case 7:
            factorial(a);
            break;
        case 8:
            factorial(b);
            break;
        case 9:
            sumar(a,b);
            restar(a,b);
            mult(a,b);
            division(a,b);
            factorial(a);
            factorial(b);
            break;
        case 10:
            seguir='n';
            break;

        }
        system("cls");
    }
    return 0;
}
