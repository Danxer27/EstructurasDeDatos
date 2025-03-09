// Archivo de Definicion e Implementacion de la lista
#ifndef __LIST_HPP__
#define __LIST_HPP__
#include <exception>
#include <iostream>
#include <string>

template <class T, int ARRAYSIZE>
class List {
 private:
  T data[ARRAYSIZE];
  int last;

  bool isValid(const int&) const;
  void copyAll(const List<T,ARRAYSIZE>&);

  void swapData(T&, T&);

  void sortDataMerge(const int&, const int&);
  void sortDataMerge(const int&, const int&, int(const T&, const T&));
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
  void sortDataMerge();
  void sortDataMerge(int(const T&, const T&));
  void sortDataQuick();
  void sortDataQuick(int(const T&, const T&));


  List<T,ARRAYSIZE> operator=(const List<T,ARRAYSIZE>&);
 
};

#endif  // __LIST_HPP__

// Implementacion de clase:

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List() : last(-1) {}

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List(const List<T,ARRAYSIZE>& l) {
  this->copyAll(l);
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
  return this->last == ARRAYSIZE;
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

  data[p + 1] = e;
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

  while (i < this->last) {
    this->data[i] = this->data[i + 1];
    i++;
  }
  this->last--;
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
    if (e == data[i]) {
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

template <class T, int ARRAYSIZE>
T& List<T,ARRAYSIZE>::retrieve(const int& p) {
  if (!this->isValid(p)) {
    throw Exception("Posicion invalida: retrieve()");
  }
  return this->data[p];
}

template <class T, int ARRAYSIZE>
std::string List<T,ARRAYSIZE>::toString() const {
  std::string result = "";
  int i(0);

  while (i <= this->last) {
    result += this->data[i].toString() + "\n";
    i++;
  }
  return result;
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::deleteAll() {
  this->last = -1;
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::copyAll(const List<T,ARRAYSIZE>& l) {
  this->last = l.last;
  int i(0);
  while (i <= this->last) {
    this->data[i] = l.data[i];
    i++;
  }
}

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE> List<T,ARRAYSIZE>::operator=(const List<T,ARRAYSIZE>& l) {
  this->copyAll(l);
  return *this;
}






//////////////////////////////////////////////////////////////////
//#####METODOS DE SORTING ###### 
template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::swapData(T& a, T& b){
    T aux(b);
    b = a;
    a = aux;
} 

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataBubble(){
    int i(this->last), j;
    bool flag;

    do{
        j = 0;
        flag = false;
        while(j < i){
            if(this->data[j] > this->data[j + 1]){
                this->swapData(data[j], data[j+1]);
                flag = true;
            }
            j++;
        }
        i--;

    } while(flag);
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataBubble(int cmp(const T&, const T&)){
    int i(this->last), j;
    bool flag;

    do{
        j = 0;
        flag = false;
        while(j < i){
            if(cmp(this->data[j], this->data[j + 1]) > 0){
                this->swapData(data[j], data[j+1]);
                flag = true;
            }
            j++;
        }
        i--;

    } while(flag);
}




template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataInsert(){
  int i(1), j;
  T aux;
  
  while(i <= this->last){
    aux = this->data[i];
    
    j = i;
    
    while(j > 0 && aux > this->data[j - 1]){
      this->data[j] = this->data[j - 1];
      
      j--;
    }
    
    if(i != j){
      this->data[j] = aux;
    }
  }
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataInsert(int cmp(const T&, const T&)){
    int i(1), j;
    T aux;

    while(i <= this->last){
        aux = this->data[i];

        j = i;

        while(j > 0 && cmp(aux, this->data[j - 1]) < 0){
            this->data[j] = this->data[j - 1];
            j--;
        }

        if(i != j){
            this->data[j] = aux;
        }
        i++;
    }
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataSelect(){
  int i(0), j, m;

  while(i < this->last){
    m = i;
    j = i + 1;

    while(j <= this->last){
      if(this->data[j] < this->data[m]){
        m = j;
      }
      j++;
    }
    if(m != i){
      this->swapData(this->data[i], this->data[m]);
    }
    i++;
  }
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataSelect(int cmp(const T&, const T&)){
  int i(0), j, m;

  while(i < this->last){
    m = i;
    j = i + 1;

    while(j <= this->last){
      if(cmp(this->data[j], this->data[m]) < 0){
        m = j;
      }
      j++;
    }
    if(m != 1){
      this->swapData(this->data[i], this->data[m]);
    }
    i++;
  }
}


template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataShellFactor(){
  float fact(1.0/2.0);
  int dif((this->last + 1) * fact), i, j;

  while(dif > 0){
    i = dif;
    while(i <= this->last){
      j = i;

      while(j >= dif && this->data[j - dif] > this->data[j]){
        this->swapData(this->data[j-dif], this->data[j]);

        j-= dif;
      }
      i++;
    }
    dif *= fact;
  }
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataShellFactor(int cmp(const T&, const T&)){
  float fact(1.0/2.0);
  int dif((this->last + 1) * fact), i, j;

  while(dif > 0){
    i = dif;
    while(i <= this->last){
      j = i; 

      while(j >= dif && cmp(this->data[j], this->data[j - dif]) < 0){
        this->swapData(this->data[j], this->data[j - dif]);

        j -= dif;
      }

      i++;
    }
    dif *= fact;
  }
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataShellCiura(int cmp(const T&, const T&)){
  int series[] = {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57,23, 10, 4, 1};
  int seq(0), dif(series[seq]), i, j;

  while(dif > 0){
      i = dif;
      while(i <= this->last){
          j = i;
          while(j >= dif && cmp(this->data[j - dif], this->data[j]) > 0){
              this->swapData(this->data[j - dif], this->data[j]);
              j -= dif;
          }
          i++;
      }
      dif = series[++seq];
  }
}

//Metodos de Ordenamiento Recursivos

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataMerge(){
    this->sortDatamMerge(0, this-last);
}


//privado
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataMerge(const int& leftEdge, const int& rightEdge){
  if(leftEdge >= rightEdge){
    return;
  }

  //Divide and conquer
  int m((leftEdge + rightEdge) / 2);
  this->sortDataMerge(leftEdge, m);
  this->sortDataMerge(m+1, rightEdge);
  
  //Intercalacion

  T temp[ARRAYSIZE];

  for(int i(leftEdge); i <= rightEdge; i++){
    temp[i] = this->data[i];
  }

  int i(leftEdge), j(m + 1), x(leftEdge);

  while(i <= m && j <= rightEdge){
    while(i <= m && j <= rightEdge){
      this->data[x++] = temp[i++];
    }
    if(i <= m){
      while(j <= rightEdge && temp[j] <= temp[i]){
        this->data[x++] + temp[j++];
      }
    }
  }
  while(i <= m && temp[i] <= temp[j]){
    this->data[x++] = temp[i++];
  }
  while(i <= m && temp[i] <= temp[j]){
    this->data[x++] = temp[j++];
  }
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataMerge(int cmp(const T&, const T&)){
    this->sortDatamMerge(0, this-last, cmp);
}



template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataMerge(const int& leftEdge, const int& rightEdge, int cmp(const T&, const T&)){
  if(leftEdge >= rightEdge){
    return;
  }

  //Divide and conquer
  int m((leftEdge + rightEdge) / 2);
  this->sortDataMerge(leftEdge, m);
  this->sortDataMerge(m+1, rightEdge);
  
  //Intercalacion

  T temp[ARRAYSIZE];

  for(int i(leftEdge); i <= rightEdge; i++){
    temp[i] = this->data[i];
  }

  int i(leftEdge), j(m + 1), x(leftEdge);

  while(i <= m && j <= rightEdge){
    while(i <= m && j <= rightEdge){
      this->data[x++] = temp[i++];
    }
    if(i <= m){
      while(j <= rightEdge && cmp(temp[j], temp[i]) > 0){
        this->data[x++] + temp[j++];
      }
    }
  }
  while(i <= m && cmp(temp[j], temp[i]) > 0){
    this->data[x++] = temp[i++];
  }
  while(i <= m && cmp(temp[j], temp[i]) > 0){
    this->data[x++] = temp[j++];
  }
}


template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataQuick(){
  this->sortDataQuick(0, this->last);
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataQuick(const int& leftEdge, const int& rightEdge){
  if(leftEdge >= rightEdge){
    return;
  }

  int i(leftEdge), j(rightEdge);

  while(i<j){

    while(i<j && this->data[i] <= this->data[rightEdge]){
      i++;
    }

    while(i <  j && this->data[j] >= this->data[rightEdge]){
      j--;
    }

    if(i != j){
      swapData(this->data[j], this->data[j]);
    }
  }

  if(i != rightEdge){
    this->swapData(this->data[i], this->data[rightEdge]);
  }

  //Divide and conquer;

  this->sortDataQuick(leftEdge, i-1);
  this->sortDataQuick(i+1, rightEdge);

}
