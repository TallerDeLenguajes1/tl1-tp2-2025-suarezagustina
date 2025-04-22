#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a) Estructura compu
typedef struct {
    int velocidad;         // Velocidad de procesamiento en GHz (Valor entre 1 y 3)
    int anio;              // Año de fabricacion (Valor entre 2015 y 2024)
    int cantidad_nucleos;  // Cantidad de nucleos (Valor entre 1 y 8)
    char *tipo_cpu;        // Tipo de procesador (Apunta a una cadena de caracteres)
} compu;

void listarPCs(compu PCS[], int cantidad);
void mostrarMasVieja(compu PCS[], int cantidad);

int main(){
    int cantidad = 5;

    // b) Genero Datos Aleatorios
    srand(time(NULL)); // Semilla

    // c) Arreglo de 5 elementos para las PC
    compu PCS[cantidad];
    char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};

    for (int i = 0; i < cantidad; i++)
    {
        PCS[i].velocidad = 1 + rand() % 3; // Formula: inicio + rand() % (fin - inicio + 1)
        PCS[i].anio = 2015 + rand() % 10;
        PCS[i].cantidad_nucleos = 1 + rand() % 8;
        int indiceTipo = rand() % 6;
        PCS[i].tipo_cpu = tipos[indiceTipo];
    }

    // d) Funciones:
    listarPCs(PCS, cantidad);
    mostrarMasVieja(PCS, cantidad);

    return 0;
}

// d) Función que lista todas las PCs
void listarPCs(compu PCS[], int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        printf("PC Numero: %d\n", i + 1);
        printf("Velocidad de Procesamiento: %d GHz\n", PCS[i].velocidad);
        printf("Anio de fabricacion: %d\n", PCS[i].anio);
        printf("Cantidad de Nucleos: %d\n", PCS[i].cantidad_nucleos);
        printf("Tipo de Procesador: %s\n", PCS[i].tipo_cpu);
        printf("\n");
    }
}

// d) Función que muestra la PC más vieja
void mostrarMasVieja(compu PCS[], int cantidad) {
    int indice_mas_vieja = 0;

    for (int i = 1; i < cantidad; i++) {
        if (PCS[i].anio < PCS[indice_mas_vieja].anio) {
            indice_mas_vieja = i;
        }
    }

    printf("La PC mas vieja es la número: %d\n", indice_mas_vieja + 1);
    printf("Velocidad de Procesamiento: %d\n", PCS[indice_mas_vieja].velocidad);
    printf("Anio de fabricacion: %d\n", PCS[indice_mas_vieja].anio);
    printf("Cantidad de Nucleos: %d\n", PCS[indice_mas_vieja].cantidad_nucleos);
    printf("Tipo de Procesador: %s\n", PCS[indice_mas_vieja].tipo_cpu);
}
