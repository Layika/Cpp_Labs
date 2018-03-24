#pragma once

#include "Watcher.h"

class WatcherCounter : public Watcher {
public:
  WatcherCounter() : _sum(0) {}
  virtual void gotNewData(int x) { _sum += x; }
  int sum() { return _sum; }

private:
  int _sum;
};
