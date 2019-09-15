#include <iostream>
#include <vector>
#include "Deque.h"

int main() {
  Deque<int> *d = new Deque<int>(4);


  int *x = new int(5);
  int *y = new int(10);
  int *z = new int(23);
  int *a = new int(7);
  int *b = new int(50);
  
  std::cout << *d->pushBack(x) << std::endl;
  std::cout << *d->pushBack(y) << std::endl;
  std::cout << *d->pushFront(z) << std::endl;
  std::cout << *d->pushBack(a) << std::endl;

  d->print();

  d->popFront();
  d->print();
  
  d->popBack();
  d->popBack();

  d->print();

  d->popFront();

  d->print();

  std::cout << *d->pushBack(y) << std::endl;
  std::cout << *d->pushBack(x) << std::endl;
  std::cout << *d->pushFront(z) << std::endl;
  std::cout << *d->pushBack(b) << std::endl;

  d->print();

  return 0;
}
