// Archivo de Definicion e Implementacion de la lista
#ifndef __LIST_HPP__
#define __LIST_HPP__
#include <exception>
#include <iostream>
#include <string>

template <class T, int ARRAYSIZE = 2048>
class List {
 private:
  T* data[ARRAYSIZE];
  int last;

  bool isValid(const int&) const;
  void copyAll(const List<T,ARRAYSIZE>&);
  void swapData(T&, T&);
  void swapDataPointers(T*&, T*&);

  void sortDataQuick(const int&, const int&);
  void sortDataQuick(const int&, const int&, int(const T&, const T&));

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
  List(const List<T,ARRAYSIZE>&);
  ~List();

  bool isEmpty() const;
  bool isFull() const;

  void insertData(const int&, const T&);
  void deleteData(const int&);

  int getFirstPos() const;
  int getLastPos() const;

  int getPreviousPos(const int&) const;
  int getNextPos(const int&) const;

  int findDataLin(const T&) const;
  int findDataLin(const T&, int(const T&, const T&)) const;
  int findDataBin(const T&) const;
  int findDataBin(const T&, int(const T&, const T&)) const;

  T& retrieve(const int&) const;

  std::string toString() const;

  void deleteAll();

  //Sort Methods
  void sortDataBubble();
  void sortDataBubble(int(const T&, const T&));
  void sortDataInsert();
  void sortDataInsert(int(const T&, const T&));
  void sortDataSelect();
  void sortDataSelect(int(const T&, const T&));
  void sortDataShellCiura();
  void sortDataShellCiura(int(const T&, const T&));
  void sortDataShellFactor();
  void sortDataShellFactor(int(const T&, const T&));

  void sortDataQuick();
  void sortDataQuick(int(const T&, const T&));

  bool isSorted();

  List<T,ARRAYSIZE> operator=(const List<T,ARRAYSIZE>&);
 
};



// Implementacion de clase:

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List() : last(-1) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        this->data[i] = nullptr; 
    }
}

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List(const List<T,ARRAYSIZE>& l) {
  this->copyAll(l);
}

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::~List() {
  this->deleteAll();
}

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isValid(const int& p) const {
  return (p >= 0) && (p <= this->last);
}

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isEmpty() const {
  return this->last == -1;
}

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isFull() const {
  return this->last == ARRAYSIZE-1;
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::insertData(const int& p, const T& e) {
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

  data[p + 1] = new T(e);
  this->last++;
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::deleteData(const int& p) {
  if (this->isEmpty()) {
    throw Exception("Lista vacia: deleteData()");
  }

  if (p != -1 && !this->isValid(p)) {
    throw Exception("Posicion invalida: deleteData()");
  }
  int i(p);
  delete data[p];
  data[p] = nullptr;
  while (i < this->last) {
    this->data[i] = this->data[i + 1];
    i++;
  }
  this->data[this->last] = nullptr;
  this->last--;
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::deleteAll() {
  int i(0);
  while(i< this->last){
    delete data[i];
    //data[i] = nullptr;
    i++;
  }
  this->last = -1;
}


//check if you can retrieve a pointer
template <class T, int ARRAYSIZE>
T& List<T,ARRAYSIZE>::retrieve(const int& p) const {
  if (!this->isValid(p) || data[p] == nullptr) {
    throw Exception("Posicion invalida: retrieve()");
  }
  return *(this->data[p]);
}
//convert
template <class T, int ARRAYSIZE>
std::string List<T,ARRAYSIZE>::toString() const {
  std::string result = "";
  int i(0);

  while (i <= this->last) {
    result += this->data[i]->toString() + "\n";
    i++;
  }
  return result;
}



template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::copyAll(const List<T,ARRAYSIZE>& l) {
  this->last = l.last;
  int i(0);
  while (i <= this->last) {
    this->data[i] = new T(*(l.data[i]));
    i++;
  }
}

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE> List<T,ARRAYSIZE>::operator=(const List<T,ARRAYSIZE>& l) {
  this->copyAll(l);
  return *this;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getFirstPos() const {
  return this->isEmpty() ? -1 : 0;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getLastPos() const {
  return this->last;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getPreviousPos(const int& p) const {
  return this->isEmpty() ? -1 : p - 1;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getNextPos(const int& p) const {
  return this->isEmpty() ? -1 : p - 1;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataLin(const T& e) const {
  int i(0);
  while (i <= this->last) {
    if (e == *data[i]) {
      return i;
    }
    i++;
  }
  return -1;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataBin(const T& e) const {
  int i(0), d(this->last);
  int m;

  while (i <= d) {
    m = (i + d) / 2;

    if (*(this->data[m]) == e) {
      return m;
    } else if (*this->data[m] > e) {
      d = m - 1;
    } else if (*this->data[m] < e) {
      i = m + 1;
    }
  }

  return -1;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataBin(const T& e, int cmp(const T&, const T&)) const {
  int i(0), d(this->last);
  int m;

  while (i <= d) {
    m = (i + d) / 2;

    if (cmp(*this->data[m], e) == 0) {
      return m;
    } else if (cmp(*this->data[m], e) > 0) {
      d = m - 1;
    } else if (cmp(*this->data[m], e) < 0) {
      i = m + 1;
    }
  }

  return -1;
}

//////////////////////////////////////////////////////////////////
//#####METODOS DE SORTING ###### 
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::swapDataPointers(T*& a, T*& b) {
  T* aux(b);
  b = a;
  a = aux;
}


template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataQuick() {
  this->sortDataQuick(0, this->last);
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataQuick(const int& leftEdge,
                                       const int& rightEdge) {
  if (leftEdge >= rightEdge) {
    return;
  }

  int i(leftEdge), j(rightEdge);

  while (i < j) {
    while (i < j && *this->data[i] <= *this->data[rightEdge]) {
      i++;
    }

    while (i < j && *this->data[j] >= *this->data[rightEdge]) {
      j--;
    }

    if (i != j) {
      swapDataPointers(this->data[i], this->data[j]);
    }
  }

  if (i != rightEdge) {
    this->swapDataPointers(this->data[i], this->data[rightEdge]);
  }

  // Divide and conquer;

  this->sortDataQuick(leftEdge, i - 1);
  this->sortDataQuick(i + 1, rightEdge);
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataQuick(int cmp(const T&, const T&)) {
  this->sortDataQuick(0, this->last, cmp);
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataQuick(const int& leftEdge,
                                       const int& rightEdge,
                                       int cmp(const T&, const T&)) {
  if (leftEdge >= rightEdge) {
    return;
  }

  int i(leftEdge), j(rightEdge);

  while (i < j) {
    while (i < j && cmp(*this->data[i], *this->data[rightEdge]) > 0) {
      i++;
    }

    while (i < j && cmp(*this->data[j], *this->data[rightEdge]) > 0) {
      j--;
    }

    if (i != j) {
      swapDataPointers(this->data[i], this->data[j]);
    }
  }

  if (i != rightEdge) {
    this->swapDataPointers(this->data[i], this->data[rightEdge]);
  }

  // Divide and conquer;

  this->sortDataQuick(leftEdge, i - 1);
  this->sortDataQuick(i + 1, rightEdge);
}

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isSorted() {
  int i(0);

  while (i < this->last) {
    if (*this->data[i] > *this->data[i + 1]) {
      return false;
    }
    i++;
  }
  return true;
}


#endif  // __LIST_HPP__