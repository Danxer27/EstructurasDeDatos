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
    //
}

bool Ingredient::operator!=(const Ingredient&) const {
    
}

bool Ingredient::operator<=(const Ingredient&) const {
    
}

bool Ingredient::operator>=(const Ingredient&) const{
    
}

bool Ingredient::operator<(const Ingredient&) const {
    
}

bool Ingredient::operator>(const Ingredient&) const
{
    
}

int Ingredient::compare(const Ingredient& a, const Ingredient& b)
{
    
}

int Ingredient::comapreByName(const Ingredient& a, const Ingredient& b){
    return a.getName().compare(b.getName());
}

int Ingredient::compareByAmount(const Ingredient& a, const Ingredient& b) {
    return a.getAmount() - b.getAmount();
}


Ingredient& Ingredient::operator=(const Ingredient&)
{
    
}
