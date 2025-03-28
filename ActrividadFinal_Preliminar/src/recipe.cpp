//Archivo de Implementacion de la Receta
#include "recipe.hpp"
using namespace std;

Recipe::Recipe() : process("") {}

Recipe::Recipe(const Recipe& r) : recipeName(r.recipeName), ingredients(r.ingredients), prepTime(r.prepTime), process(r.process), author(r.author) {}

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

void Recipe::setCathegory(const std::string& c){
    this->cathegory = c;
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

std::string Recipe::getCathegory() const {
    return this->cathegory;
}

string Recipe::toString() const {
    string result("\nReceta:");

    result += this->recipeName + 
    "\nTiempo de Preparacion: " + this->prepTime.toString() +
    "\nCategoria: " + this->cathegory +
    "\nAutor: " + this->author.toString() + 
    "\nProceso: " + this->process +
    "\nIngredientes:" + this->ingredients.toString();

    return result;
}

bool Recipe::operator==(const Recipe& r){
    return (this->recipeName == r.recipeName);
}

bool Recipe::operator!=(const Recipe& r){
    return !(*this == r);
}

bool Recipe::operator>(const Recipe& r){
    return (this->recipeName == r.recipeName);
    // return (this->ingredients.getLastPos() > r.ingredients.getLastPos()) || (this->prepTime > r.prepTime);
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

int Recipe::compareByCathergory(const Recipe& a, const Recipe& b){
    return a.cathegory.compare(b.cathegory);
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
    os << r.author << '*';
    os << r.cathegory;

    return os;
}
