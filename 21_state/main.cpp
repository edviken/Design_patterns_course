#include <iostream>
#include <vector>
#include <string>
using namespace std;


class CombinationLock
{
  vector<int> combination;
  int digitsEntered = 0;
  bool failed = false;

  void reset(){
    status = "LOCKED";
    digitsEntered = 0;
    failed = false;
  }
public:
  string status;

  CombinationLock(const vector<int> &combination) : combination(combination) {
    reset();
  }
  void enter_digit(int digit)
  {
    if (status == "LOCKED") status = "";
    status += to_string(digit);
    if(combination[digitsEntered] != digit){
      failed = true;
    }
    digitsEntered++;

    if (digitsEntered == combination.size()){
      status = failed ? "ERROR" : "OPEN";
    }
  }
};

int main() {
  CombinationLock cl({1, 2, 3});
  if (cl.status != "LOCKED") { return 1; }
  cl.enter_digit(1);
  if (cl.status != "1") { return 1; }
  cl.enter_digit(2);
  if (cl.status != "12") { return 1; }
  cl.enter_digit(3);
  if (cl.status != "OPEN") { return 1; }
  cout << "All tests passed" << endl;
  return 0;
}
