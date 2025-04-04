// Archivo de Implementaicon de la clase de proceso "Expresion"
#include "expresion.hpp"
#include <iostream>

using namespace std;

Expresion::Expresion() {}

void Expresion::setInfix(const Queue<char>& q) {
  this->infNotation = q;
  this->changeNotation();
}

Queue<char> Expresion::getPostfix() {
  return this->posNotation;
}

void Expresion::changeNotation() {
  char op;

  while (!this->infNotation.isEmpty()) {
    op = this->infNotation.dequeue();

    // Con opValue(), (Designacion del valor del operador) designa el valor de
    // presedencia, y con ella trabajar segun sea el caso para apilar/desapilar.
    switch (opValue(op)) {
      case 0:
        try {
          this->opCola.push(op);
        } catch (const Stack<char>::Exception& ex) {
          cout << ex.what() << endl;
        }
        break;

      case -1:
        while ((!this->opCola.isEmpty()) && (this->opCola.getTop() != '(')) {
          try {
            this->posNotation.enqueue(this->opCola.pop());
          } catch (const Queue<char>::Exception& ex) {
            cout << ex.what() << endl;
          }
        }
        if ((!this->opCola.isEmpty()) && (this->opCola.getTop() == '(')) {
          this->opCola.pop();
        }
        break;

      case 4:
        while ((!this->opCola.isEmpty()) &&
               this->opValue(this->opCola.getTop()) >= this->opValue(op)) {
          try {
            this->posNotation.enqueue(this->opCola.pop());
          } catch (const Queue<char>::Exception& ex) {
            cout << ex.what() << endl;
          }
        }

        try {
          this->opCola.push(op);
        } catch (const Stack<char>::Exception& ex) {
          cout << ex.what() << endl;
        }
        break;

      case 3:
        while ((!this->opCola.isEmpty()) &&
               this->opValue(this->opCola.getTop()) >= this->opValue(op)) {
          try {
            this->posNotation.enqueue(this->opCola.pop());
          } catch (const Queue<char>::Exception& ex) {
            cout << ex.what() << endl;
          }
        }

        try {
          this->opCola.push(op);
        } catch (const Stack<char>::Exception& ex) {
          cout << ex.what() << endl;
        }
        break;

      case 2:
        while ((!this->opCola.isEmpty()) &&
               this->opValue(this->opCola.getTop()) >= this->opValue(op)) {
          try {
            this->posNotation.enqueue(this->opCola.pop());
          } catch (const Queue<char>::Exception& ex) {
            cout << ex.what() << endl;
          }
        }

        try {
          this->opCola.push(op);
        } catch (const Stack<char>::Exception& ex) {
          cout << ex.what() << endl;
        }
        break;

      case 1:
        try {
          this->posNotation.enqueue(op);
        } catch (const Queue<char>::Exception& ex) {
          cout << ex.what() << endl;
        }
        break;
    }
  }
  while ((!this->opCola.isEmpty())) {
    try {
      this->posNotation.enqueue(this->opCola.pop());
    } catch (const Queue<char>::Exception& ex) {
      cout << ex.what() << endl;
    }
  }
}

int Expresion::opValue(const char& c) {
  /* Valor de presedencia los Operadores / Operandos
         ^ = 4
       * / = 3
       + - = 2
  Operando = 1
  Casos de apertura y cierre de parentesis:
          ( = 0
          ) = -1
  */

  if (c == '(') {
    return 0;
  } else if (c == ')') {
    return -1;
  } else if (c == '^') {
    return 4;
  } else if (c == '*' || c == '/') {
    return 3;
  } else if (c == '+' || c == '-') {
    return 2;
  } else {
    return 1;
  }
}

string Expresion::toString() {
  string result = "";

  while (!posNotation.isEmpty()) {
    result += posNotation.dequeue();
  }

  return result;
}
