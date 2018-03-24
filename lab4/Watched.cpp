#include "Watched.h"

Watched::Watched() :size(0), capacity(10) {
  watchers = new Watcher*[capacity];
}

void Watched::addWatcher(Watcher* toAdd) {
  if (size >= capacity) expandWatchers(watchers);

  watchers[size] = toAdd;
  size++;
}

void Watched::expandWatchers(Watcher** watchers) {
  Watcher** newWatchers = new Watcher*[capacity*2];
  for (unsigned int i = 0; i < size; ++i)
    newWatchers[i] = watchers[i];
  watchers = newWatchers;

  capacity = capacity*2;
}

void Watched::gotNewData(int x) {

}
