//Archivo Main
#include "interface.hpp"
#include <iostream>
int main(){
    std::cout << "Iniciando el programa..." << std::endl;

    try {
        Interface interfaz; // Aquí podría estar el problema
        std::cout << "Interface creada con éxito." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Error desconocido!" << std::endl;
    }

    std::cout << "Terminando el programa..." << std::endl;
    return 0;
}
