// Archivo de Definicion de la clase de wrapping Integer
#ifndef __INTEGER_HPP__
#define __INTEGER_HPP__

#include <string>

class Integer {
 private:
  __int64 intdata;

 public:
  Integer();
  Integer(const Integer&);
  Integer(const int64_t&);

  __int64 getValue() const;
  void setValue(const __int64&);

  Integer& operator=(const Integer&);

  bool operator==(const Integer&) const;
  bool operator!=(const Integer&) const;
  bool operator>(const Integer&) const;
  bool operator>=(const Integer&) const;
  bool operator<(const Integer&) const;
  bool operator<=(const Integer&) const;

  std::string toString() const;

  Integer& operator++();
  Integer operator++(int);
  Integer& operator--();
  Integer operator--(int);
  Integer operator+(const Integer&);
  Integer operator-(const Integer&);
  Integer operator*(const Integer&);
  Integer operator/(const Integer&);
  Integer operator%(const Integer&);
  Integer& operator+=(const Integer&);
  Integer& operator-=(const Integer&);
  Integer& operator*=(const Integer&);
  Integer& operator/=(const Integer&);

  int compareTo(const Integer&);
  static int compareValue(const Integer&, const Integer&);
};

#endif  //__INTEGER_HPP__