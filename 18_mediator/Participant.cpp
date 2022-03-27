//
// Created by Martin Edviken on 2022-03-13.
//

#include "Participant.h"
#include "Mediator.h"

Participant::Participant(Mediator& mediator) : mediator(mediator)
{
    mediator.participants.push_back(this);
}

void Participant::say(int value)
{
  mediator.broadcast(this, value);
}

void Participant::receive(const int n) {
  value += n;
}
