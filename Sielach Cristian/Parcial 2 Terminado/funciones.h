typedef struct
{
    char nombre[51];
    char mail[71];
    int isEmpty;
}eDestinatario;

eDestinatario* destinatario_nuevo(void);
void set_destinatario(eDestinatario* returAux,char* nombre, char* mail, int isEmpty);
void borrar_destinatario(eDestinatario* lista);
void imprimir_destinatario(eDestinatario* lista);
int parseo(FILE* pFile , ArrayList* lista);
int cargarBlacklist(ArrayList* destinatarios, ArrayList* blacklist, FILE* blacklistFile);
int depurar(ArrayList*, ArrayList*, ArrayList*);
