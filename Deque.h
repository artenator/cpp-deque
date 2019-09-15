#include <stddef.h>
#include <iterator>

#ifndef DEQUE_H
#define DEQUE_H

template <class T>
class Node {
public:
  T *value;
  Node<T> *next;
  Node<T> *prev;
  
  Node() {
    this->value = NULL;
  }
  
  Node(T value) {
    this->value = &value;
  }
};

template <class T>
class Deque {
public:
  Node<T> *front;
  Node<T> *end;
  int size;

  Deque(int size) {
    this->size = size;
    Node<T> *prev = new Node<T>();
    Node<T> *cur;

    this->front = prev;
    
    for (int i = 0; i < size - 1; i++) {
      cur = new Node<T>();
      prev->next = cur;
      cur->prev = prev;
      prev = cur;
    }

    cur->next = this->front;
    this->front->prev = cur;

    this->end = this->front;
  }

  T *pushBack(T *value) {
    if (!(this->end->next == this->front)) {
      if (this->end->value) {
        this->end = this->end->next;
      }

      this->end->value = value;
      return value;
    } else {
      return NULL;
    }
  }

  T *pushFront(T *value) {
    if (!(this->front->prev == this->end)) {
      if (this->front->value) {
        this->front = this->front->prev;
      }

      this->front->value = value;
      return value;
    } else {
      return NULL;
    }
  }

  T *popBack() {
    T *ret;
    if (this->front != this->end) {
      ret = this->end->value;
      this->end->value = NULL;
      this->end = this->end->prev;
      return ret;
    } else if (this->end) {
      ret = this->end->value;
      this->end->value = NULL;
      return ret;
    } else {
      return NULL;
    }
    return NULL;
  }

  T *popFront() {
    T *ret;
    if (this->front != this->end) {
      ret = this->end->value;
      this->front->value = NULL;
      this->front = this->front->next;
      return ret;
    } else if (this->front) {
      ret = this->front->value;
      this->front->value = NULL;
      return ret;
    } else {
      return NULL;
    }
    return NULL;
  }

  void print() {
    Node<int> *cur = this->front;
    
    for (int i = 0; i < this->size; i++) {
      if (cur->value == NULL) {
        std::cout << "NULL";
      } else {
        std::cout << *cur->value;
      }
      
      if (!(i == this->size - 1))
          std::cout << "->";
      
      cur = cur->next;
    }

    std::cout << std::endl;
  }
};

#endif
