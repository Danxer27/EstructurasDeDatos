// Archivo de implementaicon de la Interfaz
#include "interface.hpp"
#include <iostream>
#include <limits>

using namespace std;

Interface::Interface() {
  this->menu();
}

void Interface::menu() {
  char opcion;
  string cad;

  do {
    cout << "Ingresa notacion Infija: ";
    getline(cin, cad);

    this->setExpresion(cad);

    this->changeNotation();

    cout << "Posfija: " << this->expresion << endl << endl;

    cout << "Quieres ingresar mas expresiones? (s/n): ";
    cin >> opcion;

    cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

  } while (opcion == 's' || opcion == 'S');

  cout << "Saliendo..." << endl;
  getchar();
}

// Funcion que se encarga de pasar la expresion al objeto de conversion
// "Expresion"
void Interface::changeNotation() {
  Queue<char> infNotation, posNotation;  // Pilas de notacion infija y posfija

  int i, n(this->expresion.size());
  // Rellenar la cola
  for (i = 0; i < n; i++) {
    try {
      infNotation.enqueue(this->expresion[i]);
    } catch (const Stack<char>::Exception& ex) {
      cout << ex.what() << endl;
    }
  }

  // Declaracion y uso del objeto para el proceso de cambio de la expresion.
  Expresion exp;

  exp.setInfix(infNotation);
  posNotation = exp.getPostfix();

  this->expresion = exp.toString();
}

void Interface::setExpresion(const string& e) {
  this->expresion = e;
}