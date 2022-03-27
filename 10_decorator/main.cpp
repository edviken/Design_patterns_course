#include <string>
#include <iostream>
using namespace std;

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override {
    return "A rose";
  }
};

struct RedFlower : Flower
{
  Flower& flower;
  RedFlower(Flower& obj) : flower(obj) {}

  string str() override {
    string ret = flower.str();
    if (ret.find("that is") == string::npos) {
      ret = ret + " that is red";
    } else if(ret.find("red") == string::npos) {
      ret = ret + " and red";
    }
    return ret;
  }
};

struct BlueFlower : Flower
{
  Flower& flower;
  BlueFlower(Flower& obj) : flower(obj) {}

  string str() override {
    string ret = flower.str();
    if (ret.find("that is") == string::npos) {
      ret = ret + " that is blue";
    } else if(ret.find("blue") == string::npos) {
      ret = ret + " and blue";
    }
    return ret;
  }
};

int main() {
  cout << "Hello World!" << endl;
  Rose rose;
  RedFlower red_rose{rose};
  RedFlower red_red_rose{red_rose};
  BlueFlower blue_red_rose{red_rose};
  cout << rose.str() << endl; // "A rose"
  cout << red_rose.str() << endl; // "A rose that is red"
  cout << red_red_rose.str() << endl; // "A rose that is red"
  cout << blue_red_rose.str() << endl; // "A rose that is red and blue"

  BlueFlower blue_rose{rose};
  cout << blue_rose.str() << endl;

  RedFlower nested_case{blue_red_rose};
  cout << nested_case.str() << endl;
  return 0;
}