#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

void set_destinatario(eDestinatario* returnAux, char* nombre, char* mail, int isEmpty)
{
    if (returnAux != NULL);
    {
        strcpy(returnAux->nombre, nombre);
        strcpy(returnAux->mail, mail);
        returnAux->isEmpty = isEmpty;
    }
}

eDestinatario* destinatario_nuevo()
{
    eDestinatario* returnAux;

    returnAux = (eDestinatario*)malloc(sizeof(eDestinatario));

    if(returnAux != NULL)
    {
        set_destinatario(returnAux, "", "", 0);
    }
    return returnAux;
}

void borrar_destinatario(eDestinatario* lista)
{
    if (lista != NULL)
    {
        lista->isEmpty = 1;
    }

}

void imprimir_destinatario(eDestinatario* lista)
{
    if (lista != NULL)
    {
        printf("%s %s \n", lista->nombre, lista->mail);
    }
}

int parseo(FILE* pFile, ArrayList* lista)
{
    char auxNombre[51];
    char auxMail[71];

    eDestinatario* nuevoDestinatario;

    if(pFile == NULL || lista == NULL)
    {
        return -1;
    }

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%s\n", auxNombre, auxMail);

        nuevoDestinatario = destinatario_nuevo();

        if(nuevoDestinatario!= NULL)
        {
            strcpy(nuevoDestinatario->nombre, auxNombre);

            strcpy(nuevoDestinatario->mail, auxMail);

            nuevoDestinatario->isEmpty = 1;

            lista->add(lista, nuevoDestinatario);
            // al_add(pArrayListEmployee, nuevoDestinatario);

        }

    }

    return 0;
}

int cargarBlacklist(ArrayList* destinatarios, ArrayList* blacklist, FILE* blacklistFile)
{
    int i, retorno = 0;

    char auxNombre[51];
    char auxMail[71];

    eDestinatario* aux;

    while(!(feof(blacklistFile))) //RECORRO EL ARCHIVO
    {
        fscanf(blacklistFile, "%[^,],%s\n", auxNombre, auxMail); //LEO UNA LINEA DE CODIGO DEL ARCHIVO Y
                                                                 //LO GUARDO EN DOS VARIABLES. SOLAMENTE USO auxMail
        for (i = 0; i < destinatarios->len(destinatarios); i++)
        {
            aux =(eDestinatario*) al_get(destinatarios, i); //TRAIGO EL PRIMERO ELEMENTO DEL ARRAY DE "DESTINATARIOS"

            if (strcmpi(aux->mail, auxMail) == 0) //COMPARO EL CAMPO MAIL CON LO QUE EXTRAJE DEL ARCHIVO
            {
                al_add(blacklist, al_get(destinatarios, i)); //SI COINCIDEN AGREGO ELEMENTO CON ADD PORQUE ESTE ME PERMITE
            }                                                //PONERLE LA MISMA DIRRECCION DE MEMORIA. USANDO GET PORQUE
        }                                                    //NO SE PUEDE TRABAJAR CON EL ELEMENTO CRUDO
    }

    retorno = 1;

    return retorno;
}

int depurar(ArrayList* nuevaLista, ArrayList* destinatarios, ArrayList* blacklist)
{
    int retorno = 0, i, bandera = 0;
    void* aux;

    if (nuevaLista != NULL && destinatarios != NULL && blacklist != NULL) // <-- NO TE OLVIDES DEL CONTROL SOBRE
    {                                                                     //     LOS PUNTEROS
        for (i = 0; i < destinatarios->len(destinatarios); i++)
        {
            aux = al_get(destinatarios, i); //CON UN FOR RECORRO TODO EL ARRAY DE DESTINATARIOS

            if (al_contains(blacklist, aux) == 0) //PREGUNTO SI ESTA EN EL ARRAY EL MISMO ELEMENTO
            {
                al_add(nuevaLista, aux); //Y LO AGREGO A LA NUEVA LISTA
                bandera = 1;
            }
        }
    }

    if (bandera)
        retorno = 1;

    return retorno;
}






