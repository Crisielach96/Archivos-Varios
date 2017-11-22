#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListModificada.h"
#include "clientes.h"

int main()
{
    ArrayList* lista=NULL;
    ArrayList* auxCero=NULL;
    ArrayList* auxUno=NULL;
    int salida=1;

    lista = al_newArrayList();
    auxCero= al_newArrayList();
    auxUno= al_newArrayList();

    if(lista!=NULL)
    {
        while(salida)
        {
            switch(menu())
            {
            case 1:
                lee_archivo_cliente(lista);
                break;

            case 2:
                lee_archivo_cliente(auxCero);
                //lee_archivo_clienteBL(lista,auxCero);
                break;

            case 3:
                compara_cadena(lista,auxCero,auxUno);
                //divide_lista(lista,auxCero,auxUno);
                break;

            case 4:
                mostrar_clientes(lista);
                getch();
                break;

            case 5:

                salida=0;
                break;
            }
        }
    }
    return 0;
}
