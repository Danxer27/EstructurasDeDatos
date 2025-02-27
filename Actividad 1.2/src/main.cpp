// Archivo main.cpp
#include <time.h>
#include <iostream>
#include <limits>
#include <string>
#include "Matriz.h"
using namespace std;

void datosPrimitivos();
void calcularMatrices();

int main() {
  int opcion;
  bool RUN = true;

  while (RUN) {
    cout << "1.Tamanio y rangos de los Tipos de Dato Primitivos" << endl;
    cout << "2.Ejemplo de uso de Tipo de dato Estructurado" << endl;
    cout << "3.Salir" << endl;
    cin >> opcion;
    switch (opcion) {
      case 1:
        datosPrimitivos();
        break;
      case 2:
        calcularMatrices();
        break;
      case 3:
        RUN = false;
        break;
      default:
        cout << "Opcion invalida." << endl;
        break;
    }
  }

  return 0;
}

// Funcion para mostrar tabla con los datos primitivos
void datosPrimitivos() {
  cout << "Tipos de dato\t\t\t Bits\t\t Valor Minimo\t\t Valor Maximo " << endl;

  cout << "Caracter con signo: \t\t" << sizeof(char) * 8 << "\t\t"
       << int(numeric_limits<char>::min()) << "\t\t\t"
       << int(numeric_limits<char>::max()) << endl;
  cout << "Caracter sin signo: \t\t" << sizeof(unsigned char) * 8 << "\t\t"
       << int(numeric_limits<unsigned char>::min()) << "\t\t\t"
       << int(numeric_limits<unsigned char>::max()) << endl;

  cout << "Entero corto con signo: \t" << sizeof(short int) * 8 << "\t\t"
       << numeric_limits<short int>::min() << "\t\t\t"
       << numeric_limits<short int>::max() << endl;
  cout << "Entero corto sin signo: \t" << sizeof(unsigned short int) * 8
       << "\t\t" << numeric_limits<unsigned short int>::min() << "\t\t\t"
       << numeric_limits<unsigned short int>::max() << endl;

  cout << "Entero largo con signo: \t" << sizeof(int) * 8 << "\t\t"
       << numeric_limits<int>::min() << "\t\t" << numeric_limits<int>::max()
       << endl;
  cout << "Entero largo sin signo: \t" << sizeof(unsigned int) * 8 << "\t\t"
       << numeric_limits<unsigned int>::min() << "\t\t\t"
       << numeric_limits<unsigned int>::max() << endl;

  cout << "Real de presicion simple: \t" << int(sizeof(float)) * 8 << "\t\t"
       << numeric_limits<float>::min() << "\t\t" << numeric_limits<float>::max()
       << endl;
  cout << "Real de presicion double: \t" << int(sizeof(double)) * 8 << "\t\t"
       << numeric_limits<double>::min() << "\t\t"
       << numeric_limits<double>::max() << endl;
  cout << endl;
}

void calcularMatrices() {
  int n;
  cout << "Dimension de la Matriz:" << endl;
  cin >> n;
  Matriz MatrizA(n);
  Matriz MatrizB(n);
  MatrizA.multiplicarMatriz();
  MatrizA.sumarMatriz();
}