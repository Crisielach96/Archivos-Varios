#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListModificada.h"
#include "clientes.h"

int divide_lista(ArrayList* lista,ArrayList* aux,ArrayList* depuracion)
{
    ;
    int salida=-1,i;

    depuracion=lista;

    if(lista!=NULL && aux!=NULL)
    {
        for(i=0; i<lista->len(); i++)

            if((lista->containsAll(lista,aux))==1)
            {
                depuracion->remove(depuracion,i);
            }
    }

    return salida;
}

int menu(void)
{
    int opcion;

    system("cls");
    printf("1. Cargar lista\n");
    printf("2. Cargar Lista negra \n");
    printf("3. Depurar \n");
    printf("4. Listar \n");
    printf("5. Salir \n");


    printf("\n\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int valida_int(int numero,int minimoInt, int maximoInt)
{

    while(minimoInt>numero || numero>maximoInt)
    {
        printf("ERROR; Reingrese el numero: ");
        scanf("%d",&numero);
    }

    return numero;
}

float valida_float(float numero,float minimoFloat, float maximoFloat)
{
    while(minimoFloat>numero || numero>maximoFloat)
    {
        printf("ERROR; Reingrese el numero: ");
        scanf("%f",&numero);
    }

    return numero;
}


eCliente* nuevo_cliente(ArrayList* lista)
{
    eCliente* returnAux;
    eCliente aux;

    returnAux = (eCliente*) malloc(sizeof(eCliente));

    //aux= cargar_cliente(lista);

    if(returnAux !=NULL)
    {
        strcpy(returnAux->mail,aux.mail);
        strcpy(returnAux->nombre,aux.nombre);
    }

    return returnAux;
}

int mostrar_clientes (ArrayList* lista)
{
    eCliente* auxCliente;
    int salida=-1,i;

    for(i=0; i<lista->size; i++)
    {
        auxCliente= (eCliente*) lista->get(lista,i);
        printf("Nombre: %s  \t   Correo: %s \n",auxCliente->nombre,auxCliente->mail);
        salida=0;
    }

    getchar();
    return salida;

}

int lee_archivo_cliente(ArrayList* lista)
{
    FILE* archivo=NULL;
    eCliente* returnAux;
    //eCliente* auxCliente;
    char auxMail[50];
    char auxNombre[50];
    int salida=-1;
    char nomarchivo[20];

    printf("Ingrese nombre del archivo: ");
    fflush(stdin);
    gets(nomarchivo);

    archivo = fopen(nomarchivo,"r");

    if(archivo!= NULL && lista != NULL)
    {
        while(!feof(archivo))
        {
            fflush(stdin);
            fscanf(archivo,"%[^,],%s\n",auxNombre,auxMail);


            returnAux = (eCliente*) malloc(sizeof(eCliente));
            if(feof(archivo))
            {
                break;
            }

            else
            {
                if(returnAux!=NULL)
                {
                    strcpy(returnAux->mail,auxMail);
                    strcpy(returnAux->nombre,auxNombre);

                    lista->add(lista,returnAux);
                    salida=0;
                }
            }
        }
    }
    else
    {
        printf("ERROR; No se pudo abrir el archivo");
        exit(1);
    }

    mostrar_clientes(lista);

    fclose(archivo);

    return salida;
}


int lee_archivo_clienteBL(ArrayList* lista,ArrayList* listaBL)
{
    FILE* archivo=NULL;
    char auxMail[50];
    char auxNombre[50];
    int salida=-1,i,j;
    char nomarchivo[20];

    printf("Ingrese nombre del archivo: ");
    fflush(stdin);
    gets(nomarchivo);

    archivo = fopen(nomarchivo,"r");

    if(archivo!= NULL && lista != NULL)
    {
        while(!feof(archivo))
        {
            fflush(stdin);
            fscanf(archivo,"%[^,],%s\n",auxNombre,auxMail);

            if(feof(archivo))
            {
                break;
            }

            else
            {

                for(i=0; i<lista->len(); i++)
                {
                    lista->get(lista,i);

                    for(j=0; j<lista->len(); j++)
                    {
                        if((eCliente*)(lista+i)==auxMail[j])
                        {
                            listaBL->add(listaBL,lista);
                        }
                    }
                }
                salida=0;
            }
        }
    }
    else
    {
        printf("ERROR; No se pudo abrir el archivo");
        exit(1);
    }

    mostrar_clientes(lista);

    fclose(archivo);

    return salida;
}

int compara_cadena (ArrayList* lista, ArrayList* listaNegra)
{
    int i,j,salida=-1;
    eCliente* cliente;
    eCliente*  blackList;


    for(j=0; j<listaNegra->size; j++)
    {
        blackList = (eCliente*)listaNegra->get(listaNegra,j);

        for(i=0; i<lista->size; i++)
        {
            cliente = (eCliente*) lista->get(lista,i);

            if (strcmp(blackList->mail,cliente->mail) == 0)
            {
                contract(lista,i);
                salida=0;
            }

        }
    }

    return salida;
}


