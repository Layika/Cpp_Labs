#include "Executor.h"

std::ostream& operator << (std::ostream& os, const Executor::Result& r) {
  if (r.valid) os << r.value;
 return os;
}

Executor::Result Executor::secureRun(const Function& function, double x) {

  Result r;

  try { r.value = function(x); }

  catch(std::string error) {
    r.valid = 0;
    std::cout << "ERROR " << error << std::endl;
  }

  catch(bool error) {
    r.valid = 0;
    std::cout << "ERROR Boolean of value ";
    if (error) std::cout <<  "true thrown" << std::endl;
    else std::cout << "false thrown" << std::endl;
  }

  r.valid = 1;
  return r;
}
