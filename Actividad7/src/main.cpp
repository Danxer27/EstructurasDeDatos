// Archivo Main
#include <iostream>
#include "interface.hpp"

int main() {
  try {
    List<Integer, 100000> integers;
    Interface Inters(integers);
    throw std::runtime_error("Error detectado");
  } catch (const std::exception& e) {
    std::cerr << "Excepción atrapada: " << e.what() << std::endl;
  }

  return 0;
}
