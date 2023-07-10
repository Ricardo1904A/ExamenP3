#include <stdio.h>
#include <stdlib.h>

#define Nombre 50
#define Materia 50
// Uso de estructuras para guardar los datos de los estudiantes
typedef struct
{
    char nombre[Nombre];
    char materia[Materia];
    float nota1;
    float nota2;
    float nota3;
} Estudiante;
