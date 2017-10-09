#include <stdio.h>
#include <stdlib.h>

void swapeo(int*,int*);
void mostrarVector(int*,int);
void cargarVector(int*,int);


int main()
{
    /*int x=5;
    int y=8;
    int vec[]={1,9,7,5,3};

    printf("x: %d\n",x);
    printf("y: %d\n",y);
    printf("\n");

    swapeo(&x,&y);

    printf("x: %d\n",x);
    printf("y: %d\n",y);
    */

    int vec[5];

    cargarVector(vec,5);
    mostrarVector(vec,5);

    return 0;
}

void cargarVector(int* x,int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",(x+i));
    }
}

void swapeo(int* x, int* y)
{
    int aux;

    aux=*x;
    *x=*y;
    *y=aux;

    printf("x: %d\n",*x);
    printf("y: %d\n",*y);
    printf("\n");
}

void mostrarVector(int* x,int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("%d ",*(x+i));
    }
}
