#include "StringData.h"


bool StringData::cmp(const Data& other) const {
  const StringData* data = dynamic_cast<const StringData*>(&other);
  if(!data) return false;
  else if (this->str == data->str) return true;
  else return false;
}
