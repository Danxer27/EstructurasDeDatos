// Archivo de Definicion e Implementacion de la lista
#ifndef __LIST_HPP__
#define __LIST_HPP__
#include <exception>
#include <iostream>
#include <string>

using namespace std;
template <class T>
class Queue {
  class Node;

 private:
 typedef Node* Position;

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

//   bool isValid(const Position&) const;
  void addData(const Queue<T>&);

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
  Queue();
  Queue(const Queue<T>&);
  ~Queue();

  Queue<T>& operator =(const Queue<T>&);

  bool isEmpty() const;

  void enqueue(const T&);

  T dequeue();

  T& getFront();

  void addData(const Queue<T>&);

};



// Implementacion de los Nodos:

template <class T>
 Queue<T>::Node::Node() {}

template <class T>
Queue<T>::Node::Node(const T& value) : data(value) {}

template <class T>
void Queue<T>::Node::setData(const T& e) {
  this->data = e;
}

template <class T>
void Queue<T>::Node::setNext(const Position& p) {
  this->next = p;
}

template<class T>
void Queue<T>::Node::setPrev(const Position& p) {
  this->prev = p;
}

template <class T>
T& Queue<T>::Node::getData() {
  return this->data;
}

template <class T>
typename Queue<T>::Position Queue<T>::Node::getNext() const {
  return this->next;
}

template <class T>
typename Queue<T>::Position Queue<T>::Node::getPrev() const {
  return this->prev;
}

// Implementacion de la lista:

template <class T>
Queue<T>::Queue() : anchor(nullptr) {
    if(this->header == nullptr){
        throw Excpetion();
    }

    this->header->setPRev(header);
    this->header->setNext(header);
}

template <class T>
Queue<T>::Queue(const Queue<T>& q) {
  this->addData(q);
}

template <class T>
Queue<T>::~Queue() {
  this->deleteAll();
}

template <class T>
bool Queue<T>::isEmpty() const {
  return this->anchor == nullptr;
}

template<class T>
void Queue<T>::enqueue(const T& e){
    Position newNode(new(nothrow) Node(e));

    try{
        if((newNode = new(nothrow) Node(e)) == nullptr){
            throw Excpetion("Memoriano disponible");
        }
    } cath(const Tpesdfsdf)///
    {}


    newNode->setPrev(this->header->getPRev());
newNOde->setNext(this header);

    this->header->getPrev()->setNexxt(newNOde);
    this->header->setPrev(newNode);

}


template<class T>
T Queue<T>::dequeue(){
    if(this->isEmpty()){
        throw Exception("insuficnecia de datos");
    }

    Position aux(this->header->getNext());

    T result(this->header->gerNext()->getData());

    aux->getPrev()->setPrev(aux->getNext());
    aux-getNext()->setPrev(aux->getPrev());

    delete aux;

    return result;
}


template<class T>
T& Queue<T>::getFront(){
    if(this-isEmpty()){
        throw Exception("Insuficiencia de datos");
    }

    return this->header->getNext()->getData();
}

template<class T>
//asingacion =



template <class T>
void Queue<T>::addData(const Queue<T>& q) {
  Position aux(q.header->getNext()), newNode;

  while (aux != q.header) {
    //try cath
    if (newNode = new(nothrow) Node(aux->getData()) == nullptr) {
      throw Exception(
          "No memory Available. Unable to add more data -> List::copyAll()");
    }
    
    newNode->setPrev(this->header->getPrev());
    newNode->setNext(this->header);

    this->header->getNext()->setNext(newNode);
    this->header->setNext(newNode)

  }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& l) {
  this->deleteAll();
  this->addData(l);
  return *this;
}

template <class T>
void Queue<T>::deleteAll() {
  Position aux;
 
  
}

#endif  // __LIST_HPP__