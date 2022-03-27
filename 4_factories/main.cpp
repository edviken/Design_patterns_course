#include <iostream>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
public:
  Person create_person(const string& name)
  {
    static int _id{0};
    return Person{_id++, name};
  }
};

int main() {
  PersonFactory pf;
  auto p1 = pf.create_person("John");
  auto p2 = pf.create_person("Jane");

  cout << "p1:" << p1.id << ", " << p1.name << endl;
  cout << "p2:" << p2.id << ", " << p2.name << endl;

  return 0;
}
