// Arhivo de definicion de la interfaz.
#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include "integer.hpp"
#include "list.hpp"

class Interface {
 private:
  List<Integer, 100000>* listRef;

 public:
  Interface(List<Integer, 100000>&);
};

#endif  //__INTERFACE_HPP__
