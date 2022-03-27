#include <iostream>

using namespace std;

struct Command
{
  enum Action { deposit, withdraw } action;
  int amount{0};
  bool success{false};
};

struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    switch(cmd.action) {
      case Command::Action::deposit:
        balance += cmd.amount;
        cmd.success = true;
        break;
      case Command::Action::withdraw:
        if(balance >= cmd.amount) {
          balance -= cmd.amount;
          cmd.success = true;
        }
        break;
    }
  }
};

int main() {
  Account a;
  Command depositCash{Command::Action::deposit, 100, false};
  a.process(depositCash);
  cout << "Current balance: " <<  a.balance << endl;
  Command withdrawCash{Command::Action::withdraw, 60, false};
  a.process(withdrawCash);
  cout << "Current balance: " <<  a.balance << endl;
  return 0;
}
