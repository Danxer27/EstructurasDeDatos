// Archivo de definicion de la clase "Expresion"
#include "queue.hpp"
#include "stack.hpp"

class Expresion {
 private:
  Queue<char> infNotation, posNotation;  // Pila de notacion infija y posfija
  Stack<char> opCola;                    // Cola de Operadores y Operandos
 public:
  Expresion();
  Expresion(const Expresion&);
  Expresion(const string&);

  void setInfix(const Queue<char>&);  // Recibe Notacion Infija
  Queue<char>& getPostfix();           // Devuelve Notacion Posfija

  void changeNotation();

  std::string toString();

  int opValue(const char&);
};