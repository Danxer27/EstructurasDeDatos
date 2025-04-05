#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <string>
#include <exception>

template<class T>
class Stack {
 class Node;

 private:
 typedef Node* Position;

    class Node{
        private:
            T data;
            Position next = nullptr;
        public:
            Node();
            Node(const T&);

            T& getData();
            Position getNext() const;
            
            void setData(const T&);
            void setNext(const Position&);
    };
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


    Position anchor = nullptr;

    void addData(const Stack&);

    void deleteAll();

    bool isEmpty() const;

    public:

    Stack();
    Stack(const Stack&);
    ~Stack();

    void push(const T&);
    T pop();

    T& getTop();

    Stack& operator= (const Stack&);

};

#endif //__STACK_HPP__

//Implementacion del nodo

template <class T>
Stack<T>::Node::Node() {}

template <class T>
Stack<T>::Node::Node(const T& value) : data(value) {}

template <class T>
void Stack<T>::Node::setData(const T& e) {
  this->data = e;
}

template <class T>
void Stack<T>::Node::setNext(const Position& p) {
  this->next = p;
}

template <class T>
T& Stack<T>::Node::getData(){
  return this->data;
}

template <class T>
typename Stack<T>::Position Stack<T>::Node::getNext() const {
  return this->next;
}



//Implementacion de la stack

template<class T>
Stack<T>::Stack() {}

template<class T>
Stack<T>::Stack(const Stack& s){
    this->addData(s);
}

template<class T>
Stack<T>::~Stack(){
    this->deleteAll();
}

template<class T>
bool Stack<T>::isEmpty() const {
    return this->anchor == nullptr;
}

template<class T>
void Stack<T>::push(const T& e){
    Position newNode(new(nothrow) Node(e));

    if(newNode == nullptr){
        throw Exception("Memoria no disponible. Stack<T>::push()");
    }

    newNode->setNext(this->anchor);

    this->anchor = newNode;
}

template<class T>
T Stack<T>::pop(){
    if(this->isEmpty()){
        throw Exception("Insuficiencia de datos. Stack<T>::pop().");
    }

    T result(this->anchor->getData());

    Position aux(this->anchor);

    this->anchor = aux->getNext();

    delete aux;

    return result;
}

template<class T>
T& Stack<T>::getTop(){
    if(this->isEmpty()){
        throw Exception("Insuficiencia de datos. Stack<T>::getTop()");
    }

    //T result(this->anchor->getNext()->getData());
    // T result(this->anchor->getData());
    //aqui hay algo raro
    // return this->anchor->getNext();
    //return this->anchor->getNext()->getData();
    return this->anchor->getData();
}


template<class T>
void Stack<T>::deleteAll(){
    Position aux;
    //poner dentro del destructor
    while (this->anchor != nullptr) {
      aux = this->anchor;
      this->anchor = aux->getNext();
      delete aux;
    }
}

template<class T>
void Stack<T>::addData(const Stack& s){
    Position aux(s.anchor), newNode, lastInserted(nullptr);

    while (aux != nullptr) {
      if (newNode = new(nothrow) Node(aux->getData()) == nullptr) {
        throw Exception(
            "No memory Available. Unable to add more data -> Stack<T>::addData()");
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

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& l) {
  this->deleteAll();
  this->addData(l);
  return *this;
}