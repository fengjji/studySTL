#include "alloc.h"
#include "vector.hpp"
#include <iostream>

class A {
public:
  A() {
    std::cout << ".."
              << "\n";
    a = 100;
  }

  explicit A(int x) {
    std::cout << "...copy number"
              << "\n";
    a = x;
  }

  A(const A &) {
    std::cout << "...copy"
              << "\n";
  }
  int a = 0;
};

int main() {

  { fj::vector<A> v(3, A(-1)); }

  std::cout << fj::Alloc::end_ - fj::Alloc::begin_ << "\n";

  return 0;
}