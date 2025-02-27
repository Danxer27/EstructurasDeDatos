// Archivo header de la clase Matriz
#include <iostream>
#include <string>
using namespace std;

class Matriz {
 private:
  int n;
  float matriz[10][10];
  float matrizB[10][10];
  float matrizC[10][10];
  float matrizD[10][10];

 public:
  Matriz(int);
  void generarMatriz(float matriz[][10], int, int, string);
  void multiplicarMatriz();
  void sumarMatriz();
  void imprimirMatriz(float matriz[][10], int, int, string);
};