//Archivo de definicion e implemenation de la Cola (Queue)
#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <exception>
#include <iostream>
#include <string>

using namespace std;

template<class T>
class Queue{
    class Node;

    private:
    typedef Node* Position;

    class Node{
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

    void addData(const Queue&);

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
    Queue(const Queue&);
    ~Queue();

    Queue<T>& operator= (const Queue<T>&);

    bool isEmpty() const;

    void enqueue(const T&);

    T dequeue();

    T& getFront();

};

//Implementacion del Nodo;
template<class T>
Queue<T>::Node::Node() {}

template<class T>
Queue<T>::Node::Node(const T& value) : data(value) {}

template<class T>
void Queue<T>::Node::setData(const T& e){
    this->data = e;
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
T& Queue<T>::Node::getData(){
    return this->data;
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
Queue<T>::Queue() : anchor(nullptr){ //creo que aqui va un header
    if(this->header == nullptr){
        throw Exception("Memoria Insuficiente. Queue<T>::Queue().");
    }

    this->header->setPrev(header);
    this->header->setNext(header);
}

template<class T>
Queue<T>::Queue(const Queue<T>& q){
    this->addData(q);
}

template<class T>
Queue<T>::~Queue(){
    this->deleteAll();
}

template<class T>
bool Queue<T>::isEmpty() const {
    return this->anchor == nullptr;
}

template<class T>
void Queue<T>::enqueue(const T& e){
    //Position newNode(new(notrhow) Node(e));
    //checar como hiba aqui
    try {
        if((newNode = new(nothrow) Node(e)) == nullptr){
            throw Exception("Memoria no disponible. Queue<T>::enqueue().");
        }
    } catch(){ //revisar que hiba aqui

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

   T result(this->header->getNext()->getData());

   aux->getPrev()->setPrev(aux->getNext());
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

template<class T>
void Queue<T>::addData(const Queue& q){
    Position aux(q.header->getNext()), newNode;

    while(aux != q.header){
        //try catch
        if(newNode = new(notrhow))
    }
}


#endif //__QUEUE_HPP__