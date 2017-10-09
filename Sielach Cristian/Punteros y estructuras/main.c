#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char modelo[20];
    int nucleos;
}eProcesador;

typedef struct
{
    char marca[20];
    eProcesador procesador;
    int ram;
    float precio;
}eNotebook;

void mostrarNotebook(eNotebook);
void inicializarNotebook(eNotebook*);
void cargarVector(eNotebook*);

int main()
{
    eNotebook note;

    inicializarNotebook(&note);
    mostrarNotebook(note);
    cargarVector(&note);
    mostrarNotebook(note);


    return 0;
}

void mostrarNotebook(eNotebook note)
{
    printf("%s\n%s\n%d\n%d\n%.2f\n\n", note.marca,note.procesador.modelo,note.procesador.nucleos,note.ram,note.precio);
}

void inicializarNotebook(eNotebook* note)
{
    strcpy(note->marca,"");
    strcpy(note->procesador.modelo,"");
    note->procesador.nucleos=0;
    note->ram=0;
    note->precio=0;
}

void cargarVector(eNotebook* note)
{
    printf("Ingrese Marca: ");
    fflush(stdin);
    gets(note->marca);
    printf("Ingrese Procesador: ");
    fflush(stdin);
    gets(note->procesador.modelo);
    printf("Ingrese Nucleos: ");
    scanf("%d",&note->procesador.nucleos);
    printf("Ingrese RAM: ");
    scanf("%d",&note->ram);
    printf("Ingrese Precio: ");
    scanf("%f",&note->precio);
}
