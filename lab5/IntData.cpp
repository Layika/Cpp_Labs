#include "IntData.h"


bool IntData::cmp(Data& other) const {
  IntData* data = dynamic_cast<IntData*>(&other);
  if (!data) return false;
  else if (this->val == data->val) return true;
  else return false;
}
