#include "FloatData.h"


bool FloatData::cmp(const Data& other) const {
  const FloatData* data = dynamic_cast<const FloatData*>(&other);
  if (!data) return false;
  else if (this->val == data->val) return true;
  else return false;
}
