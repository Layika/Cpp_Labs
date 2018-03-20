#include "PVec.h"

PVec::PVec() {
  capacity = 10;
  wrappersVec = new Wrapper*[capacity];;
  size = 0;
}

void PVec::appendVec(Wrapper** wrappersVec) {
  Wrapper** newVec = new Wrapper*[capacity*2];
  for (unsigned int i=0; i < capacity; ++i)
    newVec[i] = wrappersVec[i];
  wrappersVec = newVec;
  capacity = 2*capacity;
}

PVec& PVec::pushBack(Wrapper* toAdd) {
  if (size >= capacity) appendVec(wrappersVec);
  wrappersVec[size++] = toAdd;

  return *this;
}

PVec& PVec::operator<<(Wrapper* toAdd) {
  return pushBack(toAdd);
}

Wrapper& PVec::operator[](unsigned int x) {
  return *wrappersVec[x];
}

std::ostream& operator<<(std::ostream& os, const PVec& vec) {
  for (unsigned int i=0; i<vec.getSize(); ++i) {
     vec.getVec()[i]->print(os);
     os << " ";
   }
  os << std::endl;
  return os;
}
