#include <iostream>
#include <string>

using namespace std;

class Person
{
  int age;
public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age=age; }

  string drink() const { return "drinking"; }
  string drive() const { return "driving"; }
  string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
public:
  ResponsiblePerson(const Person &p) : person(p) {}

  int get_age() const { return person.get_age(); }
  void set_age(int age) { person.set_age(age); }

  string drink() const {
    if(person.get_age() < 18) {
      return "too young";
    }
    return person.drink();
  }

  string drive() const {
    if(person.get_age() < 16) {
      return "too young";
    }
    return person.drive();
  }

  string drink_and_drive() const {
    if(person.drink() == "drinking" && person.drive() == "driving") {
      return "dead";
    }
    return "";
  }

private:
  Person person;
};

int main() {
  Person p{18};
  ResponsiblePerson rp{p};
  cout << rp.drive() << endl;
  cout << rp.drink() << endl;
  cout << rp.drink_and_drive() << endl;
  return 0;
}
