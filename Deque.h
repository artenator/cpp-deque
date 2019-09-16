#include <stddef.h>
#include <memory>

#ifndef DEQUE_H
#define DEQUE_H

template <class T>
class Node {
public:
  T value;
  std::shared_ptr< Node<T> > next;
  std::weak_ptr< Node<T> > prev;
  
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
  std::shared_ptr< Node<T> > front;
  std::shared_ptr< Node<T> > end;
  int size;

  Deque() {
    this->size = 0;
  }

  T pushBack(T value) {
    std::shared_ptr< Node<T> > newNode = std::make_shared< Node<T> >(value);

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
    std::shared_ptr< Node<T> > newNode = std::make_shared< Node<T> >(value);

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
    if (this->end == nullptr) {
      return;
    }
    else if (this->end == this->front) {
      this->end->next = nullptr;
      this->end = nullptr;
      this->front = nullptr;
    } else {
      std::shared_ptr< Node<int> > tmp = this->end;
      this->end = this->end->prev.lock();
      this->end->next = tmp->next;
      this->front->prev = this->end;
    }

    size--;
  }

  void popFront() {
    if (this->front == nullptr) {
      return;
    }
    else if (this->end == this->front) {
      this->front->next = nullptr;
      this->end = nullptr;
      this->front = nullptr;
    } else {
      std::shared_ptr< Node<int> > tmp = this->front;
      this->front = this->front->next;
      this->front->prev = tmp->prev;
      this->end->next = this->front;
    }

    size--;
  }

  void print() {
    std::shared_ptr< Node<int> > cur = this->front;
    
    for (int i = 0; i < this->size; i++) {
      std::cout << cur->value;
      
      if (!(i == this->size - 1))
        std::cout << "->";
      
      cur = cur->next;
    }

    std::cout << std::endl;
  }

  bool empty() {
    return this->size <= 0;
  }

  ~Deque() {
    std::cout << "destruct deque" << std::endl;
    if (this->front)
      this->front->next = nullptr;
  }
};

#endif
