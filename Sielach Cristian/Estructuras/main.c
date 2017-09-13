#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct
{
    long int dni;
    char nombre[40];
    char apellido[40];
    float peso;
} ePersona;

int main()
{
    long int auxI;
    float auxF;

    ePersona unaPersona,unaPersona2;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(unaPersona.nombre);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(unaPersona.apellido);

    printf("Ingrese DNI: ");
    scanf("%ld",&auxI);

    while(auxI<1000000 || auxI>110000000)
    {
        printf("Error DNI incorrecto!\nReingrese:");
        scanf("%ld",&auxI);
    }

    unaPersona.dni=auxI;

    printf("Ingrese peso: ");
    scanf("%f",&auxF);
    while(auxF<10 || auxF>300)
    {
        printf("Peso incorrecto!\nReingrese:");
        scanf("%f",&auxF);
    }
    unaPersona.peso=auxF;
    printf("\n\n");

    system("cls");

    /*        LO QUE NO HAY QUE HACER
    strcpy(unaPersona2.nombre,unaPersona.nombre);
    strcpy(unaPersona2.apellido,unaPersona.apellido);
    unaPersona2.dni=unaPersona.dni;
    unaPersona2.peso=unaPersona.peso;
    */


    // LO QUE SI HAY QUE HACER
    unaPersona2 = unaPersona;

    printf("Nombre: %s \nApellido: %s \nDNI: %ld \nPeso: %.2f",unaPersona.nombre,unaPersona.apellido,unaPersona.dni,unaPersona.peso);

    printf("\n\n");

    printf("Nombre: %s \nApellido: %s \nDNI: %ld \nPeso: %.2f",unaPersona2.nombre,unaPersona2.apellido,unaPersona2.dni,unaPersona2.peso);
    return 0;
}
