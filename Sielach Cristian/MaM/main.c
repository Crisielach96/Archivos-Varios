#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct{
    int id;
    char descripcion[20];
}eMateria;

typedef struct{
    int legajo;
    int idMateria;
}eInscripcion;




int main()
{
    eAlumno Alumnos[]={{1, "Jose"}, {3, "Alberto"}, {4, "Juan"}, {7, "Luis"}, {10, "Ana"}, {9, "Silvia"}, {8, "Maria"}, {15, "Sofia"}, {18, "Martin"}, {11, "Dalia"}};
    eMateria Materias[]={{1, "Progamacion"}, {2, "Matematicas"},{3, "Quimica"}, {4, "Fisica"}, {5, "Electronica"}};
    eInscripcion Inscripciones[]={{1,2}, {1,3}, {3,2}, {4,4}, {3,5}, {3,1}, {4,1}, {1,1}, {8,1}, {9,3}, {10,2}, {10,5}, {10, 3}, {8, 1}, {1,2}};





    return 0;
}

void mostrarAlumnos(eAlumno alumnos[],int tamAlumno,eMateria materias[],int tamMaterias,eInscripcion inscripcion[],int tamI)
{

}
