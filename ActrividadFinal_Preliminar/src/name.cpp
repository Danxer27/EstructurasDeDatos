#include "name.hpp"
using namespace std;

Name::Name() {}

Name::Name(const Name& n) : first(n.first), last(n.last) {}

void Name::setFirst(const string& s){
    this->first = s;
}

void Name::setLast(const string& s){
    this->last = s;
}

string Name::getFirst() const{
    return this->first;
}

string Name::getLast() const {
    return this->last;
}

string Name::getFullName() const {
    return this->toString();
}

string Name::toString() const {
    return this->first + " " + this->last;
}

Name& Name::operator=(const Name& n){
    this->last=n.last;
    this->first=n.first;
}

bool Name::operator==(const Name& e) const{
    return this->toString()==e.toString();
}

bool Name::operator!=(const Name& e) const{
    return !(*this==e);
}

bool Name::operator<=(const Name&e) const{
  return *this<e || *this==e;
}

bool Name::operator>=(const Name&e) const{
    return !(*this<e);
}

bool Name::operator<(const Name&e) const{
  return this->toString()<e.toString();
}

bool Name::operator>(const Name&e) const{
  return !(*this<=e);
}

int Name::compareTo(const Name& e){
    return this->toString()==e.toString();
}

int Name::compare(const Name& a, const Name& b){
    return a.toString().compare(b.toString());
}

int Name::comapreByFirst(const Name& a, const Name& b){
    return a.getFirst().compare(b.getFirst());
}

int Name::compareByLast(const Name& a, const Name& b){
    return a.getLast().compare(b.getLast());
}



