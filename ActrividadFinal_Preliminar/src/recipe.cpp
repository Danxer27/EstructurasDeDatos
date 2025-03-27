//Archivo de Implementacion de la Receta
#include "recipe.hpp"
using namespace std;

Recipe::Recipe() : process("") {}

Recipe::Recipe(const Recipe&){}

void Recipe::setRecipeName(const string& s){
    this->recipeName = s;
}

void Recipe::setIngredients(const List<Ingredient>& e){
    this->ingredients = e;
}

void Recipe::setPrepTime(const int& h, const int& m, const int& s){
    this->prepTime.setHours(h);
    this->prepTime.setMinutes(m);
    this->prepTime.setSeconds(s);
}

void Recipe::setProcess(const string& text){
    this->process = text;
}

void Recipe::setAuthor(const Name& a){
    this->author = a;
}

void Recipe::addIngredient(const Ingredient& e){
    this->ingredients.insertData(ingredients.getLastPos()+1, e);
}

void Recipe::addProcessStep(const string& text){
    this->process += text;
}

string Recipe::getRecipeName() const{
    return this->recipeName;
}

List<Ingredient> Recipe::getIngredients(){
   return this->ingredients; 
}

Ingredient Recipe::getIngredient(const int& pos){
   return this->ingredients.retrieve(pos);
}

string Recipe::getPrepTime(){
    return this->prepTime.toString();
}
//
string Recipe::getProcess() const {
    return this->process;
}

Name Recipe::getAuthor() const{
    return this->author;
}

string Recipe::toString() const {
    stringstream ss;
    ss << left << setw(25) << this->getRecipeName() 
    << left << setw(20) << this->ingredients.toString()
    << left << setw(10) << this->prepTime.toString() 
    << left << setw(30) << this->process
    << left << setw(20) << this->author.toString();
    return ss.str();
}

bool Recipe::operator==(const Recipe& r){
    return (this->recipeName == r.recipeName) && (this->ingredients.toString() == r.ingredients.toString()) && (this->prepTime == r.prepTime);
}

bool Recipe::operator!=(const Recipe& r){
    return !(*this == r);
}

bool Recipe::operator>(const Recipe& r){
    return (this->ingredients.getLastPos() > r.ingredients.getLastPos()) || (this->prepTime > r.prepTime);
}

bool Recipe::operator>=(const Recipe& r){
    return (*this == r) || (*this > r);
}

bool Recipe::operator<(const Recipe& r){
    return !(*this >= r);
}

bool Recipe::operator<=(const Recipe& r){
    return !(*this > r);
}

int Recipe::comapreTo(const Recipe& r){
    return this->ingredients.toString().compare(r.ingredients.toString());
}

int Recipe::compare(const Recipe& a, const Recipe& b){
    return a.ingredients.toString().compare(b.ingredients.toString());
}

int Recipe::compareByRecipeName(const Recipe& a, const Recipe& b){
    return a.recipeName.compare(b.recipeName);
}

int Recipe::compareByIngredients(const Recipe& a, const Recipe& b){
    return a.ingredients.toString().compare(b.ingredients.toString());
}

int Recipe::compareByPrepTime(const Recipe& a, const Recipe& b){
    return a.prepTime - b.prepTime;
}

int Recipe::compareByAuthor(const Recipe& a, const Recipe& b){
    return a.author.toString().compare(b.author.toString());
}

istream& operator >> (istream&, Recipe&)
{
    
}

ostream& operator << (ostream& os, const Recipe& r){
    os << r.recipeName << '*';

    int i(0);
    while(i <= r.ingredients.getLastPos()){
        os << r.ingredients.retrieve(i) << '$';

        i++;
    }
    os << '*';
    os << r.prepTime << '*';
    os << r.process << '*';
    os << r.author;

    return os;
}
