#include "Executor.h"

std::ostream& operator << (std::ostream& os, const Executor::Result& r) {
  if (r.valid) os << r.value;
 return os;
}

static Executor::Result Executor::secureRun(const Function& function, double x) {

  Result r;

  try { r.value = function(x); }
  catch(std::string error) r.valid = 0;
  catch(bool error) r.valid = 0;

  r.valid = 1;
  return r;
}
