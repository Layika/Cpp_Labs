#pragma once
#include <string>
#include "Wrapper.h"

class StringWrapper : public Wrapper {

public:
  StringWrapper(std::string str) : str(str) {}
  virtual void push_back(StringWrapper* s);

private:
  std::string str;
};
