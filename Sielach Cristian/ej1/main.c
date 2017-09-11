#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char[], int);
void mostrarNombres(char[][20], int);
void ordenarNombres(char[][20], int);
void mostrarNombre(char[]);

int main()
{

    char aux[50];

    char mat[5][20];

        for(int i=0; i<5; i++){
              printf("Ingrese un nombre: ");
              gets(aux);

              while( !validarCadena(aux, 20) ){
                 printf("Error. Nombre demasiado largo. Reingrese: ");
                gets(aux);
              }

              strcpy(mat[i], aux);

        }

    mostrarNombres(mat, 5);
    printf("\n\n");

    ordenarNombres(mat, 5);

     mostrarNombres(mat, 5);
    printf("\n\n");

    return 0;
}

int validarCadena(char cadena[], int tam){

    int esValido = 0;

    if(strlen(cadena) < tam){
        esValido = 1;
    }

    return esValido;
}

void mostrarNombres(char nombres[][20], int cant){


   for(int i=0; i< cant; i++){

      mostrarNombre(nombres[i]);
   }

}

void mostrarNombre(char nombre[]){

    printf("\n%s", nombre);
}

void ordenarNombres(char mat[][20], int tam){

    char aux[20];

 for(int i=0; i< tam-1; i++){
        for(int j= i+1; j<tam; j++){
            if(strcmp(mat[i], mat[j])>0){
                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }

        }
    }

}

