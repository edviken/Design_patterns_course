#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct DiscriminantStrategy
{
  virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
  // if the discriminant is negative, we return it as is.
  double calculate_discriminant(double a, double b, double c) override {
    double discriminant = pow(b, 2) - 4*a*c;
    return discriminant;
  }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
  // if thew discriminant is negative, we return NaN as pair.
  double calculate_discriminant(double a, double b, double c) override {
    double discriminant = pow(b, 2) - 4*a*c;
    return discriminant >= 0 ? discriminant : NAN;
  }
};

class QuadraticEquationSolver
{
  DiscriminantStrategy& strategy;
public:
  QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

  tuple<complex<double>, complex<double>> solve(double a, double b, double c)
  {
    complex<double> discriminant{strategy.calculate_discriminant(a, b, c), 0};
    return {(-b + sqrt(discriminant)) / (2*a),
            (-b - sqrt(discriminant)) / (2*a) };
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  OrdinaryDiscriminantStrategy strategy;
  QuadraticEquationSolver solver{strategy};
  auto results = solver.solve(1,10,16);
  if (complex<double>(-2,0) != get<0>(results)) { return 1; }
  if (complex<double>(-8,0) != get<1>(results)) { return 1; }

  auto results2 = solver.solve(1,4,5);
  if (complex<double>(-2,1) != get<0>(results2)) {
    cout << get<0>(results2) << " != (-2, 1)" << endl;
    return 2;
  }
  if (complex<double>(-2,-1) != get<1>(results2)) {
    cout << get<1>(results2) << " != (-2, -1)" << endl;
    return 2;
  }

  RealDiscriminantStrategy strategyReal;
  QuadraticEquationSolver solverReal{strategyReal};
  auto results3 = solverReal.solve(1,4,5);
  auto x1 = get<0>(results3);
  auto x2 = get<1>(results3);
  if (!isnan(x1.real())) {return 3;}
  if (!isnan(x2.real())) { return 3; }
  if (!isnan(x1.imag())) { return 3; }
  if (!isnan(x2.imag())) { return 3; }

  return 0;
}
