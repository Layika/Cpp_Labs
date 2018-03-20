#pragma once
#include "Wrapper.h"

class IntWrapper : public Wrapper{
public:
  IntWrapper(int value) : value(value) {}
  virtual void print(std::ostream& os) override { os << value; }

private:
  int value;
};
