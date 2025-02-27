#include "name.hpp"

using namespace std;

Name::Name(){};
Name::Name(const Name& n) : first(n.first), last(n.last) {}

void Name::setFirst(const string& f){
    this->first = f;
}

void Name::setLast(const string& l){
    this->last = l;
}

string Name::toString(){
    return this->first + " " + this->last;
}

string  Name::getFirst() const{
    return this->first;
}

string Name::getLast() const{
    return this->last;
}