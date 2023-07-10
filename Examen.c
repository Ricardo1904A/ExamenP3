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
// Primera funcion para crear el archivo de estudiantes
void G_estudiante(Estudiante estudiante, int numero)
{
    FILE *archivo;
    archivo = fopen("estudiantes.txt", "a");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%d;%s;%s;%.2f;%.2f;%.2f\n", numero, estudiante.nombre, estudiante.materia, estudiante.nota1, estudiante.nota2, estudiante.nota3);

    fclose(archivo);
}
// segunda funcion para cargar el archivo de estudiantes una ves ingresado los datons mas adelante en el programa
void C_estudiante()
{
    FILE *archivo;
    archivo = fopen("estudiantes.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Estudiante estudiante;
    int numero = 1;
    // Utilizamos "%*[^;] para poder separar cada valor de la estructura por un punto y como como fue pedido en el ejercicio
    while (fscanf(archivo, "%*[^;];%[^;];%[^;];%f;%f;%f\n", estudiante.nombre, estudiante.materia, &estudiante.nota1, &estudiante.nota2, &estudiante.nota3) == 5)
    {
        printf("%d;%s;%s;%.2f;%.2f;%.2f\n", numero, estudiante.nombre, estudiante.materia, estudiante.nota1, estudiante.nota2, estudiante.nota3);
        numero++;
    }

    fclose(archivo);
}
// iniciamos ingresando los estudiantes con las respectivas notas que nos daba el problema del programa a resolver
int main()
// ingresamos manualmente cada estudiante haciendo uso de la estructura antes creada y creando una variable para despues usar en la funcion de cargar archivos para que se escriba en el archivo estudianetes
{
    Estudiante estudiante1 = {"Carlos Mata", "Software", 6.00, 7.00, 8.00};
    Estudiante estudiante2 = {"Luis Miguel", "Contabilidad", 5.00, 6.00, 7.00};
    Estudiante estudiante3 = {"Ana Belén", "Ciberseguridad", 10.00, 9.00, 10.00};
    Estudiante estudiante4 = {"Maria Victoria", "Software", 9.00, 9.00, 9.00};
    Estudiante estudiante5 = {"Juan Pérez", "Administración", 8.50, 8.00, 9.00};
    // despues de ingresar los datos por teclado hacemos que carge en la funcion antes creada para que se suba los datos al archivo
    G_estudiante(estudiante1, 1);
    G_estudiante(estudiante2, 2);
    G_estudiante(estudiante3, 3);
    G_estudiante(estudiante4, 4);
    G_estudiante(estudiante5, 5);

    C_estudiante();

    return 0;
}