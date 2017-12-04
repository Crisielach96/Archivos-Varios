#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int menu();

int main()
{
    int verificar, i;
    char seguir = 's';
    char nombreDeArchivo[101];

    eDestinatario* auxDestinatario;

    ArrayList* nuevaLista = al_newArrayList();
    ArrayList* destinatariosArray = al_newArrayList();
    ArrayList* black_listArray = al_newArrayList();

    if(destinatariosArray == NULL && black_listArray == NULL && nuevaLista == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }

    do
    {
        switch(menu())
        {

        case 1:

            printf("Ingrese el nombre del archivo (con extension): \n");
            fflush(stdin);
            gets(nombreDeArchivo);

            FILE* destinatarios = fopen(nombreDeArchivo, "r");

            if(destinatarios == NULL )
            {
                printf("No se pudo abrir el archivo");
                exit(1);
            }

            verificar = parseo(destinatarios, destinatariosArray);

            if(verificar)
            {
                printf("\nError al parsear los archivos\n\n");
            }
            else
            {
                printf("\nArchivo cargado con exito\n\n");
            }

            system("pause");
            break;

        case 2:

            printf("Ingrese el nombre del archivo (con extension): \n");
            fflush(stdin);
            gets(nombreDeArchivo);

            FILE* black_list = fopen(nombreDeArchivo, "r");

            if(black_list == NULL)
            {
            printf("No se pudo abrir los archivos");
            exit(1);
            }

            verificar = cargarBlacklist(destinatariosArray, black_listArray, black_list);

            if(verificar)
            {
                printf("\nArchivo cargado con exito\n\n");
            }
            else
            {
                printf("\nError al parsear archivo\n\n");
            }
            system("pause");
            break;

        case 3:

            verificar = depurar(nuevaLista, destinatariosArray, black_listArray);

            if (verificar)
            {
                printf("\nArchivo depurado con exito\n\n");
            }
            else
            {
                printf("\nError al depurar archivo\n\n");
            }
            system("pause");
            break;

        case 4:
            printf("Lista de destinatarios\n\n");
            printf("Nombre  Mail\n\n");

            for(i = 0; i < nuevaLista->len(nuevaLista); i++)
            {
                auxDestinatario = (eDestinatario*) nuevaLista->get(nuevaLista, i);
                imprimir_destinatario(auxDestinatario);
            }
            printf("\n");
            system("pause");
            break;

        case 5:

            seguir = 'n';
            break;

        }
    }

    while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("**Menu de Opciones**\n\n");

    printf("1. Cargar destinatarios\n");
    printf("2. Cargar lista negra\n");
    printf("3. Depurar\n");
    printf("4. Listar\n");
    printf("5. Salir\n");
    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
