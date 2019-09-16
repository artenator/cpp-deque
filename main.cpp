#include <iostream>
#include <vector>
#include "Deque.h"

int main() {
  Deque<int> d = Deque<int>();

  std::cout << d.pushBack(5) << std::endl;
  std::cout << d.pushBack(10) << std::endl;
  std::cout << d.pushFront(30) << std::endl;
  std::cout << d.pushBack(22) << std::endl;

  d.print();
  
  std::cout << "Popping back " << d.end->value << std::endl;
  d.popBack();
  d.print();

  std::cout << "Popping front " << d.front->value << std::endl;
  d.popFront();
  d.print();

  std::cout << "Popping back " << d.end->value << std::endl;
  d.popBack();
  d.print();

  std::cout << "Popping front " << d.front->value << std::endl;
  d.popFront();
  d.print();

  std::cout << "Popping front when empty " << d.front << std::endl;
  d.popFront();
  d.print();

  return 0;
}
