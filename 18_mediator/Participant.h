//
// Created by Martin Edviken on 2022-03-13.
//

#ifndef INC_18_MEDIATOR_PARTICIPANT_H
#define INC_18_MEDIATOR_PARTICIPANT_H


class Mediator; // Forward declaration

class IParticipant {
public:
  IParticipant() {}

  virtual void say(int value) = 0;
  virtual void receive(const int n) = 0;
};

struct Participant : IParticipant
{
  int value{0};
  Mediator& mediator;

public:
  Participant(Mediator& mediator);

  void say(int value) override;

  void receive(const int n) override;
};


#endif //INC_18_MEDIATOR_PARTICIPANT_H
