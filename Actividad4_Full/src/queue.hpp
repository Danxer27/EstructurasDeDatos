// Archivo de Definicion e Implementacion de la Cola (Queue)
#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <exception>
#include <string>

using namespace std;

template <class T, int ARR = 500>
class Queue {
 private:
  T data[ARR];
  int frontPos;
  int endPos;

  void copyAll(const Queue<T, ARR>&);

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

  Queue();
  Queue(const Queue<T, ARR>&);

  bool isEmpty() const;
  bool isFull() const;

  void enqueue(const T&);
  T dequeue();

  T& getFront();

  Queue<T, ARR>& operator=(const Queue<T, ARR>&);
};

#endif  //__QUEUE_HPP__

// Implementacion de la Clase

template <class T, int ARR>
Queue<T, ARR>::Queue() : frontPos(0), endPos(ARR - 1) {}

template <class T, int ARR>
Queue<T, ARR>::Queue(const Queue<T, ARR>& q) {
  this->copyAll(q);
}

template <class T, int ARR>
void Queue<T, ARR>::copyAll(const Queue<T, ARR>& q) {
  this->frontPos = q.frontPos;
  this->endPos = q.endPos;

  int i = this->frontPos;

  do {
    this->data[i] = q.data[i];
    i = (i + 1) % ARR;
  } while (i != (this->endPos + 1) % ARR);
}

template <class T, int ARR>
bool Queue<T, ARR>::isEmpty() const {
  return (this->frontPos == endPos + 1) or
         (this->frontPos == 0 && this->endPos == ARR - 1);
}

template <class T, int ARR>
bool Queue<T, ARR>::isFull() const {
  return (this->frontPos == this->endPos + 2) or
         (this->frontPos == 0 and this->endPos == ARR - 2) or
         (this->frontPos == 1 and this->endPos == ARR - 1);
}

template <class T, int ARR>
void Queue<T, ARR>::enqueue(const T& e) {
  if (this->isFull()) {
    throw Exception("Desbordamiento: enqueue().");
  }
  this->endPos = ++this->endPos == ARR ? 0 : this->endPos;

  data[this->endPos] = e;
}

template <class T, int ARR>
T Queue<T, ARR>::dequeue() {
  if (this->isEmpty()) {
    throw Exception("Insuficiendia de datos. dequeue().");
  }

  T result(this->data[this->frontPos]);

  this->frontPos++;

  if (this->frontPos == ARR) {
    this->frontPos = 0;
  }

  return result;
}

template <class T, int ARR>
T& Queue<T, ARR>::getFront() {
  if (this->isEmpty()) {
    throw Exception("Insuficiencia de Datos. getFront().");
  }

  return data[this->frontPos];
}

template <class T, int ARR>
Queue<T, ARR>& Queue<T, ARR>::operator=(const Queue<T, ARR>& q) {
  copyAll(q);

  return *this;
}