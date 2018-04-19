#include "Executor.h"

double Executor::secureRun(function, double x) {
  try { Result.value = function(x); }
  catch(std::string error) return error;
  catch(bool error) return error;

  Result.valid = 1;
}
