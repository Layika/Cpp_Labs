#pragma once
#include "Wrapper.h"

class IntWrapper : public Wrapper {
private:
  int val;

public:
  IntWrapper(int val) : val(val) {}
};
