#include <iostream>
#include <functional>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    auto* s1 = factory();
    auto* s2 = factory();
    return s1 == s2;
  }
};

int main() {

  return 0;
}
