typedef struct
{
    int idDuenio;
    char nombre[20];
    char apellido[20];
    long int numeroTarjeta;
    int direccion;
    int estado;
}eCliente;

typedef struct
{
    char patente[4];
    int marca;
    int duenio;
    int horaEntrada;
    int estado;
}eAuto;


int buscarLibre(eCliente lista[],int tam);
int buscarClientePorId(int id,eCliente lista[],int tam);
void variablesCero(eCliente lista[],int i);
void inicializarVariables(eCliente lista[],int tam);
void alta(eCliente lista[],int tam);
void harcCliente(eCliente lista[],int tam);
void mostrarClientes(eCliente lista[], int tam);
void mostrarCliente(eCliente lista);
int buscarLibreAuto(eAuto lista[],int tam);
void variablesCeroAuto(eAuto lista[],int i);
void inicializarVariablesAutos(eAuto lista[],int tam);
void altaAuto(eAuto lista[],int tamA,eCliente cliente[],int tamC);
void mostrarClientesAutos(eCliente lista[], int tamC,eAuto autos[],int tamA);
void ordenar(eAuto autos[],int tamA);
void harcAuto(eAuto autos[],int tam);
