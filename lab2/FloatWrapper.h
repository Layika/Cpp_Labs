#pragma once
#include "Wrapper.h"

class FloatWrapper : public Wrapper {
public:
  FloatWrapper(float value) : value(value) {}
  virtual void print(std::ostream& os) override { os << value; }

private:
  float value;
};
