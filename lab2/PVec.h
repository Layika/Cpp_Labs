#pragma once
#include "IntWrapper.h"
#include "FloatWrapper.h"
#include "StringWrapper.h"
#include "Wrapper.h"
#include <iostream>

class PVec {
public:
  PVec();
  ~PVec() { delete [] wrappersVec; }

  unsigned int getSize() const { return size; }
  Wrapper** getVec() const { return wrappersVec; }

  void appendVec(Wrapper** wrappersVec);
  PVec& pushBack(Wrapper* toAdd);

  PVec& operator<<(Wrapper* toAdd);

  Wrapper& operator[](unsigned int x);

private:
  Wrapper** wrappersVec;
  unsigned int size;
  unsigned int capacity;
};

std::ostream& operator<<(std::ostream& os, const PVec& vec);
