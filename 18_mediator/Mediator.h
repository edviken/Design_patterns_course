//
// Created by Martin Edviken on 2022-03-13.
//

#ifndef INC_18_MEDIATOR_MEDIATOR_H
#define INC_18_MEDIATOR_MEDIATOR_H
#include "Participant.h"
#include <vector>

class Mediator {
public:
  std::vector<IParticipant*> participants;

  Mediator() = default;

  void broadcast(const IParticipant* speaker, const int& n);
};


#endif //INC_18_MEDIATOR_MEDIATOR_H
