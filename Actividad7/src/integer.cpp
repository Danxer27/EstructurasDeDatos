// Archivo de implementacion de la clase Integer
#include "integer.hpp"

using namespace std;

Integer::Integer() : intdata(0) {}

Integer::Integer(const Integer& e) : intdata(e.intdata) {}

Integer::Integer(const int64_t& e) : intdata(e) {}

__int64 Integer::getValue() const {
  return intdata;
}

void Integer::setValue(const __int64& i) {
  this->intdata = i;
}

std::string Integer::toString() const {
  return std::to_string(intdata);
}

Integer& Integer::operator=(const Integer& e) {
  this->intdata = e.intdata;

  return *this;
}

bool Integer::operator==(const Integer& e) const {
  return this->intdata == e.intdata;
}

bool Integer::operator!=(const Integer& e) const {
  return !(*this == e);
}

bool Integer::operator>(const Integer& e) const {
  return this->intdata > e.intdata;
}

bool Integer::operator>=(const Integer& e) const {
  return *this > e || *this == e;
}

bool Integer::operator<(const Integer& e) const {
  return !(*this >= e);
}

bool Integer::operator<=(const Integer& e) const {
  return !(*this > e);
}

Integer Integer::operator++(int) {
  return this->intdata++;
}

Integer& Integer::operator++() {
  ++intdata;

  return *this;
}

Integer& Integer::operator--() {
  --this->intdata;

  return *this;
}

Integer Integer::operator--(int) {
  return this->intdata--;
}

Integer Integer::operator+(const Integer& e) {
  return this->intdata + e.intdata;
}

Integer Integer::operator-(const Integer& e) {
  return this->intdata - e.intdata;
}

Integer Integer::operator*(const Integer& e) {
  return this->intdata * e.intdata;
}

Integer Integer::operator/(const Integer& e) {
  return this->intdata / e.intdata;
}

Integer Integer::operator%(const Integer& e) {
  return this->intdata % e.intdata;
}

Integer& Integer::operator+=(const Integer& e) {
  this->intdata += e.intdata;
  return *this;
}

Integer& Integer::operator-=(const Integer& e) {
  this->intdata -= e.intdata;
  return *this;
}

Integer& Integer::operator/=(const Integer& e) {
  this->intdata /= e.intdata;
  return *this;
}

Integer& Integer::operator*=(const Integer& e) {
  this->intdata *= e.intdata;
  return *this;
}

int Integer::compareTo(const Integer& e) {
  return this->intdata - e.intdata;
}

int Integer::compareValue(const Integer& a, const Integer& b) {
  return a.getValue() - b.getValue();
}
