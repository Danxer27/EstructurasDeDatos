// Archivo de implementaicon de la Interfaz
#include "interface.hpp"
#include <iostream>
#include <limits>

using namespace std;

Interface::Interface() {
  char opcion;
  string expresion;

  do {
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingresa notacion Infija: ";
    getline(cin, expresion);

    cout << "Posfija: " << this->changeNotation(expresion) << endl << endl;

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
string Interface::changeNotation(const string& ex) {
  Queue<char> infNotation, posNotation;  // Pilas de notacion infija y posfija

  int i, n(ex.size());
  // Rellenar la cola
  for (i = 0; i < n; i++) {
    try {
      infNotation.enqueue(ex[i]);
    } catch (const Stack<char>::Exception& ex) {
      cout << ex.what() << endl;
    }
  }

  // Declaracion y uso del objeto para el proceso de cambio de la expresion.
  Expresion exp;

  exp.setInfix(infNotation);
  posNotation = exp.getPostfix();

  return exp.toString();
}
