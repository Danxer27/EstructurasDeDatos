// Archivo de Definicion e Implementacion de la lista
#ifndef __LIST_HPP__
#define __LIST_HPP__
#include <exception>
#include <iostream>
#include <string>

template <class T>
class List {
 private:
  T data[500];
  int last;

  bool isValid(const int&) const;
  void copyAll(const List<T>&);

 public:
  class Exception : public std::exception {
   private:
    std::string msg;

   public:
    Exception() noexcept : msg("Error indefinido") {}
    Exception(const Exception& ex) noexcept : msg(ex.msg) {}
    Exception(const std::string& m) : msg(m) {}
    Exception& operator=(const Exception& ex) noexcept {
      this->msg = ex.msg;
      return *this;
    }
    virtual ~Exception() {}
    virtual const char* what() const noexcept { return this->msg.c_str(); }
  };
  List();
  List(const List<T>&);

  bool isEmpty() const;
  bool isFull() const;

  void insertData(const int&, const T&);
  void deleteData(const int&);

  int getFirstPos() const;
  int getLastPos() const;

  int getPreviousPos(const int&) const;
  int getNextPos(const int&) const;

  int findDataLin(const T&) const;
  int findDataBin(const T&) const;

  T& retrieve(const int&);

  std::string toString() const;

  void sortData();

  void deleteAll();

  List<T> operator=(const List<T>&);
  List<T> operator+(const T&);  // Testeo: remover despues xdxdxd
};

#endif  // __LIST_HPP__

// Implementacion de clase:

template <class T>
List<T>::List() : last(-1) {}

template <class T>
List<T>::List(const List<T>& l) {
  this->copyAll(l);
}

template <class T>
bool List<T>::isValid(const int& p) const {
  return (p >= 0) && (p <= this->last);
}

template <class T>
bool List<T>::isEmpty() const {
  return this->last == -1;
}

template <class T>
bool List<T>::isFull() const {
  return this->last == 499;
}

template <class T>
void List<T>::insertData(const int& p, const T& e) {
  if (this->isFull()) {
    throw Exception("Lista llena: insertData()");
  }

  if (p != -1 && !this->isValid(p)) {
    throw Exception("Posicion invalida: insertData()");
  }
  int i(this->last);

  while (i > p) {
    this->data[i + 1] = this->data[i];
    i--;
  }

  data[p + 1] = e;
  this->last++;
}

template <class T>
void List<T>::deleteData(const int& p) {
  if (this->isEmpty()) {
    throw Exception("Lista vacia: deleteData()");
  }

  if (p != -1 && !this->isValid(p)) {
    throw Exception("Posicion invalida: deleteData()");
  }
  int i(p);

  while (i < this->last) {
    this->data[i] = this->data[i + 1];
    i++;
  }
  this->last--;
}

template <class T>
int List<T>::getFirstPos() const {
  return this->isEmpty() ? -1 : 0;
}

template <class T>
int List<T>::getLastPos() const {
  return this->last;
}

template <class T>
int List<T>::getPreviousPos(const int& p) const {
  return this->isEmpty() ? -1 : p - 1;
}

template <class T>
int List<T>::getNextPos(const int& p) const {
  return this->isEmpty() ? -1 : p - 1;
}

template <class T>
int List<T>::findDataLin(const T& e) const {
  int i(0);
  while (i <= this->last) {
    if (e == data[i]) {
      return i;
    }
    i++;
  }
  return -1;
}

template <class T>
int List<T>::findDataBin(const T& e) const {
  int i(0), d(this->last);
  int m;

  while (i <= d) {
    m = (i + d) / 2;

    if (this->data[m] == e) {
      return m;
    } else if (this->data[m] > e) {
      d = m - 1;
    } else if (this->data[m] < e) {
      i = m + 1;
    }
  }

  return -1;
}

template <class T>
T& List<T>::retrieve(const int& p) {
  if (!this->isValid(p)) {
    throw Exception("Posicion invalida: retrieve()");
  }
  return this->data[p];
}

template <class T>
std::string List<T>::toString() const {
  std::string result = "";
  int i(0);

  while (i <= this->last) {
    result += this->data[i].toString() + "\n";
    i++;
  }
  return result;
}

template <class T>
void List<T>::sortData() {
  return;
}

template <class T>
void List<T>::deleteAll() {
  this->last = -1;
}

template <class T>
void List<T>::copyAll(const List<T>& l) {
  this->last = l.last;
  int i(0);
  while (i <= this->last) {
    this->data[i] = l.data[i];
    i++;
  }
}

template <class T>
List<T> List<T>::operator=(const List<T>& l) {
  this->copyAll(l);
  return *this;
}
