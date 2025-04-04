// Archivo de definicion de la Interfaz.
#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include "expresion.hpp"

class Interface {
 public:
  Interface();

  std::string changeNotation(const string&);
  std::string toString(Queue<char>&);

};

#endif  //__INTERFACE_HPP__