// Archivo de Definicion e Implementacion de la clase Stack (Pila)
#ifndef __STACK_HPP__
#define __STACK_HPP__
#include <exception>
#include <string>

using namespace std;

template <class T, int ARRAYSIZE = 500>
class Stack {
 private:
  T data[ARRAYSIZE];
  int top;

  void copyAll(const Stack<T, ARRAYSIZE>&);

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

  Stack();
  Stack(const Stack<T, ARRAYSIZE>&);

  bool isEmpty();
  bool isFull();

  void push(const T&);
  T& pop();

  T& getTop();

  Stack<T, ARRAYSIZE>& operator=(const Stack<T, ARRAYSIZE>&);
};

#endif  //__STACK_HPP__

// Implementacion

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1) {}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack& s) {
  this->copyAll(s);
}

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>& s) {
  int i(0);

  this->top = s.top;

  while (i <= this->top) {
    this->data[i] = s.data[i];
    i++;
  }
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty() {
  return this->top == -1;
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull() {
  return this->top == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T& e) {
  if (this->isFull()) {
    throw Exception("Data overflow. push()");
  }

  this->top++;

  this->data[this->top] = e;
}

template <class T, int ARRAYSIZE>
T& Stack<T, ARRAYSIZE>::pop() {
  if (this->isEmpty()) {
    throw Exception("Insuficiencia de datos. pop()");
  }
  return this->data[this->top--];
}

template <class T, int ARRAYSIZE>
T& Stack<T, ARRAYSIZE>::getTop() {
  if (this->isEmpty()) {
    throw Exception("Insuficiencia de datos. getTop()");
  }

  return this->data[this->top];
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator=(
    const Stack<T, ARRAYSIZE>& s) {
  copyAll(s);

  return *this;
}
