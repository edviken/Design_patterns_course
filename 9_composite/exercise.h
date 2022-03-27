//
// Created by Martin Edviken on 2022-02-22.
//

#ifndef INC_7_COMPOSITE_EXERCISE_H
#define INC_7_COMPOSITE_EXERCISE_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

struct ContainsIntegers {
  virtual int getTotalValue() const = 0;
};

struct SingleValue : ContainsIntegers
{
  int value{ 0 };

  SingleValue() = default;

  explicit SingleValue(const int value)
      : value{value} {}

  int getTotalValue() const override {
    return value;
  }
};

struct ManyValues : vector<int>, ContainsIntegers
{
  void add(const int value)
  {
    push_back(value);
  }

  int getTotalValue() const override {
    return std::accumulate(begin(), end(), 0);
  }
};

int sum(const vector<ContainsIntegers*> items);

#endif //INC_7_COMPOSITE_EXERCISE_H
