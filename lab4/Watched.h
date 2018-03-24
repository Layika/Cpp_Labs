#pragma once

#include "WatcherCounter.h"
#include "WatcherPrinter.h"

class Watcher;

class Watched {
public:

  Watched();
  void gotNewData(int x);
  void addWatcher(Watcher* toAdd);
  void expandWatchers(Watcher** watchers);

private:
  Watcher** watchers;
  unsigned int size;
  unsigned int capacity;
};
