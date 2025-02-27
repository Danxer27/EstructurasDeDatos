#include "producto.hpp"
using namespace std;

Producto::Producto() {}

Producto::Producto(const Producto& p) : codigoBarra(p.codigoBarra), nombre(p.nombre), peso(p.peso) {}

void Producto::setCodigoBarra(string& s) {
    this->codigoBarra = s;
}

void Producto::setNombre(string& n){
    this->nombre = n;
}

void Producto::setPeso(float& p){
    this->peso = p;
}

void Producto::setFechaEntrada(Fecha& f){
    this->fechaEntrada = f;
}

void Producto::setPrecioMayoreo(float& p){
    this->precioMayoreo = p;
}

void Producto::setPrecioMenudeo(float& pm){
    this->precioMenudeo = pm;
}

void Producto::setExistencia(int& ex){
    this->existencia = ex;
}

string Producto::toString(){

}

string Producto::getCodigoBarra(){
    return this->codigoBarra;
}

string Producto::getNombre(){
    return this->nombre;
}

float Producto::getPeso(){
    return this->peso;
}

Fecha Producto::getFechaEntrada(){
    return this->fechaEntrada;
}

float Producto::getPrecioMayoreo(){
    return this->precioMayoreo;
}

float Producto::getPrecioMayoreo(){
    return this->precioMenudeo;
}

int Producto::getExistencia(){
    return this->existencia;
}