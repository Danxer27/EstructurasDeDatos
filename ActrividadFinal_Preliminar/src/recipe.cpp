#include "recipe.hpp"
using namespace std;

Recipe::Recipe() : process("") {}

Recipe::Recipe(const Recipe&){}

void Recipe::setIngredients(const Ingredient& e){
    this->ingredients.insertData(ingredients.getLastPos()+1, e);
}

void Recipe::setPrepTime(const int& h, const int& m, const int& s){
    this->prepTime.setHours(h);
    this->prepTime.setMinutes(m);
    this->prepTime.setSeconds(s);
}

void Recipe::setProcess(const string& text){
    this->process = text;
}

void Recipe::setAuthor(const string& a){
    this->author = a;
}

void Recipe::addProcessStep(const string& text){
    this->process += text;
}

string Recipe::getIngredients(){
   return this->ingredients.toString(); 
}

Ingredient Recipe::getIngredient(const int& pos){
   return this->ingredients.retrieve(pos);
}

string Recipe::getPrepTime(){
    return this->prepTime.toString();
}
//
string Recipe::getProcess(){
    return this->process;
}

string Recipe::getAuthor(){
    return this->author;
}

string Recipe::toString(){
    //
}

bool Recipe::operator==(const Recipe& r){
    
}

bool Recipe::operator!=(const Recipe&)
{
    
}

bool Recipe::operator<(const Recipe&)
{
    
}

bool Recipe::operator<=(const Recipe&)
{
    
}

bool Recipe::operator>(const Recipe&)
{
    
}

bool Recipe::operator>=(const Recipe&)
{
    
}

int Recipe::comapreTo(const Recipe&)
{
    
}

int Recipe::compare(const Recipe&, const Recipe&)
{
    
}

int Recipe::compareByIngredients(/*PENDING TO ADD*/)
{
    
}

int Recipe::comapreByPrepTime(/*PENDING TO DECIDE*/)
{
    
}

int Recipe::compareByAuthor(const string&, const string())
{
    
}
