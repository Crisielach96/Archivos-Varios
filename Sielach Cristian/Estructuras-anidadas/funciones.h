typedef struct
    {
       int id;
       char nombre[20];
       int categ;
       float sueldo;
       int estado;
    }eProg;

    typedef struct
    {
       int idCat;
       char nombCat[12];
       float sueldo;
    }eCat;

    typedef struct
    {
       int idProy;
       char desc[10];
    }eProy;

    typedef struct
    {
       int idProg;
       int idProy;
       int hsTrabajadas;
    }ProgProy;

void variablesCero(eProg[],int);
void inicializarVariables(eProg[],int);
void mostrarProgramador(eProg);
void mostrarProgramadores(eProg[],eCat[],int,int);
int buscarLibre(eProg[],int);
int buscarProgramador(int,eProg[],int);
void alta(eProg[],int);
void baja(eProg[],int);
void modificacion(eProg[],int);
void harcProg(eProg[],int);
void harcProy(eProy[],int);
void buscarCat(eProg[],eCat[],int,int);
void harcCat(eCat[],int);
