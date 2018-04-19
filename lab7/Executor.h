#pragma once

#include <iostream>

class Executor {
public:

  struct Result {
    unsigned int valid;
    double value;
    operator double () { return value; }
  };

  class Function {};
  static Result secureRun(const Function& function, double x);
};

std::ostream& operator << (std::ostream& os, const Executor::Result& r);
