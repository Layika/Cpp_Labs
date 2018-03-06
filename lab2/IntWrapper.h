#pragma once
#include "Wrapper.h"

class IntWrapper : public Wrapper {

public:
  IntWrapper(int val) : val(val) {}
  virtual void push_back(IntWrapper* i);

private:
  int val;
};
