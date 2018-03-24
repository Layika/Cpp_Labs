#pragma once

#include "WatcherCounter.h"
#include "WatcherPrinter.h"

class Watcher;

class Watched {
public:
  void gotNewData(int x);
  void addWatcher(Watcher* toAdd);

private:
};
