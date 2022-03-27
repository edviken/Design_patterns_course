//
// Created by Martin Edviken on 2022-03-13.
//

#include "Mediator.h"

void Mediator::broadcast(const IParticipant* speaker, const int& n) {
  for(auto* p : participants){
    if(speaker != p){
      p->receive(n);
    }
  }
}