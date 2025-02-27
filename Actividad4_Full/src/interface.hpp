// Archivo de definicion de la Interfaz.
#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include "expresion.hpp"

class Interface {
 private:
  std::string expresion;

 public:
  Interface();
  Interface(const Interface&);
  void menu();

  void changeNotation();
  std::string toString(Queue<char>&);

  void setExpresion(const string&);
};

#endif  //__INTERFACE_HPP__