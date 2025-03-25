#include "ingredient.hpp"
using namespace std;


Ingredient::Ingredient() {}

Ingredient::Ingredient(const Ingredient& i) : name(i.name), amount(i.amount) {}

void Ingredient::setName(const std::string& n){
    this->name = n;
}

void Ingredient::setAmount(const float& a){
    this->amount = a;
}

void Ingredient::setMeasurementUnit(const std::string& s){
    this->measureUnit = s;
}

std::string Ingredient::getName() const {
    return this->name;
}

float Ingredient::getAmount() const{
    return this->amount;
}

std::string Ingredient::getUnit() const {
    return this->measureUnit;
}

std::string Ingredient::toString(){
    return this->getName() + " " + to_string(this->getAmount()) + this->getUnit();
}


bool Ingredient::operator==(const Ingredient& i) const {
    return (this->name.compare(i.name)) && (this->amount == i.amount);
}

bool Ingredient::operator!=(const Ingredient& i) const {
    return !(*this == i);
}

bool Ingredient::operator<(const Ingredient& i) const {
    return (this->amount < i.amount) && (this->measureUnit == i.measureUnit);
}

bool Ingredient::operator<=(const Ingredient& i) const {
    return *this == i || *this < i;
}

bool Ingredient::operator>=(const Ingredient& i) const{
    return !(*this < i);
}

bool Ingredient::operator>(const Ingredient& i) const{ 
    return !(*this <= i);
}

int Ingredient::compareTo(const Ingredient& i){
    return this->name.compare(i.name);
}

int Ingredient::comapreByName(const Ingredient& a, const Ingredient& b){
    return a.getName().compare(b.getName());
}

int Ingredient::compareByAmount(const Ingredient& a, const Ingredient& b) {
    return a.getAmount() - b.getAmount();
}

int Ingredient::compareUnit(const Ingredient& a, const Ingredient& b) {
    return a.getAmount() - b.getAmount();
}

Ingredient& Ingredient::operator=(const Ingredient& i){
    this->name = i.name;
    this->amount = i.amount;
    this->measureUnit = i.measureUnit;
}
