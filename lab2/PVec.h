#pragma once

#include "IntWrapper.h"
#include "FloatWrapper.h"
#include "StringWrapper.h"

class PVec {

public:
  virtual void push_back() {}

private:
  PVec** vect;
};
