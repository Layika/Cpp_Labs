#pragma once
#include "Wrapper.h"

class FloatWrapper : public Wrapper {

public:
  FloatWrapper(float val) : val(val) {}
  virtual void push_back(FloatWrapper* f);

private:
  float val;
};
