#include "Executor.h"

std::ostream& operator << (std::ostream& os, const Executor::Result& r) {
  if (r.valid) os << r.value;
 return os;
}

Executor::Result Executor::secureRun(const Function& function, double x) {

  Result r;

  r.valid = 1;

  try { r.value = function(x); }

  catch(const char* error) {
    r.valid = 0;
    std::cout << "ERROR " << error;
  }

  catch(bool error) {
    r.valid = 0;
    std::cout << "ERROR Boolean of value ";
    if (error) std::cout <<  "true thrown";
    else std::cout << "false thrown";
  }

  return r;
}
