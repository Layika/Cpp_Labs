#include "StringData.h"


bool StringData::cmp(Data& other) const {
  StringData* data = dynamic_cast<StringData*>(&other);
  if(!data) return false;
  else if (this->str == data->str) return true;
  else return false;
}
