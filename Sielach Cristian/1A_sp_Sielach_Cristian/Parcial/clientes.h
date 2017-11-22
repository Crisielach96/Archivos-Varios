#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    char mail[50];
    char nombre[20];

} eCliente;

int divide_lista(ArrayList* lista,ArrayList* aux,ArrayList* depuracion);
int baja_logica_cliente(ArrayList*);
int menu(void);
int valida_int(int,int, int);
float valida_float(float,float, float);
char* valida_cadena(char[],int,int);
eCliente* nuevo_cliente(ArrayList*);
eCliente cargar_cliente(ArrayList*);
void mostrar_un_cliente(eCliente*);
int mostrar_clientes (ArrayList* lista);
int busca_tarea(ArrayList*,int);
int lee_archivo_cliente(ArrayList* lista);
int lee_archivo_clienteBL(ArrayList* lista,ArrayList* listaBL);
int ordena_por_hora(ArrayList*);
int compara_cadena(lista,auxCero);


#endif // CLIENTES_H_INCLUDED
