#pragma once

#include <iostream>

class Executor {
public:

  struct Result {
    unsigned int valid;
    double value;
    std::string error;
    operator double () { return value; }
  };

  class Function {
  public:
    virtual double operator()(double x) const = 0;
  };

  static Result secureRun(const Function& function, double x);
};

std::ostream& operator << (std::ostream& os, const Executor::Result& r);
