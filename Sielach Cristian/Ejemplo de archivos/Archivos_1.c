#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* miArchivo;


    char palabra[50]="Un te por favor";

 /*miArchivo = fopen("prueba.txt","w");

    fprintf(miArchivo,"Hola\na\ntodos");

    fclose(miArchivo);*/


    miArchivo = fopen("prueba.txt","r");


    fgets(palabra,50,miArchivo);

    puts(palabra);






}
