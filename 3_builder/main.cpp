#include <iostream>
#include <ostream>
#include <vector>
#include <sstream>

using namespace std;

/* Expected output to generate
class Person
{
  std::string name;
  int age;
};
*/

class CodeElement{
protected:
  string name, type;
  vector<CodeElement> elems;
  const size_t indent_size = 2;

  friend class CodeBuilder;

  CodeElement() = default;
  CodeElement(const string& name, const string& type) : name(name), type(type) {}

  string str(int indent = 1) const {
    ostringstream oss;
    string i(indent_size * indent, ' ');
    if(!name.empty()) {
      oss << "class" << " " << name << "\n{\n";
      for (auto& item : elems){
        oss << i << item.type << " " << item.name << ";" << std::endl;
      }
      oss << "};";
    }
    return oss.str();
  }
};

class CodeBuilder {
  CodeElement root;
public:
  CodeBuilder(const string& class_name){
    root.name = class_name;
  }

  CodeBuilder& add_field(const string& name, const string& type) {
    CodeElement e{name, type};
    root.elems.push_back(e);
    return *this;
  }
  string str() const { return root.str(); }
  operator CodeElement() const { return root; }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj);
};

ostream& operator<<(ostream& os, const CodeBuilder& obj) {
  os << obj.str();
  return os;
}

int main() {
  auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
  cout << cb;
  return 0;
}
