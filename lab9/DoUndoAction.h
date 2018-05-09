#pragma once

#include <iostream>

class DoUndoAction {
public:

  virtual void dodo() { }
  virtual void undoOk() { }
  virtual void undoFail() { }

private:
};
