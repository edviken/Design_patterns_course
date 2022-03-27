#include <iostream>
#include <map>
#include <vector>

using namespace std;

inline vector<string> split(const string& str) {
    vector<string> result;
    uint count = 0, pos = 0;
    for(int i{0}; i < str.size(); i++){
      if(str.at(i) == '+' || str.at(i) == '-'){
        result.push_back(str.substr(pos, count));
        result.push_back( string({str.at(i)}) );
        count = 0;
        pos = i + 1;
      } else {
        count++;
      }
    }
    result.push_back(str.substr(pos, count));
  return result;
}


struct ExpressionProcessor
{
  map<char,int> variables;

  enum class Op {
    plus,
    minus
  };

  int convertToNumber(string& str) {
    int res;
    try {
      res = stoi(str);
    } catch (const invalid_argument&) {
      if (str.length() == 1 &&
          variables.find(str[0]) != variables.end()){
        res = variables[str[0]];
      } else {
        res = 0;
      }
    }
    return res;
  }

  int calculate(const string& expression)
  {
    vector<string> exp = split(expression);
    int res = 0;
    Op op = Op::plus;
    for(int i{0}; i < exp.size(); i++){
      if(i % 2 == 0){
        if (convertToNumber(exp.at(i)) == 0) {
          res = 0;
          break;
        }
        switch (op) {
          case Op::plus:
            res += convertToNumber(exp.at(i));
            break;
          case Op::minus:
            res -= convertToNumber(exp.at(i));
            break;
        }
      } else {
        op = (exp.at(i) == "+") ? Op::plus : Op::minus;
      }
    }
    return res;
  }
};

int main() {
  ExpressionProcessor ep{{{'x', 3}}};
  int r1, r2, r3;
  r1 = ep.calculate("1+2+3");   // 6
  r2 = ep.calculate("1+2+xy");  // 0
  r3 = ep.calculate("10-2-x");  // when x=3 in variables, should return 5
  cout << r1 << endl;
  cout << r2 << endl;
  cout << r3 << endl;
  return 0;
}
