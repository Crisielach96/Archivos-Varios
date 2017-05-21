#include <stdio.h>
#include <stdlib.h>

int main()
{
   int variable=9;
   int* puntero;
   int* otro;

   puntero= &variable;        //obtenemos la direccion de memeria de vatiable y la guardamos en puntero.
   otro=puntero;

   printf("%p\n",&variable);  //mostramos la direccion de memoria de variable.
   printf("%p\n",puntero);    //mostramos el contenido de puntero.
   printf("%d\n",variable);   //muestra el contenido de variable.
   printf("%d\n",*puntero);   //accedemos a la direccion de memoria que contiene puntero.
   printf("%p\n",&puntero);   //muestra la direccion de memoria del puntero.

   *puntero=17;               //mediante la direccion de memoria cambiamos el valor de la variable.
   printf("%d\n",*puntero);
   scanf("%d",puntero);       //ingresa el valor para cambiar.
   *otro=14;
   printf("%d",*puntero);     //cambiamos el valor de otro eso cambia el valor de puntero que cambia el valor de variable.

   puntero++;                 //nos movemos una direccion de memoria hacia arriba.
   puntero--;                 //nos movemos una direccion de memoria hacia abajo.


   //int* x; los punteros son dinamicos


   int vec[5]={4,9,1,3,5};
   int* pvec;

   pvec=&vec[0];
    //MAL!☻
   pvec=&vec;
    //MAL!☻
   pvec=vec;
    //BIEN!☺

    /*
    MOSTRAR
    printf("%d",vec[2]);     Muestra el dato en la posicion 3 con VECTORES.
    printf("%d",*(pvec+2));  Muestra el dato en la posicion 3 con PUNTERO.


    LEER
    scanf("%d",&vec[2]);     Lee el dato en la posicion 3 con VECTORES.
    scanf("%d",pvec+2);      Lee el dato en la posicion 3 con PUNTERO.
    */


   int vec[5]={0};
   int* pvec;



return 0;
}
