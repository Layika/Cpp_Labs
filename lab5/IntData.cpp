#include "IntData.h"


bool IntData::cmp(const Data& other) const {
  const IntData* data = dynamic_cast<const IntData*>(&other);
  if (!data) return false;
  else if (this->val == data->val) return true;
  else return false;
}
