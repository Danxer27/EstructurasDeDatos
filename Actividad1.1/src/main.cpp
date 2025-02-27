#include <time.h>
#include <iostream>
#include <limits>
#include "Matriz.h"
using namespace std;

void datosPrimitivos();
void calcularMatrices();

int main() {
  srand(time(NULL));
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

void datosPrimitivos() {
  cout << "Tipos de dato\t\t\t Bits\t\t Valor Minimo\t\t Valor Maximo " << endl;

  cout << "Caracter con signo: \t\t" << numeric_limits<char>::min() << "\t"
       << numeric_limits<char>::max() << endl;
  cout << "Caracter sin signo: \t\t" << numeric_limits<unsigned char>::min()
       << "\t" << numeric_limits<unsigned char>::max() << endl;

  cout << "Entero corto con signo: \t" << numeric_limits<short int>::min()
       << "\t" << numeric_limits<short int>::max() << endl;
  cout << "Entero corto sin signo: \t"
       << numeric_limits<unsigned short int>::min() << "\t"
       << numeric_limits<unsigned short int>::max() << endl;

  cout << "Entero largo con signo: \t" << numeric_limits<int>::min() << "\t"
       << numeric_limits<int>::max() << endl;
  cout << "Entero largo sin signo: \t" << numeric_limits<unsigned int>::min()
       << "\t" << numeric_limits<unsigned int>::max() << endl;

  cout << "Real de presicion simple: \t" << numeric_limits<float>::min() << "\t"
       << numeric_limits<float>::max() << endl;
  cout << "Real de presicion double: \t" << numeric_limits<double>::min()
       << "\t" << numeric_limits<double>::max() << endl;
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