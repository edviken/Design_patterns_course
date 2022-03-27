#include <iostream>

#include "Mediator.h"
#include "Participant.h"

int main() {
  Mediator mediator;
  Participant p1(mediator), p2(mediator);
  p1.say(3);
  std::cout << "p1 has value = " << p1.value << std::endl;
  std::cout << "p2 has value = " << p2.value << std::endl;
  std::cout << "-------" << std::endl;

  p2.say(2);
  std::cout << "p1 has value = " << p1.value << std::endl;
  std::cout << "p2 has value = " << p2.value << std::endl;


  return 0;
}
