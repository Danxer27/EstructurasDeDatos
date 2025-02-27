// Archivo Matriz.cpp de implementacion de la clase Matriz
#include "Matriz.h"
#include <time.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Constructor que requiere de la dimension de la matriz
Matriz::Matriz(int num) {
  n = num;
  generarMatriz(matriz, n, n, "A");
  generarMatriz(matrizB, n, n, "B");
};

// Metodo para generar una matriz con numeros aleatorios
void Matriz::generarMatriz(float matrizGen[][10],
                           int n,
                           int n2,
                           string nombre) {
  int i, j;
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrizGen[i][j] =
          float(rand() % -100 + 100) + (float(rand() % 100) / 100);
    }
  }
  string nombreMatriz = nombre;
  imprimirMatriz(matrizGen, n, n, ("Matriz " + nombreMatriz));
}

// Metodo para multiplicar dos matrices
void Matriz::multiplicarMatriz() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrizC[i][j] = matriz[i][j] * matrizB[i][j];
    }
  }
  imprimirMatriz(matrizC, n, n, "C");
}

// Metodo para sumar dos matrices
void Matriz::sumarMatriz() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrizD[i][j] = matriz[i][j] + matrizB[j][i];
    }
  }
  imprimirMatriz(matrizD, n, n, "D");
}

// Metodo para imprimir una matriz
void Matriz::imprimirMatriz(float matrizImp[][10],
                            int n,
                            int n2,
                            string nombre) {
  int i, j;
  cout << "Matriz " + nombre << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << fixed << setprecision(2) << matrizImp[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}