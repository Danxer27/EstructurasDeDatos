// Archivo de Definicion e Implementacion de la lista
#ifndef __LIST_HPP__
#define __LIST_HPP__
#include <exception>
#include <iostream>
#include <string>

using namespace std;
template <class T>
class List {
  class Node;

 public:
  typedef Node* Position;

 private:
  class Node {
   private:
    T data;
    Position prev = nullptr;
    Position next = nullptr;

   public:
    Node();
    Node(const T&);

    void setData(const T&);
    void setNext(const Position&);
    void setPrev(const Position&);
    
    T& getData();
    Position getNext() const;
    Position getPrev() const;

  };

  bool isValid(const Position&) const;
  void addData(const List<T>&);

 public:
  Position anchor = nullptr;

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
  ~List();

  bool isEmpty() const;
  bool isFull() const;

  void insertData(const Position&, const T&);
  void deleteData(const Position&);

  Position getFirstPos() const;
  Position getLastPos() const;

  Position getPreviousPos(const Position&) const;
  Position getNextPos(const Position&) const;

  Position findData(const T&);

  T& retrieve(const Position&);

  std::string toString() const;

  void deleteAll();

  List<T> operator=(const List<T>&);
};



// Implementacion de los Nodos:

template <class T>
List<T>::Node::Node() {}

template <class T>
List<T>::Node::Node(const T& value) : data(value) {}

template <class T>
void List<T>::Node::setData(const T& e) {
  this->data = e;
}

template <class T>
void List<T>::Node::setNext(const Position& p) {
  this->next = p;
}

template<class T>
void List<T>::Node::setPrev(const Position& p) {
  this->prev = p;
}

template <class T>
T& List<T>::Node::getData() {
  return this->data;
}

template <class T>
typename List<T>::Position List<T>::Node::getNext() const {
  return this->next;
}

template <class T>
typename List<T>::Position List<T>::Node::getPrev() const {
  return this->prev;
}

// Implementacion de la lista:

template <class T>
List<T>::List() : anchor(nullptr) {}

template <class T>
List<T>::List(const List& l) {
  this->addData(l);
}

template <class T>
List<T>::~List() {
  this->deleteAll();
}

template <class T>
bool List<T>::isEmpty() const {
  return this->anchor == nullptr;
}

template <class T>
void List<T>::insertData(const Position& p, const T& e) {
  if (p != nullptr && !this->isValid(p)) {
    throw Exception("Posicion Invalida. List<T>::insertData()");
  }

  Position newNode(new Node(e));

  if(newNode == nullptr){
    throw Exception("Memoria no disponible. List<T>::insertData.");
  }

  if (p == nullptr) { 
    newNode->setNext(this->anchor);
    this->anchor = newNode;
    
  } else {
    newNode->setNext(p->getNext());
    p->setNext(newNode);
  }
}

template <class T>
void List<T>::deleteData(const Position& p) {
  if (!this->isValid(p)) {
    throw Exception("Posicion Invalida. List::deleteData()");
  }

  if (p == this->anchor) {
    this->anchor = p->getNext();
  } else {
    this->getPreviousPos(p)->setNext(p->getNext());
  }

  delete p;
}

template <class T>
typename List<T>::Position List<T>::getFirstPos() const {
  return this->anchor;
}

template <class T>
typename List<T>::Position List<T>::getLastPos() const {
  if (this->isEmpty()) {
    return nullptr;
  }

  Position aux(this->anchor);

  while (aux->getNext() != nullptr) {
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
typename List<T>::Position List<T>::getPreviousPos(const Position& p) const {
  Position aux(this->anchor);

  while (aux != nullptr && aux->getNext() != p) {
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
typename List<T>::Position List<T>::getNextPos(const Position& p) const {
  if (!this->isValid(p)) {
    return nullptr;
  }

  return p->getNext();
}

template <class T>
typename List<T>::Position List<T>::findData(const T& e) {
  Position aux(this->anchor);

  while (aux != nullptr && aux->getData() != e) {
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
T& List<T>::retrieve(const Position& p) {
  if (!this->isValid(p)) {
    throw Exception("Position invalida. List::retrieve()");
  }

  return p->getData();
}

template <class T>
string List<T>::toString() const {
  string result;

  Position aux(this->anchor);

  while (aux != nullptr) {
    result += aux->getData().toString() + "\n";
    aux = aux->getNext();
  }
  return result;
}

template <class T>
bool List<T>::isValid(const Position& p) const {
  Position aux(this->anchor);

  while (aux != nullptr) {
    if (aux == p) {
      return true;
    }
    aux = aux->getNext();
  }

  return false;
}

//Pendiente ###########
template <class T>
void List<T>::addData(const List<T>& l) {
  Position aux(l->anchor), newNode, lastInserted(this->getLastPost());

  while (aux != nullptr) {
    if (newNode = new Node(aux->getData()) == nullptr) {
      throw Exception(
          "No memory Available. Unable to add more data -> List::copyAll()");
    }
    if (lastInserted == nullptr) {
      this->anchor = newNode;
    } else {
      lastInserted->setNext(newNode);
    }

    lastInserted = newNode;

    aux = aux->getNext();
  }
}

template <class T>
List<T> List<T>::operator=(const List<T>& l) {
  this->deleteAll();
  this->addData(l);
  return *this;
}

template <class T>
void List<T>::deleteAll() {
  Position aux;
  while (this->anchor != nullptr) {
    aux = this->anchor;
    this->anchor = aux->getNext();
    delete aux;
  }
}

#endif  // __LIST_HPP__