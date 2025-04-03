// Archivo de Definicion e Implementacion de la lista
#ifndef __LIST_HPP__
#define __LIST_HPP__
#include <exception>
#include <iostream>
#include <string>

template<class T>
class Node {
    private:

};


template <class T>
class List {
    class Node;
public:
    typedef Node* Position;

private:
    class Node {
        private:
            T* data;
            Node* Next;
            Position next;
        public:
            Node(); 
            Node(const T&);
            
            T& getData();
            Position getNext() const;
            void setData(const T&);
            void setNext(Position);
    };


  Position anchor = nullptr;

  int last;

  bool isValid(const Position) const;
  void copyAll(const List<T>&);

 public:
    typedef Node* Position;



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

  void insertData(const int&, const Position& ,const T&);
  void deleteData(const Position);

  int getFirstPos() const;
  int getLastPos() const;

  int getPreviousPos(const Position) const;
  int getNextPos(const Position) const;

  int findDataLin(const T&) const;
//   int findDataBin(const T&) const;

  T& retrieve(const Position&);

  std::string toString() const;

  void deleteAll();

  //Sort Methods
  void sortDataBubble();
  void sortDataBubbleEx(int(const T&, const T&));
  void sortDataInsert();
  void sortDataSelect();
  void sortDataSelectEx(int(const T&, const T&));
  void sortDataShellCiura();
  void sortDataShellCiuraEx(int(const T&, const T&));
  void sortDataShellFactor();
  void sortDataShellFactorEx(int(const T&, const T&));

  void swapData(T&, T&);

  List<T> operator=(const List<T>&);
  //implementar leer a disco
 
};
#endif  // __LIST_HPP__1

template<class T>
List<T>::Node::Node(){
    //: next(nullprt)

}

template<class T>
List<T>::Node::Node(const T&) : data(e)
{ }


template<class T>
T& List<T>Node::getDatat(){
    return data;
}

template<class T>
void List<T>Node::setData(const Position& P){
    this->next = p;
}

template<class T>
List<T>::Position List<T>Node::getNext(){
//
}
//Implementaicon de la lista
template<class T>
List<T>::List() : anchor(nullptr) {}

template<class T>
List<T>::List(const List<T>& l) {
    this->copyAll(l)
}

//operator copyALl + return *this;

template<class T>
bool List<T>::isEmpty() const{
    return this->anchor == nullptr;
}

template<class T>
bool List<T>::insertData() const{
  if(p != nullptr && !this->isValid(p)){
    throw exception("posicion invalida, insertData()");
  }

  Position newNode(new Node(e));

  if(newNode == nullptr){
    throw Exception("NO hay memoriadispoinible, insertData");
  }

  if(p == nullptr) { //insiertar al principio
    newNode->setNext(this->anchor);
    this->anchor = newNode;
  } else { //cualquier otra posicion
    newNOde->setNext(p->getNext());
    p->setNext(newNode);
  }

    
}

template<class T>
void List<T>::deleteData(const Position& P){
    if(!this->isvalid(p)){
        throw Exception("Posicion invalida, deleteData");
    }

    if(p == this->anchor) { //eliminar primer
        this->anchor = p->getNext();
    }else{
        this->getPreviousPos(p)->setNext(p->getNext());
    }

    delete p;

}

template<class T>
List<T>:::Position List<T>::getFirstPos(){
    return this->anchor;
}

template<class T>
List<T>:::Position List<T>::getFirstPos(){
    if(this->isempty()){
        return nullptr;
    }
 Poisitiono aux(this->aux);

 while(aux_>getNext() != nullptr){
    aux = aux->getNext();
 }

 return aux;
}

template<class T>
List<T>::Position List<T>:getPreiousPos(const Position& p) const {
    Poisition aux(this->aanchor);

    while(aux != nullptr &7 aux->getNex() != p){
        aux = aux->getNext()
    }

    return aux;
}

tempalte<class T>
list<T>::Position LIst<T>::getNextPost(const Position& p) const {
    if(!this->isValid(p)){
        return nullptr;
    }

    return p->getNext();
}

template<class T>
List<T>::Positio List<T>::findData(const T& e) const{
    Position aux(this->anchor);

    while()

    return aux;
}

template<class T>
T& List<T>::retrieve(const Position& p){
if(this->isValid(p)){

}

return p->getData();
}

template<class T>
string List<T>::toString(){
    string result;

    Position aux(this->anchor);

    while(aux != nullptr){
        result += aux->getData().toString() + "\n";

        aux = aux->getNext();
    }

    return result;
}

template<class T>
void List<T>::deleteAll(){
    Position aux;

    while(this->anchor != nullptr){
        aux + this->anchor;

        this->anchor = this->anchor->getNext();

        delete aux;
    }
}

template<class T>
bool LIst<T>::isValid(const Position& p) const {
    Position aux(this->anchor);

    while( aux != nullptr){
        if(aux == p){
            return true;
        }
        aux = aux-getNext();
    }

    return false;
}

template<class T>
void LIst<T>addData(const LIst<T>& l){
    Position aux(l->anchor), newNode, lastInserted(this->getLastPost());

    while(aux != nullptr){
       if(newNode = new Node(aux->getdata()) == nullptr){
        throw Exceptio("no memory availabe, copyALl");
       }
       if(lastInserted == nullptr){
        this->anchor = newNode;
       }else{
        lastInserted->setNext(newNode);
       }

       lastInserted = newNode;

        aux = aux->getNext();
    }
}