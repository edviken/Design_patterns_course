#include <iostream>
#include "exercise.h"

int main() {
  std::cout << "Hello, World!" << std::endl;

  SingleValue singleValue{11};
  ManyValues otherValues;
  otherValues.add(22);
  otherValues.add(33);
  auto res = sum({ &singleValue, &otherValues }); // returns 6
  cout << "The total sum is: " << res << endl;
  return 0;
}
