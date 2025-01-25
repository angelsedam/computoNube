#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para inicializar la semilla de rand()

int main() {
    // Definir el tamaño de los arreglos
    const int size = 1000;

    // Crear los arreglos
    std::vector<int> A(size), B(size), R(size);

    // Inicializar los arreglos con valores aleatorios
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        A[i] = rand() % 100; // Valores entre 0 y 99
        B[i] = rand() % 100; // Valores entre 0 y 99
    }

    // Realizar la suma en paralelo usando OpenMP
#pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        R[i] = A[i] + B[i];
    }

    // Imprimir los primeros 10 resultados para verificar
    std::cout << "Primeros 10 elementos de cada arreglo:" << std::endl;
    std::cout << "A: ";
    for (int i = 0; i < 10; ++i) std::cout << A[i] << " ";
    std::cout << "\nB: ";
    for (int i = 0; i < 10; ++i) std::cout << B[i] << " ";
    std::cout << "\nR: ";
    for (int i = 0; i < 10; ++i) std::cout << R[i] << " ";
    std::cout << std::endl;

    return 0;
}
