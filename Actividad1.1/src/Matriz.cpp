#include "Matriz.h"
#include <iostream>
#include <string>
using namespace std;

Matriz::Matriz(int num) {
  n = num;
  generarMatriz(matriz, n, n, "A");
  generarMatriz(matrizB, n,n, "B");
};

void Matriz::generarMatriz(double matrizGen[][10], int n, int n2, string nombre) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrizGen[i][j] = rand() % 100000;
    }
  }
  string nombreMatriz = nombre;
  imprimirMatriz(matrizGen, n, n, ("Matriz " + nombreMatriz));
}

void Matriz::multiplicarMatriz() {
  int i, j;
  //double matriz2 = *matrizB;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrizC[i][j] = matriz[i][j] * matrizB[i][j];
    }
  }
  imprimirMatriz(matrizC, n, n, "C");
}

void Matriz::sumarMatriz() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrizD[i][j] = matriz[i][j] + matrizB[j][i];
    }
  }
  imprimirMatriz(matrizD, n, n, "D");
}

void Matriz::accederMatriz() {
  double **matriz = new double *[n];
  //return matriz;
}

void Matriz::imprimirMatriz(double matrizImp[][10], int n, int n2, string nombre) {
  int i, j;
  cout << "Matriz " + nombre << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << matrizImp[i][j] << " ";
    }
    cout << endl;
  }
  cout<<endl;
}