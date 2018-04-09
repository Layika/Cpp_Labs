#include "FloatData.h"


bool FloatData::cmp(Data& other) const {
  FloatData* data = dynamic_cast<FloatData*>(&other);
  if(!data) return false;
  else if (this->val == data->val) return true;
  else return false;
}
