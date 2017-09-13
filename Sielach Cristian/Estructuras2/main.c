#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

typedef struct
{
    long int dni;
    char nombre[40];
    char apellido[40];
    float peso;
} ePersona;

void ingresarDatos(ePersona unaPersona[]);
void mostarPersonas(ePersona unaPersona[]);
void mostrarPersona(ePersona unaPersona);
void ordenar(ePersona unaPersona[],int tam);

int main()
{
    ePersona unaPersona[TAM];
    ingresarDatos(unaPersona);
    mostarPersonas(unaPersona);
    ordenar(unaPersona,TAM);
    mostarPersonas(unaPersona);
    return 0;
}

void ingresarDatos(ePersona unaPersona[])
{
    int i;
    long int auxI;
    float auxF;

    for(i=0; i<TAM; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(unaPersona[i].nombre);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(unaPersona[i].apellido);

        printf("Ingrese DNI: ");
        scanf("%ld",&auxI);

        while(auxI<1000000 || auxI>110000000)
        {
            printf("Error DNI incorrecto!\nReingrese:");
            scanf("%ld",&auxI);
        }

        unaPersona[i].dni=auxI;

        printf("Ingrese peso: ");
        scanf("%f",&auxF);
        while(auxF<10 || auxF>300)
        {
            printf("Peso incorrecto!\nReingrese:");
            scanf("%f",&auxF);
        }
        unaPersona[i].peso=auxF;

        printf("\n\n");
    }

        system("cls");
}


void mostarPersonas(ePersona unaPersona[])
{
    int i;

    printf("Nombre\t\tApellido\tDNI\t\tPeso\n");

    for(i=0; i<TAM; i++)
    {
        mostrarPersona(unaPersona[i]);

        printf("\n\n");

    }
}

void mostrarPersona(ePersona unaPersona)
{
    printf("%s\t\t%s\t\t%ld\t\t%.2f",unaPersona.nombre,unaPersona.apellido,unaPersona.dni,unaPersona.peso);
}

void ordenar(ePersona unaPersona[],int tam)
{
    int i,j;
    ePersona aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=1;j<tam;j++)
        {
            if(strcmp(unaPersona[i].nombre,unaPersona[j].nombre)>0)
            {
                aux=unaPersona[i];
                unaPersona[i]=unaPersona[j];
                unaPersona[j]=aux;
            }
            if((unaPersona[i].nombre,unaPersona[j].nombre)==0)
            {
                aux=unaPersona[i];
                unaPersona[i]=unaPersona[j];
                unaPersona[j]=aux;
                if
            }
        }
    }
    printf("\n\n");
}
