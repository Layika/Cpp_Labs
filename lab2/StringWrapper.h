#pragma once
#include <string>
#include "Wrapper.h"

class StringWrapper : public Wrapper {
private:
  std::string str;

public:
  StringWrapper(std::string str) : str(str) {}
};
