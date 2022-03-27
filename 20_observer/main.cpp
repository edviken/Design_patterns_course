#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IRat {
public:
  virtual void changeAttackValue(int newAttack) = 0;
};

struct Game
{
  vector<IRat*> rats;

  Game() {}

  enum class Rat{
    Born,
    Died
  };

  void notify(Game::Rat msg, IRat* rat){
    if(!rat) { return; }

    switch (msg) {
      case Rat::Born:
        rats.push_back(rat);
        break;
      case Rat::Died:
        erase_if(rats,[&](const auto* item){
          return item == rat;
        });
        break;
    }

    for(auto* r : rats){
      r->changeAttackValue(rats.size());
    }
  }
};

struct Rat : IRat
{
  Game& game;
  int attack{1};

  Rat(Game &game) : game(game)
  {
    game.notify(Game::Rat::Born, this);
  }

  ~Rat()
  {
    game.notify(Game::Rat::Died, this);
  }

private:
  void changeAttackValue(int newAttack) override {
    attack = newAttack;
  }
};

int main() {
  Game game;
  Rat r1{game};
  cout << "Number of rats in game = " << game.rats.size() << endl;
  Rat r2{game};
  cout << "Number of rats in game = " << game.rats.size() << endl;
  cout << "r1 attack = " << r1.attack << endl;
  cout << "r2 attack = " << r2.attack << endl;
  {
    Rat r3{game};
    cout << "Number of rats in game = " << game.rats.size() << endl;
    cout << "r1 attack = " << r1.attack << endl;
    cout << "One rat dies" << endl;
  }
  cout << "r1 attack = " << r1.attack << endl;

  return 0;
}
