#pragma once

#include <iostream>
#include "DoUndoAction.h"


class KeepInt : public DoUndoAction {
public:
	void dodo() {}
	void undoOk() {}
	void undoFail() {i=prev;}

	KeepInt(int& i) : i(i), prev(i) {}

private:
	int& i;
	int prev;
};


class DoUndo {
public:

	DoUndo(DoUndoAction* act) : act(act) {act->dodo(); ok=0;}

	~DoUndo() { if (!ok) act->undoFail(); else act->undoOk(); }

	static void allok() { ok=1; }

private:
	DoUndoAction* act;
	static bool ok;
};
