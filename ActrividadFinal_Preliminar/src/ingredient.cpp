#include "ingredient.hpp"
using namespace std;


Ingredient::Ingredient() {}

Ingredient::Ingredient(const Ingredient& i) : name(i.name), amount(i.amount), measureUnit(i.measureUnit) {}

void Ingredient::setName(const string& n){
    this->name = n;
}

void Ingredient::setAmount(const double& a){
    this->amount = a;
}

void Ingredient::setMeasurementUnit(const string& s){
    this->measureUnit = s;
}

string Ingredient::getName() const {
    return this->name;
}

double Ingredient::getAmount() const{
    return this->amount;
}

string Ingredient::getUnit() const {
    return this->measureUnit;
}

string Ingredient::toString(){
    stringstream amountStr;
    amountStr << fixed << setprecision(2) << this->getAmount();
    return "\t" + this->getName() + " " + amountStr.str() + " " + this->getUnit();
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

istream& operator >> (istream&, Ingredient&)
{
    
}

ostream& operator << (ostream& os, const Ingredient& i){
    os << i.name << '*';
    os << i.amount << '*';
    os << i.measureUnit;

    return os;
}