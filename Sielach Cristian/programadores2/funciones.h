


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

int menu();
void variablesCero(eProgramador[],int);
void inicializarVariables(eProgramador[],int);
void mostrarProgramador(eProgramador,eCategoria);
void mostrarProgramadores(eProgramador[],eCategoria[],int);
int buscarLibre(eProgramador[],int);
int buscarProgramador(int,eProgramador[],int);
void alta(eProgramador[],eCategoria[],int);
void baja(eProgramador[],eCategoria[],int);
void modificacion(eProgramador[],eCategoria[],int);
