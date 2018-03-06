#pragma once
#include "Wrapper.h"

class FloatWrapper : public Wrapper {
private:
  float val;

public:
  FloatWrapper(float val) : val(val) {}

};
