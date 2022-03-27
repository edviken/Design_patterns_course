#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Forward declarations
struct Value;
struct AdditionExpression;
struct MultiplicationExpression;

struct ExpressionVisitor
{
  virtual void accept(Value& v) = 0;
  virtual void accept(AdditionExpression& ae) = 0;
  virtual void accept(MultiplicationExpression& ep) = 0;
};

struct Expression
{
  virtual void visit(ExpressionVisitor& ev) = 0;
};

struct Value : Expression
{
  int value;

  Value(int value) : value(value) {}

  void visit(ExpressionVisitor& ev) override {
    ev.accept(*this);
  }
};

struct AdditionExpression : Expression
{
  Expression &lhs, &rhs;

  AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}

  void visit(ExpressionVisitor& ev) override {
    ev.accept(*this);
  }
};

struct MultiplicationExpression : Expression
{
  Expression &lhs, &rhs;

  MultiplicationExpression(Expression &lhs, Expression &rhs)
      : lhs(lhs), rhs(rhs) {}

  void visit(ExpressionVisitor& ev) override {
    ev.accept(*this);
  }
};

struct ExpressionPrinter : ExpressionVisitor
{
  void accept(Value& v) override {
    oss << v.value;
  }

  void accept(AdditionExpression& ae) override {
    oss << "(";
    ae.lhs.visit(*this);
    oss << "+";
    ae.rhs.visit(*this);
    oss << ")";
  }

  void accept(MultiplicationExpression& me) override {
    me.lhs.visit(*this);
    oss << "*";
    me.rhs.visit(*this);
  }

  string str() const { return oss.str(); }

private:
  ostringstream oss;
};

int main() {
  Value v2{2};
  Value v3{3};
  AdditionExpression simple{v2, v3};
  ExpressionPrinter ep;
  ep.accept(simple);
  if("(2+3)" != ep.str()) { return 1; }
  return 0;
}
