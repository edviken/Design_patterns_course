//
// Created by Martin Edviken on 2022-02-22.
//
#include "exercise.h"

int sum(const vector<ContainsIntegers*> items)
{
  int sum{0};
  for (const auto item : items) {
    sum += item->getTotalValue();
  }
  return sum;
}