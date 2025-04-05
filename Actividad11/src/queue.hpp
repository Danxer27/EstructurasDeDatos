//Archivo de definicion e implemenation de la Cola (Queue)
#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <exception>
#include <iostream>
#include <string>

using namespace std;

template<class T>
class Queue {
    class Node;

    private:
    typedef Node* Position; 
    class Node{
        private:
            T* dataPtr;
            Position prev = nullptr;
            Position next = nullptr;
        public:
            class Exception : public Queue<T>::Exception {
                using Queue<T>::Exception::Exception;
            };

            Node();
            Node(const T&);

            void setData(const T&);
            void setDataPtr(T*);
            void setNext(const Position&);
            void setPrev(const Position&);

            T& getData();
            T* getDataPtr();
            Position getNext() const;
            Position getPrev() const;
    };

    void addData(const Queue&);

    public:
    //Position anchor = nullptr;

    Position header = nullptr;

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
    Queue(const Queue&);
    ~Queue();

    Queue<T>& operator= (const Queue<T>&);

    bool isEmpty() const;

    void enqueue(const T&);

    T dequeue();

    T& getFront();

    void deleteAll();

};

//Implementacion del Nodo;
template<class T>
Queue<T>::Node::Node() {}

template<class T>
Queue<T>::Node::Node(const T& e) : dataPtr(new(nothrow) T(e)){
    if(dataPtr == nullptr){
        throw Exception("Memoria Insuficiente. Queue<T>::Node()::Node(cosnt T&)");
    }
}

template<class T>
void Queue<T>::Node::setData(const T& e) {
    if(this->dataPtr == nullptr){
        if((this->dataPtr = new(nothrow) T(e)) == nullptr){
            throw Exception("Memoria no disponible. Queue<T?::setData()");
        }
    }else {
        *this->data = e;
    }
}

template<class T>
void Queue<T>::Node::setDataPtr(T* pe) {
    this->data = pe;
}

template<class T>
void Queue<T>::Node::setNext(const Position& p){
    this->next = p;
}

template<class T>
void Queue<T>::Node::setPrev(const Position& p){
    this->prev = p;
}

template<class T>
T* Queue<T>::Node::getDataPtr(){
    return this->dataPtr;
}


template<class T>
T& Queue<T>::Node::getData(){
    if(this->dataPtr == nullptr){
        throw Queue<T>::Node::Exception("Dato inexistente.");
    }
    return *this->dataPtr;
}

template<class T>
typename Queue<T>::Position Queue<T>::Node::getNext() const {
    return this->next;
}

template<class T>
typename Queue<T>::Position Queue<T>::Node::getPrev() const {
    return this->prev;
}

//Implementacion de la Queue

template<class T>
Queue<T>::Queue() : header(new(nothrow) Node) {
    if(this->header == nullptr){
        throw Exception("Memoria Insuficiente. Queue<T>::Queue().");
    }

    this->header->setPrev(header);
    this->header->setNext(header);
}

template<class T>
Queue<T>::Queue(const Queue<T>& q) : Queue() {
    this->addData(q);
}

template<class T>
Queue<T>::~Queue(){
    this->deleteAll();

    delete this->header;
}

template<class T>
bool Queue<T>::isEmpty() const {
    return this->header->getNext() == this->header;
}

template<class T>
void Queue<T>::enqueue(const T& e){
    Position newNode;

    try {
        if((newNode = new(nothrow) Node(e)) == nullptr){
            throw Exception("Memoria no disponible. Queue<T>::enqueue().");
        }
    } catch(const typename Node::Exception& ex){ 
        throw Exception(ex.what());
    }

    newNode->setPrev(this->header->getPrev());
    newNode->setNext(this->header);

    this->header->getPrev()->setNext(newNode);
    this->header->setPrev(newNode);
}

template<class T>
T Queue<T>::dequeue() {
   if(this->isEmpty()){
    throw Exception("Insuficiencia de Datos. Queue<T>::dequeue()");
   }

   Position aux(this->header->getNext());

   T result(aux->getData());
   //T result(this->header->getNext()->getData());

   aux->getPrev()->setNext(aux->getNext());
   aux->getNext()->setPrev(aux->getPrev());

   delete aux;

   return result;
}

template<class T>
T& Queue<T>::getFront(){
    if(this->isEmtpy()){
        throw Exception("Insuficiencia de Datos. Queue<T>::getFront()");
    }

    return this->header->getNext()->getData();
}

template <class T>
void Queue<T>::addData(const Queue<T>& q) {
  Position aux(q.header->getNext()), newNode;

  while (aux != q.header) {
    try {
        if ((newNode = new(nothrow) Node(aux->getData())) == nullptr) {
            throw Exception("Memoria no disponible. Queue<T>::addData()");
        }
    } catch (const typename Node::Exception& ex){
        throw Exception(ex.what());
    }
    
    newNode->setPrev(this->header->getPrev());
    newNode->setNext(this->header);

    this->header->getPrev()->setNext(newNode);
    this->header->setPrev(newNode);

    aux = aux->getNext();
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
 
  while(this->header->getNext() != header){
    aux = this->header->getNext();

    this->header->setNext(aux->getNext());

    delete aux;
  }

  this->header->setPrev(header);
}


#endif //__QUEUE_HPP__