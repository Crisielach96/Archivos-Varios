#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 2

typedef struct{
    int id;
    char nombre[20];
    int proyecto;
    int idCategoria;
    int estado;
    float sueldo;
    int cantHsTrab;
}
eProgramador;

typedef struct{
    int id;
    int desc;
    float precio;
    int estadoCat;
}
eCategoria;

//a = Senior
//b = SemiSenior
//c = Junior

int main()
{
    eProgramador equipo[]={{124,"Juan",111,3,1},{125,"Raul",222,2,1},{126,"Oscar",333,1,1}};
    eCategoria cat[]={{1,"Senior",100},{2,"SemiSenior",75},{3,"Junior",50}};

    int i;

    for(i=0; i<3; i++)
    {
        if(cat[i].id==equipo.idCategoria)
        {
            printf("%d    %c    %c",equipo[i].id,equipo[i].nombre,cat[i].desc);
            break
        }

    }
}
