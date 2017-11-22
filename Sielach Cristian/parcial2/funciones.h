


typedef struct
{
  char descripcion[100];
  int prioridad;
  int tiempo;
  int Empty;
}eParcial;


int parserParcial(FILE* pFile, ArrayList* pArrayListEmployee);

eParcial* employee_new(void);

void employee_print(eParcial* lista);

int menu();
