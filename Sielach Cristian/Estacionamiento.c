
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Estacionamiento.h"


int id=0;
int obtenerEspacioLibre(eAuto coche[])
{
    int lugar= -1;
    short int i;

    for(i=0; i<10000; i++)
    {


        if(coche[i].estado==0)
        {

            lugar = i;
            break;
        }


    }
    return lugar;
}

void mostrarDatos(eAuto coche[],  int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(coche[i].estado==1)
            printf("%s\t %s\t      %d\t\n",coche[i].patente, coche[i].modelo, coche[i].id);
    }
    printf("\n");
}



void cargarDatos(eAuto coche[], int tam)
{
    int hayLugar=obtenerEspacioLibre(coche);


    if(hayLugar!=-1)
    {
        getString("Ingrese Patente: ",coche[hayLugar].patente);
        getString("Ingrese Modelo: ",coche[hayLugar].modelo);
        printf("\n");
        id++;
        coche[hayLugar].id=id;
        coche[hayLugar].estado=1;

        hayLugar=1;

        if(!hayLugar)
        {
            printf("No hay lugar disponible.");
        }
    }
}


void bajaDatos(eAuto coche[],  int tam)
{
    int id, i;
    char respuesta;
    int flagEncontro=0;
    printf("Ingrese id: ");
    scanf("%d", &id);
    for(i=0; i<tam; i++)
    {
        if(coche[i].estado== 1 && id == coche[i].id)
        {
            printf("%d--%s", coche[i].id, coche[i].patente);
            printf("Esta seguro que desea dar de baja? s/n");
            respuesta = getche();
            if(respuesta=='s')
            {
                coche[i].estado = 0;
            }
            else
            {
                printf("Accion cancelada!!!");
            }

            flagEncontro = 1;
            break;
        }

    }
    if(!flagEncontro)
    {
        printf("Auto inexistente");
    }


}
void modificarDatos(eAuto coche[],  int tam)
{
    int id, i;
    char respuesta, auxPatente[15],auxModelo[15];
    int flagEncontro=0;
    printf("Ingrese id: ");
    scanf("%d", &id);
    for(i=0; i<tam; i++)
    {
        if(coche[i].estado == 1 && id == coche[i].id)
        {
            printf("%d--%s", coche[i].id, coche[i].patente);
            printf("ingrese el nueva patente: ");
            fflush(stdin);
            gets(auxPatente);
            printf("ingrese el nuevo modelo: ");
            fflush(stdin);
            gets(auxModelo);
            printf("Esta seguro que desea modificar? s/n");
            respuesta = getche();
            if(respuesta=='s')
            {
                strcpy(coche[i].patente, auxPatente);
                strcpy(coche[i].modelo, auxModelo);
            }
            else
            {
                printf("Accion cancelada!!!");
            }

            flagEncontro = 1;
            break;
        }

    }
    if(!flagEncontro)
    {
        printf("Id inexistente");
    }


}
void ordenarPorNombre(eAuto coche[],  int tam)
{
    int i, j;
    char auxCadena[15];
    int auxInt;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(coche[i].patente,coche[j].patente)>0)
            {
                strcpy(auxCadena,coche[i].patente);
                strcpy(coche[i].patente,coche[j].patente);
                strcpy(coche[j].patente, auxCadena);

                auxInt = coche[i].id;
                coche[i].id = coche[j].id;
                coche[j].id = auxInt;

                auxInt = coche[i].estado;
                coche[i].estado = coche[j].estado;
                coche[j].estado = auxInt;

            }
            else
            {
                if(strcmp(coche[i].patente,coche[j].patente)==0)
                {
                    if(coche[i].id > coche[j].id)
                    {

                        auxInt = coche[i].id;
                        coche[i].id = coche[j].id;
                        coche[j].id = auxInt;


                        auxInt = coche[i].estado;
                        coche[i].estado = coche[j].estado;
                        coche[j].estado = auxInt;
                    }
                }
            }
        }
    }
}

void variablesCero(eAuto coche[], int i)
{

    strcpy(coche[i].patente, "\0");
    strcpy(coche[i].modelo, "\0");
    coche[i].marca = 0;
    coche[i].estado = 0;
}

void inicializarVariables(eAuto coche[], int tam)
{
    short int i;

    for(i=0; i<tam; i++)
    {
        variablesCero(coche,i);
    }
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje,int auxiliar)
{
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    clearStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    clearStdin();
    scanf ("%[^\n]s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}


/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMessageLenght Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargará el texto ingresado
 * \param maxLenght int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 *
 */
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getStringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps)
{
    char auxStr[256];
    int i, retorno = -1;
    float auxInt;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atof(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}


/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clearStdin(void)
{
    setbuf(stdin,NULL);
}

/**
 * \brief Hace una pausa, similar al system("pause")
 * \param -
 * \return -
 *
 */
void pause(void)
{
    getChar("");
}

/**
 * \brief Hace un clear, similar al system("clear")
 * \param -
 * \return -
 *
 */
void clearScreen(void)
{
    system("clear"); //system("cls");
}


