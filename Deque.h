#include <stddef.h>
#include <iterator>

#ifndef DEQUE_H
#define DEQUE_H

template <class T>
class Node {
public:
  T value;
  Node<T> *next;
  Node<T> *prev;
  
  Node() {}
  
  Node(T value) {
    this->value = value;
  }

  ~Node() {
    std::cout << "Freed memory for Node with value: " << this->value << std::endl;
  }
};

template <class T>
class Deque {
public:
  Node<T> *front;
  Node<T> *end;
  int size;

  Deque() {
    this->size = 0;
  }

  T pushBack(T value) {
    Node<T> *newNode = new Node<T>(value);
    
    if (!this->front && !this->end) {
      newNode->next = newNode;
      newNode->prev = newNode;
      
      this->front = newNode;
      this->end = newNode;
    } else {
      this->end->next = newNode;
      newNode->prev = this->end;
      newNode->next = this->front;
      this->end = newNode;
      this->front->prev = newNode;
    }

    size++;

    return value;
  }

  T pushFront(T value) {
    Node<T> *newNode = new Node<T>(value);
    
    if (!this->front && !this->end) {
      newNode->next = newNode;
      newNode->prev = newNode;

      this->front = newNode;
      this->end = newNode;
    } else {
      this->front->prev = newNode;
      newNode->next = this->front;
      newNode->prev = this->end;
      this->front = newNode;
      this->end->next = newNode;
    }

    size++;

    return value;
  }

  void popBack() {
    if (this->end == NULL) {
      return;
    }
    else if (this->end == this->front) {
      delete this->end;
      this->end = NULL;
      this->front = NULL;
    } else {
      Node<int> *tmp = this->end;
      this->end = this->end->prev;
      this->end->next = tmp->next;
      this->front->prev = this->end;
      delete tmp;
    }

    std::cout << "addr for front is " << this->front << std::endl;
    std::cout << "addr for end is " << this->end << std::endl;

    size--;
    
    std::cout << "size is " << this->size << std::endl;
  }

  void popFront() {
    if (this->front == NULL) {
      return;
    }
    else if (this->end == this->front) {
      delete this->front;
      this->end = NULL;
      this->front = NULL;
    } else {
      Node<int> *tmp = this->front;
      this->front = this->front->next;
      this->front->prev = tmp->prev;
      this->end->next = this->front;
      delete tmp;
    }

    std::cout << "addr for front is " << this->front << std::endl;
    std::cout << "addr for end is " << this->end << std::endl;

    size--;
    
    std::cout << "size is " << this->size << std::endl;
  }

  void print() {
    Node<int> *cur = this->front;
    
    for (int i = 0; i < this->size; i++) {
      std::cout << cur->value;
      
      if (!(i == this->size - 1))
        std::cout << "->";
      
      cur = cur->next;
    }

    std::cout << std::endl;
  }
};

#endif
