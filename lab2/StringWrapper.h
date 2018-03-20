#pragma once
#include "Wrapper.h"
#include <string>

class StringWrapper : public Wrapper {
public:
  StringWrapper(std::string str) : str(str) {}
  virtual void print(std::ostream& os) override { os << str; }

private:
  std::string str;
};
